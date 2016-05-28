#pragma once

#include <iostream>
#include <string>
#include <vector>

class Core {
    public:
        Core(): midterm(0), final_grade(0) { };
        Core(std::istream& is) {read(is);}
        std::istream& read(std::istream&);
        virtual std::string name() const;
        virtual double grade() const;

        virtual ~Core() { };

    protected:
        std::istream& read_common(std::istream&);
        double midterm, final_grade;
        std::vector<double> homework;

    private:
        std::string n;
};

class Grad: public Core {
    public:
        Grad() : thesis(0) { }
        Grad(std::istream& is) { read(is); }
        std::istream& read(std::istream&);
        double grade() const;

    private:
        double thesis;
};

bool compare_Core_ptrs(const Core*, const Core*);
