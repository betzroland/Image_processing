#ifndef OUTPUT_H_INCLUDED
#define OUTPUT_H_INCLUDED

using namespace std;

//A function for saving the modified images.
void save(const string output_filename, const int row, const int column, const int max_intensity, vector <vector<int> >& vect);

#endif // OUTPUT_H_INCLUDED
