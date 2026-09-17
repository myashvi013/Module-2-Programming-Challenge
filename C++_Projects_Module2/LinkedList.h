/*
 * Base: LinkedList.h
 * Maker: Yashvi Mehta
 * Summary: Singly linked list with head and tail pointers 
 */

#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>

//Node holding normal data and next link
template <typename T>
struct ListNode {
    T data;
    ListNode * next;
};

//Forward declaration of list class
template <typename T>
class LinkedList;

//Forward declaration for overloaded output stream operator
template <typename T>
std::ostream& operator<<(std::ostream& stream, const LinkedList<T>& list);
template <typename T>
class LinkedList {
private:
    ListNode<T> * head;
    ListNode<T> * tail;
    int size;
public:
    LinkedList();
    ~LinkedList();

    void addItem(T val);
    bool remove(T val);
    bool find(T val) const;
    int getSize()const;
    friend std::ostream& operator<< <T>(std::ostream& stream, const LinkedList<T>& list);
};

//Stream insertion operator: prints elements in-order with arrows
template <typename T>
std::ostream& operator<<(std::ostream& stream, const LinkedList<T>& list){
    ListNode<T> * traveler = list.head;
    if(!traveler) {
        stream<<"[Empty List]";
        return stream;
    }
    while(traveler){
        stream<<traveler->data;
        if(traveler->next){
            stream<<"->";
        }
        traveler=traveler->next;
    }
    return stream;
}
#endif