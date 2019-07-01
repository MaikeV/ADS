#define CATCH_CONFIG_RUNNER

#include <iostream>
#include "Graph.h"
#include "catch.h"

int main() {
    Catch::Session().run();

    char choice = '1';
    char graphChoice = '1';
    int start = 0;
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
                std::cout << "Bitte Startknoten eingeben: ?- ";
                std::cin >> start;

                if(graph.depthSearchRek(start)) {
                    std::cout << "Es konnten alle Knoten besucht werden." << std::endl << std::endl;
                } else {
                    std::cout << "Es konnten nicht alle Knoten besucht werden." << std::endl << std::endl;
                }

                std::cout << std::endl;

                break;
            case '3':
                std::cout << "Bitte Startknoten eingeben: ?- ";
                std::cin >> start;

                if(graph.breadthSearchIter(start)) {
                    std::cout << "Es konnten alle Knoten besucht werden." << std::endl << std::endl;
                } else {
                    std::cout << "Es konnten nicht alle Knoten besucht werden." << std::endl << std::endl;
                }

                std::cout << std::endl;

                break;
            case '4':
                std::cout << "Bitte Startknoten eingeben: ?- ";
                std::cin >> start;

                std::cout << "Prim: " << graph.prim(start) << std::endl << std::endl;
                break;
            case '5':
                std::cout << "Kruskal: " << graph.kruskal() << std::endl << std::endl;
                break;
            case '6':
                graph.printAll();
                break;
            case '0':
                break;
            default:
                std::cout << "Falsche Eingabe " << std::endl << std::endl;
                break;
        }
    }


    return 0;
}