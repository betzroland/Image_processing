#ifndef READ_IN_H_INCLUDED
#define READ_IN_H_INCLUDED

using namespace std;

class Image{
public:
    int column, row, max_intensity;
    string image_name;
    vector <vector<int> > vect;

    void load();

    void save();
};

#endif // READ_IN_H_INCLUDED
