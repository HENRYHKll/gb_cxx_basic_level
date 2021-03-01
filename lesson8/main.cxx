#include <iostream>
#include <time.h>

#define CHK_DOT(x, sz) ((x) >= 0 && (x) < (sz))

enum PLAYER
{
    HUMAN    = 'X',
    COMPYTER = 'O',
    EMPTY    = '_'
};

typedef struct
{
    int      szX;
    int      szY;
    PLAYER** map;
    int      towin;

} Field;

void setval(PLAYER** map, int x, int y, PLAYER state)
{
    map[y][x] = state;
};
PLAYER getval(PLAYER** map, int x, int y)
{
    return map[y][x];
}

int isvalid(Field& field, int x, int y)
{
    return CHK_DOT(x, field.szX) && CHK_DOT(y, field.szY);
};
int isempty(Field& field, int x, int y)
{
    return getval(field.map, y, x) == EMPTY;
};
int check_line(Field& field, int x, int y, int vx, int vy, PLAYER c)
{
    const int endx = x + (field.towin - 1) * vx;
    const int endy = y + (field.towin - 1) * vy;
    if (!isvalid(field, endx, endy))
        return 0;
    for (int i = 0; i < field.towin; i++)
        if (getval(field.map, (y + i * vy), (x + i * vx)) != c)
            return 0;
    return 1;
};

void init(Field& field)
{
    field.towin = 3;
    field.szX   = 3;
    field.szY   = 3;
    field.map   = (PLAYER**)calloc(sizeof(PLAYER*), field.szY);
    for (int i = 0; i < field.szY; ++i)
    {
        field.map[i] = (PLAYER*)calloc(sizeof(PLAYER), field.szX);
        for (int j = 0; j < field.szX; ++j)
            setval(field.map, j, i, EMPTY);
    }
}

void print(Field& field)
{
    system("cls"); // system("clear")
    std::cout << "-------------\n";
    for (int i = 0; i < field.szY; ++i)
    {
        std::cout << "|";
        for (int j = 0; j < field.szX; ++j)
        {
            std::cout << static_cast<char>(getval(field.map, j, i)) << "|";
        }
        std::cout << std::endl;
    }
}

void huma_muve(Field& field)
{
    int x, y;
    do
    {
        std::cout << "Enter X and Y: ";
        std::cin >> x >> y;
        x--;
        y--;
    } while (!isvalid(field, x, y) || !isempty(field, x, y));
    setval(field.map, y, x, HUMAN);
}

void compyter_move(Field& field)
{
    int x, y;
    do
    {
        x = rand() % field.szX;
        y = rand() % field.szX;
    } while (!isvalid(field, x, y) || !isempty(field, x, y));
    setval(field.map, x, y, COMPYTER);
}

int check_win(Field& field, PLAYER player)
{
    for (int x = 0; x < field.szX; ++x)
    {
        for (int y = 0; y < field.szY; ++y)
        {
            if (check_line(field, x, y, 1, 0, player))
                return 1;
            if (check_line(field, x, y, 0, 1, player))
                return 1;
            if (check_line(field, x, y, 1, -1, player))
                return 1;
        }
    }
    return 0;
}

int check_draw(Field& field)
{
    for (int x = 0; x < field.szX; ++x)
    {
        for (int y = 0; y < field.szY; ++y)
        {
            if (isempty(field, x, y))
                return 0;
        }
    }
    return 1;
}
int check_game(Field& field, PLAYER p, const char* win_sring)
{
    if (check_win(field, p))
    {
        std::cout << win_sring << std::endl;
        return 1;
    }
    if (check_draw(field))
    {
        std::cout << "draw" << std::endl;
        return 1;
    }
    return 0;
};

void tictactoe()
{
    Field field;
    while (1)
    {
        init(field);
        print(field);
        while (1)
        {
            huma_muve(field);
            print(field);
            if (check_game(field, HUMAN, "Human win!"))
                break;
            compyter_move(field);
            print(field);
            if (check_game(field, COMPYTER, "COMPYTER win!"))
                break;
        }
        std::cout << "Play agen?\n n - no" << std::endl;
        char answer;
        std::cin >> answer;
        if (answer == 'n')
            break;
    }
}
int main()
{
    srand(time(0));
    tictactoe();
}
