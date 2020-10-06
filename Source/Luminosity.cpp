#include <iostream>
#include <string>
#include <vector>
#include "Luminosity.h"

using namespace std;

Luminosity::Luminosity(string name) : ImageProcessor(name){ }

void Luminosity::process_image(){

    int percent;
    cout << "By how many percent? (-99 -> 99)" << endl;
    cin >> percent;

    for(int i=0; i<row; i++){
        for(int j=0; j<column; j++){
            if(pixel_vector[i][j]+(percent/100.0)*pixel_vector[i][j]<max_intensity){
                pixel_vector[i][j]=pixel_vector[i][j]*(1+(percent/100.0));
            }
            else pixel_vector[i][j]=max_intensity;
        }
    }
    image_name=image_name+"_luminosity_changed_by_"+to_string(percent)+"%.pgm";
}
