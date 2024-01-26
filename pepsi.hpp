#ifndef PEPSI_HPP
#define PEPSI_HPP

#include "napoj.hpp"

class Pepsi : public napoj {
private:
    const int NR = 2; 

public:
    Pepsi() : napoj("Pepsi") { cena = 5.0; }
    double get_cena() const override { return cena; }
    std::string get_nazwa() const override { return "Pepsi"; }
};

#endif 