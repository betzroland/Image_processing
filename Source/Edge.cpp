#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include "Edge.h"

using namespace std;

Edge::Edge(string name){
    image_name=name;
}

void Edge::operation(){
    image_copyvector=vect;
    double G_max=0;
    for(int i=1; i<row-1; i++){
        for(int j=1; j<column-1; j++){
            vect[i][j]=Edge::apply_Sobel_on_pixel(i, j);
            if(vect[i][j]>G_max){
                G_max=vect[i][j];
            }
        }
    }
    Edge::normalize_pixelvalues(G_max);
    image_name=image_name+"_edge_detected.pgm";
}

int Edge::apply_Sobel_on_pixel(const int i, const int j){
    double a1=0.0;
    double a2=0.0;
    for(int k=0; k<3; k++){
        for(int m=0; m<3; m++){
            a1=a1+image_copyvector[i+k-1][j+m-1]*Edge_x[k][m];
            a2=a2+image_copyvector[i+k-1][j+m-1]*Edge_y[k][m];
        }
    }
    return sqrt(a1*a1+a2*a2);
}

void Edge::normalize_pixelvalues(double G_max){
    for(int i=1; i<row-1; i++){
        for(int j=1; j<column-1; j++){
            vect[i][j]=(int)((vect[i][j]/G_max)*max_intensity);
        }
    }
}
