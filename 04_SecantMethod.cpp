#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

double f(double x) { return x * x - 4 * x - 10; }

int main() {
    double x1, x2, x3, E;
    cout << "Enter 2 initial guesses [x1, x2]: ";
    cin >> x1 >> x2;
    cout << "Enter Tolerance: ";
    cin >> E;

    x3 = x2 - f(x2) * (x2 - x1) / (f(x2) - f(x1));

    int it = 1;
    while (abs(x2 - x1) > E) {
        cout << "Iteration " << it++ << ":" << endl;
        cout << "\t\tX1 = " << x1 << endl;
        cout << "\t\tX2 = " << x2 << endl;
        cout << "\t\tX3 = " << x3 << endl;

        x1 = x2;
        x2 = x3;
        x3 = x2 - f(x2) * (x2 - x1) / (f(x2) - f(x1));
        cout << endl;
    }
    cout << "The final root: " << x3 << endl;
    return 0;
}