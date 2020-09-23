#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <cstdio>
#include "Read_in.h"
#include "Lights.h"
#include "Transform.h"
#include "Convolve.h"

using namespace std;

int main(){

string next="y";

while(next=="y"){

    Image image;
    image.load();

    string functions;
    cout << "What kind of function do you want to apply? (Light, Transform, Convolution)" << endl;
    cin >> functions;

    string str;

    if(functions=="Light"){
        Lights light;
        cout << "Choose a specific operation! (Darken, Brighten, Invert, Contrast+)" << endl;
        cin >> str;
        if(str=="Darken"){
            light.darken(image);
            image.save();
        }
        else if(str=="Brighten"){
            light.brighten(image);
            image.save();
        }
        else if(str=="Invert"){
            light.invert(image);
            image.save();
        }
        else if(str=="Contrast+"){
            light.contrast(image);
            image.save();
        }
    }
    else if(functions=="Transform"){
        Transform transf(image);
        cout << "Choose a specific operation! (Rotate, Mirror)" << endl;
        cin >> str;
        if(str=="Rotate"){
            transf.rotation(image);
            image.save();
        }
        else if(str=="Mirror"){
            transf.mirroring(image);
            image.save();
        }
    }
    else if(functions=="Convolution"){
        Convolve convolve(image);
        cout << "Choose a specific operation! (Blur, Sharpen, Edge)" << endl;
        cin >> str;
        if(str=="Blur"){
            convolve.blur(image);
            image.image_name=image.image_name+"_blurred.pgm";
            image.save();
        }
        else if(str=="Edge"){
            convolve.edge(image);
            image.image_name=image.image_name+"_edged.pgm";
            image.save();
        }
        else if(str=="Sharpen"){
            convolve.sharpen(image);
            image.image_name=image.image_name+"_sharpened.pgm";
            image.save();
        }
    }
    cout << "\nDo you want to continue your work on other images? Press (y) or (n)!" << endl;
    cin >> next;
}

/*catch(std::exception &e){
    fprintf(stderr, e.what());
    return 1;
    }*/

return 0;
}
