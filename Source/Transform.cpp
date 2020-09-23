#include <iostream>
#include <string>
#include <vector>
#include "Transform.h"

using namespace std;

Transform::Transform(Image& image){
    image_copyvector=image.vect;
}

void Transform::rotation(Image& image){

    int angle_of_rotation;
    cout << "Angle_of_rotation? (90, 180, 270)" << endl;
    cin >> angle_of_rotation;

    switch(angle_of_rotation){
        case 90 :
        Transform::rotate_by_90(image);
        image.image_name=image.image_name+"_rotated_90.pgm";
        break;

        case 180 :
        Transform::rotate_by_180(image);
        image.image_name=image.image_name+"_rotated_180.pgm";
        break;

        case 270 :
        Transform::rotate_by_270(image);
        image.image_name=image.image_name+"_rotated_270.pgm";
    }
}

void Transform::mirroring(Image& image){
    string axis_of_mirroring;
    cout << "Mirroring to x-axis: press (x). Mirroring to y-axis: press (y)." << endl;
    cin >> axis_of_mirroring;

    if(axis_of_mirroring=="x"){
        Transform::mirror_to_x_axis(image);
        image.image_name=image.image_name+"_mirrored_to_x.pgm";
    }
    else if(axis_of_mirroring=="y"){
        Transform::mirror_to_y_axis(image);
        image.image_name=image.image_name+"_mirrored_to_y.pgm";
    }
}

void Transform::rotate_by_90(Image& image){
    for(int i=0; i<image.row; i++){
        for(int j=0; j<image.column; j++){
            image.vect[i][j]=image_copyvector[j][(image.column-1)-i];
        }
    }
}

void Transform::rotate_by_180(Image& image){
    for(int i=0; i<image.row; i++){
        for(int j=0; j<image.column; j++){
            image.vect[i][j]=image_copyvector[(image.row-1)-i][(image.column-1)-j];
        }
    }
}

void Transform::rotate_by_270(Image& image){
    for(int i=0; i<image.row; i++){
        for(int j=0; j<image.column; j++){
            image.vect[i][j]=image_copyvector[(image.row-1)-j][i];
        }
    }
}

void Transform::mirror_to_x_axis(Image& image){
    for(int i=0; i<image.row; i++){
        for(int j=0; j<image.column; j++){
            image.vect[i][j]=image_copyvector[(image.row-1)-i][j];
        }
    }
}

void Transform::mirror_to_y_axis(Image& image){
    for(int i=0; i<image.row; i++){
        for(int j=0; j<image.column; j++){
            image.vect[i][j]=image_copyvector[i][(image.column-1)-j];
        }
    }
}
