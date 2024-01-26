#ifndef COCACOLA_HPP
#define COCACOLA_HPP

#include "napoj.hpp"

class CocaCola : public napoj {
private:
    const int NR = 1; 
public:
    CocaCola() : napoj("CocaCola") { cena = 3.0; }
    double get_cena() const override { return cena; }
    std::string get_nazwa() const override { return "CocaCola"; }
};

#endif 
