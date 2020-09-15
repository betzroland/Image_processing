#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>
#include "Lights.h"
#include "Output.h"

using namespace std;

void Lights::darken(Read_in& read){
    cout << "By how many percent? (1-99)" << endl;
    cin >> percent;
    if(typeid(percent).name()!=typeid(1).name() || percent<1 || percent>99){
        throw std::domain_error("Wrong parameter!");
    }
    for(int i=0; i<read.row; i++){
        for(int j=0; j<read.column; j++){
            read.vect[i][j]=read.vect[i][j]*(1-(percent/100.0));
        }
    }
    read.image_name=read.image_name+"_darkened_"+to_string(percent)+"%.pgm";
}

void Lights::brighten(Read_in& read){
    cout << "By how many percent? (1-99)" << endl;
    cin >> percent;
    if(typeid(percent).name()!=typeid(1).name() || percent<1 || percent>99){
        throw std::domain_error("Wrong parameter!");
    }
    for(int i=0; i<read.row; i++){
        for(int j=0; j<read.column; j++){
            if(read.vect[i][j]+(percent/100.0)*read.vect[i][j]<read.max_intensity){
                read.vect[i][j]=read.vect[i][j]*(1+(percent/100.0));
            }
            else read.vect[i][j]=read.max_intensity;
        }
    }
    read.image_name=read.image_name+"_brightened_"+to_string(percent)+"%.pgm";
}

void Lights::invert(Read_in& read){
    for(int i=0; i<read.row; i++){
        for(int j=0; j<read.column; j++){
            read.vect[i][j]=read.max_intensity-read.vect[i][j];
        }
    }
    read.image_name=read.image_name+"_inverted.pgm";
}

void Lights::contrast(Read_in& read){
    cout << "How many percent of contrast enhancement do you want? (1-20)" << endl;
    cin >> percent;
    if(typeid(percent).name()!=typeid(1).name() || percent<1 || percent>99){
        throw std::domain_error("Wrong parameter!");
    }
    for(int i=0; i<read.row; i++){
        for(int j=0; j<read.column; j++){
            if(read.vect[i][j]<(read.max_intensity/2.0)){
                read.vect[i][j]=read.vect[i][j]*(1-(percent/100.0));
            }
            if(read.vect[i][j]>(read.max_intensity/2.0) && (read.vect[i][j]+read.vect[i][j]*(percent/100.0))<read.max_intensity){
                read.vect[i][j]=read.vect[i][j]*(1+(percent/100.0));
            }
            if(read.vect[i][j]>(read.max_intensity/2.0) && (read.vect[i][j]+read.vect[i][j]*(percent/100.0))>read.max_intensity){
                read.vect[i][j]=read.max_intensity;
            }
        }
    }
    read.image_name=read.image_name+"_contrast_+"+to_string(percent)+"%.pgm";
}
