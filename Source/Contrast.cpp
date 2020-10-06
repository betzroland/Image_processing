#include <iostream>
#include <string>
#include <vector>
#include "Contrast.h"

using namespace std;

Contrast::Contrast(string name) : ImageProcessor(name){ }

void Contrast::process_image(){
    int percent;
    cout << "By how many percent? (1-99)" << endl;
    cin >> percent;

    for(int i=0; i<row; i++){
        for(int j=0; j<column; j++){
            if(pixel_vector[i][j]<(max_intensity/2.0)){
                pixel_vector[i][j]=pixel_vector[i][j]*(1-(percent/100.0));
            }
            else if(pixel_vector[i][j]>(max_intensity/2.0) && (pixel_vector[i][j]*(1+(percent/100.0)))<max_intensity){
                pixel_vector[i][j]=pixel_vector[i][j]*(1+(percent/100.0));
            }
            else{
                pixel_vector[i][j]=max_intensity;
            }
        }
    }
    image_name=image_name+"_contrast_+"+to_string(percent)+"%.pgm";
}
