#ifndef SPRITE_HPP
#define SPRITE_HPP

#include "napoj.hpp"

class Sprite : public napoj {
private:
    const int NR = 3; 
public:
    Sprite() : napoj("Sprite") { cena = 4.0; }
    double get_cena() const override { return cena; }
    std::string get_nazwa() const override { return "Sprite"; }
};

#endif 
