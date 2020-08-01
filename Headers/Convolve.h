#ifndef CONVOLVE_H_INCLUDED
#define CONVOLVE_H_INCLUDED

using namespace std;

class Convolve{
    public:
    int level;

    //Blurring the image by using a 5x5 "Gaussian" matrix (aka. kernel).
    void blur(string& image_name, int& row, int& column, int& max_intensity, vector <vector<int> >& vect);

    //Edge detection by using Sobel-algorithm.
    void edge(string& image_name, int& row, int& column, int& max_intensity, vector <vector<int> >& vect);

    //Sharpening the image by using contrast enhancement on the "lines" given by Edge detection.
    void sharpen(string& image_name, int& row, int& column, int& max_intensity, vector <vector<int> >& vect);

};

#endif // CONVOLVE_H_INCLUDED
