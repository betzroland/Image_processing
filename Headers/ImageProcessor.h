#ifndef IMAGEPROCESSOR_H_INCLUDED
#define IMAGEPROCESSOR_H_INCLUDED
#include <vector>
#include <string>

class ImageProcessor{
protected:
    int column, row, max_intensity;
    std::string image_name;
    std::vector <std::vector<int> > pixel_vector;

public:
    ImageProcessor(std::string name);

    virtual ~ImageProcessor() { };

    virtual void process_image()=0;

    void save_image();
};


#endif // IMAGEPROCESSOR_H_INCLUDED
