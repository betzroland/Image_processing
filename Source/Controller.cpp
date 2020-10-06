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

    int options;
    cout << "Choose an operation you want to apply!"
                "\n\nChange luminosity -> press 1\nInversion -> press 2\n"
                        "Contrast enhancement -> press 3\nRotation -> press 4\n"
                                "Blurring -> press 5\nEdge detection -> press 6\n" << endl;

    cin >> options;
    enum Options {change_luminosity=1, inversion=2, contrast_enhancement=3, rotation=4,
                                                                blurring=5, edge_detection=6};

    switch(options){
        case change_luminosity :
            {
                Luminosity luminosity(name);
                luminosity.process_image();
                luminosity.save_image();
            break;
            }
        case inversion :
            {
                Inversion inversion(name);
                inversion.process_image();
                inversion.save_image();
            break;
            }
        case contrast_enhancement :
            {
                Contrast contrast(name);
                contrast.process_image();
                contrast.save_image();
                break;
            }
        case rotation :
            {
                Rotation rotated(name);
                rotated.process_image();
                rotated.save_image();
                break;
            }
        case blurring :
            {
                Blurring blurred(name);
                blurred.process_image();
                blurred.save_image();
                break;
            }
        case edge_detection :
            {
                Edge edge(name);
                edge.process_image();
                edge.save_image();
                break;
            }
    }
    cout << "\nDo you want to continue working on other images? Press (y) or (n)!" << endl;
    cin >> next;
}
}
