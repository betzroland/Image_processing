#include <iostream>
#include <string>
#include <vector>
#include "Transform.h"
#include "Output.h"

using namespace std;

void Transform::rotation(const string image_name, const int row, const int column, const int max_intensity, vector <vector<int> >& vect){

    vector <vector<int> > vect_temp(row, vector<int>(column, 0));
    vect.swap(vect_temp);
    cout << "Angle of rotation? (90, 180, 270)" << endl;
    cin >> angle;
    if(angle!=90 || angle!=180 || angle!=270){
        throw std::domain_error("Wrong parameter!");
    }

    if(angle==90){
        for(int i=0; i<row; i++){
            for(int j=0; j<column; j++){
                vect[i][j]=vect_temp[j][(column-1)-i];
            }
        }
        string output=image_name+"_rotated_90.pgm";
        save(output, row, column, max_intensity, vect);
        cout << "The modified image has been saved with a name: "<< image_name << "_rotated_90" << endl;
    }
    else if(angle==180){
        for(int i=0; i<row; i++){
            for(int j=0; j<column; j++){
                vect[i][j]=vect_temp[(row-1)-i][(column-1)-j];
            }
        }
        string output=image_name+"_rotated_180.pgm";
        save(output, row, column, max_intensity, vect);
        cout << "The modified image has been saved with a name: "<< image_name << "_rotated_180" << endl;
    }
    else if(angle==270){
        for(int i=0; i<row; i++){
            for(int j=0; j<column; j++){
                vect[i][j]=vect_temp[(row-1)-j][i];
            }
        }
        string output=image_name+"_rotated_270.pgm";
        save(output, row, column, max_intensity, vect);
        cout << "The modified image has been saved with a name: "<< image_name << "_rotated_270" << endl;
    }
}

void Transform::mirroring(const string image_name, const int row, const int column, const int max_intensity, vector <vector<int> >& vect){

    vector <vector<int> > vect_temp(row, vector<int>(column, 0));
    vect.swap(vect_temp);

    cout << "Mirroring to x-axis: press (x). Mirroring to y-axis: press (y)." << endl;
    cin >> axis;
    if(axis!="x" || axis!="y"){
        throw std::domain_error("Wrong parameter!");
    }

    if(axis=="x"){
        for(int i=0; i<row; i++){
            for(int j=0; j<column; j++){
                vect[i][j]=vect_temp[(row-1)-i][j];
            }
        }
        string output=image_name+"_mirrored_to_x.pgm";
        save(output, row, column, max_intensity, vect);
        cout << "The modified image has been saved with a name: "<< image_name << "_mirrored_to_x" << endl;
    }
    else if(axis=="y"){
        for(int i=0; i<row; i++){
            for(int j=0; j<column; j++){
                vect[i][j]=vect_temp[i][(column-1)-j];
            }
        }
        string output=image_name+"_mirrored_to_y.pgm";
        save(output, row, column, max_intensity, vect);
        cout << "The modified image has been saved with a name: "<< image_name << "_mirrored_to_y" << endl;
    }
}
