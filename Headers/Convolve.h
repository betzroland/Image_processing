#ifndef CONVOLVE_H_INCLUDED
#define CONVOLVE_H_INCLUDED

using namespace std;

class Convolve{
    public:
    int level;

    //Blurring the image by using a 5x5 "Gaussian" matrix (aka. kernel).
    void blur(const string image_name, const int row, const int column, const int max_intensity, vector <vector<int> >& vect);

    //Edge detection by using Sobel-algorithm.
    void edge(const string image_name, const int row, const int column, const int max_intensity, vector <vector<int> >& vect);

    //Sharpening the image by using contrast enhancement on the "lines" given by Edge detection.
    void sharpen(const string image_name, const int row, const int column, const int max_intensity, vector <vector<int> >& vect);

};

#endif // CONVOLVE_H_INCLUDED
