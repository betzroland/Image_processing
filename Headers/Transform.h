#ifndef TRANSFORM_H_INCLUDED
#define TRANSFORM_H_INCLUDED
#include "Read_in.h"

using namespace std;

class Transform{
public:
    int angle;
    string axis;

    //Rotates the image by 90, 180, or 270 degrees.
    void rotation(Read_in& read);

    //Mirrors the image to x or y axis.
    void mirroring(Read_in& read);

};

#endif // TRANSFORM_H_INCLUDED
