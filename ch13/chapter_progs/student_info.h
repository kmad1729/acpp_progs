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
        std::istream& read
};
