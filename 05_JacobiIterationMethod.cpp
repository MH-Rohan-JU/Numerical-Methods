#include <bits/stdc++.h>
using namespace std;

double f1(double x2, double x3) { return (5 - x2 - x3) / 2; }

double f2(double x1, double x3) { return (15 - 3 * x1 - 2 * x3) / 5; }

double f3(double x1, double x2) { return (8 - 2 * x1 - x2) / 4; }

int main() {
    double x1 = 0, x2 = 0, x3 = 0;
    double x1_n, x2_n, x3_n;
    double tolerance = 1e-6;
    int maxIter = 10;
    int i = 0;

    cout << endl
         << right << setw(48) << "<---- Jacobi Iteration Method ---->" << endl;
    cout << "-------------------------------------------------------------"
         << endl;
    cout << right << setw(10) << "Iteration" << setw(15) << "x1" << setw(15)
         << "x2" << setw(15) << "x3" << endl;
    cout << "-------------------------------------------------------------"
         << endl;

    while (i < maxIter) {
        x1_n = f1(x2, x3);
        x2_n = f2(x1, x3);
        x3_n = f3(x1, x2);

        cout << right << setw(10) << i + 1 << setw(15) << fixed
             << setprecision(5) << x1_n << setw(15) << fixed << setprecision(5)
             << x2_n << setw(15) << fixed << setprecision(5) << x3_n << endl;

        if (fabs(x1_n - x1) < tolerance && fabs(x2_n - x2) < tolerance &&
            fabs(x3_n - x3) < tolerance) {
            cout << endl << "Solution found: " << endl;
            cout << "x1 = " << fixed << setprecision(5) << x1_n << endl;
            cout << "x2 = " << fixed << setprecision(5) << x2_n << endl;
            cout << "x3 = " << fixed << setprecision(5) << x3_n << endl;
            break;
        }

        x1 = x1_n;
        x2 = x2_n;
        x3 = x3_n;

        i++;
    }

    if (i == maxIter) {
        cout << endl
             << "Maximum iterations reached without finding the exact solution."
             << endl;
        cout << "Last approximation:" << endl;
        cout << "x1 = " << fixed << setprecision(5) << x1_n << endl;
        cout << "x2 = " << fixed << setprecision(5) << x2_n << endl;
        cout << "x3 = " << fixed << setprecision(5) << x3_n << endl;
    }

    return 0;
}
