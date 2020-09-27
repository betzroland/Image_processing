#ifndef CONTRAST_H_INCLUDED
#define CONTRAST_H_INCLUDED
#include "Base.h"

class Contrast : public Base{
public:
    Contrast(std::string name);

    ~Contrast() { };

    void operation();
};

#endif // CONTRAST_H_INCLUDED
