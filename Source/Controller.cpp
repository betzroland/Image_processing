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
                                                    blurring=5, edge_detection=6, sharpening=7};
    int options;
    cout << "Choose an operation you want to apply!"
                "\n\nChange luminosity -> press 1\nInversion -> press 2\n"
                        "Contrast enhancement -> press 3\nRotation -> press 4\n"
                            "Blurring -> press 5\nEdge detection -> press 6\nSharpening -> press 7\n" << endl;
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
                Inversion inversion(name);
                inversion.load();
                inversion.operation();
                inversion.save();
            break;
            }
        case contrast_enhancement :
            {
                Contrast contrast(name);
                contrast.load();
                contrast.operation();
                contrast.save();
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
        case blurring :
            {
                Blurring blurred(name);
                blurred.load();
                blurred.operation();
                blurred.save();
                break;
            }
        case edge_detection :
            {
                Edge edge(name);
                edge.load();
                edge.operation();
                edge.save();
                break;
            }
        case sharpening :
            {

                break;
            }
    }
    cout << "\nDo you want to continue your work on other images? Press (y) or (n)!" << endl;
    cin >> next;

}
}
