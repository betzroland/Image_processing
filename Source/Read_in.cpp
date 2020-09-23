#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "Read_in.h"

using namespace std;

void Image::load(){

    cout << "Write the name of the image (without format) you want to process!" << endl;
    cin >> image_name;
    string filepath="C:/Users/betzr/Desktop/Images/PGM/Source/"+image_name+".pgm";
    ifstream myfile1(filepath.c_str());

    string str_temp;
    int rowcounter=1;

    //------------------------------------------------------------------------
    //Separating header and pixel_data strings, without comment lines (marked by #).

    string header, pixel_data;
    while(!myfile1.eof()){
        getline(myfile1, str_temp);
        if(rowcounter<=3 && str_temp.find('#')!=0){
            header.append(str_temp+"\n");
            rowcounter++;
        }
        else if(rowcounter>3 && str_temp.find('#')!=0){
            pixel_data.append(str_temp+"\n");
            rowcounter++;
        }
    }
    myfile1.close();

    //-------------------------------------------------------
    //Get the values of column, row and max "color" intensity.

    string stream_temp;
    stringstream ss;
    int a=1;
    ss << header;

    while(ss >> stream_temp){
        if(a==2){
            stringstream(stream_temp) >> column;
        }
        if(a==3){
            stringstream(stream_temp) >> row;
        }
        if(a==4){
            stringstream(stream_temp) >> max_intensity;
        }
        a++;
    }

    //---------------------------------------------------------------------------------
    //Creating a vector from pixel_data string, which represents the pixel values of the image.

    stream_temp.clear();
    ss.clear();
    ss << pixel_data;

    vector <vector<int> > vect_temp(row, vector<int>(column, 0));
    for(int i=0; i<row; i++){
        for(int j=0; j<column; j++){
            ss >> stream_temp;
            stringstream(stream_temp) >> vect_temp[i][j];
        }
    }
    vect.swap(vect_temp);
}

void Image::save(){

    string filepath="C:/Users/betzr/Desktop/Images/PGM/Modified/"+image_name;
    ofstream savedata(filepath.c_str());
    savedata << "P2\n" << column << " " << row << "\n" << max_intensity << "\n";

    int rowbreak=0;
    for(int i=0; i<row; i++){
        for(int j=0; j<column; j++){
            savedata << vect[i][j] << " ";
            rowbreak++;
            if(rowbreak==30){
                savedata << "\n";
                rowbreak=0;
            }
        }
    }
    savedata.close();
    cout << "The modified image has been saved with a name: "<< image_name << endl;
}
