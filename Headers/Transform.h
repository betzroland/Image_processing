#ifndef TRANSFORM_H_INCLUDED
#define TRANSFORM_H_INCLUDED

using namespace std;

class Transform{
public:
    int angle;
    string axis;

    //Rotates the image by 90, 180, or 270 degrees.
    void rotation(const string image_name, const int row, const int column, const int max_intensity, vector <vector<int> >& vect);

    //Mirrors the image to x or y axis.
    void mirroring(const string image_name, const int row, const int column, const int max_intensity, vector <vector<int> >& vect);

};

#endif // TRANSFORM_H_INCLUDED
