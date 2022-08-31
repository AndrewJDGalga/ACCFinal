/*
 * NAME: Andrew J
 * COSC 2436
 * PURPOSE:
 *    LINKED LIST IMPLEMENTATION
 *      The following class implements a bi-directional
 *        linked list, where the list connects in 2 directions.
 *          Private variable head serves as the attach point for all nodes.
 *          Constructor initializes head while destructor cleans up memory used by list.
 *          Includes ability to add, delete, get, print, count, and clear nodes added to list.
 */

#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include <string>
#include <iostream>
#include "data.h"
using std::cout;
using std::endl;

class LinkedList
{
  private:
    Node *head;
    void addHead(int, int, string*, Node*);
    void addMid(int, int, string*, Node*);
    void addTail(int, int, string*, Node*);
    void deleteNode(Node*);
    Node* search(int);
  public:
    LinkedList();
    ~LinkedList();
    operator bool() const;
    bool addNode(int, int, string*);
    bool deleteNode(int);
    bool getNode(int, Data*);
    bool changeNodeContent(int, Data*);
    void printList(bool = false);
    int getCount();
    bool headAlive();
    bool clear();
    bool exists(int);
    bool headAlone();
    int nextID(int);
};

#endif //linked_list
