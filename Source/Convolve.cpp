#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include "Convolve.h"
#include "Output.h"

using namespace std;

void Convolve::blur(const string image_name, const int row, const int column, const int max_intensity, vector <vector<int> >& vect){

    vector <vector<int> > vect_temp(row, vector<int>(column, 0));
    for(int i=0; i<row; i++){
        for(int j=0; j<column; j++){
            vect_temp[i][j]=vect[i][j];
        }
    }

    //3 types of normalized matrices for blurring: the matrix represents a Gaussian curve,
    //with its maximum value indexed by [2][2]
    //The "flatter" the Gaussian curve the more blurring effect it applies on the image.

    float f=576.0;
    float Gaussian1[5][5]=  {
                            {1/f, 6/f, 10/f, 6/f, 1/f},
                            {6/f, 36/f, 60/f, 36/f, 6/f},
                            {10/f, 60/f, 100/f, 60/f, 10/f},
                            {6/f, 36/f, 60/f, 36/f, 6/f},
                            {1/f, 6/f, 10/f, 6/f, 1/f}
                            };

    float e=256.0;
    float Gaussian2[5][5]=  {
                            {1/e, 4/e, 6/e, 4/e, 1/e},
                            {4/e, 16/e, 24/e, 16/e, 4/e},
                            {6/e, 24/e, 36/e, 24/e, 6/e},
                            {4/e, 16/e, 24/e, 16/e, 4/e},
                            {1/e, 4/e, 6/e, 4/e, 1/e}
                            };

    float d=49.0;
    float Gaussian3[5][5]=  {
                            {1/d, 1.5/d, 2/d, 1.5/d, 1/d},
                            {1.5/d, 2.25/d, 3/d, 2.25/d, 1.5/d},
                            {2/d, 3/d, 4/d, 3/d, 2/d},
                            {1.5/d, 2.25/d, 3/d, 2.25/d, 1.5/d},
                            {1/d, 1.5/d, 2/d, 1.5/d, 1/d}
                            };

    cout << "Level of blurring? (1, 2, 3)" << endl;
    cin >> level;
    if(level!=1 && level!=2 && level!=3){
        throw std::domain_error("Wrong parameter!");
    }

    //----------------------------------------------------------------------------
    //Applying the matrix on every pixel in the image, except a 2 pixel wide range
    //at the edges of the image.

    float a=0.0;
    for(int i=2; i<row-2; i++){
        for(int j=2; j<column-2; j++){
            for(int k=0; k<5; k++){
                for(int l=0; l<5; l++){
                    if(level==1){
                        a=a+vect_temp[i+k-2][j+l-2]*Gaussian1[k][l];
                    }
                    else if(level==2){
                        a=a+vect_temp[i+k-2][j+l-2]*Gaussian2[k][l];
                    }
                    else if(level==3){
                        a=a+vect_temp[i+k-2][j+l-2]*Gaussian3[k][l];
                    }
                }
            }
            vect[i][j]=(int)a;
            a=0.0;
        }
    }
    string output=image_name+"_blur"+to_string(level)+".pgm";
    save(output, row, column, max_intensity, vect);
    cout << "The modified image has been saved with a name: "<< image_name << "_blur" << level << endl;
}

void Convolve::edge(const string image_name, const int row, const int column, const int max_intensity, vector <vector<int> >& vect){

    vector <vector<int> > vect_temp(row, vector<int>(column, 0));
    for(int i=0; i<row; i++){
        for(int j=0; j<column; j++){
            vect_temp[i][j]=vect[i][j];
        }
    }

    //-----------------------------------------
    //Using Sobel-algorithm.

    float Edge_x[3][3]=    {                    // Sobel-operator1, convoluted form.
                            {-1.0, 0.0, 1.0},
                            {-2.0, 0.0, 2.0},
                            {-1.0, 0.0, 1.0}
                            };

    float Edge_y[3][3]=    {                    // Sobel-operator2, convoluted form.
                            {1.0, 2.0, 1.0},
                            {0.0, 0.0, 0.0},
                            {-1.0, -2.0, -1.0}
                            };

    float a1=0.0;
    float a2=0.0;
    float G=0;
    float G_max=0;
    for(int i=1; i<row-1; i++){
        for(int j=1; j<column-1; j++){
            for(int k=0; k<3; k++){
                for(int l=0; l<3; l++){
                    a1=a1+vect_temp[i+k-1][j+l-1]*Edge_x[k][l];
                    a2=a2+vect_temp[i+k-1][j+l-1]*Edge_y[k][l];
                }
            }
            G=sqrt(a1*a1+a2*a2);
            if(G>G_max){
                G_max=G;
            }
            vect[i][j]=(int)((G/G_max)*max_intensity);  //Adjusting values between 0 and max_intensity.
            a1=0.0;
            a2=0.0;
            G=0.0;
        }
    }
    string output=image_name+"_edges.pgm";
    save(output, row, column, max_intensity, vect);
    cout << "The modified image has been saved with a name: "<< image_name << "_edges" << endl;
}

void Convolve::sharpen(const string image_name, const int row, const int column, const int max_intensity, vector <vector<int> >& vect){

    vector <vector<int> > vect_temp1(row, vector<int>(column, 0));
    vector <vector<int> > vect_temp2(row, vector<int>(column, 0));
    vector <vector<int> > vect_edge(row, vector<int>(column, 0));

    for(int i=0; i<row; i++){
        for(int j=0; j<column; j++){
            vect_temp1[i][j]=vect[i][j];
            vect_temp2[i][j]=vect[i][j];
        }
    }

    //-------------------------------------
    //Using Sobel-algorithm, same as above.

    float Edge_x[3][3]=    {
                            {-1.0, 0.0, 1.0},
                            {-2.0, 0.0, 2.0},
                            {-1.0, 0.0, 1.0}
                            };

    float Edge_y[3][3]=    {
                            {1.0, 2.0, 1.0},
                            {0.0, 0.0, 0.0},
                            {-1.0, -2.0, -1.0}
                            };

    float a1=0.0;
    float a2=0.0;
    float G=0;
    float G_max=0;
    for(int i=1; i<row-1; i++){
        for(int j=1; j<column-1; j++){
            for(int k=0; k<3; k++){
                for(int l=0; l<3; l++){
                    a1=a1+vect_temp1[i+k-1][j+l-1]*Edge_x[k][l];
                    a2=a2+vect_temp1[i+k-1][j+l-1]*Edge_y[k][l];
                }
            }
            G=sqrt(a1*a1+a2*a2);
            if(G>G_max){
                G_max=G;
            }
            vect_edge[i][j]=(int)((G/G_max)*max_intensity);
            a1=0.0;
            a2=0.0;
            G=0.0;
        }
    }

    //-----------------------------------------------------------------------------------------------------
    //The comparison always done with the pixels of the original picture, then we modify the temp_vectors,
    //then finally the image vector gets all the values of the modified temp_vector.

    //Whenever an "edge" pixel is found (a pixel with higher intensity), its intensity will be enhanced further,
    //since it marks a brighter edge on the original image. At the same time we also inspect its neighbour
    //pixels, and if a darker pixel is found, its intensity will be reduced further, so all in all, the
    //edges on the image will appear more distinct.
    //The numbers used below are a bit arbitrary, but it works quite well.

    for(int i=1; i<row-1; i++){
        for(int j=1; j<column-1; j++){
            if(vect_edge[i][j]>150 && vect[i][j]*1.2<max_intensity){
                vect_temp2[i][j]=vect_temp2[i][j]*1.2;
                for(int k=0; k<3; k++){
                    for(int l=0; l<3; l++){
                        if(vect[i+k-1][j+l-1]<0.9*vect[i][j]){
                            vect_temp2[i+k-1][j+l-1]=0.8*vect_temp2[i+k-1][j+l-1];
                        }
                    }
                }
            }
            else if(vect_edge[i][j]>150 && vect[i][j]*1.2>max_intensity){
                vect_temp2[i][j]=max_intensity;
                for(int k=0; k<3; k++){
                    for(int l=0; l<3; l++){
                        if(vect[i+k-1][j+l-1]<0.9*vect[i][j]){
                            vect_temp2[i+k-1][j+l-1]=0.8*vect_temp2[i+k-1][j+l-1];
                        }
                    }
                }
            }
        }
    }
    vect.swap(vect_temp2);

    string output=image_name+"_sharpened.pgm";
    save(output, row, column, max_intensity, vect);
    cout << "The modified image has been saved with a name: "<< image_name << "_sharpened" << endl;
}
