/*
 * NAME: Andrew Jonhardt
 * COSC 2436
 * PURPOSE:
 *    GRAPH ATTEMPT
 */


#ifndef DATA_H
#define DATA_H

#include <string>
using std::string;


/*
    A structure to hold integer ID, weight, and a string data value;
*/
struct Data
{
    int id, weight;
    string data;
};


/*
    A structure to be used as part of a linked list or similiar dynamic object.
    Holds values of type data and 2 pointers to allow use as part of chain.
*/
struct Node
{
    Data data;
    Node *prev;
    Node *next;
};
#endif
