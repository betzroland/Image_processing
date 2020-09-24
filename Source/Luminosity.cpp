#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>
#include "Luminosity.h"

using namespace std;

Luminosity::Luminosity(string name){
    image_name=name;
}

void Luminosity::operation(){

    int percent;
    cout << "By how many percent? (-99 -> 99)" << endl;
    cin >> percent;

    /*if(typeid(percent).name()!=typeid(1).name() || percent<1 || percent>99){
        throw std::domain_error("Wrong parameter!");
    }*/

    for(int i=0; i<row; i++){
        for(int j=0; j<column; j++){
            if(vect[i][j]+(percent/100.0)*vect[i][j]<max_intensity){
                vect[i][j]=vect[i][j]*(1+(percent/100.0));
            }
            else vect[i][j]=max_intensity;
        }
    }
    image_name=image_name+"_luminosity_changed_by_"+to_string(percent)+"%.pgm";
}
