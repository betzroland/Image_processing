#include <iostream>
#include <vector>
#include "Controller.h"

using namespace std;

void Controller::controller(){
    string next="y";

while(next=="y"){
    string name;
    cout << "Write the name of the image (without format) you want to process!" << endl;
    cin >> name;
    enum Options {darkening=1, brightening=2, inversion=3, contrast_enhancement=4, rotation=5,
                        mirroring=6, blurring=7, edge_detection=8, sharpening=9};
    int options;
    cout << "Choose an operation you want to apply!"
        "\n\nDarkening -> press 1\nBrightening -> press 2\nInversion -> press 3\n"
                "Contrast enhancement -> press 4\nRotation -> press 5\nMirroring -> press 6\n"
                        "Blurring -> press 7\nEdge detection -> press 8\nSharpening -> press 9\n" << endl;
    cin >> options;

    switch(options){
        case darkening :
            {
                Darkening darkened(name);
                darkened.load();
                darkened.operation();
                darkened.save();
            break;
            }
        case brightening :
            {
                cout << "ok" << endl;
                break;
            }
        case inversion :
            {
                cout << "ok" << endl;
                break;
            }
        case contrast_enhancement :
            {
                cout << "ok" << endl;
                break;
            }
        case rotation :
            {
                Rotation rotated(name);
                rotated.load();
                rotated.operation();
                rotated.save();
                break;
            }
        case mirroring :
            {
                cout << "ok" << endl;
                break;
            }
        case blurring :
            {
                cout << "ok" << endl;
                break;
            }
        case edge_detection :
            {
                cout << "ok" << endl;
                break;
            }
        case sharpening :
            {
                cout << "ok" << endl;
                break;
            }
    }
    cout << "\nDo you want to continue your work on other images? Press (y) or (n)!" << endl;
    cin >> next;

}
}
