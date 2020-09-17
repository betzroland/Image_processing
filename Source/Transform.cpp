#include <iostream>
#include <string>
#include <vector>
#include "Transform.h"

using namespace std;

void Transform::rotation(Image& image){

    vector <vector<int> > vect_temp(image.row, vector<int>(image.column, 0));
    image.vect.swap(vect_temp);
    cout << "Angle of rotation? (90, 180, 270)" << endl;
    cin >> angle;
    if(angle!=90 || angle!=180 || angle!=270){
        throw std::domain_error("Wrong parameter!");
    }

    if(angle==90){
        for(int i=0; i<image.row; i++){
            for(int j=0; j<image.column; j++){
                image.vect[i][j]=vect_temp[j][(image.column-1)-i];
            }
        }
        image.image_name=image.image_name+"_rotated_90.pgm";
    }
    else if(angle==180){
        for(int i=0; i<image.row; i++){
            for(int j=0; j<image.column; j++){
                image.vect[i][j]=vect_temp[(image.row-1)-i][(image.column-1)-j];
            }
        }
        image.image_name=image.image_name+"_rotated_180.pgm";
    }
    else if(angle==270){
        for(int i=0; i<image.row; i++){
            for(int j=0; j<image.column; j++){
                image.vect[i][j]=vect_temp[(image.row-1)-j][i];
            }
        }
        image.image_name=image.image_name+"_rotated_270.pgm";
    }
}

void Transform::mirroring(Image& image){

    vector <vector<int> > vect_temp(image.row, vector<int>(image.column, 0));
    image.vect.swap(vect_temp);

    cout << "Mirroring to x-axis: press (x). Mirroring to y-axis: press (y)." << endl;
    cin >> axis;

    if(axis=="x"){
        for(int i=0; i<image.row; i++){
            for(int j=0; j<image.column; j++){
                image.vect[i][j]=vect_temp[(image.row-1)-i][j];
            }
        }
        image.image_name=image.image_name+"_mirrored_to_x.pgm";
    }
    else if(axis=="y"){
        for(int i=0; i<image.row; i++){
            for(int j=0; j<image.column; j++){
                image.vect[i][j]=vect_temp[i][(image.column-1)-j];
            }
        }
        image.image_name=image.image_name+"_mirrored_to_y.pgm";
    }
}
