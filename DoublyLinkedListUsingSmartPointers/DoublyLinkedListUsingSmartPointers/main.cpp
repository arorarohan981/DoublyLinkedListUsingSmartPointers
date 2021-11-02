//
//  main.cpp
//  DoublyLinkedListUsingSmartPointers
//
//  Created by Rohan Arora on 02/11/21.
//

#include <iostream>
#include "DoublyLinkedList.hpp"

int main(int argc, const char * argv[]) {
    mylib::List<int> mylist;
    for(int i =1;i<10;i++){
        mylist.append(i);
    }
    mylist.print();
    return 0;
}
