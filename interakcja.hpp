#ifndef INTERAKCJA_HPP
#define INTERAKCJA_HPP

#include "napoj.hpp"
#include "cola.hpp"
#include "pepsi.hpp"
#include "sprite.hpp"
#include <iostream>
#include <limits>
#include <iomanip>
#include <memory>  // Dołączenie nagłówka dla std::unique_ptr

const int ILOSC = 3;

class Interakcja {
private:
    std::unique_ptr<napoj> wybrany_napoj;

public:
    Interakcja() : wybrany_napoj(nullptr) {} // Inicjalizacja wskaźnika jako nullptr w konstruktorze
    ~Interakcja() = default; // Domyślny destruktor automatycznie zarządza pamięcią

    int choose_drink();
    void check_number(int& chosen_number);
    void show_price();
    std::string get_wybrana_nazwa();
};

int Interakcja::choose_drink() {
    int drinknumber;
    do {
        std::cout << "Wybierz napoj: ";
        while (!(std::cin >> drinknumber)) {
            std::cout << "Nieprawidlowa wartosc. Wybierz ponownie: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        if (drinknumber > ILOSC) {
            std::cout << "Numer poza zakresem. Wybierz numer od 1 do " << ILOSC << "." << std::endl;
            continue;
        }

        check_number(drinknumber);
    } while (drinknumber > ILOSC);

    switch (drinknumber) {
    case 1:
        wybrany_napoj = std::make_unique<CocaCola>();
        break;
    case 2:
        wybrany_napoj = std::make_unique<Pepsi>();
        break;
    case 3:
        wybrany_napoj = std::make_unique<Sprite>();
        break;
    }

    return drinknumber;
}

void Interakcja::check_number(int& chosen_number) {
    if ((chosen_number > ILOSC) && (chosen_number = 0)) {
        std::cout << "Brak wybranego napoju. Wybierz inny numer." << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

void Interakcja::show_price() {
    if (wybrany_napoj != nullptr) {
        std::cout << std::fixed << std::setprecision(2) << "Cena wybranego napoju to: " << wybrany_napoj->get_cena() << " zl.\n" << std::endl;
    } else {
        std::cout << "Nie wybrano napoju." << std::endl;
    }
}

std::string Interakcja::get_wybrana_nazwa() {
    if (wybrany_napoj != nullptr) {
        return wybrany_napoj->get_nazwa();
    } else {
        return "Brak wybranego napoju";
    }
}

#endif // INTERAKCJA_HPP
