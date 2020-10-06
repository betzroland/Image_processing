#include <vector>
#include "Inversion.h"

using namespace std;

Inversion::Inversion(string name) : ImageProcessor(name){ }

void Inversion::process_image(){
    for(int i=0; i<row; i++){
        for(int j=0; j<column; j++){
            pixel_vector[i][j]=max_intensity-pixel_vector[i][j];
        }
    }
    image_name=image_name+"_inverted.pgm";
}
