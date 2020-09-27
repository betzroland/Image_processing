#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include "Edge.h"

using namespace std;

Edge::Edge(string name) : Base(name){
    image_copyvector=vect;
}

void Edge::operation(){
    double S_max=0;
    for(int i=1; i<row-1; i++){
        for(int j=1; j<column-1; j++){
            vect[i][j]=Edge::apply_Sobel_on_pixel(i, j);
            if(vect[i][j]>S_max){
                S_max=vect[i][j];
            }
        }
    }
    Edge::normalize_pixelvalues(S_max);
    image_name=image_name+"_edge_detected.pgm";
}

int Edge::apply_Sobel_on_pixel(const int i, const int j){
    double Sx=0.0;
    double Sy=0.0;
    for(int k=0; k<3; k++){
        for(int m=0; m<3; m++){
            Sx=Sx+image_copyvector[i+k-1][j+m-1]*Edge_x[k][m];
            Sy=Sy+image_copyvector[i+k-1][j+m-1]*Edge_y[k][m];
        }
    }
    return sqrt(Sx*Sx+Sy*Sy);
}

void Edge::normalize_pixelvalues(double S_max){
    for(int i=1; i<row-1; i++){
        for(int j=1; j<column-1; j++){
            vect[i][j]=(int)((vect[i][j]/S_max)*max_intensity);
        }
    }
}
