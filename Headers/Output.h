#ifndef OUTPUT_H_INCLUDED
#define OUTPUT_H_INCLUDED

using namespace std;

//A function for saving the modified images.
void save(string& filename, int& row, int& column, int& max_intensity, vector <vector<int> >& vect);

//Just an auxiliary function, used at writing output file names. It converts an int type to a string.
string intToString(int t);

#endif // OUTPUT_H_INCLUDED
