#ifndef LIGHTS_H_INCLUDED
#define LIGHTS_H_INCLUDED
#include "Read_in.h"

using namespace std;

class Lights{
public:
    int percent;

    void darken(Image& image);

    void brighten(Image& image);

    void invert(Image& image);

    void contrast(Image& image);

};

#endif // LIGHTS_H_INCLUDED
