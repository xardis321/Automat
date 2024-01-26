#ifndef NAPOJ_HPP
#define NAPOJ_HPP

#include <string>

class napoj {
private:
    std::string nazwa_napoju;

protected:
    double cena;

public:
    napoj() : cena(0.0) {}
    napoj(std::string nazwa) : nazwa_napoju(nazwa), cena(0.0) {}
    napoj(const napoj&) : cena(0.0) {}
    virtual void set_nazwa(std::string nazwa) { nazwa_napoju = nazwa; }
    virtual double get_cena() const { return cena; }
    virtual std::string get_nazwa() const { return nazwa_napoju; }
    virtual ~napoj() {}
};

#endif 
