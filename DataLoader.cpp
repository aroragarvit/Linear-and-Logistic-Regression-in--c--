#include <bits/stdc++.h>
#include "Matrix.h"
#include "DataLoader.h"
using namespace std;

Matrix DataLoader::load_csv(string filename)
{
    Matrix data_matrix;
    vector<double> columns_of_a_row_of_matrix;
    int totalcolumns = 0;
    int row = 0;
    int column = 0;
    string s, p;
    ifstream inputdata;
    inputdata.open(filename);
    inputdata.seekg(0);
    while (!inputdata.eof())
    {
        while (getline(inputdata, s)) 
        {
            row++;
            stringstream x(s);
            column = 0;
            while (getline(x, p, ','))
            {
                column++;
                columns_of_a_row_of_matrix.push_back(stoi(p));
            }
            totalcolumns = column;
            data_matrix.mm_matrix.push_back(columns_of_a_row_of_matrix);
            columns_of_a_row_of_matrix.clear();
        }
    }
    data_matrix.n = row;
    data_matrix.m = totalcolumns;
    return data_matrix;
}