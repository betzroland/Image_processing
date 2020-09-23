#include <iostream>
#include "Base.h"
#include "Darkening.h"
#include "Rotation.h"

using namespace std;

int main()
{
    /*Darkening darkened;
    darkened.load();
    darkened.operation();
    darkened.save();*/

    Rotation rotated;
    //rotated.load();
    rotated.operation();
    rotated.save();
    return 0;
}
