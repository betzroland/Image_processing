#ifndef ROTATION_H_INCLUDED
#define ROTATION_H_INCLUDED
#include <vector>
#include "ImageProcessor.h"

class Rotation : public ImageProcessor{
private:
    std::vector<std::vector<int> > pixel_copyvector;
public:
    Rotation(std::string name);

    ~Rotation() { };

    void process_image();

    void rotate_by_90();
    void rotate_by_180();
    void rotate_by_270();
};


#endif // ROTATION_H_INCLUDED
