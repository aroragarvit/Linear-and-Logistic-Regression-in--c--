#include <bits/stdc++.h>
#include "Matrix.h"
#include "LogisticRegression.h"
using namespace std;

double LogisticRegression::sigmoid(double n)
{
    double x;
    return x = (1 / (1 + (exp(-1 * n))));
}

//TODO: Fix 0 into log
double LogisticRegression::error(Matrix hx, Matrix Y)
{
    double sum = 0;
    for (double i = 0; i < hx.mm_matrix.size(); i++)
    {
        if (hx.mm_matrix[i][0] == 1)
            hx.mm_matrix[i][0] = 0.99;
        sum += Y.mm_matrix[i][0] * log(hx.mm_matrix[i][0]) + (1 - Y.mm_matrix[i][0]) * (log(1 - hx.mm_matrix[i][0]));
    }

    return sum;
}

void LogisticRegression::gradient_decent(Matrix X, Matrix hx, Matrix Y, Matrix *theta, double alpha)
{
    *theta = *theta - (X.transpose() * (hx - Y)) * (alpha / theta->mm_matrix.size());
}

/*Matrix LogisticRegression::initialize_theta(double dimension)
{
    vector<vector<double>> temp;
    for (double i = 0; i < dimension; i++)
    {
        //TODO: Change 0 to random number
        vector<double> temp2 = {0};
        temp.push_back(temp2);
    }
    Matrix theta;
    theta.set_matrix(temp);
} */
Matrix LogisticRegression::initialize_theta(double n, double dimension)
{
    vector<vector<double>> temp;
    for (double i = 0; i < dimension; i++)
    {
        vector<double> temp2 = {n};
        temp.push_back(temp2);
    }
    Matrix theta;
    theta.set_matrix(temp);
    return theta;
}

void LogisticRegression::train(Matrix X, Matrix *theta, Matrix Y, double epochs, double alpha)
{
    std::cout << "Training Your Data\n";
    for (double e = 0; e < epochs; e++)
    {
        std::cout << "Epoch " << e + 1 << "\n";
        Matrix gx = X * (*theta);
        Matrix hx; //hx = sigmoid(gx)
        vector<vector<double>> hx_vector;
        for (double i = 0; i < gx.mm_matrix.size(); i++)
        {
            vector<double> temp;
            temp.push_back(sigmoid(gx.mm_matrix[i][0]));
            hx_vector.push_back(temp);
        }
        hx.set_matrix(hx_vector);
        gradient_decent(X, hx, Y, theta, alpha);
        test(X, theta, Y);
    }
}

double LogisticRegression::predict(Matrix x, Matrix *theta)
{
    Matrix gx = x * (*theta);
    return sigmoid(gx.mm_matrix[0][0]) >= 0.5 ? 1 : 0;
}

void LogisticRegression::test(Matrix X, Matrix *theta, Matrix Y)
{
    double accuracy = 0;
    double correct = 0;
    for (double i = 0; i < X.mm_matrix.size(); i++)
    {
        Matrix x;
        x.set_matrix({X.mm_matrix[i]}); //Sending single X as input
        double output = predict(x, theta);
        if (output == Y.mm_matrix[i][0])
            correct++;
    }
    accuracy = (correct / X.mm_matrix.size()) * 100;
    std::cout << "Accuracy is :" << accuracy << "\n";
}