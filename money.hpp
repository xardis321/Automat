#ifndef MONEY_HPP
#define MONEY_HPP

#include <vector>
#include <iostream>
#include <limits>
#include <iomanip>
#include <iomanip>
using namespace std;

class Money
{
private:
    double total_money; 
    const double nominaly[3] = { 5.0, 2.0, 1.0 };

public:
    Money();    
    ~Money();
    double money_input();
    double money_output(double price);
    double check_money(double price);
    std::vector<double> wydawanie_reszty(double change);
};


Money::Money() : total_money(0.0) {}

Money::~Money()
{
    
}

double Money::money_input()
{
    double coin;

    std::cout << "Wprowadz monety 1 zl, 2 zl, 5 zl. Wpisz 0, aby zakonczyc: " << std::endl;

    do
    {
        if (!(std::cin >> coin) || (coin != 1.0 && coin != 2.0 && coin != 5.0 && coin != 0.0))
        {
            std::cout << "Nieprawidlowa moneta. Wprowadz 1 zl, 2 zl, 5 zl lub 0, aby zakonczyc." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else if (coin != 0.0)
        {
            total_money += coin;
            std::cout << "Aktualne środki: " << std::fixed << std::setprecision(2) << total_money << " zl." << std::endl;
        }

    } while (coin != 0.0);

    return total_money;
}

double Money::money_output(double price)
{
    double change = total_money - price;

    if (change < 0)
    {
        cout << "Brak środków. Brakuje: " << fixed << setprecision(2) << -change << " zl." << endl;
        return -1; 
    }
    else
    {
        total_money = 0; 
        return change;
    }
}

double Money::check_money(double price)
{
    double total_money_backup = total_money; 
    double additional_money = money_input(); 

    while (total_money < price)
    {
        cout << "Brak środków. Wprowadz wiecej monet." << endl;
        additional_money = money_input(); 
    }

    total_money += total_money_backup; 

    return additional_money;
}
std::vector<double> Money::wydawanie_reszty(double change) {
    std::vector<double> wydaneNominaly;

    for (int index = 0; index < 3 && change > 0; ++index) {
        int ileRazy = static_cast<int>(change / nominaly[index]);

        for (int i = 0; i < ileRazy; ++i) {
            wydaneNominaly.push_back(nominaly[index]);
        }

        change -= ileRazy * nominaly[index];
    }

    return wydaneNominaly;
}

#endif 
