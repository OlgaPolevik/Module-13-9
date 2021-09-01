//
//  main.cpp
//  Module13-9
//
//  Created by Ольга Полевик on 01.09.2021.
//

#include <iostream>
#include "Connections.h"

using namespace std;

int main(int argc, const char * argv[])
{
    Connections c;
       
       // добавляем вершины
    c.addPeople("name0");
    c.addPeople("name1");
    c.addPeople("name2");
    c.addPeople("name3");
    c.addPeople("name4");
    c.addPeople("name5");
    c.addPeople("name6");
    c.addPeople("name7");
    c.addPeople("name8");
    c.addPeople("name9");


       // добавляем ребра
    c.addMeet(0, 1);
    c.addMeet(1, 2);
    c.addMeet(2, 3);
    c.addMeet(3, 4);
    c.addMeet(4, 5);
    c.addMeet(5, 6);
    c.addMeet(6, 7);
    c.addMeet(7, 8);
    c.addMeet(8, 9);
    
    for(int i = 0; i < c.getPeopleCount() - 1; i++)
    {
        for(int j = i + 1; j < c.getPeopleCount(); j++)
        {
            int distance = c.findMinWayDFS(i, j);
            if(distance == 3)
            {
                cout << c.getPeopleName(i) << " дружит c " << c.getPeopleName(j) << endl;
            }
        }
    }
    
    return 0;
}
