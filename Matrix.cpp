#include <bits/stdc++.h>
#include "Matrix.h"
using namespace std;
void Matrix::set_matrix(vector<vector<double>> A)
{
    vector<double> v;
    for (int i = 0; i < A.size(); i++)
    {
        for (int j = 0; j < A[i].size(); j++)
        {
            v.push_back(A[i][j]);
        }
        this->mm_matrix.push_back(v);
        v.clear();
    }
    this->m = mm_matrix.size();
    this->n = mm_matrix[0].size();
}

void Matrix::display_matrix()
{
    for (int i = 0; i < mm_matrix.size(); i++)
    {
        for (int j = 0; j < mm_matrix[i].size(); j++)
            cout << mm_matrix[i][j] << " ";
        cout << endl;
    }
}

Matrix Matrix::operator+(Matrix M)
{
    if (this->m == M.m && this->n == M.n)
    {
        Matrix sum;
        for (int i = 0; i < M.mm_matrix.size(); i++)
        {
            vector<double> temp;
            for (int j = 0; j < M.mm_matrix[i].size(); j++)
            {
                temp.push_back(this->mm_matrix[i][j] + M.mm_matrix[i][j]);
            }
            sum.mm_matrix.push_back(temp);
        }
        return sum;
    }
}

Matrix Matrix::operator-(Matrix M)
{
    Matrix diff;
    for (int i = 0; i < M.mm_matrix.size(); i++)
    {
        vector<double> temp;
        for (int j = 0; j < M.mm_matrix[i].size(); j++)
        {
            temp.push_back(this->mm_matrix[i][j] - M.mm_matrix[i][j]);
        }
        diff.mm_matrix.push_back(temp);
    }
    return diff;
}

Matrix Matrix::operator*(Matrix M)
{
    Matrix product;
    for (int i = 0; i < this->mm_matrix.size(); i++)
    {
        vector<double> v;
        for (int j = 0; j < M.mm_matrix[0].size(); j++)
        {
            double d = 0;
            for (int p = 0; p < M.mm_matrix.size(); p++)
            {
                d += this->mm_matrix[i][p] * M.mm_matrix[p][j];
            }
            v.push_back(d);
        }
        product.mm_matrix.push_back(v);
    }
    return product;
}

Matrix Matrix::operator*(double n)
{
    Matrix matrix;
    for (int i = 0; i < this->mm_matrix.size(); i++)
    {
        vector<double> temp;
        for (int j = 0; j < this->mm_matrix[0].size(); j++)
        {
            temp.push_back(n * mm_matrix[i][j]);
        }
        matrix.mm_matrix.push_back(temp);
    }
    return matrix;
}

Matrix Matrix::transpose()
{
    Matrix transpose;
    for (int j = 0; j < this->mm_matrix[0].size(); j++)
    {
        vector<double> temp;
        for (int i = 0; i < this->mm_matrix.size(); i++)
        {
            temp.push_back(this->mm_matrix[i][j]);
        }
        transpose.mm_matrix.push_back(temp);
    }
    return transpose;
}

Matrix Matrix::square()
{
    Matrix square;
    for (int i = 0; i < mm_matrix.size(); i++)
    {
        vector<double> temp;
        for (int j = 0; j < mm_matrix[0].size(); j++)
        {
            temp.push_back(pow(mm_matrix[i][j], 2));
        }
        square.mm_matrix.push_back(temp);
    }
    return square;
}

double Matrix::sum()
{
    double sum;
    for (int i = 0; i < mm_matrix.size(); i++)
    {
        for (int j = 0; j < mm_matrix[0].size(); j++)
        {
            sum += mm_matrix[i][j];
        }
    }
    return sum;
}