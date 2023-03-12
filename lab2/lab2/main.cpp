// Задані дійсні додатні числа a, b, c, x, y. З‘ясувати чи пройде цеглина з ребрами a, b, c в прямокутний отвір із cторонами x та y. Просувати цеглину у отвір дозволяється тільки так, щоб кожне із ребер було паралельне або перпендикулярне кожній із сторін отвору.

#include <iostream>

using namespace std;

void brickIsGood(double width, double height, double length, double x, double y)
{
    if (width < x && (height < y || length < y))
        cout << "Yes, the brick will pass" << endl;
    else if (width < y && (height < x || length < x))
        cout << "Yes, the brick will pass" << endl;
    else if ((height < x && length < y) || (height < y && length < x))
        cout << "Yes, the brick will pass" << endl;
    else
        cout << "No, the brick will not pass" << endl;
}

int main()
{
    double a; //ініціалізовуємо змінну та присвоюємо їй розмір ширини цеглини
    cout << "a = ";
    cin >> a; //8
    
    double b; //ініціалізовуємо змінну та присвоюємо їй розмір висоти цеглини
    cout << "b = ";
    cin >> b; //10
    
    double c; //ініціалізовуємо змінну та присвоюємо їй розмір довжини цеглини
    cout << "c = ";
    cin >> c; //10
    
    double x = 11, y = 9; //ініціалізовуємо змінні для позначення отвору
    cout << "x = ";
    cin >> x; //11
    
    cout << "y = ";
    cin >> y; //9
    
    brickIsGood(a, b, c, x, y);

    return 0;
}
