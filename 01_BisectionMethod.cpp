#include <iostream>
using namespace std;
#define endl "\n"
#define ll long long

double f(double x) { return x * x - 4 * x - 10; }

int main() {
    double x1, x2, x0, E;
    int i = 1;
    cout << "Enter 2 initial guesses [x1, x2]: ";
    cin >> x1 >> x2;
    cout << "Enter tolerance: ";
    cin >> E;

    if (f(x1) * f(x2) > 0) {
        cout << "Root doesn't lie in this interval!" << endl;
        exit(0);
    }

    while (abs((x2 - x1) / x2) > E) {
        x0 = (x1 + x2) / 2;
        cout << "After " << i << " iterations, Root(x0): " << x0 << endl;
        i++;

        if (f(x0) * f(x1) < 0) {
            x2 = x0;
        } else {
            x1 = x0;
        }
    }
    cout << "\nThe final root: " << (x1 + x2) / 2 << endl;
    return 0;
}