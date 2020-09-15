#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <cstdio>
#include "Read_in.h"
#include "Lights.h"
#include "Transform.h"
#include "Convolve.h"
#include "Output.h"

using namespace std;

int main(){

try{

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
                light.darken(read);
                save(read);
            }
            else if(str=="Brighten"){
                light.brighten(read);
                save(read);
            }
            else if(str=="Invert"){
                light.invert(read);
                save(read);
            }
            else if(str=="Contrast+"){
                light.contrast(read);
                save(read);
            }
    }
    else if(functions=="Transform"){
            Transform transf;
            cout << "Choose a specific operation! (Rotate, Mirror)" << endl;
            cin >> str;
            if(str=="Rotate"){
                transf.rotation(read);
                save(read);
            }
            else if(str=="Mirror"){
                transf.mirroring(read);
                save(read);
            }
    }
    else if(functions=="Convolution"){
            Convolve convolve;
            cout << "Choose a specific operation! (Blur, Sharpen, Edge)" << endl;
            cin >> str;
            if(str=="Blur"){
                convolve.blur(read);
                save(read);
            }
            else if(str=="Edge"){
                convolve.edge(read);
                save(read);
            }
            else if(str=="Sharpen"){
                convolve.sharpen(read);
                save(read);
            }
    }
    cout << "\nDo you want to continue your work on other images? Press (y) or (n)!" << endl;
    cin >> next;
}
}
catch(std::exception &e){
    fprintf(stderr, e.what());
    return 1;
    }

return 0;
}
