#ifndef MONEY_HPP
#define MONEY_HPP

#include <vector>
#include <iostream>
#include <limits>
#include <iomanip>

class Money {
private:
    double total_money; 
    const double nominaly[3] = { 5.0, 2.0, 1.0 };

public:
    Money();    
    ~Money();
    double kasain();
    double kasaout(double price);
    double kasacheck(double price);
    std::vector<double> wydawanie_reszty(double change);
};
// test

Money::Money() : total_money(0.0) {}

Money::~Money() {}

double Money::kasain() {
    double coin;

    std::cout << "Wprowadz monety 1 zl, 2 zl, 5 zl. Wpisz 0, aby zakonczyc: " << std::endl;

    do {
        if (!(std::cin >> coin) || (coin != 1.0 && coin != 2.0 && coin != 5.0 && coin != 0.0)) {
            std::cout << "Nieprawidlowa moneta. Wprowadz 1 zl, 2 zl, 5 zl lub 0, aby zakonczyc." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else if (coin != 0.0) {
            total_money += coin;
            std::cout << "Aktualne środki: " << std::fixed << std::setprecision(2) << total_money << " zl." << std::endl;
        }
    } while (coin != 0.0);

    return total_money;
}

double Money::kasaout(double price) {
    double change = total_money - price;
    if (change < 0) {
        std::cout << "Brak środków. Brakuje: " << std::fixed << std::setprecision(2) << -change << " zl." << std::endl;
        return -1; 
    }

    total_money = 0; 
    return change;
}
double Money::kasacheck(double price) {
    double total_money_backup = total_money; 
    double additional_money = kasain(); 

    while (total_money < price) {
        std::cout << "Brak środków. Wprowadz wiecej monet." << std::endl;
        additional_money = kasain(); 
    }

    total_money += total_money_backup; 

    return additional_money;
}

std::vector<double> Money::wydawanie_reszty(double change) {
    std::vector<double> wydaneNominaly;

    for (const double nominal : nominaly) {
        while (change >= nominal) {
            wydaneNominaly.push_back(nominal);
            change -= nominal;
        }
    }

    return wydaneNominaly;
}


#endif // MONEY_HPP
