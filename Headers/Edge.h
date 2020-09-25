#ifndef EDGE_H_INCLUDED
#define EDGE_H_INCLUDED
#include "Base.h"

class Edge : public Base{
private:
    std::vector<std::vector<int> > image_copyvector;

    const double Edge_x[3][3]=   {                    // Sobel-operator1, convoluted form.
                                {-1.0, 0.0, 1.0},
                                {-2.0, 0.0, 2.0},
                                {-1.0, 0.0, 1.0}
                                };

    const double Edge_y[3][3]=   {                    // Sobel-operator2, convoluted form.
                                {1.0, 2.0, 1.0},
                                {0.0, 0.0, 0.0},
                                {-1.0, -2.0, -1.0}
                                };
public:
    Edge(std::string name);

    void operation();

    int apply_Sobel_on_pixel(const int i, const int j);

    void normalize_pixelvalues(double G_max);
};


#endif // EDGE_H_INCLUDED
