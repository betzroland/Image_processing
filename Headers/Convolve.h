#ifndef CONVOLVE_H_INCLUDED
#define CONVOLVE_H_INCLUDED
#include "Read_in.h"

using namespace std;

class Convolve{
    public:
    int level;

    //Blurring the image by using a 5x5 "Gaussian" matrix (aka. kernel).
    void blur(Read_in& read);

    //Edge detection by using Sobel-algorithm.
    void edge(Read_in& read);

    //Sharpening the image by using contrast enhancement on the "lines" given by Edge detection.
    void sharpen(Read_in& read);

};

#endif // CONVOLVE_H_INCLUDED
