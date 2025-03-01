#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

double f(double x) { return x * x - 3 * x + 2; }
double fd(double x) { return 2 * x - 3; }

int main() {
    double x1 = 0, E, x2;

    cout << "Enter tolerance: ";
    cin >> E;
    x2 = x1 - (f(x1) / fd(x1));

    int it = 1;
    while (abs(x2 - x1) > E) {
        cout << "Iteration " << it++ << ":" << endl;
        cout << "\t\tX1 = " << x1 << endl;
        cout << "\t\tX2 = " << x2 << endl;

        x1 = x2;
        x2 = x1 - (f(x1) / fd(x1));
        cout << endl;
    }
    cout << "The final root: " << x2 << endl;
    return 0;
}