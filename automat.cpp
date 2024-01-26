#include "automat.hpp"
#include <iostream>
#include <limits>
#include <iomanip>
#include <vector>
#include <string>
#include <cctype>
#include <sstream>
#include <unistd.h>
#include "interakcja.hpp"
#include "money.hpp"


void uruchomAutomat() {
    std::cout << "Automat przyjmuje monety 1 zl, 2 zl i 5 zl \n NR 1\t\t NR 2\t\t NR 3\n CocaCola\t Pepsi\t\t Sprite\n 3 zl\t\t 5zl\t\t 4 zl\n";
    Interakcja interakcja;

    int chosen_number = interakcja.choose_drink();

    std::cout << "Wybrany napoj to: " << chosen_number << std::endl;
    interakcja.show_price();
    Money money_manager;
    double total_money = money_manager.kasacheck(interakcja.get_wybrana_nazwa() == "CocaCola" ? 3.0 : (interakcja.get_wybrana_nazwa() == "Pepsi" ? 5.0 : 4.0));

    if (total_money < 0)
    {
        std::cout << "Anulowano, Brak wystarczajacej ilosci pieniedzy." << std::endl;
        return;
    }

    std::cout << "Automat wydaje napoj...\n" << std::endl;
    sleep(2);
    std::cout << "Oto twoj napoj: " << interakcja.get_wybrana_nazwa() << std::endl;

    double change = money_manager.kasaout(interakcja.get_wybrana_nazwa() == "CocaCola" ? 3.0 : (interakcja.get_wybrana_nazwa() == "Pepsi" ? 5.0 : 4.0));

    if (change >= 0)
    {
        std::cout << "\nAutomat wydaje reszte...\n";
        sleep(2);
        std::cout << "\nOto twoja reszta: " << std::fixed << std::setprecision(2) << change << " zl." << std::endl;
    }
    std::vector<double> wydaneNominaly = money_manager.wydawanie_reszty(change);

    std::cout << "Wydane nominaly: ";
    for (double nominal : wydaneNominaly) {
        std::cout << nominal << " ";
    }
    std::cout << std::endl;
}
