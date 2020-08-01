#include <iostream>
#include <string>
#include <vector>
#include "Read_in.h"
#include "Lights.h"
#include "Transform.h"
#include "Convolve.h"

using namespace std;

int main(){

string next="y";

while(next=="y"){

    Read_in read;
    read.load();

    string functions;
    cout << "What kind of function do you want to apply? (Light, Transform, Convolution)" << endl;
    cin >> functions;

    string str;

    if(functions=="Light"){
            Lights light;
            cout << "Choose a specific operation! (Darken, Brighten, Invert, Contrast+)" << endl;
            cin >> str;
            if(str=="Darken"){
                light.darken(read.image_name, read.row, read.column, read.max_intensity, read.vect);
            }
            else if(str=="Brighten"){
                light.brighten(read.image_name, read.row, read.column, read.max_intensity, read.vect);
            }
            else if(str=="Invert"){
                light.invert(read.image_name, read.row, read.column, read.max_intensity, read.vect);
            }
            else if(str=="Contrast+"){
                light.contrast(read.image_name, read.row, read.column, read.max_intensity, read.vect);
            }
    }
    else if(functions=="Transform"){
            Transform transf;
            cout << "Choose a specific operation! (Rotate, Mirror)" << endl;
            cin >> str;
            if(str=="Rotate"){
                transf.rotation(read.image_name, read.row, read.column, read.max_intensity, read.vect);
            }
            else if(str=="Mirror"){
                transf.mirroring(read.image_name, read.row, read.column, read.max_intensity, read.vect);
            }
    }
    else if(functions=="Convolution"){
            Convolve convolve;
            cout << "Choose a specific operation! (Blur, Sharpen, Edge)" << endl;
            cin >> str;
            if(str=="Blur"){
                convolve.blur(read.image_name, read.row, read.column, read.max_intensity, read.vect);
            }
            else if(str=="Edge"){
                convolve.edge(read.image_name, read.row, read.column, read.max_intensity, read.vect);
            }
            else if(str=="Sharpen"){
                convolve.sharpen(read.image_name, read.row, read.column, read.max_intensity, read.vect);
            }
    }
    cout << "\nDo you want to continue your work on other images? Press (y) or (n)!" << endl;
    cin >> next;
}
return 0;
}
