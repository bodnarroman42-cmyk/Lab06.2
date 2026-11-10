#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

// Прототипи рекурсивних функцій
void Create(int* a, const int size, const int Low, const int High, int i);
void Print(int* a, const int size, int i);
int FindMinOddIndex(int* a, const int size, int i, int minVal, int minIndex, bool found);

int main()
{
    // Ініціалізація генератора випадкових чисел
    srand((unsigned)time(NULL));

    const int n = 12;
    int a[n];
    int Low = -10;
    int High = 35;
    int minOddIndex;

    // Формування масиву рекурсивним способом
    Create(a, n, Low, High, 0);

    // Виведення створеного масиву у вигляді рядка рекурсивним способом
    cout << "Initial array:" << endl;
    Print(a, n, 0);

    // Пошук індексу найменшого непарного елемента рекурсивним способом
    // Початкові параметри: i = 0, minVal = 0, minIndex = -1, found = false
    minOddIndex = FindMinOddIndex(a, n, 0, 0, -1, false);

    // Виведення результату виконання завдання
    if (minOddIndex != -1) {
        cout << "Index of the smallest odd element: " << minOddIndex << endl;
        cout << "Value of this element: " << a[minOddIndex] << endl;
    }
    else {
        cout << "No odd elements found in the array." << endl;
    }

    return 0;
}

// Рекурсивна функція формування масиву випадковими числами
void Create(int* a, const int size, const int Low, const int High, int i)
{
    // Генерація та запис випадкового числа у поточний елемент масиву
    a[i] = Low + rand() % (High - Low + 1);

    // Рекурсивний виклик для наступного елемента
    if (i < size - 1) {
        Create(a, size, Low, High, i + 1);
    }
}

// Рекурсивна функція виведення масиву у рядок
void Print(int* a, const int size, int i)
{
    // Виведення поточного елемента з виділенням ширини поля
    cout << setw(4) << a[i];

    // Рекурсивний виклик для наступного елемента або завершення рядка
    if (i < size - 1) {
        Print(a, size, i + 1);
    }
    else {
        cout << endl;
    }
}

// Рекурсивна функція пошуку індексу найменшого непарного елемента масиву
int FindMinOddIndex(int* a, const int size, int i, int minVal, int minIndex, bool found)
{
    // Базовий випадок: якщо переглянуто весь масив
    if (i >= size) {
        return minIndex;
    }

    // Перевірка, чи є поточний елемент непарним
    if (a[i] % 2 != 0) {
        // Якщо це перший непарний елемент або він менший за попередній мінімум
        if (!found || a[i] < minVal) {
            minVal = a[i];
            minIndex = i;
            found = true;
        }
    }

    // Рекурсивний виклик для перевірки наступного елемента масиву
    return FindMinOddIndex(a, size, i + 1, minVal, minIndex, found);
}