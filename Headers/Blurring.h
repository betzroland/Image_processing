#ifndef BLURRING_H_INCLUDED
#define BLURRING_H_INCLUDED
#include "Base.h"

class Blurring : public Base{
private:
    std::vector<std::vector<int> > image_copyvector;
    const double d=49.0;
    const double Gaussian[5][5]= {
                                {1/d, 1.5/d, 2/d, 1.5/d, 1/d},
                                {1.5/d, 2.25/d, 3/d, 2.25/d, 1.5/d},
                                {2/d, 3/d, 4/d, 3/d, 2/d},
                                {1.5/d, 2.25/d, 3/d, 2.25/d, 1.5/d},
                                {1/d, 1.5/d, 2/d, 1.5/d, 1/d}
                                };

public:
    Blurring(std::string name);

    ~Blurring() { };

    void operation();

    int apply_Gaussian_on_pixel(const int i, const int j);
};

#endif // BLURRING_H_INCLUDED
