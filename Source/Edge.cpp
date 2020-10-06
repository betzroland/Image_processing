#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include "Edge.h"

using namespace std;

Edge::Edge(string name) : ImageProcessor(name){
    pixel_copyvector=pixel_vector;
}

void Edge::process_image(){
    double S_max=0;
    for(int i=1; i<row-1; i++){
        for(int j=1; j<column-1; j++){
            pixel_vector[i][j]=Edge::apply_Sobel_on_pixel(i, j);
            if(pixel_vector[i][j]>S_max){
                S_max=pixel_vector[i][j];
            }
        }
    }
    Edge::normalize_pixelvalues(S_max);
    image_name=image_name+"_edge_detected.pgm";
}

int Edge::apply_Sobel_on_pixel(const int i, const int j){
    double Sx=0.0;    double Sy=0.0;
    for(int k=0; k<3; k++){
        for(int m=0; m<3; m++){
            Sx=Sx+pixel_copyvector[i+k-1][j+m-1]*Edge_x[k][m];
            Sy=Sy+pixel_copyvector[i+k-1][j+m-1]*Edge_y[k][m];
        }
    }
    return sqrt(Sx*Sx+Sy*Sy);
}

void Edge::normalize_pixelvalues(double S_max){
    for(int i=1; i<row-1; i++){
        for(int j=1; j<column-1; j++){
            pixel_vector[i][j]=(int)((pixel_vector[i][j]/S_max)*max_intensity);
        }
    }
}
