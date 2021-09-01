//
//  Connections.cpp
//  Module13-9
//
//  Created by Ольга Полевик on 01.09.2021.
//

#include <stdio.h>
#include "Connections.h"
#define VERYBIGINT 1000000000

Connections::Connections()
{
    for(int i = 0;i < SIZE; i++)
    {
        for(int j = 0; j < SIZE; j++)
        {
            matrix[i][j] = 0;
        }
    }
    peopleCount = 0;
}
// добавление вершины
void Connections::addPeople(string name)
{
    peoples[peopleCount].name = name;
    peopleCount++;
}
// добавление ребра
void Connections::addMeet(int p1, int p2)
{
    matrix[p1][p2] = 1;
    matrix[p2][p1] = 1;
}
// проверка существования ребра
bool Connections::meetExists(int p1, int p2)
{
    return matrix[p1][p2] > 0;
}

int Connections::getPeopleCount() const
{
    return peopleCount;
}

string Connections::getPeopleName(int index) const
{
    return peoples[index].name;
}

int Connections::findMinWayDFS(int from, int to)
{
    bool visited[SIZE]; // список посещенных вершин
    
    for(int i = 0; i < SIZE; i++)
    {
        visited[i] = false;
    }
        
    int minDistance = VERYBIGINT;
 
    int currentDistance = 0;
 
    inner(from, to, visited, minDistance, currentDistance);
 
    return minDistance;
}

void Connections::inner(int current,int to, bool visited[], int& minDistance, int currentDistance)
{
       if(current == to)
       {
          // если попали в целевую вершину, сравниваем текущий путь с минимальным
          if(minDistance > currentDistance)
          {
              // если новое расстояние меньше, запоминаем
              minDistance = currentDistance;
              return;
          }
       }
       visited[current] = true; // обозначем вершину посещенной
       for(int i = 0; i < SIZE; i++)
       {
           if(meetExists(current, i) && !visited[i])
           {
               // запускаем рекурсию для всех непосещенных смежных вершин
               int newDist = currentDistance + matrix[current][i];
               inner(i, to, visited, minDistance, newDist);
           }
       }
       // отмечаем, что путь уже не содержит эту вершину
       visited[current] = false;
   }
