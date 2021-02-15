#include <algorithm>
#include <iostream>
//Задать целочисленный массив, состоящий из элементов 0 и 1. Например: [ 1, 1,
// 0, 0, 1, 0, 1, 1, 0, 0 ]. Написать функцию, заменяющую в принятом массиве 0
// на 1, 1 на 0;
void arry_di(int* arr, int size)
{
    //** Написать функцию из первого задания так, чтобы она работала с
    //аргументом переменной длины.

    for (int i = 0; i < size; i++)
    {
        arr[i] = (arr[i] == 0) ? 1 : 0;
    }
}

void view_arr(int* arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << ' ';
    }
    std::cout << std::endl;
}

void task1()
{
    const int arr_size      = 10;
    int       arr[arr_size] = { 1, 1, 0, 0, 1, 0, 1, 1, 0, 0 };
    std::cout << "original array ";
    view_arr(arr, arr_size);
    arry_di(arr, arr_size);
    std::cout << "New array ";
    view_arr(arr, arr_size);
}

//Задать пустой целочисленный массив размером 8. Написать функцию, которая с
//помощью цикла заполнит его значениями 1 4 7 10 13 16 19 22;

void arr2_in(int* arr2, int size2)
{
    for (int i = 0; i < size2; i++)
    {
        arr2[i] = (i == 0) ? 1 : arr2[i - 1] + 3;
    }
}

void task2()
{
    const int arr_size2 = 8;
    int       arr2[arr_size2];
    arr2_in(arr2, arr_size2);
    std::cout << "view array ";
    view_arr(arr2, arr_size2);
}
//* Написать метод, в который передается не пустой одномерный целочисленный
//массив, метод должен вернуть истину если в массиве есть место, в котором сумма
//левой и правой части массива равны. Примеры: checkBalance([1, 1, 1, || 2, 1])
//→ true, checkBalance ([2, 1, 1, 2, 1]) → false, checkBalance ([10, || 1, 2, 3,
// 4]) → true. Абстрактная граница показана символами ||, эти символы в массив
// не входят.
int sum_arr(int* arr, int size, int index = 0)
{
    int sum = 0;
    if (index == 0)
    {
        for (; index <= size; index++)
        {
            sum += arr[index];
        }
    }
    else
    {
        for (; index < size; index++)
        {
            sum += arr[index];
        }
    }
    return sum;
}

bool arry_balans(int* arr, int size)
{
    for (int i = 0; i < size - 1; i++)
    {

        if (sum_arr(arr, i) == sum_arr(arr, size, i + 1))
            return true;
    }
    return false;
}

void task3()
{
    const int arr_size3 = 5;
    int       arr3[5]   = { 10, 1, 1, 2, 1 };

    std::cout << "Array balans - "
              << ((arry_balans(arr3, arr_size3) == 1) ? "true" : "false")
              << std::endl;
}

//* Написать функцию, которой на вход подаётся одномерный массив и число n
//(может быть положительным, или отрицательным), при этом метод должен
//циклически сместить все элементы массива на n позиций.

void arr_move(int* arr, int size, int setings)
{
    int cash_val = 0;
    for (int i = 0; i < size; i++)
    {
        cash_val = arr[i];
        arr[i]   = arr[i + setings];
        std::cout << arr[i] << ' ' << std::endl;
    }
}

void arr_algorithm(int* arr, int size, int setings)
{
    std::rotate(arr, arr + setings, arr + size);
    view_arr(arr, size);
}
void task4()
{ // не до конца сделал
    const int arr_size4 = 5;
    int       arr4[5] = { 1, 2, 3, 4, 5 }, move = 0;
    std::cout << "Source array ";
    view_arr(arr4, arr_size4);
    std::cout << "Move to ";
    std::cin >> move;
    if (move > 0)
    {
        arr_algorithm(arr4, arr_size4, move);
    }
    else if (move < 0)
    {
        arr_move(arr4, arr_size4, move);
    }
    else
    {
        std::cout << "Move array ";
        view_arr(arr4, arr_size4);
    }
}

int main()
{

    task1();
    task2();
    task3();
    task4();
}
