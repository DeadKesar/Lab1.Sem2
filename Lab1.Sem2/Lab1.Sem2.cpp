/* Задача 1(25)
1.	Разработать программу для автоматизации вычислений с использованием римских чисел. Необходимо реализовать:
a.	функции перевода из римских в арабские числа и наоборот;
b.	функции простейших арифметических операций с римскими числами.
Решая задачу в рамках ООП, необходимо составить класс для представления римского числа.
Усложнение (+5 баллов). Использовать Unicode для представления римских чисел.
*/

//  I V  X  L  C   D    M 
//  1 5 10 50 100 500 1000


#include <iostream>
#include <string>

int RimToArab(std::string rim);
std::string ArabToRim(int num);
void Paste(std::string &rim, std::string ch, int count);

int main()
{
    
    setlocale(LC_ALL, "ru-Ru.UTF-8");
    std::string rimNumb1, rimNumb2;
    int numb = 1987;
    std::cout << ArabToRim(numb);
    double arabNumb1 = -1, arabNumb2 = -1;
    while (arabNumb1 == -1)
    {
        std::wprintf(L"введите римское число 1 \u2185: ");
        std::getline(std::cin, rimNumb1);
        arabNumb1 = RimToArab(rimNumb1);
        if (arabNumb1 == -1)
        {
            std::wprintf(L"\n введённое число - некоректно, попробуйте сноваю \n");
        }
    }
    if (rimNumb1[0] == '-')
    {
        arabNumb1 *= -1;
    }
    std::cout << std::endl;
    while (arabNumb2 == -1)
    {
        std::wprintf(L"введите римское число 2 \u2185: ");
        std::getline(std::cin, rimNumb2);
        arabNumb2 = RimToArab(rimNumb2);
        if (arabNumb2 == -1)
        {
            std::wprintf(L"\n введённое число - некоректно, попробуйте сноваю \n");
        }
    }
    if (rimNumb1[0] == '-')
    {
        arabNumb2 *= -1;
    }
    std::cout << std::endl << arabNumb1 << "   " << arabNumb2;
}
int RimToArab(std::string rim)
{
    int num = 0, countI =0, countV=0, countX = 0, countL =0, countC = 0, countD = 0, countM = 0,countIV = 0, 
        countIX = 0, countXL = 0, countXC =0, countCD = 0, countCM = 0;
    for (int i = 0, length = rim.length(); i < length; i++)
    {

        switch (std::toupper(rim[i]))
        {
        case ('-'):
        {
            break;
        }
        case ('I'):
        {
            if (i + 1 < length && std::toupper(rim[i+1]) == 'V')
            {
                num -= 2;
                countI--;
                countIV++;
            }
            if (i + 1 < length &&  std::toupper(rim[i + 1]) == 'X')
            {
                num -= 2;
                countI--;
                countIX++;
            }
            if (i + 1 < length && (std::toupper(rim[i+1]) == 'L' || std::toupper(rim[i+1]) == 'C' || std::toupper(rim[i+1]) == 'D' || std::toupper(rim[i+1]) == 'M'))
            {
                return -1;
            }
            num += 1;
            countI++;
            break;
        }
        case ('V'):
        {
            if (i + 1 < length && (std::toupper(rim[i + 1]) == 'X' || std::toupper(rim[i + 1]) == 'L' || std::toupper(rim[i + 1]) == 'C' || std::toupper(rim[i + 1]) == 'D' || std::toupper(rim[i + 1]) == 'M'))
            {
                return -1;
            }
            num += 5;
            countV++;
            break;
        }
        case ('X'):
        {
            if (i + 1 < length && std::toupper(rim[i+1]) == 'L' )
            {
                num -= 20;
                countX--;
                countXL++;
            }
            if (i + 1 < length && std::toupper(rim[i + 1]) == 'C')
            {
                num -= 20;
                countX--;
                countXC++;
            }
            if (i + 1 < length && (std::toupper(rim[i + 1]) == 'D' || std::toupper(rim[i + 1]) == 'M'))
            {
                return -1;
            }
            num += 10;
            countX++;
            break;
        }
        case ('L'):
        {
            if (i + 1 < length && ( std::toupper(rim[i + 1]) == 'C' || std::toupper(rim[i + 1]) == 'D' || std::toupper(rim[i + 1]) == 'M'))
            {
                return -1;
            }
            num += 50;
            countL++;
            break;
        }
        case ('C'):
        {
            if (i + 1 < length && std::toupper(rim[i + 1]) == 'D')
            {
                num -= 200;
                countC--;
                countCD++;
            }
            if (i + 1 < length && std::toupper(rim[i+1]) == 'M')
            {
                num -= 200;
                countC--;
                countCM++;
            }
            num += 100;
            countC++;
            break;
        }
        case ('D'):
        {
            num += 500;
            countD++;
            break;
        }
        case ('M'):
        {
            num += 1000;
            countM++;
            break;
        }
        default:
            return -1;
            break;
        }
    }    
    //проверка правил построения римского числа: меньшие числа не стоят перед большими кроме особого случая когда число предыдущего разряда
    // вычитается, нет ситуаций когда из числа сначала вычли единицу, а потом добавили.
    //
    if (countI > 3 || countV > 1 || countX > 3 || countL > 1 || countC > 3 || countD > 1 || countM > 3 || 
        countIV > 1|| countIX >1 || countXL >1 || countXC >1 || countCD >1 || countCM >1 ||
        (countIV == 1 && countIX == 1) || (countIV == 0 && countIX == 1 && countV>0) || 
        (countXL == 1 && countXC == 1) || (countXL == 0 && countXC == 1 && countL>0) ||
        (countCD == 1 && countCM == 1) || (countCD == 0 && countCM == 1 && countD>0) ||
        (countIX == 1 && countI > 0) || (countIV == 1 && countI > 0) ||
        (countXC == 1 && countX > 0) || (countXL == 1 && countXC > 0) ||
        (countCM == 1 && countC > 0) || (countCD == 1 && countC > 0))
    {
        return -1;
    }
    return num;
}
//  I V  X  L  C   D    M 
//  1 5 10 50 100 500 1000
std::string ArabToRim(int num)
{
    std::string &answer = &"";
    if (num / 1000 > 0)
    {
        Paste(answer, "M", num / 1000);
        num %= 1000;
    }
    if (num / 900 > 0)
    {
        Paste(answer, "CM", num / 900);
        num %= 900;
    }
    if (num / 500 > 0)
    {
        Paste(answer, "D", num / 500);
        num %= 500;
    }
    if (num / 400 > 0)
    {
        Paste(answer, "CD", num / 400);
        num %= 400;
    }
    if (num / 100 > 0)
    {
        Paste(answer, "C", num / 100);
        num %= 100;
    }
    if (num / 90 > 0)
    {
        Paste(answer, "XC", num / 90);
        num %= 90;
    }
    if (num / 50 > 0)
    {
        Paste(answer, "L", num / 50);
        num %= 50;
    }
    if (num / 40 > 0)
    {
        Paste(answer, "XL", num / 40);
        num %= 40;
    }

    if (num / 10 > 0)
    {
        Paste(answer, "X", num / 10);
        num %= 10;
    }
    if (num / 9 > 0)
    {
        Paste(answer, "IX", num / 9);
        num %= 9;
    }
    if (num / 5 > 0)
    {
        Paste(answer, "V", num / 5);
        num %= 5;
    }
    if (num / 4 > 0)
    {
        Paste(answer, "IV", num / 4);
        num %= 4;
    }
    if (num / 1 > 0)
    {
        Paste(answer, "L", num / 1);
        num = 0;
    }
    return answer;
}
void Paste(std::string& rim, std::string ch, int count)
{
    for (int i = 0; i < count; i++)
    {
        rim + ch;
    }
}