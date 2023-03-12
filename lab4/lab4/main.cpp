#include <iostream>
#include <cmath>

using namespace std;

double result(int n)
{
    double sum = 0; // Оголошення суми
    
    for (int k = 1; k <= n; k++)
    {
        sum += (1 / (k * (pow(2 * k + 1, 2)))); // Обчислюємо за заданою формулою суму
    }
    
    return sum; //повертаємо результат виконання функції
}

int main()
{
    int n; //оголошення змінної натурального числа
    cout << "n = ";
    cin >> n;

    cout << "Результат: " << result(n) << endl;

    return 0;
}

