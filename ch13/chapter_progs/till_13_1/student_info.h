#pragma once

#include "grade.h"
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>

class Core {
    public:
        Core();
        Core(std::istream&);
        std::istream& read(std::istream&);
        std::string name() const {return n;}
        double grade() const;

    protected:
        std::istream& read_common(std::istream&);
        double midterm, final;
        std::vector<double> homework;

    private:
        std::string n;
};


class Grad: public Core {
    public:
        Grad();
        Grad(std::istream&);
        std::istream& read(std::istream&);
        double grade() const;

    private:
        double thesis;
};

Core::Core(): midterm(0), final(0) { }

Core::Core(std::istream& in) { read(in); }

double Core::grade() const {
    return ::grade(midterm, final, homework);
}

double Grad::grade() const {
    return std::min(Core::grade(), thesis);
}

std::istream& read_hw(std::istream& in, std::vector<double>& hw)
{
    if(in) {
        hw.clear();

        double x;
        while(in >> x) {
            hw.push_back(x);
        }

        in.clear();
    }
    return in;
}

std::istream& Core::read(std::istream& in)
{
    read_common(in);
    read_hw(in, homework);
    return in;
}

std::istream& Core::read_common(std::istream& in)
{
    in >> n >> midterm >> final;
    return in;
}

Grad::Grad(): thesis(0) { }

Grad::Grad(std::istream& in) {read(in);}

std::istream& Grad::read(std::istream& in)
{
    read_common(in);
    in >> thesis;
    read_hw(in, homework);
    return in;
}

bool compare(const Core& c1, const Core& c2)
{
    return c1.name().size() < c2.name().size();
}
