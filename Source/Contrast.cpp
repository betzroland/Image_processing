#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>
#include "Contrast.h"

using namespace std;

Contrast::Contrast(string name){
    image_name=name;
}

void Contrast::operation(){
    int percent;
    cout << "How many percent of contrast enhancement do you want? (1-20)" << endl;
    cin >> percent;
    if(typeid(percent).name()!=typeid(1).name() || percent<1 || percent>99){
        throw std::domain_error("Wrong parameter!");
    }
    for(int i=0; i<row; i++){
        for(int j=0; j<column; j++){
            if(vect[i][j]<(max_intensity/2.0)){
                vect[i][j]=vect[i][j]*(1-(percent/100.0));
            }
            else if(vect[i][j]>(max_intensity/2.0) && (vect[i][j]*(1+(percent/100.0)))<max_intensity){
                vect[i][j]=vect[i][j]*(1+(percent/100.0));
            }
            else{
                vect[i][j]=max_intensity;
            }
        }
    }
    image_name=image_name+"_contrast_+"+to_string(percent)+"%.pgm";
}
