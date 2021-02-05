#include <iostream>
#include <bitset>
constexpr char BITS_PER_CELL = 2;
constexpr char BITS_PER_ROW  = BITS_PER_CELL * 3;

//1. Создать и инициализировать переменные пройденных типов данных

void type_lesson () {
    int variable_int = -13;
    unsigned int variable_unsigned_int = 13;
    long int variable_long_int = 13;
    short variable_short = 13;
    char variable_char = 'H';
    float variable_float = -13.13;
    double variable_double = 13.13131313;
    bool variable_bool = true;

}

//2. Создать перечисление с возможными вариантами символов для игры в крестики-нолики
//3. Создать массив, способный содержать значения такого перечисления и инициализировать его. 
void tic_tac_toe (){
    const int arr =3;
    char tic_tac_toe_arr [arr] ={'X', 'O', ' '};
}


//4.* Создать структуру данных «Поле для игры в крестики-нолики» и снабдить его всеми необходимыми свойствами
//5.** Создать объединение и структуру с битовыми флагами указывающими какого типа значение в данный момент содержится в объединении

union Field
    {
        int allCells{};
        struct
        {
            char c11 : BITS_PER_CELL; // 1st row, 1st column
            char c12 : BITS_PER_CELL; // 1st row, 2nd column
            char c13 : BITS_PER_CELL; // ...

            char c21 : BITS_PER_CELL;
            char c22 : BITS_PER_CELL;
            char c23 : BITS_PER_CELL;

            char c31 : BITS_PER_CELL;
            char c32 : BITS_PER_CELL;
            char c33 : BITS_PER_CELL;
        };

        struct
        {
            char row1 : BITS_PER_ROW;
            char row2 : BITS_PER_ROW;
            char row3 : BITS_PER_ROW;
        };
    };

int main_tic_tac_toe(){
    Field field{};

    field.c11 = 1;
    field.c12 = 1;
    field.c13 = 2;

    std::cout << std::bitset<18>(field.allCells) << std::endl;

    return std::cout.good() ? 0 : 1;
}
//00 - не ходили
//01 - ноль
//10 - крест
