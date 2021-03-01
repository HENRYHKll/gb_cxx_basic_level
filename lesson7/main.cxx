#include <cstring>
#include <iostream>

//  1
#define IN_THE_RANGE(num, max) ((num) >= 0 && (num) < (max))
#define IN_TO_TEXT(val_to_tex)                                                 \
    (val_to_tex ? "IN THE RANGE - Yes" : "IN THE RANGE - No")
//  2
#define SIZE_INNER_ARRAY 20
#define SIZE_OUTER_ARRAY 5
#define GET_ELEMENT(array, row, col) (*(*((array) + (row)) + (col)))
//  3
#define GET_SIZE_ARRAY(array, type) (sizeof(array) / sizeof(type))

//Описать макрокоманду, проверяющую, входит ли переданное ей число в диапазон от
//нуля (включительно) до переданного ей второго аргумента (исключительно)

void task1()
{
    std::cout << IN_TO_TEXT(IN_THE_RANGE(4, 13)) << std::endl;
    std::cout << IN_TO_TEXT(IN_THE_RANGE(0, 13)) << std::endl;
    std::cout << IN_TO_TEXT(IN_THE_RANGE(13, 13)) << std::endl;
    std::cout << IN_TO_TEXT(IN_THE_RANGE(5 * 3, 10 + 2)) << std::endl;
    std::cout << IN_TO_TEXT(IN_THE_RANGE(5 - 3, 10 - 2)) << std::endl;
}

//Описать макрокоманду, получающую доступ к элементу двумерного массива
//(организованного динамически) посредством разыменования указателей

void task2()
{

    char** array = (char**)malloc(sizeof(char*) * SIZE_OUTER_ARRAY);

    for (int i = 0; i < SIZE_OUTER_ARRAY; ++i)
        array[i] = (char*)malloc(sizeof(char) * SIZE_INNER_ARRAY);

    strncpy(array[2], "First there was light", 22);
    strncpy(array[4], "I always tell the truth, I lie", 31);
    std::cout << GET_ELEMENT(array, 2, 10) << std::endl;
    std::cout << GET_ELEMENT(array + 3, 2 - 1, 2 * 7 + 1) << std::endl;

    for (int i = 0; i < SIZE_OUTER_ARRAY; ++i)
        free(array[i]);
    free(array);
}

void task3()
{
    float array[16];
    std::cout << "size " << GET_SIZE_ARRAY(array, float) << std::endl;
}
int main()
{
    task1();
    task2();
    task3();

    return 0;
}
