//
//  main.cpp
//  DoublyLinkedListUsingSmartPointers
//
//  Created by Rohan Arora on 02/11/21.
//

#include <iostream>
#include <string>
#include "DoublyLinkedList.hpp"

int main(int argc, const char * argv[]) {
    mylib::List<std::string> mylist;

    mylist.append("R");
    mylist.append("o");
    mylist.append("h");
    mylist.append("a");
    mylist.append("n");
//    mylist.printReverse();
//    mylist.resetList();
//    mylist.remove(8);
    mylist.printForward();
//    mylist.remove("n");
    mylist.printForward();
//    std::cout<<std::boolalpha<<mylist.search("n");
    return 0;
}
