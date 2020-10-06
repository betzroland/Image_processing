#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "ImageProcessor.h"

using namespace std;

ImageProcessor::ImageProcessor(string name){
    image_name=name;
    string filepath="C:/Users/betzr/Desktop/Images/PGM/Source/"+image_name+".pgm";
    ifstream myfile(filepath.c_str());
    if(!myfile){
        cout << "File not found!" << endl;
    }

    //------------------------------------------------------------------------
    //Separating header and pixel_data strings, omitting comment lines (marked by #).

    string str_temp;
    int rowcounter=1;
    string header, pixel_data;
    while(!myfile.eof()){
        getline(myfile, str_temp);
        if(rowcounter<=3 && str_temp.find('#')!=0){
            header.append(str_temp+"\n");
            rowcounter++;
        }
        else if(rowcounter>3 && str_temp.find('#')!=0){
            pixel_data.append(str_temp+"\n");
        }
    }
    myfile.close();

    //-------------------------------------------------------
    //Get the values of column, row and max "color" intensity.

    string stream_temp;
    stringstream ss;
    rowcounter=1;
    ss << header;
    while(ss >> stream_temp){
        if(rowcounter==2){                  // Omitting the "P2" identifier in row 1
            stringstream(stream_temp) >> column;
        }
        else if(rowcounter==3){
            stringstream(stream_temp) >> row;
        }
        else if(rowcounter==4){
            stringstream(stream_temp) >> max_intensity;
        }
        rowcounter++;
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
    pixel_vector.swap(vect_temp);
}

void ImageProcessor::save_image(){

    string filepath="C:/Users/betzr/Desktop/Images/PGM/Modified/"+image_name;
    ofstream savedata(filepath.c_str());
    savedata << "P2\n" << column << " " << row << "\n" << max_intensity << "\n"; //P2 is a pgm format identifier

    int rowbreak=0;
    for(int i=0; i<row; i++){
        for(int j=0; j<column; j++){
            savedata << pixel_vector[i][j] << " ";
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
