#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>
#include "Lights.h"
#include "Output.h"

using namespace std;

void Lights::darken(string& image_name, int& row, int& column, int& max_intensity, vector <vector<int> >& vect){
    cout << "With how many percent? (1-99)" << endl;
    cin >> percent;
    if(typeid(percent).name()!=typeid(1).name || percent<1 || percent>99){
        throw std::domain_error("Wrong parameter!");
    }
    for(int i=0; i<row; i++){
        for(int j=0; j<column; j++){
            vect[i][j]=vect[i][j]*(1-(percent/100.0));
        }
    }
    string output=image_name+"_darkened_"+intToString(percent)+"%.pgm";
    save(output, row, column, max_intensity, vect);
    cout << "The modified image has been saved with a name: "<< image_name << "_darkened_" << intToString(percent) << "%" << endl;
}

void Lights::brighten(string& image_name, int& row, int& column, int& max_intensity, vector <vector<int> >& vect){
    cout << "With how many percent? (1-99)" << endl;
    cin >> percent;
    if(typeid(percent).name()!=typeid(1).name || percent<1 || percent>99){
        throw std::domain_error("Wrong parameter!");
    }
    for(int i=0; i<row; i++){
        for(int j=0; j<column; j++){
            if(vect[i][j]+(percent/100.0)*vect[i][j]<max_intensity){
                vect[i][j]=vect[i][j]*(1+(percent/100.0));
            }
            else vect[i][j]=max_intensity;
        }
    }
    string output=image_name+"_brightened_"+intToString(percent)+"%.pgm";
    save(output, row, column, max_intensity, vect);
    cout << "The modified image has been saved with a name: "<< image_name << "_brightened_" << intToString(percent) << "%" << endl;
}

void Lights::invert(string& image_name, int& row, int& column, int& max_intensity, vector <vector<int> >& vect){
    for(int i=0; i<row; i++){
        for(int j=0; j<column; j++){
            vect[i][j]=max_intensity-vect[i][j];
        }
    }
    string output=image_name+"_inverted.pgm";
    save(output, row, column, max_intensity, vect);
    cout << "The modified image has been saved with a name: "<< image_name << "_inverted" << endl;
}

void Lights::contrast(string& image_name, int& row, int& column, int& max_intensity, vector <vector<int> >& vect){
    cout << "How many percent of contrast enhancement do you want? (1-20)" << endl;
    cin >> percent;
    if(typeid(percent).name()!=typeid(1).name || percent<1 || percent>99){
        throw std::domain_error("Wrong parameter!");
    }
    for(int i=0; i<row; i++){
        for(int j=0; j<column; j++){
            if(vect[i][j]<(max_intensity/2.0)){
                vect[i][j]=vect[i][j]*(1-(percent/100.0));
            }
            if(vect[i][j]>(max_intensity/2.0) && (vect[i][j]+vect[i][j]*(percent/100.0))<max_intensity){
                vect[i][j]=vect[i][j]*(1+(percent/100.0));
            }
            if(vect[i][j]>(max_intensity/2.0) && (vect[i][j]+vect[i][j]*(percent/100.0))>max_intensity){
                vect[i][j]=max_intensity;
            }
        }
    }
    string output=image_name+"_contrast_+"+intToString(percent)+"%.pgm";
    save(output, row, column, max_intensity, vect);
    cout << "The modified image has been saved with a name: "<< image_name << "_contrast_+" << intToString(percent) << "%" << endl;
}
