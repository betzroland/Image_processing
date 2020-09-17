#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include "Convolve.h"
#include "Output.h"

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

    vector <vector<int> > vect_temp;
    vect_temp=image_copyvector;

    Convolve::edge(image);

    //-----------------------------------------------------------------------------------------------------
    //The comparison always done with the pixels of the original picture, then we modify the temp_vectors,
    //then finally the image vector gets all the values of the modified temp_vector.

    //Whenever an "edge" pixel is found (a pixel with higher intensity), its intensity will be enhanced further,
    //since it marks a brighter edge on the original image. At the same time we also inspect its neighbour
    //pixels, and if a darker pixel is found, its intensity will be reduced further, so all in all, the
    //edges on the image will appear more distinct.
    //The numbers used below are a bit arbitrary, but it works quite well.

    for(int i=1; i<image.row-1; i++){
        for(int j=1; j<image.column-1; j++){
            if(image.vect[i][j]>150 && image_copyvector[i][j]*1.2<image.max_intensity){
                vect_temp[i][j]=vect_temp[i][j]*1.2;
                for(int k=0; k<3; k++){
                    for(int l=0; l<3; l++){
                        if(image_copyvector[i+k-1][j+l-1]<0.9*image_copyvector[i][j]){
                            vect_temp[i+k-1][j+l-1]=0.8*vect_temp[i+k-1][j+l-1];
                        }
                    }
                }
            }
            else if(image.vect[i][j]>150 && image_copyvector[i][j]*1.2>image.max_intensity){
                vect_temp[i][j]=image.max_intensity;
                for(int k=0; k<3; k++){
                    for(int l=0; l<3; l++){
                        if(image_copyvector[i+k-1][j+l-1]<0.9*image_copyvector[i][j]){
                            vect_temp[i+k-1][j+l-1]=0.8*vect_temp[i+k-1][j+l-1];
                        }
                    }
                }
            }
        }
    }
    image.vect.swap(vect_temp);
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
            image.vect[i][j]=(int)((image.vect[i][j]/G_max)*image.max_intensity); // Normalizing.
        }
    }
}
