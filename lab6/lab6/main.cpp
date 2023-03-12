#include <iostream>
#include <ctime>
#include <cmath>

using namespace std;

double calcArea(double *A, double *B, double *C);

int main() {
    //ініціалізація сторін трьох трикутників
    double A1 = 13, B1 = 14, C1 = 19;
    double A2 = 28, B2 = 23, C2 = 27;
    double A3 = 35, B3 = 34, C3 = 33;

    //Обчислюємо площі трьох трикутників за допомогою функцій
    double area1 = calcArea(&A1, &B1, &C1);
    cout << "Area of the first triangle = " << area1 << endl;
    
    double area2 = calcArea(&A2, &B2, &C2);
    cout << "Area of the second triangle = " << area2 << endl;
    
    double area3 = calcArea(&A3, &B3, &C3);
    cout << "Area of the third triangle = " << area3 << endl;

    cout << endl;
    //Визначаємо, який трикутник має найбільшу площу
    if (area1 > area2 && area1 > area3) {
        cout << "Triangle 1 has the largest area." << endl;
    } else if (area2 > area1 && area2 > area3) {
        cout << "Triangle 2 has the largest area." << endl;
    } else if (area3 > area1 && area3 > area2) {
        cout << "Triangle 3 has the largest area." << endl;
    } else {
        cout << "All triangles have the same area." << endl;
    }
}

double calcArea(double *A, double *B, double *C) {
    double p = ((*A) + (*B) + (*C)) / 2; // Знаходження півпериметра для подальших розрахунків площі
    
    return sqrt(p * (p - (*A)) * (p - (*B)) * (p - (*C))); // використання формули Герона
}



//
//double A1, B1, C1;
//cout << "Введіть довжини трьох сторін першого трикутника: " << endl;
//cin >> A1;
//cin >> B1;
//cin >> C1;
//
//double A2, B2, C2;
//cout << "Введіть довжини трьох сторін другого трикутника: " << endl;
//cin >> A2;
//cin >> B2;
//cin >> C2;
//
//double A3, B3, C3;
//cout << "Введіть довжини трьох сторін третього трикутника: " << endl;
//cin >> A3;
//cin >> B3;
//cin >> C3;
