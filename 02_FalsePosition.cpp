#include <iostream>
using namespace std;
#define endl "\n"
#define ll long long

double f(double x) { return x * x - x - 2; }

int main() {
    double x1, x2, x0, E;
    int maximumIterations = 20;

    cout << "Enter 2 initial guesses [x1, x2]: ";
    cin >> x1 >> x2;
    cout << "Enter tolerance: ";
    cin >> E;

    if (f(x1) * f(x2) > 0) {
        cout << "Root doesn't lie in this interval!" << endl;
        exit(0);
    }

    cout << endl;
    for (int i = 0; i < maximumIterations; i++) {
        x0 = x2 - (f(x2) * (x2 - x1)) / (f(x2) - f(x1));

        cout << "After " << i + 1 << " iterations, Approximate Root(x0): " << x0
             << endl;

        if (abs(f(x0)) < E) {
            cout << "\nThe Final Root: " << x0 << endl;
            break;
        }
        if (f(x1) * f(x0) < 0) {
            x2 = x0;
        } else {
            x1 = x0;
        }
    }
    return 0;
}