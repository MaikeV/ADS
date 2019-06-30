#define CATCH_CONFIG_RUNNER

#include <iostream>
#include "Graph.h"
#include "catch.h"

int main() {
    Catch::Session().run();

    char choice = '1';
    char graphChoice = '1';
    std::string path = "";
    Graph graph;

    while(choice != '0') {
        std::cout << "Working on Grphs. Please choose:" << std::endl <<
        "1) Graph einlesen" << std::endl <<
        "2) Tiefensuche" << std::endl <<
        "3) Breitensuche" << std::endl <<
        "4) Prim" << std::endl <<
        "5) Kruskal" << std::endl <<
        "6) Print Graph" << std::endl <<
        "0 zum beenden" << std::endl << "?> ";

        std::cin >> choice;

        switch(choice) {
            case '1':
                std::cout << "Welcher Graph soll eingelesen werden - 1, 2 oder 3?" << std::endl;
                std::cin >> graphChoice;

                path = "/home/mauske/Studium/ADS/ADS/Praktika/Praktikum5/";

                switch(graphChoice) {
                    case '1':
                        path += "graph1.txt";
                        break;
                    case '2':
                        path += "graph2.txt";
                        break;
                    case '3':
                        path += "graph3.txt";
                        break;
                    default:
                        std::cout << "Falsche Eingabe " << std::endl << std::endl;
                }

                graph.init(path);

                break;
            case '2':

            case '3':

            case '4':

            case '5':

            case '6':
                graph.printAll();
            case '0':
                break;
            default:
                std::cout << "Falsche Eingabe " << std::endl << std::endl;
                break;
        }
    }


    return 0;
}