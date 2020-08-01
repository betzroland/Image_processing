#ifndef LIGHTS_H_INCLUDED
#define LIGHTS_H_INCLUDED

using namespace std;

class Lights{
public:
    int percent;

    //Reduces the values of each pixels by the percent given by the user.
    void darken(string& image_name, int& row, int& column, int& max_intensity, vector <vector<int> >& vect);

    //Increases the values of each pixels by the percent given by the user.
    void brighten(string& image_name, int& row, int& column, int& max_intensity, vector <vector<int> >& vect);

    //Inverting each pixels: light->dark and dark->light
    void invert(string& image_name, int& row, int& column, int& max_intensity, vector <vector<int> >& vect);

    //Increases the difference between the lighter and darker parts of the image.
    void contrast(string& image_name, int& row, int& column, int& max_intensity, vector <vector<int> >& vect);

};

#endif // LIGHTS_H_INCLUDED
