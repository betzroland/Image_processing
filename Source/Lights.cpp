#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>
#include "Lights.h"
#include "Output.h"

using namespace std;

void Lights::darken(Image& image){
    cout << "By how many percent? (1-99)" << endl;
    cin >> percent;
    if(typeid(percent).name()!=typeid(1).name() || percent<1 || percent>99){
        throw std::domain_error("Wrong parameter!");
    }
    for(int i=0; i<image.row; i++){
        for(int j=0; j<image.column; j++){
            image.vect[i][j]=image.vect[i][j]*(1-(percent/100.0));
        }
    }
    image.image_name=image.image_name+"_darkened_"+to_string(percent)+"%.pgm";
}

void Lights::brighten(Image& image){
    cout << "By how many percent? (1-99)" << endl;
    cin >> percent;
    if(typeid(percent).name()!=typeid(1).name() || percent<1 || percent>99){
        throw std::domain_error("Wrong parameter!");
    }
    for(int i=0; i<image.row; i++){
        for(int j=0; j<image.column; j++){
            if(image.vect[i][j]+(percent/100.0)*image.vect[i][j]<image.max_intensity){
                image.vect[i][j]=image.vect[i][j]*(1+(percent/100.0));
            }
            else image.vect[i][j]=image.max_intensity;
        }
    }
    image.image_name=image.image_name+"_brightened_"+to_string(percent)+"%.pgm";
}

void Lights::invert(Image& image){
    for(int i=0; i<image.row; i++){
        for(int j=0; j<image.column; j++){
            image.vect[i][j]=image.max_intensity-image.vect[i][j];
        }
    }
    image.image_name=image.image_name+"_inverted.pgm";
}

void Lights::contrast(Image& image){
    cout << "How many percent of contrast enhancement do you want? (1-20)" << endl;
    cin >> percent;
    if(typeid(percent).name()!=typeid(1).name() || percent<1 || percent>99){
        throw std::domain_error("Wrong parameter!");
    }
    for(int i=0; i<image.row; i++){
        for(int j=0; j<image.column; j++){
            if(image.vect[i][j]<(image.max_intensity/2.0)){
                image.vect[i][j]=image.vect[i][j]*(1-(percent/100.0));
            }
            if(image.vect[i][j]>(image.max_intensity/2.0) && (image.vect[i][j]+image.vect[i][j]*(percent/100.0))<image.max_intensity){
                image.vect[i][j]=image.vect[i][j]*(1+(percent/100.0));
            }
            if(image.vect[i][j]>(image.max_intensity/2.0) && (image.vect[i][j]+image.vect[i][j]*(percent/100.0))>image.max_intensity){
                image.vect[i][j]=image.max_intensity;
            }
        }
    }
    image.image_name=image.image_name+"_contrast_+"+to_string(percent)+"%.pgm";
}
