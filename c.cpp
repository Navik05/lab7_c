#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include "square.h"
#include "circle.h"
#include "triangle.h"
#include <set>
#include <algorithm>

int block_int(int min, int max);
double block_double();

int main()
{
    using namespace std;
    int min, max, i, f, j;
    double sides[N], p, s;
    square one;
    circle two;
    triangle three;
    set<figure> fg;
    setlocale(LC_ALL, "Rus");
    f = 1; p = 0; s = 0;
    printf("\n1-квадрат\n2-круг\n3-треугольник\nВыберите фигуру:");
    min = 1; max = 3;
    one.setType(block_int(min, max));
    //Ввод и обработка
    j = 0;
    do {
        switch (one.getType())
        {
        case 1:
            printf("Длина стороны квадрата:");
            one = square(block_double());
            one.workSquare();
            fg.insert(one);
            break;
        case 2:
            printf("Радиус круга:");
            two = circle(block_double());
            two.workCircle();
            fg.insert(two);
            break;
        case 3:
            printf("Длина сторон треугольника:");
            for (i = 0; i < 3; i++)
            {
                sides[i] = block_double();
            }
            three = triangle(sides);
            try
            {
                three.workTriangle();
            }
            catch (const char* error_message)
            {
                cout << error_message << endl;
                f = 0;
            }
            fg.insert(three);
            break;
        default:;
        }
        j++;
    } while (j < 3);
    //Вывод результатов
    for (auto& item : fg)
    {
        cout << item << endl;
    }

}
//Защита на целые числа
int block_int(int min, int max)
{
    int type, f = 1;
    do {
        if (f != 1)
        {
            printf("Такого варианта нет. Попробуйте ещё раз: ");
        }
        while (scanf("%d", &type) != 1)
        {
            while (getchar() != '\n');
            printf("Ошибка. Попробуйте ещё раз: ");
        }
        f = 0;
        while (getchar() != '\n');
    } while (type<min || type>max);
    printf("\n");
    return type;
}
//Защита на дробные числа
double block_double()
{
    int f = 1;
    double e;
    do {
        if (f != 1)
        {
            printf("Такого варианта нет. Попробуйте ещё раз: ");
        }
        while (scanf("%lf", &e) != 1)
        {
            while (getchar() != '\n');
            printf("Ошибка. Попробуйте ещё раз: ");
        }
        f = 0;
        while (getchar() != '\n');
    } while (e <= 0);
    return e;
}
//Дружественная функция
int view(triangle& three)
{
    if (three.sides[0] == three.sides[1] && three.sides[1] == three.sides[2])
        return 1;
    else if (three.sides[0] == three.sides[1] || three.sides[1] == three.sides[2] || three.sides[0] == three.sides[2])
        return 2;
    else return 3;
}