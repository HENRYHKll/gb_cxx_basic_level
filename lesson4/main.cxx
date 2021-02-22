#include <iostream>
//Написать программу, проверяющую что сумма двух чисел лежит в пределах от 10 до
// 20 (включительно), если да – вывести true, в противном случае – false;

void task1()
{
    int a = 0, b = 0;
    std::cout << "Checking the sum of numbers a + b" << std::endl;
    std::cout << "Enter a" << std::endl;
    std::cin >> a;
    std::cout << "Enter b" << std::endl;
    std::cin >> b;
    if (((a + b) >= 10) && ((a + b) <= 20))
    {
        std::cout << "numbers ranges from 10 to 20 true" << std::endl;
    }
    else
    {
        std::cout << "numbers ranges from 10 to 20 false" << std::endl;
    }
}

//Написать программу, проверяющую, является ли некоторое число - натуральным
//простым. Простое число - это число, которое делится без остатка только на
//единицу и себя само.

void task2()
{
    int num = 0;
    std::cout << "check if prime number" << std::endl;
    std::cin >> num;
    for (int i = 2; i < num; i++)
    {
        if (num % i == 0)
        {
            num = -1;
            std::cout << "No" << std::endl;
            break;
        }
    }
    if (num > 0)
        std::cout << "Yes" << std::endl;
}

//Написать программу, выводящую на экран “истину”, если две целочисленные
//константы, объявленные в её начале либо равны десяти сами по себе, либо их
//сумма равна десяти.

void task3()
{
    int a = 10, b = 0;
    if ((a == 10 && b == 10) || (a + b == 10))
    {
        std::cout << "True" << std::endl;
    }
}

//* Написать программу, которая определяет является ли год високосным. Каждый
// 4-й год является високосным, кроме каждого 100-го, при этом каждый 400-й –
//високосный. Для проверки работы вывести результаты работы программы в консоль

void task4()
{
    int year = 0;
    std::cout << "Enter the year to check" << std::endl;
    std::cin >> year;
    if ((year % 4 == 0) || (year % 100 == 0) || (year % 400 == 0))
    {
        std::cout << "leap year" << std::endl;
    }
    else
    {
        std::cout << "not a leap year" << std::endl;
    }
}

int main()
{
    task1();
    task2();
    task3();
    task4();
}
