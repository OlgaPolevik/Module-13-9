//
//  Connections.h
//  Module13-9
//
//  Created by Ольга Полевик on 01.09.2021.
//

#ifndef Connections_h
#define Connections_h

#include <string>

#define SIZE 10
using namespace std;

class Connections {
    public:
        Connections();
        // добавление вершины
        void addPeople(string name);
        // добавление ребра
        void addMeet(int p1, int p2);
        int findMinWayDFS(int from, int to);
        void inner(int current,int to, bool visited[], int& minDistance, int currentDistance);
        int getPeopleCount() const;
        string getPeopleName(int index) const;
    private:
        bool meetExists(int p1, int p2);
        int matrix[SIZE][SIZE]; // матрица смежности
        
        struct People
        {
            string name;
        };
    
        People peoples[SIZE]; // хранилище вершин
   
        int peopleCount; // количество добавленных вершин        
};

#endif /* Connections_h */
