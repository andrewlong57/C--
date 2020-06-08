#ifndef AIRPORT_H
#define AIRPORT_H

#include <string>
using namespace std;

struct Airport
{   


        int id;
        string airportName;
        int minutes;
        double cost;
        double distance;
    public:
        Airport(){
            id = -1;
            airportName = "UNK";
        };
        Airport(int i, string name){
            id = i;
            airportName = name;
        };
    
};

#endif