#pragma once

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
        std::istream& read;

    private:
        double thesis;
};

Core::Core(): midterm(0), final(0) { }

Core::Core(std::istream& in) { read(in); }

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