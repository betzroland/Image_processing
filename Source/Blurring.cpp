#include <iostream>
#include <vector>
#include "Blurring.h"

using namespace std;

Blurring::Blurring(string name) : ImageProcessor(name){
    pixel_copyvector=pixel_vector;
}

void Blurring::process_image(){

    for(int i=2; i<row-2; i++){
        for(int j=2; j<column-2; j++){
            pixel_vector[i][j]=Blurring::apply_Gaussian_on_pixel(i, j);
        }
    }
    image_name=image_name+"_blurred.pgm";
}

int Blurring::apply_Gaussian_on_pixel(const int i, const int j){
    double new_pixelvalue=0;
    for(int k=0; k<5; k++){
        for(int m=0; m<5; m++){
            new_pixelvalue=new_pixelvalue+pixel_copyvector[i+k-2][j+m-2]*Gaussian[k][m];
        }
    }
return (int)new_pixelvalue;
}
