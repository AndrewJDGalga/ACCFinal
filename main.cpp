/*
 * NAME: Andrew J
 * COSC 2436
 * PURPOSE:
 *    GRAPH ATTEMPT
 *      tests
 */


#include "main.h"

int main()
{
    RoomsGraph graph;
    Data trashData = {-1,-1,""};
    Data testData = {2,2,"2"};
    int twoMod = 2;
    int eighteenMod = 18;
    int mass = 200;
    string testStr = "thing";

    cout << "\n\nEMPTY TESTS\n"
        << "-------------------------------------\n";
    cout << "is empty? " << graph.isEmpty() << endl;
    cout << "room exists? " << graph.roomExists(INI_ROOM_SIZE) << endl;

    
    cout << "destroy room? " << graph.destroyRoom(INI_ROOM_SIZE) << endl;
    cout << "build hall? " 
        << graph.buildHallBetweenRooms(eighteenMod, twoMod, BASE_ROOM_WEIGHT, &testStr) 
        << endl;
    cout << "destroy hall? " 
        << graph.destroyHallBetweenRooms(eighteenMod, twoMod) << endl;
    cout << "change hall? " << graph.changeHall(eighteenMod,twoMod,&testData) << endl;
    cout << "hall exists? " << graph.hallExistsBetween(twoMod, eighteenMod) << endl;
    cout << "count rooms: " << graph.getRoomCount() << " & count halls: " << graph.getHallCount() << endl;
    cout << "trying to get contents: " << graph.getRoomContents(twoMod, &trashData) << endl;
    cout << "got: " << trashData.id << " : " << trashData.weight << " : " << trashData.data << endl;


    cout << "\n\nTWO ROOMS TESTS\n"
        << "-------------------------------------\n";
    cout << "building: " << graph.buildRoom(twoMod, &testStr) << endl;
    cout << "building: " << graph.buildRoom(-twoMod, &testStr) << endl;
    cout << "building: " << graph.buildRoom(twoMod, &trashData.data) << endl;
    cout << "building: " << graph.buildRoom(eighteenMod, &testStr) << endl;
    cout << "is empty? " << graph.isEmpty() << endl;
    cout << "room exists? " << graph.roomExists(twoMod) << endl;
    cout << "build hall? " 
        << graph.buildHallBetweenRooms(eighteenMod, twoMod, BASE_ROOM_WEIGHT, &testStr) 
        << endl;

    
    cout << "build hall? " 
        << graph.buildHallBetweenRooms(eighteenMod, -twoMod, BASE_ROOM_WEIGHT, &testStr) 
        << endl;
    cout << "change hall? " << graph.changeHall(eighteenMod,twoMod,&testData) << endl;
    cout << "change hall? " << graph.changeHall(eighteenMod,-twoMod,&testData) << endl;
    cout << "hall exists? " << graph.hallExistsBetween(eighteenMod, twoMod) << endl;
    
    cout << "count rooms: " << graph.getRoomCount() << " & count halls: " << graph.getHallCount() << endl;
    cout << "trying to get contents: " << graph.getRoomContents(twoMod, &trashData) << endl;  //TODO: FIX THIS
    cout << "got: " << trashData.id << " : " << trashData.weight << " : " << trashData.data << endl;
    
    cout << "destroy hall? " 
        << graph.destroyHallBetweenRooms(eighteenMod, twoMod) << endl;
    cout << "destroy room? " << graph.destroyRoom(twoMod) << endl;
    cout << "destroy hall? " 
        << graph.destroyHallBetweenRooms(eighteenMod, twoMod) << endl;
    cout << "destroy room? " << graph.destroyRoom(twoMod) << endl;
    


    cout << "\n\nMASS IN MASS OUT TEST\n"
        << "-------------------------------------\n";

    for(int i = 0; i < mass; i++)  //fails this test because of size, and when I attempt to resize destroying crashes
    {
        testStr = to_string(i);
        cout << "building: " << graph.buildRoom(i, &testStr) << endl;
    }
 
    for(int i = 0; i < mass; i++) //fails here unless I manually set the max size because I cannot get resize to work
    {
        cout << "destroying: " << graph.destroyRoom(i) << endl;
    }

    cout << "\n\nRANDOM TESTS\n"
        << "-------------------------------------\n";
    cout << "project failed to pass earlier tests, and is not dynamic. Failure.\n";


    return 0;
}
