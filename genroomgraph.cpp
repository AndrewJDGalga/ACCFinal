/*
 * NAME: Andrew J
 * COSC 2436
 * PURPOSE:
 *    GRAPH ATTEMPT
 *      implementation for graph class
 */

#include "genroomgraph.h"


/*
    constructor initializes vector like an array,
    and my inability to figure out vectors means this is only time it's appropriately sized.
    Counters also initialized here
*/
RoomsGraph::RoomsGraph()
{
    rooms.resize(INI_ROOM_SIZE);
    countRooms = 0;
    countHalls = 0;
    largestID = INI_ROOM_SIZE-1;
}


/*
    The following method is supposed to dynamically add a first node to serve as the "room"
    in a graph. It doesn't quite work because I've failed to learn how to take advantage of
    vectors dynamism, and as a result I've settles for something that at least runs.
*/
bool RoomsGraph::buildRoom(int roomID, string* roomDescription)
{
    bool created = false;
    int increase = largestID;

    if( roomID > 0 && !rooms.at(roomID) && *roomDescription != "") //fails at 18 & idk why
    {
        created = rooms[roomID].addNode(roomID, BASE_ROOM_WEIGHT, roomDescription);
    }
    if(created)
    {
        countRooms++;
        if(roomID > largestID)
        {
            largestID = roomID;
        }
    }

    return created;
}


/*
    The following method allows modification of the representation of a node's connection
    to another.
*/
bool RoomsGraph::changeHall(int roomStart, int roomEnd, Data* newValues)
{
    bool modified = false;

    if(roomStart > 0 && rooms[roomStart].headAlive())
    {
        modified = rooms[roomStart].changeNodeContent(roomEnd, newValues);
    }

    return modified;
}


/*
    The following method destroys room present at roomID position
*/
bool RoomsGraph::destroyRoom(int roomID)
{
    bool removed = false;

    if(roomID > 0 && rooms[roomID] && roomID < rooms.size())
    {
        removed = rooms[roomID].clear();

        if(removed)
        {
            countRooms--;
        }
    }

    return removed;
}


/*
    method to return node contents
*/
bool RoomsGraph::getRoomContents(int roomID, Data* returnContents)
{
    bool found = false;

    if(roomID > 0 && rooms[roomID].headAlive())
    {
        found = rooms[roomID].getNode(roomID, returnContents);
    }

    return found;
}


/*
    method to build a connection between 2 other nodes,
    or effectively build the representation of an edge between 2 graph points
*/
bool RoomsGraph::buildHallBetweenRooms(int tarRoomID, int destRoomID, int weight, string* details)
{
    bool built = false;

    //when a vector recieves an ID out of bounds, it doesn't resize or error, it tries to keep going
    //must check that value passed is less than the current largest value vector would use as ID!
    if(tarRoomID < largestID && tarRoomID > 0 && destRoomID > 0)
    {
        built = true;
    }

    if(built && rooms[tarRoomID].headAlive())
    {
        built = rooms[tarRoomID].addNode(destRoomID, weight, details);

        if(built)
        {
            countHalls++;
        }
    }
    else
    {
        built = false;
    }

    return built;
}


/*
    destroys edge between nodes
*/
bool RoomsGraph::destroyHallBetweenRooms(int startID, int destinationID)
{
    bool removed = false;

    if(startID > 0)
    {
        removed = rooms[startID].deleteNode(destinationID);

        if(removed)
        {
            countHalls--;
        }
    }

    return removed;
}


/*
    checks if edge exists
*/
bool RoomsGraph::hallExistsBetween(int startID, int endID)
{
    bool exists = false;

    if(startID > 0 && endID > 0 && rooms[startID] && rooms[endID])
    {
        exists = rooms[startID].exists(endID);
    }

    return exists;
}


/*
    checks if room node exists
*/
bool RoomsGraph::roomExists(int roomID)
{
    bool exists = false;

    if(rooms[roomID].headAlive())
    {
        exists = true;
    }

    return exists;
}


/*
    returns count of halls AKA edges
*/
int RoomsGraph::getHallCount()
{
    return countHalls;
}


/*
    returns count of rooms/nodes
*/
int RoomsGraph::getRoomCount()
{
    return countRooms;
}


/*
    provides if empty
*/
bool RoomsGraph::isEmpty()
{
    return (countHalls + countRooms) == 0;
}
