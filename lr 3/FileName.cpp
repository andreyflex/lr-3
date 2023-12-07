#include <stdio.h> // ��������� �������� ��� ������ �� ������� 
#include <math.h> // ����������� ��������
#include <locale.h> //��� ���������� ���������� ���� 

float GetSqrt(float x, float a)//����� �� ������ 
{
    return 3 * x + a;
}

float GetResult(float a, float b, float x)//����������� �������
{
    return sqrt(GetSqrt(x, a)) / sin(b * x - 1) + sin(fabs(x));
}

int main()//���� ����� 
{
    setlocale(LC_ALL, "ukr");//���������� ��������� ����
    //����������� ������
    float x1, x2;
    float a, b, step;
    //---------------------
    //��� �����
    printf("������ ����-��� �������� (�1,�2):\n");
    scanf_s("%f", &x1);
    scanf_s("%f", &x2);
   
    if (x1 >= x2)
    {
        printf("�������");
        return 0;
    }
    printf("\n������ ����-��� �������� (a,b):\n");
    scanf_s("%f", &a);
    scanf_s("%f", &b);
    printf("\n������ ����-��� �������� (step):\n");
    scanf_s("%f", &step);
    if (step <= 0)
    {
        printf("�������");
        return 0;
    }
    //-----------
    printf(".................................................................................................\n\
|\tx\t|\tf(x)\t|\tx\t|\tf(x)\t|\tx\t|\tf(x)\t| \n\
.................................................................................................\n");//������ ������� 
    const int iCount = 2;
    int i = iCount;
    for (float x = x1; x < x2; x += step)// ���� ������ ������� ������� 
    {
        printf("|\t");
        printf("%.2f\t", x);
        printf("|\t");
        if (GetSqrt(x, a) > 0)//�������� �������� �� �������
        {

            float result = GetResult(a, b, x);//�������� ���������
            if (result > 999.00f || result < -999.00f)//��� ����� �� ���� ����� �� 5 �������
            {
                printf("�������\t");
            }
            else
            {
                printf("%.2f\t", result);
            }
        }
        else
        {
            printf("�� ���\t");
        }

        if (i == 0)//�������� �� ����� ������
        {
            printf("|\n");
            i = iCount;
        }
        else
        {
            i--;
        }

    }
    if (i != iCount)//�������� ��� ���������� ������� �������� ���������� 
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