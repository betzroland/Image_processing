#include <iostream>
#include <string>
#include <vector>
#include "Transform.h"
#include "Output.h"

using namespace std;

void Transform::rotation(Read_in& read){

    vector <vector<int> > vect_temp(read.row, vector<int>(read.column, 0));
    read.vect.swap(vect_temp);
    cout << "Angle of rotation? (90, 180, 270)" << endl;
    cin >> angle;
    if(angle!=90 || angle!=180 || angle!=270){
        throw std::domain_error("Wrong parameter!");
    }

    if(angle==90){
        for(int i=0; i<read.row; i++){
            for(int j=0; j<read.column; j++){
                read.vect[i][j]=vect_temp[j][(read.column-1)-i];
            }
        }
        read.image_name=read.image_name+"_rotated_90.pgm";
    }
    else if(angle==180){
        for(int i=0; i<read.row; i++){
            for(int j=0; j<read.column; j++){
                read.vect[i][j]=vect_temp[(read.row-1)-i][(read.column-1)-j];
            }
        }
        read.image_name=read.image_name+"_rotated_180.pgm";
    }
    else if(angle==270){
        for(int i=0; i<read.row; i++){
            for(int j=0; j<read.column; j++){
                read.vect[i][j]=vect_temp[(read.row-1)-j][i];
            }
        }
        read.image_name=read.image_name+"_rotated_270.pgm";
    }
}

void Transform::mirroring(Read_in& read){

    vector <vector<int> > vect_temp(read.row, vector<int>(read.column, 0));
    read.vect.swap(vect_temp);

    cout << "Mirroring to x-axis: press (x). Mirroring to y-axis: press (y)." << endl;
    cin >> axis;

    if(axis=="x"){
        for(int i=0; i<read.row; i++){
            for(int j=0; j<read.column; j++){
                read.vect[i][j]=vect_temp[(read.row-1)-i][j];
            }
        }
        read.image_name=read.image_name+"_mirrored_to_x.pgm";
    }
    else if(axis=="y"){
        for(int i=0; i<read.row; i++){
            for(int j=0; j<read.column; j++){
                read.vect[i][j]=vect_temp[i][(read.column-1)-j];
            }
        }
        read.image_name=read.image_name+"_mirrored_to_y.pgm";
    }
}
