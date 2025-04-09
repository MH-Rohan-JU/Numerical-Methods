#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;

double f1(double x2, double x3) { return (5 - x2 - x3) / 2; }

double f2(double x1, double x3) { return (15 - 3 * x1 - 2 * x3) / 5; }

double f3(double x1, double x2) { return (8 - 2 * x1 - x2) / 4; }

int main() {
    double x1 = 0, x2 = 0, x3 = 0;
    double x1_new, x2_new, x3_new;
    double tol = 1e-6;
    int maxIt = 10;
    int i = 0;

    cout << "-------------------------------------------------------------"
         << endl;
    cout << right << setw(10) << "Iteration" << setw(15) << "x1" << setw(15)
         << "x2" << setw(15) << "x3" << endl;
    cout << "-------------------------------------------------------------"
         << endl;

    while (i < maxIt) {
        x1_new = f1(x2, x3);
        x2_new = f2(x1_new, x3);
        x3_new = f3(x1_new, x2_new);

        cout << right << setw(10) << i + 1 << setw(15) << fixed
             << setprecision(5) << x1_new << setw(15) << fixed
             << setprecision(5) << x2_new << setw(15) << fixed
             << setprecision(5) << x3_new << endl;

        if (fabs(x1_new - x1) < tol && fabs(x2_new - x2) < tol &&
            fabs(x3_new - x3) < tol) {
            cout << endl << "Solution found: " << endl;
            cout << "x1 = " << fixed << setprecision(5) << x1_new << endl;
            cout << "x2 = " << fixed << setprecision(5) << x2_new << endl;
            cout << "x3 = " << fixed << setprecision(5) << x3_new << endl;
            break;
        }

        x1 = x1_new;
        x2 = x2_new;
        x3 = x3_new;

        i++;
    }

    if (i == maxIt) {
        cout << endl;
        cout << "Approximate solution:" << endl;
        cout << "x1 = " << fixed << setprecision(5) << x1_new << endl;
        cout << "x2 = " << fixed << setprecision(5) << x2_new << endl;
        cout << "x3 = " << fixed << setprecision(5) << x3_new << endl;
    }

    return 0;
}
