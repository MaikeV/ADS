#include <iostream>

#define CATCH_CONFIG_RUNNER

#include "catch.hpp"
#include "List.h"

void test() {
    List TestList;

    std::cout << "================================" << std::endl;
    std::cout << "         EIGENE TESTS: " << std::endl;
    std::cout << "================================" << std::endl << std::endl;


    TestList.insertBack(5);
    TestList.insertBack(6);
    TestList.insertBack(7);
    TestList.insertBack(8);

    TestList.insertFront(1);
    TestList.insertFront(2);
    TestList.insertFront(3);
    TestList.insertFront(4);

    std::cout << TestList;

    int key = 8;
    if (!TestList.getBack(key)) {
        std::cout << "Failure: failed to get " << key << " from the back of the list." << std::endl;
    } else {
        std::cout << "Success: " << key << " is the back of the list." << std::endl;
    }

    std::cout << std::endl << TestList;

    key = 4;
    if (!TestList.getFront(key)) {
        std::cout << "Failure: failed to get " << key << " from the front of the list." << std::endl;
    } else {
        std::cout << "Success: " << key << " is the front of the list." << std::endl;
    }

    std::cout << std::endl << TestList << std::endl;

    std::cout << "Swap [1, 5]: ";
    TestList.swap(1, 5);
    std::cout << TestList << std::endl;

    std::cout << "Swap [7, 6]: ";
    TestList.swap(6, 7);
    std::cout << TestList << std::endl;

    std::cout << "Swap [3, 2]: ";
    TestList.swap(3, 2);
    std::cout << TestList << std::endl;

    key = 2;
    if(!TestList.search(key)) {
        std::cout << "Failure: failed to find " << key << " in the list!" << std::endl;
    } else {
        std::cout << "Success: found " << key << " in list!" << std::endl;
    }

    key = 8;
    if(!TestList.search(key)) {
        std::cout << "Success: failed to find " << key << " in the list!" << std::endl;
    } else {
        std::cout << "Failure: found " << key << " in list!" << std::endl;
    }
}

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

    MyList3.swap(8, 103);

    std::cout << MyList3;

    if (MyList3.test()) {
        std::cout << "MyList3: Zeiger OK\n\n";
    } else {
        std::cout << "MyList3: Zeiger ******Error\n\n";
    }

    test();

    //system("PAUSE");
    return 0;
}
