#ifndef LUMINOSITY_H_INCLUDED
#define LUMINOSITY_H_INCLUDED
#include "Base.h"

class Luminosity : public Base{
public:
    Luminosity(std::string name);

    ~Luminosity() { };

    void operation();
};


#endif // LUMINOSITY_H_INCLUDED
