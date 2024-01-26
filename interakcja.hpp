#ifndef INTERAKCJA_HPP
#define INTERAKCJA_HPP

#include "napoj.hpp"
#include "cola.hpp"
#include "pepsi.hpp"
#include "sprite.hpp"
#include <iostream>
#include <limits>
#include <iomanip>
const int ILOSC = 3;

using namespace std;

class Interakcja
{
private:
    napoj* wybrany_napoj;

public:
    Interakcja();               
    ~Interakcja();              
    int choose_drink();         
    void check_number(int& chosen_number); 
    void show_price();
    std::string get_wybrana_nazwa();
};
Interakcja::Interakcja() : wybrany_napoj(nullptr) {}

Interakcja::~Interakcja()
{
    delete wybrany_napoj; 
}

int Interakcja::choose_drink()
{
    int drinknumber; // użytkownik wybiera numer
    do
    {
        cout << "Wybierz napoj: ";
        while (!(cin >> drinknumber))
        {
            cout << "Nieprawidlowa wartosc. Wybierz ponownie: ";
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        if (drinknumber > ILOSC)
        {
            cout << "Numer poza zakresem. Wybierz numer od 1 do " << ILOSC << "." << endl;
            continue; // Powrót na początek pętli do
        }

        check_number(drinknumber);
    } while (drinknumber > ILOSC);

    delete wybrany_napoj; // zwalnia pamięć, jeśli była już zaalokowana
    switch (drinknumber)
    {
    case 1:
        wybrany_napoj = new CocaCola();
        break;
    case 2:
        wybrany_napoj = new Pepsi();
        break;
    case 3:
        wybrany_napoj = new Sprite();
        break;
    }

    return drinknumber;
}



void Interakcja::check_number(int& chosen_number)
{
    if ((chosen_number > ILOSC)&&(chosen_number =0))
    {
        cout << "Brak wybranego napoju. Wybierz inny numer." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

void Interakcja::show_price()
{
    if (wybrany_napoj != nullptr)
    {
        cout << fixed << setprecision(2) << "Cena wybranego napoju to: " << wybrany_napoj->get_cena() << " zl.\n" << endl;
    }
    else
    {
        cout << "Nie wybrano napoju." << endl;
    }
}

std::string Interakcja::get_wybrana_nazwa()
{
    if (wybrany_napoj != nullptr)
    {
        return wybrany_napoj->get_nazwa();
    }
    else
    {
        return "Brak wybranego napoju";
    }
}


#endif // INTERAKCJA_HPP
