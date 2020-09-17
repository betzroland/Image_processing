#ifndef CONVOLVE_H_INCLUDED
#define CONVOLVE_H_INCLUDED
#include "Read_in.h"
#include <vector>

using namespace std;

class Convolve{
    public:
    vector <vector<int> > image_copyvector;

    const float Edge_x[3][3]=    {                    // Sobel-operator1, convoluted form.
                            {-1.0, 0.0, 1.0},
                            {-2.0, 0.0, 2.0},
                            {-1.0, 0.0, 1.0}
                            };

    const float Edge_y[3][3]=    {                    // Sobel-operator2, convoluted form.
                            {1.0, 2.0, 1.0},
                            {0.0, 0.0, 0.0},
                            {-1.0, -2.0, -1.0}
                            };

    const float d=49.0;
    const float Gaussian[5][5]=  {
                            {1/d, 1.5/d, 2/d, 1.5/d, 1/d},
                            {1.5/d, 2.25/d, 3/d, 2.25/d, 1.5/d},
                            {2/d, 3/d, 4/d, 3/d, 2/d},
                            {1.5/d, 2.25/d, 3/d, 2.25/d, 1.5/d},
                            {1/d, 1.5/d, 2/d, 1.5/d, 1/d}
                            };

    Convolve(Image& image);

    //Blurring the image by using a 5x5 "Gaussian" matrix (aka. kernel).
    void blur(Image& image);

    //Edge detection by using Sobel-algorithm.
    void edge(Image& image);

    //Sharpening the image by using contrast enhancement on the "lines" given by Edge detection.
    void sharpen(Image& image);

    int apply_Gaussian_on_pixel(const int i, const int j);

    int apply_Sobel_on_pixel(const int i, const int j);

    void normalize_pixelvalues(Image& image, float G_max);

};

#endif // CONVOLVE_H_INCLUDED
