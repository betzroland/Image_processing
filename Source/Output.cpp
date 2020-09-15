#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "Output.h"

using namespace std;

void save(Read_in& read){

    string filepath="C:/Users/betzr/Desktop/Images/PGM/Modified/"+read.image_name;
    ofstream savedata(filepath.c_str());
    savedata << "P2\n" << read.column << " " << read.row << "\n" << read.max_intensity << "\n";

    //----------------------------------------------------------------------------------------------
    //Output files (also can be opened as text) will have 30 columns, but it doesn't really matters.
    //The only important thing is that the pixel values have to be separated by a whitespace.

    int rowbreak=0;
    for(int i=0; i<read.row; i++){
        for(int j=0; j<read.column; j++){
            savedata << read.vect[i][j] << " ";
            rowbreak++;
            if(rowbreak==30){
                savedata << "\n";
                rowbreak=0;
            }
        }
    }
    savedata.close();
    cout << "The modified image has been saved with a name: "<< read.image_name << endl;
}
