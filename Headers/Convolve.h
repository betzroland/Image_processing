#ifndef CONVOLVE_H_INCLUDED
#define CONVOLVE_H_INCLUDED
#include "Read_in.h"
#include <vector>

using namespace std;

class Convolve{
    public:
    vector <vector<int> > image_copyvector;

    const float Edge_x[3][3]=   {                    // Sobel-operator1, convoluted form.
                                {-1.0, 0.0, 1.0},
                                {-2.0, 0.0, 2.0},
                                {-1.0, 0.0, 1.0}
                                };

    const float Edge_y[3][3]=   {                    // Sobel-operator2, convoluted form.
                                {1.0, 2.0, 1.0},
                                {0.0, 0.0, 0.0},
                                {-1.0, -2.0, -1.0}
                                };

    const float d=49.0;
    const float Gaussian[5][5]= {
                                {1/d, 1.5/d, 2/d, 1.5/d, 1/d},
                                {1.5/d, 2.25/d, 3/d, 2.25/d, 1.5/d},
                                {2/d, 3/d, 4/d, 3/d, 2/d},
                                {1.5/d, 2.25/d, 3/d, 2.25/d, 1.5/d},
                                {1/d, 1.5/d, 2/d, 1.5/d, 1/d}
                                };

    Convolve(Image& image);

    void blur(Image& image);

    void edge(Image& image);

    void sharpen(Image& image);

    int apply_Gaussian_on_pixel(const int i, const int j);

    int apply_Sobel_on_pixel(const int i, const int j);

    void normalize_pixelvalues(Image& image, float G_max);

    void sharpen_along_edges(Image& image, vector <vector<int> >& vect_edged);

    void darken_neighbourpixels(Image& image, const int i, const int j);

};

#endif // CONVOLVE_H_INCLUDED
