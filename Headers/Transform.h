#ifndef TRANSFORM_H_INCLUDED
#define TRANSFORM_H_INCLUDED
#include "Read_in.h"

using namespace std;

class Transform{
public:
    vector <vector<int> > image_copyvector;

    Transform(Image& image);

    void rotation(Image& image);

    void mirroring(Image& image);

    void rotate_by_90(Image& image);

    void rotate_by_180(Image& image);

    void rotate_by_270(Image& image);

    void mirror_to_x_axis(Image& image);

    void mirror_to_y_axis(Image& image);

};

#endif // TRANSFORM_H_INCLUDED
