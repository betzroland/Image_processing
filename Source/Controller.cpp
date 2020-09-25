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
    enum Options {change_luminosity=1, inversion=2, contrast_enhancement=3, rotation=4,
                                    mirroring=5, blurring=6, edge_detection=7, sharpening=8};
    int options;
    cout << "Choose an operation you want to apply!"
                "\n\nChange luminosity -> press 1\nInversion -> press 2\n"
                    "Contrast enhancement -> press 3\nRotation -> press 4\nMirroring -> press 5\n"
                        "Blurring -> press 6\nEdge detection -> press 7\nSharpening -> press 8\n" << endl;
    cin >> options;

    switch(options){
        case change_luminosity :
            {
                Luminosity luminosity(name);
                luminosity.load();
                luminosity.operation();
                luminosity.save();
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
