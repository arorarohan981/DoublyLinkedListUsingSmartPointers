//
//  DoublyLinkedList.hpp
//  DoublyLinkedListUsingSmartPointers
//
//  Created by Rohan Arora on 02/11/21.
//

#ifndef DoublyLinkedList_hpp
#define DoublyLinkedList_hpp

#include <stdio.h>
#include <memory>
namespace mylib{

template <typename T>
class List{
private:
    
    struct Node{
        T data;
        std::unique_ptr<Node> next;
        Node* prev;
        Node(T &userData)
        {
            data=userData;
        }
        
    };
    
    std::unique_ptr<Node> head;
    Node *tail=nullptr;
    size_t numberOfNodes;
    
public:
    //Appends the T type of data to the end of the List.
    void append(T &userData);
    
    //Checks whether the List is Empty.
    //Return True if the List is Empty.
    bool isEmpty() const;
     
    //Prints the List
    void print() const;
    
    
};

template <typename T>
void List<T>::append(T &userData){
    std::unique_ptr<Node> userNode= std::make_unique<Node>(userData);
    if(isEmpty()){
        head=std::move(userNode);
        tail=head.get();
        numberOfNodes++;
    }else{
        tail->next=std::move(userNode);
        tail=tail->next.get();
        numberOfNodes++;
    }
}

template <typename T>
bool List<T>::isEmpty() const{
    if(head==nullptr ){
        return true;
    }
    return false;
}


template <typename T>
void List<T>::print() const{
    std::cout<<"Elements in the List are as follows"<<std::endl;
    Node *iterptr=head.get();
    while(iterptr->next!=nullptr){
        std::cout<<iterptr->data<<std::endl;
        iterptr=iterptr->next.get();
    }
    std::cout<<iterptr->data<<std::endl;
    
}


}
#endif /* DoublyLinkedList_hpp */
