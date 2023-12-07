#include <stdio.h> // підключаємо бібліотеку для виводу на консоль 
#include <math.h> // математична бібліотека
#include <locale.h> //для підключання локалізації мови 

float GetSqrt(float x, float a)//вираз під корнем 
{
    return 3 * x + a;
}

float GetResult(float a, float b, float x)//табулювання функції
{
    return sqrt(GetSqrt(x, a)) / sin(b * x - 1) + sin(fabs(x));
}

int main()//вхід файлу 
{
    setlocale(LC_ALL, "ukr");//підключення української мови
    //ініціалізація змінних
    float x1, x2;
    float a, b, step;
    //---------------------
    //ввід даних
    printf("ввести будь-яке значення (х1,х2):\n");
    scanf_s("%f", &x1);
    scanf_s("%f", &x2);
   
    if (x1 >= x2)
    {
        printf("помилка");
        return 0;
    }
    printf("\nввести будь-яке значення (a,b):\n");
    scanf_s("%f", &a);
    scanf_s("%f", &b);
    printf("\nввести будь-яке значення (step):\n");
    scanf_s("%f", &step);
    if (step <= 0)
    {
        printf("помилка");
        return 0;
    }
    //-----------
    printf(".................................................................................................\n\
|\tx\t|\tf(x)\t|\tx\t|\tf(x)\t|\tx\t|\tf(x)\t| \n\
.................................................................................................\n");//титиул таблиці 
    const int iCount = 2;
    int i = iCount;
    for (float x = x1; x < x2; x += step)// цикл виводу значень таблиці 
    {
        printf("|\t");
        printf("%.2f\t", x);
        printf("|\t");
        if (GetSqrt(x, a) > 0)//перевірка значення під коренем
        {

            float result = GetResult(a, b, x);//отримуємо результат
            if (result > 999.00f || result < -999.00f)//щоб числа не були більше ніж 5 символів
            {
                printf("перепов\t");
            }
            else
            {
                printf("%.2f\t", result);
            }
        }
        else
        {
            printf("не виз\t");
        }

        if (i == 0)//перевірка на кінець строки
        {
            printf("|\n");
            i = iCount;
        }
        else
        {
            i--;
        }

    }
    if (i != iCount)//перевірка для заповнення таблиці пустимим значеннями 
    {
        for (int G = -1; G <= i + 1; G++)
        {
            printf("|\t\t");
        }
        printf("|\n");
    }
    printf(".................................................................................................");
    return  0;
}