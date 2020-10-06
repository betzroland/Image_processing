#ifndef INVERSION_H_INCLUDED
#define INVERSION_H_INCLUDED
#include "ImageProcessor.h"

class Inversion : public ImageProcessor{
public:
    Inversion(std::string name);

    ~Inversion() { };

    void process_image();
};

#endif // INVERSION_H_INCLUDED
