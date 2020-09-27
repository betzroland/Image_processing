#include <iostream>
#include <string>
#include <vector>
#include "Contrast.h"

using namespace std;

Contrast::Contrast(string name) : Base(name){ }

void Contrast::operation(){
    int percent;
    cout << "How many percent of contrast enhancement do you want? (1-99)" << endl;
    cin >> percent;

    //Exception

    for(int i=0; i<row; i++){
        for(int j=0; j<column; j++){
            if(vect[i][j]<(max_intensity/2.0)){
                vect[i][j]=vect[i][j]*(1-(percent/100.0));
            }
            else if(vect[i][j]>(max_intensity/2.0) && (vect[i][j]*(1+(percent/100.0)))<max_intensity){
                vect[i][j]=vect[i][j]*(1+(percent/100.0));
            }
            else{
                vect[i][j]=max_intensity;
            }
        }
    }
    image_name=image_name+"_contrast_+"+to_string(percent)+"%.pgm";
}
