#ifndef FLIGHT_H
#define FLIGHT_H
#include "Airport.h"
#include <string>

using namespace std;

struct Flight {


		Airport *src;
		Airport *dest;
        int minutes;
        double cost;
        double distance;
    public:
        Flight(Airport *s, Airport *d, int m, double c, double dis){
            src = s;
            dest = d;
            minutes = m;
            cost = c;
            distance = dis;
        }


};

#endif