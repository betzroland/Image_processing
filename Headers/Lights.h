#ifndef LIGHTS_H_INCLUDED
#define LIGHTS_H_INCLUDED

using namespace std;

class Lights{
public:
    int percent;

    //Reduces the values of each pixels by the percent given by the user.
    void darken(const string image_name, const int row, const int column, const int max_intensity, vector <vector<int> >& vect);

    //Increases the values of each pixels by the percent given by the user.
    void brighten(const string image_name, const int row, const int column, const int max_intensity, vector <vector<int> >& vect);

    //Inverting each pixels: light->dark and dark->light
    void invert(const string image_name, const int row, const int column, const int max_intensity, vector <vector<int> >& vect);

    //Increases the difference between the lighter and darker parts of the image.
    void contrast(const string image_name, const int row, const int column, const int max_intensity, vector <vector<int> >& vect);

};

#endif // LIGHTS_H_INCLUDED
