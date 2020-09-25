#include <vector>
#include "Inversion.h"

using namespace std;

Inversion::Inversion(string name) : Base(name){
}

void Inversion::operation(){
    for(int i=0; i<row; i++){
        for(int j=0; j<column; j++){
            vect[i][j]=max_intensity-vect[i][j];
        }
    }
    image_name=image_name+"_inverted.pgm";
}
