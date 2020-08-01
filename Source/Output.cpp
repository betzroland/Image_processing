#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "Output.h"

using namespace std;

void save(string& output_filename, int& row, int& column, int& max_intensity, vector <vector<int> >& vect){

    string filepath="C:/Users/betzr/Desktop/Images/PGM/Modified/"+output_filename;
    ofstream savedata(filepath.c_str());
    savedata << "P2\n" << column << " " << row << "\n" << max_intensity << "\n";

    //----------------------------------------------------------------------------------------------
    //Output files (also can be opened as text) will have 30 columns, but it doesn't really matters.
    //The only important thing is that the pixel values have to be separated by a whitespace.

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
}

string intToString(int t){
            string s;
            ostringstream out;
            out << t;
            s = out.str();
            return s;
        }
