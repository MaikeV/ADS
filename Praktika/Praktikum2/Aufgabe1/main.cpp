/*************************************************
* ADS Praktikum 2.1
* main.cpp
* 
*************************************************/
#define CATCH_CONFIG_RUNNER

#include <iostream>
#include <string>
#include "Ring.h"
#include "catch.hpp"

using namespace std;


int main() {
	int result = Catch::Session().run();
	int answer = 0;
    std::string descr;
    std::string data;
    bool found = false;
	Ring ring;

    std::cout << "OneRingToRuleThemAll v0.1, by Sauron Schmidt" << std::endl;
    std::cout << "============================================" << std::endl;

    while (answer != 4) {
        std::cout << "1) Backup einfuegen" << std::endl;
        std::cout << "2) Backup suchen" << std::endl;
        std::cout << "3) Alle Backups ausgeben" << std::endl;
        std::cout << "4) Programm Beenden" << std::endl;
        std::cout << "?> ";

        std::cin >> answer;

        switch(answer) {
            case 1:
                std::cout << "+ Neuen Datensatz einfuegen" << std::endl;
                std::cout << "Beschreibung ?> ";
                std::cin >> descr;
                std::cout << "Daten ?> ";
                std::cin >> data;

                ring.addNode(descr, data);

                std::cout << "+ Ihr Datensatz wurde hinzugefuegt." << std::endl << std::endl;

                break;
            case 2:
                std::cout << "+ Nach welchen Daten soll gesucht werden?" << std::endl;
                std::cout << "?> ";
                std::cin >> data;

                found = ring.search(data);

                if (found) {
                    RingNode *ptr = ring.getNodeByAge(0);

                    std::cout << "+ Gefunden in Backup: ";

                    while(ptr->getNext()->getAge() != 0) {
                        if(ptr->getData() == data) {
                            break;
                        }
                        ptr = ptr->getNext();
                    }

                    std::cout << "OldAge: " << ptr->getAge() << ", Beschreibung: " << ptr->getDescription() << ", Daten: " << ptr->getData() << std::endl << std::endl;
                } else {
                    std::cout << "+ Datensatz konnte nicht gefunden werden." <<std::endl << std::endl;
                }

                break;
            case 3:
                ring.print();

                break;
            case 4:
                break;
            default:
                std::cout << "Ungueltige Eingabe, bitte versuchen Sie es erneut" << std::endl << std::endl;
                break;
        }
    }


	return 0;
}
