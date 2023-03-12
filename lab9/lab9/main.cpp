#include <iostream>
#include <string>

using namespace std;

// Прототипи
int checkCondition (string input); // Перевірка умови
int getSum (string input); // Розрахунок суми

int main()
{
    string input; // Оголошуємо вхідний рядок
    cout << "Введіть рядок цифр з пробілами: ";
    getline(cin, input); // Запис вхідного рядка у консолі
    
    if (checkCondition(input))
        cout << "Sum: " << getSum (input) << endl; // Виведення результата
    else
        cout << "Error!" << endl; // Виведення результата
    
}

int getSum (string input)
{
    int sum = 0; // Оголошуємо допоміжну змінну sum та ініціалізуємо її нулем
    size_t pos = input.find_first_of("0123456789"); // Знаходимо позицію першої цифри у вхідному рядку
    
    while (pos != -1) // Перебираємо вхідний рядок і знаходимо суму чисел ((-1) - це як неіснуюча позиція)
    {
        size_t nextSpacePos = input.find_first_of(" ", pos); // Знаходимо позицію наступного пропуску після першої цифри
        
        string word = input.substr(pos, nextSpacePos - pos); // Витягуємо слово між позиціями першої цифри та наступного пропуску
        
        sum += stoi(word); // Перетворюємо слово в ціле число і додаємо його до суми
        
        pos = input.find_first_of("0123456789", nextSpacePos); // Знаходимо позицію наступної цифри
    }
    
    return sum; // Повертаємо суму (результат)
}

int checkCondition (string input) {
    for (int i = 0; i < input.size(); i++) // Цикл, що проходиться по довжині рядка
    {
        if (!(isnumber(input[i]) || input[i] == ' ')) // Перевірка, щоб рядок містив лише цифри та пробіли
            return 0;
    }
    return 1;
}
