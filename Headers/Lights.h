#ifndef LIGHTS_H_INCLUDED
#define LIGHTS_H_INCLUDED
#include "Read_in.h"

using namespace std;

class Lights{
public:
    int percent;

    //Reduces the values of each pixels by the percent given by the user.
    void darken(Read_in& read);

    //Increases the values of each pixels by the percent given by the user.
    void brighten(Read_in& read);

    //Inverting each pixels: light->dark and dark->light
    void invert(Read_in& read);

    //Increases the difference between the lighter and darker parts of the image.
    void contrast(Read_in& read);

};

#endif // LIGHTS_H_INCLUDED
