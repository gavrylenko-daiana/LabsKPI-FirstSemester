#include <iostream>
#include <stdlib.h> //rand() srand()
#include <ctime> //time(0)

using namespace std;

void findMax(int y, int diff, int size, int direction, int** matrix, int &max);
int getMax(int** A, int x, int y, int size);
void print(int** arr, int size);
int** createMatrix(int size);
void fillMatrix(int** &A, int size);
void calculateMatrix(int** A, int** &B, int size);

int main() {
    int size; //ініціалізація змінної, що позначає розмір квадратної матриці
    cout << "Запишіть розмір квадратної матриці: ";
    cin >> size;
    int** A = createMatrix(size); //ініціалізація головного динамічного двовимірного масива
    int** B = createMatrix(size); //ініціалізація динамічного двовимірного масива, що буде результатом
    
    fillMatrix(A, size);
    calculateMatrix(A, B, size);

    cout << "\nМатриця A\n";
    print(A, size);
    
    cout << endl;
    
    cout << "Матриця B\n";
    print(B, size);
    
    //видалення динамічних масивів
    delete[] A;
    delete[] B;
    
    return 0;
}

void findMax(int y, int diff, int size, int direction, int** matrix, int &max)
{
    for (int i = y + diff; i < size; i++)
    {
        if (max < matrix[i][direction])
        {
            max = matrix[i][direction];
        }
    }
}

int getMax(int** A, int x, int y, int size)
{
    int start = x - (size - y - 1); //ініціалізація допоміжної змінної
    if (start < 0) start = 0; //знаходження найлівішої колонки через яку проходить діагональ
    int end = size - y - 1 + x; //ініціалізація допоміжної змінної
    if (end > size - 1) end = size - 1; //знаходження найправішої колонки через яку проходить діагональ
    int max = A[y][x]; //оголошуємо змінну для запису максимального числа і присвоюємо взятий елемент із матриці А
    int diff = 0; //оголошуємо змінну щоб розуміти яке значення брати першим у колонці для визначення максимального

    for (int left = x; left >= start; left--) //йдемо від поточного елемента вліво
    {
        findMax(y, diff, size, left, A, max);
        diff++;
    }

    diff = 0;
    for (int right = x; right <= end; right++) //тут робимо те ж саме, що і зверху, тільки вправо
    {
        findMax(y, diff, size, right, A, max);
        diff++;
    }
    
    cout << "Максимальне значення = " << max << endl;
    return max; //повертаємо масимальне число
}

void print(int** arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
}

int** createMatrix(int size)
{
    int** newMatrix = new int* [size]; //ініціалізація допоміжної змінної
    for (int i = 0; i < size; i++)
    {
        newMatrix[i] = new int[size]; //наповнення двовимірного масиву масивами
    }
    
    return newMatrix;
}

void fillMatrix(int** &A, int size)
{
    srand(time(NULL));
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            A[i][j] = rand()%21 - 10;
        }
    }
}

void calculateMatrix(int** A, int** &B, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            B[i][j] = getMax(A, j, i, size);
        }
    } //заповнення масиву В результатом функції getMax, що знаходить максимальне число під діагоналями, що проведені через елемент і паралельні головній та побічній
}
