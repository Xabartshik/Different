//#include <iostream>
//#include <cmath>
//
//using namespace std;
//
//double f(double x) {
//    return log(x);
//}
//
//int main() {
//    const int M1 = 1;
//    const int M2 = 4;
//    const double xo = 2;
//    const double eps = 0.001;
//
//    cout << "По первой формуле верхний порог для h = " << sqrt(6 * eps / M1) << ". Введите желаемое h..." << endl;
//    double h1;
//    cin >> h1;
//    double diff1 = (f(xo + h1) - f(xo - h1)) / (2 * h1);
//    cout << "Производная, вычисленная по первой формуле: " << diff1 << endl;
//
//    cout << "По второй формуле верхний порог для h = " << pow(30 * eps / M2, 0.25) << ". Введите желаемое h..." << endl;
//    double h2;
//    cin >> h2;
//    double diff2 = (f(xo - 2 * h2) - 8 * f(xo - h2) + 8 * f(xo + h2) - f(xo + 2 * h2)) / (12 * h2);
//    cout << "Производная, вычисленная по второй формуле: " << diff2 << endl;
//
//    return 0;
//} 
//\t -- табуляция
#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>

using namespace std;

const double h = 0.7; // Размер шага
const int n = 7;     // Число точек

int main() {
    // Массивы для чисел
    vector<double> x(n);
    vector<vector<double>>y(n+1, vector<double>(n+1, 0));
    y[0][0] = 1.85107;
    y[1][0] = 1.03027;
    y[2][0] = 0.11931;
    y[3][0] = -0.87462;
    y[4][0] = -1.94582;
    y[5][0] = -3.08963;
    y[6][0] = -4.30214;

    //Заполнение Х
    for (int i = 0; i < n; ++i) {
        x[i] = 3.2 + h * i;
    }

    // Вычисление производной используя таблицу
    for (int j = 1; j < n; ++j) {
        for (int i = 0; i <= n - j; ++i) {
            y[i][j] = y[i + 1][j - 1] - y[i][j - 1];
        }
    }

    // Вывод значений таблицы
    cout << setw(5) << "k" << setw(10) << "x" << setw(20) << "y(x)" << endl;
    for (int i = 0; i < n; ++i) {
        cout << setw(5) << i << setw(10) << x[i] << setw(20) << y[i][0] << endl;
    }

    // Вывод разностей
    cout << endl;
    for (int j = 1; j < n; ++j) {
        cout << setw(5) << "D" << j << ":";
        for (int i = 0; i < n - j; ++i) {
            cout << setw(20) << y[i][j];
        }
        cout << endl;
    }

    //Вычисление производных 
    double y_xo = 0;
    double d = -1;
    double error = 0;
    double delta;

    for (int j = 1; j < n - 1; ++j) {
        d *= -1;
        y_xo += d * y[0][j] / (j * h);
        delta = abs(y[0][j + 1] / ((j + 1) * h));
        // Вывод производных и ошибки 
        cout << "y'(" << x[0] << ") = " << y_xo << ", погрешность: " << delta << endl; 
    }

    return 0;
}