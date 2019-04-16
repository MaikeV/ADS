#include <iostream>

#define CATCH_CONFIG_RUNNER

#include "catch.hpp"
#include "List.h"

int main() {
    int result = Catch::Session().run();
    int i;
    List MyList;

    for (i = 0; i < 10; i++) {
        MyList.insertFront(i + 1);
        MyList.insertBack(i + 100);
    }

    std::cout << MyList;

    std::cout << "100: " << (MyList.search(100) ? "gefunden" : "nicht gefunden") << std::endl;
    std::cout << "99: " << (MyList.search(99) ? "gefunden" : "nicht gefunden") << std::endl << std::endl;

    while (MyList.getBack(i)) {
        std::cout << i << " ";
    }

    std::cout << std::endl << std::endl;

    List MyList1, MyList2, MyList3;
    List *MyList_dyn = new List;

    for (i = 0; i < 10; i++) {
        MyList1.insertFront(i + 1);
        MyList2.insertBack(i + 100);
    }

    MyList1.format("MyList1\n<<", ", ", ">>\n\n");
    std::cout << MyList1;

    MyList_dyn->format("MyList_dyn\n<<", ", ", ">>\n\n");
    MyList_dyn->insertFront(-111);
    std::cout << MyList_dyn;

    MyList2.format("MyList2\n<<", ", ", ">>\n\n");
    std::cout << MyList2;

    MyList3 = MyList1 + MyList_dyn + MyList2;

    delete MyList_dyn;

    std::cout << "Groesse von MyList3: " << MyList3.size() << std::endl << std::endl;

    MyList3.format("MyList3\n<<", ", ", ">>\n\n");
    std::cout << MyList3 << std::endl;

    //MyList3.swap(8, 103);
    MyList3.swap(9, 2);
    std::cout << MyList3;

    if (MyList3.test()) {
        std::cout << "MyList3: Zeiger OK\n\n";
    } else {
        std::cout << "MyList3: Zeiger ******Error\n\n";
    }

    //system("PAUSE");
    return 0;
}
