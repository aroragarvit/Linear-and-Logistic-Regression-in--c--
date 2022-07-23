#ifndef MATRIX_H
#define MATRIX_H

class Matrix
{
    public:
        int m; //rows
        int n; //columns
        std::vector<std::vector<double>> mm_matrix;
        void set_matrix(std::vector<std::vector<double>> A);
        void display_matrix(); // Print the matrix
        Matrix operator+(Matrix M); //Add two matrices
        Matrix operator-(Matrix M); //Subtract two matrices
        Matrix operator*(Matrix M); //Multiply two matrices
        Matrix operator*(double n); //Multiply with scaler
        Matrix transpose(); //Transpose the matrix
        Matrix square(); //Square the matrix
        double sum(); //Get sum of the matrix
        //TODO: Implement seprate_colums()
};

#endif
