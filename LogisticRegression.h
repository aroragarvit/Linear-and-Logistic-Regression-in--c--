#ifndef LOGISTIC_REGRESSION_H
#define LOGISTIC_REGRESSION_H
class LogisticRegression
{
private:
    static double sigmoid(double n);
    static double error(Matrix hx, Matrix Y);
    static void gradient_decent(Matrix X, Matrix hx, Matrix Y, Matrix *theta, double alpha);

public:
    static Matrix initialize_theta(double dimension);                                  // initialize theta with Random Number (TO BE IMPLEMENTED)
    static Matrix initialize_theta(double n, double dimension);                        // initialize the theta with n
    static void train(Matrix X, Matrix *theta, Matrix Y, double epochs, double alpha); //train the data
    static double predict(Matrix x, Matrix *theta);                                 //Predict for a single x;
    static void test(Matrix X, Matrix *theta, Matrix Y);                            //Test Accuracy
};
#endif