#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include "Convolve.h"

using namespace std;

Convolve::Convolve(Image& image){
    image_copyvector=image.vect;
}

void Convolve::blur(Image& image){

    for(int i=2; i<image.row-2; i++){
        for(int j=2; j<image.column-2; j++){
            image.vect[i][j]=Convolve::apply_Gaussian_on_pixel(i, j);
        }
    }
}

void Convolve::edge(Image& image){

    float G_max=0;
    for(int i=1; i<image.row-1; i++){
        for(int j=1; j<image.column-1; j++){
            image.vect[i][j]=Convolve::apply_Sobel_on_pixel(i, j);
            if(image.vect[i][j]>G_max){
                G_max=image.vect[i][j];
            }
        }
    }
    Convolve::normalize_pixelvalues(image, G_max);
}

void Convolve::sharpen(Image& image){

    vector <vector<int> > vect_edged;
    vect_edged=image_copyvector;

    Convolve::edge(image);

    vect_edged.swap(image.vect); // image.vect becomes filled with original values,
                                 // and vect_edged gets the pixelvalues after "edging"

    Convolve::sharpen_along_edges(image, vect_edged);
}

int Convolve::apply_Gaussian_on_pixel(const int i, const int j){
    float new_pixelvalue=0;
    for(int k=0; k<5; k++){
        for(int m=0; m<5; m++){
            new_pixelvalue=new_pixelvalue+image_copyvector[i+k-2][j+m-2]*Gaussian[k][m];
        }
    }
return (int)new_pixelvalue;
}

int Convolve::apply_Sobel_on_pixel(const int i, const int j){
    float a1=0.0;
    float a2=0.0;
    for(int k=0; k<3; k++){
        for(int m=0; m<3; m++){
            a1=a1+image_copyvector[i+k-1][j+m-1]*Edge_x[k][m];
            a2=a2+image_copyvector[i+k-1][j+m-1]*Edge_y[k][m];
        }
    }
    return sqrt(a1*a1+a2*a2);
}

void Convolve::normalize_pixelvalues(Image& image, float G_max){
    for(int i=1; i<image.row-1; i++){
        for(int j=1; j<image.column-1; j++){
            image.vect[i][j]=(int)((image.vect[i][j]/G_max)*image.max_intensity);
        }
    }
}

void Convolve::sharpen_along_edges(Image& image, vector <vector<int> >& vect_edged){
    for(int i=1; i<image.row-1; i++){
        for(int j=1; j<image.column-1; j++){
            if(vect_edged[i][j]>150 && image_copyvector[i][j]*1.2<image.max_intensity){
                image.vect[i][j]=image_copyvector[i][j]*1.2;
                Convolve::darken_neighbourpixels(image, i, j);
            }
            else if(vect_edged[i][j]>150 && image_copyvector[i][j]*1.2>image.max_intensity){
                image.vect[i][j]=image.max_intensity;
                Convolve::darken_neighbourpixels(image, i, j);
            }
        }
    }
}

void Convolve::darken_neighbourpixels(Image& image, int i, int j){
    for(int k=0; k<3; k++){
        for(int l=0; l<3; l++){
            if(image_copyvector[i+k-1][j+l-1]<0.9*image_copyvector[i][j]){
                image.vect[i+k-1][j+l-1]=0.8*image_copyvector[i+k-1][j+l-1];
            }
        }
    }
}
