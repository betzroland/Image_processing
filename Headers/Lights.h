#ifndef LIGHTS_H_INCLUDED
#define LIGHTS_H_INCLUDED
#include "Read_in.h"

using namespace std;

class Lights{
public:
    int percent;

    //Reduces the values of each pixels by the percent given by the user.
    void darken(Image& image);

    //Increases the values of each pixels by the percent given by the user.
    void brighten(Image& image);

    //Inverting each pixels: light->dark and dark->light
    void invert(Image& image);

    //Increases the difference between the lighter and darker parts of the image.
    void contrast(Image& image);

};

#endif // LIGHTS_H_INCLUDED
