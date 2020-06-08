#ifndef ROUTE_H
#define ROUTE_H
#include "Flight.h"
#include "Airport.h"
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <iostream>
using namespace std;

class Route{

    int total;
    list<Airport*> Airports; // Pointer to an array containing adjacency lists    
    void DFS(int v, bool visited[]);
    
    public:
        void determineShortestPath(Airport* src, Airport* dest);
        void addFlight(Flight* flight);
        void DFS(Airport* src);
        Route(int totalAirports){
            total = totalAirports;
        };
            

};
void Route::addFlight(Flight* flight){
    Airports.push_front(flight->dest);
    Airports.push_back(flight->src);
    cout<< "worked" << endl;
}

void Route::determineShortestPath(Airport* src, Airport* des)
{
    int start = src->id;
    int dest = des->id;
    // Create a priority queue to store vertices that are being preprocessed.
    priority_queue<pair<int, int>, vector<pair<int, int>>> pq;

    // Create a vector to hold the weights (default to infinity/large number)
    vector<int> distance(total, 10000);

    // Insert source itself in priority queue and initialize its distance as 0.
    pq.push(make_pair(start, 0));
    distance[start] = 0; // Set start to 0

    //Looping till priority queue becomes empty (or all  distances are not finalized)
    while (!pq.empty())
    {
        // The first vertex in pair is the minimum distance vertex, extract it from priority queue.
        // vertex label is stored in second of pair (it has to be done this way to keep the vertices
        // sorted distance (distance must be first item in pair)
        pair<int, int> v = pq.top();
        pq.pop();

        if (v.first == dest)
        {
            cout << distance[v.first] << endl; // Out prints the weight
            break;
        }
        // 'i' is used to get all adjacent vertices of a vertex
        list<int>::iterator i;
        for (i = Airports[v.first].begin(); i != adjLists[v.first].end(); ++i)
        {
            if(distance[*i] > (distance[v.first]+1)) {
                distance[*i] =  distance[v.first]+1;
                pq.push(make_pair(*i, v.second + 1));
            }
        }
    }
}

#endif



/*
void Route::DFS(Airport* src)
{   
    visited[v] = true;    
    cout << v << " ";    
    list<int>::iterator i;    
    for (i = adjLists[v].begin(); i != adjLists[v].end(); ++i)   
    {       
        if (!visited[*i])       
        {           
            DFS(*i, visited);       
        }    
    }
}
*/
/*
Flight
void Flight::setArrivingAirport(Airport * airport) {
	this->destination = airport;
}
Airport
void Airport::addArrivingFlight(Flight * arrival) {
	arrival->setArrivingAirport(this);
	arrivals.push_back(arrival);
};
*/