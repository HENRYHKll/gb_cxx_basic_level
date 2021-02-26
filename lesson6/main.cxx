#include <fstream>
#include <iostream>
#include <sstream>
//Написать программу, которая создаст два текстовых файла, примерно по 50-100
//символов в каждом (особого значения не имеет);
void task1()
{
    std::ofstream file;
    file.open("1.txt");
    if (file.is_open())
    {
        file << "I love the fall season\n"
                "All the bright colors that are seen in the darkness\n";
    }
    std::ofstream file2;
    file2.open("2.txt");
    if (file2.is_open())
    {
        file2 << "This truth is only accessible to the blind sighted,\n"
                 "that wander in misty dreams\n";
    }
}

//Написать функцию, «склеивающую» эти файлы, предварительно буферизуя их
//содержимое в динамически выделенный сегмент памяти нужного размера.
void task2()
{
    std::string   str;
    std::ifstream file1;
    std::ofstream fileout;
    fileout.open("done.txt");
    file1.open("1.txt");
    if (file1.is_open())
    {
        while (getline(file1, str))
        {
            fileout << str << "\n";
        }
    }
    std::ifstream file2;
    file2.open("2.txt");
    if (file2.is_open())
    {
        while (getline(file2, str))
        {
            fileout << str << "\n";
        }
    }
    fileout.close();
}
//* Написать программу, которая проверяет присутствует ли указанное
//пользователем при запуске программы слово в указанном пользователем файле (для
//простоты работаем только с латиницей).
void task3()
{
    std::string   buf, s, n;
    std::ifstream file;
    file.open("done.txt");
    if (file.is_open())
    {
        while (getline(file, buf))
        {
            s += buf;
        }
    }
    std::cin >> n;
    std::size_t found = s.find(n);
    if (found != std::string::npos)
    {
        std::cout << "found";
    }
    else
    {
        std::cout << "not found";
    }
}
int main()
{

    task1();
    task2();
    task3();
}
