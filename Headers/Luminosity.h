#ifndef LUMINOSITY_H_INCLUDED
#define LUMINOSITY_H_INCLUDED
#include "ImageProcessor.h"

class Luminosity : public ImageProcessor{
public:
    Luminosity(std::string name);

    ~Luminosity() { };

    void process_image();
};


#endif // LUMINOSITY_H_INCLUDED
