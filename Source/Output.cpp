#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "Output.h"

using namespace std;

void save(Image& image){

    string filepath="C:/Users/betzr/Desktop/Images/PGM/Modified/"+image.image_name;
    ofstream savedata(filepath.c_str());
    savedata << "P2\n" << image.column << " " << image.row << "\n" << image.max_intensity << "\n";

    //----------------------------------------------------------------------------------------------
    //Output files (also can be opened as text) will have 30 columns, but it doesn't really matters.
    //The only important thing is that the pixel values have to be separated by a whitespace.

    int rowbreak=0;
    for(int i=0; i<image.row; i++){
        for(int j=0; j<image.column; j++){
            savedata << image.vect[i][j] << " ";
            rowbreak++;
            if(rowbreak==30){
                savedata << "\n";
                rowbreak=0;
            }
        }
    }
    savedata.close();
    cout << "The modified image has been saved with a name: "<< image.image_name << endl;
}
