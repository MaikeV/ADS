#define CATCH_CONFIG_RUNNER
#include <iostream>
#include "Tree.h"
#include "catch.h"

int main() {
    int result = Catch::Session().run();

    char answer = '0';
    std::string name;
    int plz;
    int age;
    double income;
    char yesNo;
    int posId;

    Tree tree;

    std::cout << "Person Analyzer v19.84, by George Orwell" << std::endl;
    std::cout << "========================================" << std::endl;

    while(answer != '6') {
        std::cout << "1) Datensatz einfuegen, manuell" << std::endl;
        std::cout << "2) Datensatz einfuegen, csv" << std::endl;
        std::cout << "3) Datensatz loeschen" << std::endl;
        std::cout << "4) Suchen" << std::endl;
        std::cout << "5) Datenstruktur anzeigen" << std::endl;
        std::cout << "6) Programm beenden" << std::endl;
        std::cout << "?> ";
        std::cin >> answer;

        switch (answer) {
            case '1':
                std::cout << "+ Bitte geben Sie den Datensatz ein" << std::endl;
                std::cout << "Name ?> ";
                std::cin >> name;
                std::cout << "Alter ?> ";
                std::cin >> age;
                std::cout << "Einkommen ?> ";
                std::cin >> income;
                std::cout << "PLZ ?> ";
                std::cin >> plz;

                tree.addNode(name, age, income, plz);

                std::cout << "+ Ihr Datensatz wurde eingefuegt" << std::endl << std::endl;

                break;
            case '2':
                std::cout << "+ Moechten Sie die Datei \"Export Zielanalyse.csv\" importieren? (j/n) ?> " << std::endl;
                std::cin >> yesNo;

                if(yesNo == 'j') {
                    tree.readFromCsv();

                    std::cout << "+ Daten wurden dem Baum hinzugefuegt." << std::endl << std::endl;
                    break;
                } else if (yesNo == 'n') {
                    break;
                } else {
                    std::cout << "+ Ungeueltige Eingabe, bitte versuchen Sie es erneut." << std::endl << std::endl;
                    break;
                }
            case '3':
                std::cout << "+ Bitte geben Sie den zu loeschenden Datensatz an" << std::endl;
                std::cout << "PosId ?> ";
                std::cin >> posId;

                std::cout << "+ Datensatz wurde geloescht." << std::endl << std::endl;
                break;
            case '4':
                std::cout << "+ Bitte geben Sie den zu suchenden Datensatz an" << std::endl;
                std::cout << "Name ?> ";
                std::cin >> name;

                std::cout << "+ Fundstellen: " << std::endl;

                if(!tree.searchNode(name)) {
                    std::cout << "Keine." << std::endl << std::endl;
                }

                std::cout << std::endl;
                break;
            case '5':
                tree.printAll();
                break;
            case '6':
                break;
            default:
                std::cout << "+ Ungueltige Eingabe, bitte versuchen Sie es erneut." << std::endl << std::endl;
                break;
        }
    }


    return 0;
}
