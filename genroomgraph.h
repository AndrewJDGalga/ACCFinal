/*
 * NAME: Andrew J
 * COSC 2436
 * PURPOSE:
 *    GRAPH ATTEMPT
 *      attempt at a graph class
 */

#ifndef GENROOMGRAPH_H
#define GENROOMGRAPH_H

#define BASE_ROOM_WEIGHT 0
#define INI_ROOM_SIZE 200 //whenever I attempted to re-size during the program's execution I got crashes
//setting the size outside the possible range is the only thing that seems to work, which I assume to mean
//all of my attempts at resizing or reserving remain wrong in a way I cannot currently understand

#include <string>
#include <iostream>
#include <vector>
#include "linkedlist.h"
using std::string;
using std::cout;
using std::endl;
using std::vector;

class RoomsGraph
{
    public:
        RoomsGraph();
        bool buildRoom(int, string*);
        bool destroyRoom(int);
        bool getRoomContents(int, Data*);
        int getRoomCount();
        bool buildHallBetweenRooms(int, int, int, string*);
        bool changeHall(int, int, Data*);
        bool destroyHallBetweenRooms(int, int);
        int getHallCount();
        bool hallExistsBetween(int, int);
        bool roomExists(int);
        bool isEmpty();
    private:
        vector<LinkedList> rooms;
        int countRooms;
        int countHalls;
        int largestID;
};
#endif
