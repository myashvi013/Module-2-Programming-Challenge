/*
 * Planet: LinkedList.cpp
 * Creator: Yashvi Mehta
 * Backstory: The map guiding the templeted LinkedList class
 */

#include "LinkedList.h"

//Constructur: Initializes empty state
template<typename T>
LinkedList<T>::LinkedList():head(nullptr), tail(nullptr), size(0){}

//Destructor: De-allocates nodes to free memory
template <typename T>
LinkedList<T>::~LinkedList(){
    ListNode<T>*walker=head;
    while (walker){
        ListNode<t>*holdNext=walker->next;
        delete walker;
        walker=holdNext;
    }
    head=nullptr;
    tail=nullptr;
    size=0;
}

//Adds a new element at the tail
template <typename T>
void LinkedList<T>::addItem(T val) {
    ListNode<T>*freshNode=new ListNode<T>{val, nullptr};
    if(!head){
        head=freshNode;
        tail=freshNode;
    } else{
        tail->next=freshNode;
        tail=freshNode;
    }
    size++;
}

//Finds and deletes the first matching element
template <typename T>
bool LinkedList<T>::remove(T val){
    if(!head) return false;
    ListNode<T>*target=head;
    ListNode<T>*trailing=nullptr;

    //Iterates through items unitl item found or list finished
    while(target&&target->data!=val){
        trailing=target;
        target=target->next;
    }
    //Item not found
    if(!target) return false;

    //Unlink logic
    if(!trailing){
        head=target->next;
        if(!head)tail = nullptr;
    } else{
        trailing->next=target->next;
        if(target==tail)tail=trailing;
    }
    delete target;
    size--;
    return true;
}
//Searches for a value in the list
template <typename T>
bool LinkedList<T>::find(T val)const{
    ListNode<T>*seeker=head;
    while(seeker){
        if(seeker->data==val){
            return true;
        }
        seeker=seeker->next;
    }
    return false;
}

//Returns the element count
template <typename T>
int LinkedList<T>::getSize()const{
    return size;
}

//Explicit template instantation for integer lists
template class LinkedList<int>;