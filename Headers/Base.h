#ifndef BASE_H_INCLUDED
#define BASE_H_INCLUDED
#include <vector>
#include <string>

class Base{
protected:
    int column, row, max_intensity;
    std::string image_name;
    std::vector <std::vector<int> > vect;

public:
    Base(std::string name);

    virtual ~Base() { };

    virtual void operation()=0;

    void save();
};

#endif // BASE_H_INCLUDED
