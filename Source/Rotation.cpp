#include <iostream>
#include <string>
#include <vector>
#include "Rotation.h"

using namespace std;

Rotation::Rotation(string name) : ImageProcessor(name){
    pixel_copyvector=pixel_vector;
}

void Rotation::process_image(){

    int angle_of_rotation;
    cout << "Type the angle of rotation: (90, 180, 270)" << endl;
    cin >> angle_of_rotation;

    switch(angle_of_rotation){
        case 90 :
        Rotation::rotate_by_90();
        image_name=image_name+"_rotated_90.pgm";
        break;

        case 180 :
        Rotation::rotate_by_180();
        image_name=image_name+"_rotated_180.pgm";
        break;

        case 270 :
        Rotation::rotate_by_270();
        image_name=image_name+"_rotated_270.pgm";
    }
}

void Rotation::rotate_by_90(){
    for(int i=0; i<row; i++){
        for(int j=0; j<column; j++){
            pixel_vector[i][j]=pixel_copyvector[j][(column-1)-i];
        }
    }
}

void Rotation::rotate_by_180(){
    for(int i=0; i<row; i++){
        for(int j=0; j<column; j++){
            pixel_vector[i][j]=pixel_copyvector[(row-1)-i][(column-1)-j];
        }
    }
}

void Rotation::rotate_by_270(){
    for(int i=0; i<row; i++){
        for(int j=0; j<column; j++){
            pixel_vector[i][j]=pixel_copyvector[(row-1)-j][i];
        }
    }
}
