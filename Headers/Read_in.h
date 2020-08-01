#ifndef READ_IN_H_INCLUDED
#define READ_IN_H_INCLUDED

using namespace std;

class Read_in{
public:
    int column, row, max_intensity;
    string header, data;
    string image_name;
    vector <vector<int> > vect;

    void load();
};

#endif // READ_IN_H_INCLUDED
