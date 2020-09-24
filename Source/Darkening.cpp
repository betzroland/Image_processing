#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>
#include "Darkening.h"

using namespace std;

Darkening::Darkening(string name){
    image_name=name;
}

void Darkening::operation(){

    int percent;
    cout << "By how many percent? (1-99)" << endl;
    cin >> percent;
    if(typeid(percent).name()!=typeid(1).name() || percent<1 || percent>99){
        throw std::domain_error("Wrong parameter!");
    }
    for(int i=0; i<row; i++){
        for(int j=0; j<column; j++){
            vect[i][j]=vect[i][j]*(1-(percent/100.0));
        }
    }
    image_name=image_name+"_darkened_"+to_string(percent)+"%.pgm";
}
