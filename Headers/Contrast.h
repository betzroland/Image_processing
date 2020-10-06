#ifndef CONTRAST_H_INCLUDED
#define CONTRAST_H_INCLUDED
#include "ImageProcessor.h"

class Contrast : public ImageProcessor{
public:
    Contrast(std::string name);

    ~Contrast() { };

    void process_image();
};

#endif // CONTRAST_H_INCLUDED
