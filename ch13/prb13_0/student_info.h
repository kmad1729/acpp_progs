#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

class Core {
    friend class Student_info;
    public:
        Core(): midterm(0), final_grade(0) { }
        Core(std::istream& is) {read(is);}
        std::string name() const;
        virtual double grade() const;
        virtual std::istream& read(std::istream&);

        virtual ~Core() { }

    protected:
        std::istream& read_common(std::istream&);
        double midterm, final_grade;
        std::vector<double> homework;
        virtual Core* clone() { return new Core(*this);}

    private:
        std::string n;

};

class Grad: public Core {
    public:
        Grad(): thesis(0) { }
        Grad(std::istream& is) {read(is);}
        double grade() const;
        std::istream& read(std::istream&);

    protected:
        virtual Grad* clone() { return new Grad(*this);}

    private:
        double thesis;
};

class Student_info {
    public:
        Student_info() : cp(0) { }
        Student_info(std::istream& is) { read(is);}
        Student_info(const Student_info&);
        Student_info& operator=(const Student_info&);
        ~Student_info() { delete cp;}

        std::istream& read(std::istream&);

        std::string name() const {
            if(cp) { return cp -> name(); }
            else throw std::runtime_error("uninitialized student!");
        }

        double grade() const {
            if(cp) { return cp -> grade(); }
            else throw std::runtime_error("uninitialized student!");
        }

        static bool compare(const Student_info& s1, const Student_info& s2) {
            return s1.name() < s2.name();
        }

    private:
        Core* cp;
};
