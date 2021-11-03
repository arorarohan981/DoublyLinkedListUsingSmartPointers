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
            prev=nullptr;
        }
        
    };
    
    std::unique_ptr<Node> head;
    Node *tail=nullptr;
    size_t numberOfNodes;
    
public:
    //Appends the T type of data to the end of the List.
    void append(T userData);
    
    //Appends the T type of data at the specified position in the List.
    void append(T userData,int position);
    
    //Checks whether the List is Empty.
    //Return True if the List is Empty.
    bool isEmpty() const;
     
    //Prints the List in Forward/first in first out format.
    void printForward() const;
    
    
    //Prints the List in Reverse Order.
    void printReverse()const;
    
    
    //Resets the List
    void resetList() ;
    
    
    //Removes the data from the List by the position which is specified.Return True if Removed Successfully or else return false.
    bool remove(size_t position);
    
    //Removes the data from the List .Return True if Removed Successfully or else return false.
    bool remove(T data);
    
    
    //Returns true if the data is present or else returns false
    bool search(T data);
};

template <typename T>
void List<T>::append(T userData){
    std::unique_ptr<Node> userNode= std::make_unique<Node>(userData);
    if(isEmpty()){
        head=std::move(userNode);
        tail=head.get();
        numberOfNodes++;
    }else{
        tail->next=std::move(userNode);
        tail->next->prev=tail;
        tail=tail->next.get();
        numberOfNodes++;
    }
}


template <typename T>
void List<T>::append(T userData,int position){
    if(position<0){
        std::cout<<"Position cannot be Negative "<<std::endl;
        return;
    }else{
    if(position!=0 and isEmpty()){
        std::cout<<"List is Empty. Cannot Append the Element at the Specified Position"<<std::endl;
        return;
    }else
    {
        std::unique_ptr<Node> temp;
        if(position==0){
            temp=std::move(head);
            head=std::make_unique<Node>(userData);
            head->next=std::move(temp);
            head->next->prev=head.get();
        }else{
            int counter{1};
            Node *iterptr=head.get();
            while(counter<position){
                iterptr=iterptr->next.get();
                counter++;
            }
            
            if(!position==numberOfNodes){
                temp=std::move(iterptr->next);
            iterptr->next=std::make_unique<Node>(userData);
            iterptr->next->prev=iterptr;
            iterptr->next->next=std::move(temp);
                return;
            }else{
                iterptr->next=std::make_unique<Node>(userData);
                iterptr->next->prev=iterptr;
                return;
            }
            
        }
    }
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
void List<T>::printForward() const{
    std::cout<<"Elements in the List are as follows"<<std::endl;
    Node *iterptr=head.get();
    while(iterptr->next!=nullptr){
        std::cout<<iterptr->data<<std::endl;
        iterptr=iterptr->next.get();
    }
    std::cout<<iterptr->data<<std::endl;
    
    
}

template <typename T>
void List<T>::printReverse() const{
    std::cout<<"Elements in the List are as follows (Reverse Order) "<<std::endl;
    Node *iterptr=tail;
    while(iterptr->prev!=nullptr){
        std::cout<<iterptr->data<<std::endl;
        iterptr=iterptr->prev;
    }
    std::cout<<iterptr->data<<std::endl;
    
}


template <typename T>
void List<T>::resetList() {
    head.reset();
}


template <typename T>
bool List<T>::remove(size_t position){
    if(isEmpty()){
        std::cout<<"List is Empty .Cannot Remove element at position"<<position<<std::endl;
        return false;
    }else{
        if(position>=numberOfNodes){
            std::cout<<"Position Entered is Incorrect Please Try Again Later."<<std::endl;
            return false;
        }
        //if there is only one node in the List.
        if(position==0){
            head=std::move(head->next);
            if(numberOfNodes>1){
                head->prev=nullptr;
            }
            numberOfNodes--;
            return true;
        }else{
            size_t counter{0};
            Node *iterptr=head.get();
            while(counter<position-1){
                iterptr=iterptr->next.get();
                counter++;
            }
            if(position!=numberOfNodes-1){
            iterptr->next=std::move(iterptr->next->next);
                iterptr->next->prev=iterptr;
                numberOfNodes--;
                
            }else{
                iterptr->next=nullptr;
                numberOfNodes--;
             
            }
            return true;
        
        }
    }
}

template <typename T>
bool List<T>::remove(T data){
    if(isEmpty()){
        std::cout<<"List is Empty "<<std::endl;
        return false;
    }else{
        Node *iterptr=head.get();
        if(iterptr->data==data){
            head=std::move(head->next);
            if(numberOfNodes>1){
                head->prev=nullptr;
            }
            numberOfNodes--;
            return true;
        }else{
            while (iterptr->next!=nullptr ) {
                if(iterptr->data==data){
                    iterptr->next->prev=iterptr->prev;
                    iterptr->prev->next=std::move(iterptr->next);
                    numberOfNodes--;
                    return true;
                }
                iterptr=iterptr->next.get();
            }
            //If the node is Last Node in the List
            if(iterptr->data==data){
                iterptr->prev->next=nullptr;
                numberOfNodes--;
                return true;
            }else{
                std::cout<<"Node With the Given Value is not found "<<std::endl;
                return false;
            }
        }
    }
}


template <typename T>
bool List<T>::search(T userData) {
    
    Node *iterptr=head.get();
    while(iterptr->next!=nullptr){
        if(iterptr->data==userData){
            return true;
        }
        iterptr=iterptr->next.get();
    }
    if(iterptr->data==userData){
        return true;
    }
    return false;
    
}

}
#endif /* DoublyLinkedList_hpp */
