#include <iostream>
#include <stdlib.h> // rand() srand()
#include <ctime> // time(0)
#include <cmath>

using namespace std;

void difference (double K[], int n); // Обчислення масиву відповідно до умови задачі. Вивід результату
double* randomArr (int size); // Виділення пам'яті для масиву. Генерування масиву

int main() {
    srand(time(0));
    
    int size; // Оголошення змінної для позначення розміру динамічного масиву
    cout << "Вкажіть розмір одновимірного масиву: ";
    cin >> size;
    
    double* B = randomArr(size); // Оголошення динамічного одновимірного масиву
    
    difference (B, size); //
    
    // Видалення пам'яті
    delete[] B;
}

// Обчислення масиву відповідно до умови задачі
void difference (double K[], int n) {
    double module; // Оголошення змінної для підрахунку модуля
    double maxModule = abs(K[1] - K[0]); // Оголошення змінної найбільшого значення модуля різниці
    double minModule = abs(K[1] - K[0]); // Оголошення змінної найменшого значення модуля різниці
    
    for (int j = 0; j < n - 1; j++) {
        module = abs(K[j + 1] - K[j]);
        
        if (module > maxModule) {
            maxModule = module;
        }
        if (module < minModule) {
            minModule = module;
        }
        cout << module << "  ";
    }
    
    // Вивід результатів
    cout << "\nLargest module: " << maxModule << endl;
    cout << "Smallest module: " << minModule << endl;
}

// Генерування масиву
double* randomArr (int size) {
     double* array = new double[size] {}; // Виділення пам'яті для масиву
    
    for (int i = 0; i < size; i++)
    {
        array[i] = ((rand() / (double)RAND_MAX) * 19) - 9; // Генерація псевдо-випадкових дійсних чисел в діпазоні від -10 до 10
        array[i] = round(array[i] * 10) / 10; // Округлення чисел до одного значення після крапки
        cout << array[i] << "  "; // Вивід кожного елемента масива
    }
    cout << endl;
    
    return array; // Повертаємо відповідний масив в головну функцію
}
