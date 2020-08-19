#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "Read_in.h"

using namespace std;

void Read_in::load(){

    cout << "Write the name of the image (without format) you want to process!" << endl;
    cin >> image_name;
    string filepath="C:/Users/betzr/Desktop/Images/PGM/Source/"+image_name+".pgm";
    ifstream myfile1(filepath.c_str());

    string str_temp;
    int rowcounter=1;

    //------------------------------------------------------------------------
    //Separating header and data strings, without comment lines (marked by #).

    while(!myfile1.eof()){
        getline(myfile1, str_temp);
        if(rowcounter<=3 && str_temp.find('#')!=0){
            header.append(str_temp+"\n");
            rowcounter++;
        }
        else if(rowcounter>3 && str_temp.find('#')!=0){
            data.append(str_temp+"\n");
            rowcounter++;
        }
    }
    myfile1.close();

    //-------------------------------------------------------
    //Get the values of column, row and max "color" intensity.

    string stream_temp1;
    stringstream ss1;
    int a=1;
    ss1 << header;

    while(ss1 >> stream_temp1){
        if(a==2){
            stringstream(stream_temp1) >> column;
        }
        if(a==3){
            stringstream(stream_temp1) >> row;
        }
        if(a==4){
            stringstream(stream_temp1) >> max_intensity;
        }
        a++;
    }

    //---------------------------------------------------------------------------------
    //Creating a vector from data string, which represents the pixel values of the image.

    string stream_temp2;
    stringstream ss2;
    ss2 << data;

    vector <vector<int> > vect_temp(row, vector<int>(column, 0));
    for(int i=0; i<row; i++){
        for(int j=0; j<column; j++){
            ss2 >> stream_temp2;
            stringstream(stream_temp2) >> vect_temp[i][j];
        }
    }
    vect.swap(vect_temp);
}
