#ifndef ROTATION_H_INCLUDED
#define ROTATION_H_INCLUDED
#include <vector>
#include "Base.h"

class Rotation : public Base{
private:
    std::vector<std::vector<int> > image_copyvector;
public:
    Rotation(std::string name);

    void operation();

    void rotate_by_90();
    void rotate_by_180();
    void rotate_by_270();
};


#endif // ROTATION_H_INCLUDED
