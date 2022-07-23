#include <bits/stdc++.h>
#include "Matrix.h"
#include "DataLoader.h"
#include "LogisticRegression.h"
using namespace std;
int main()
{
    Matrix X, Y, X_test, Y_test;
    X = DataLoader::load_csv("train_x.csv");
    Y = DataLoader::load_csv("train_y.csv");
    X_test = DataLoader::load_csv("test_x.csv");
    Y_test = DataLoader::load_csv("test_y.csv");
    Matrix theta = LogisticRegression::initialize_theta(0.0, X.mm_matrix[0].size());
    Matrix *theta_p = &theta;
    cout << "Accuracy on Training Set Without Training\n";
    LogisticRegression::test(X_test, theta_p, Y_test);
    LogisticRegression::train(X, theta_p, Y, 100, 0.01);
    LogisticRegression::train(X, theta_p, Y, 100, 0.001);
    cout << "Accuracy on Training Set After Training\n";
    LogisticRegression::test(X_test, theta_p, Y_test);
    return 0;
};
