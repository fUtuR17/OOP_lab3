#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

string spell_number(int number)
{
    std::unordered_map<int, std::string> names = {
        {0, "sifir"},
        {1, "bir"},
        {2, "iki"},
        {3, "üç"},
        {4, "dört"},
        {5, "beş"},
        {6, "altı"},
        {7, "yedi"},
        {8, "sekiz"},
        {9, "dokuz"},
        {10, "on"},
        {20, "yirmi"},
        {30, "otuz"},
        {40, "kırk"},
        {50, "elli"},
        {60, "altmış"},
        {70, "yetmiş"},
        {80, "seksen"},
        {90, "doksan"}};

    if ((number > 99) or (number < 0))
    {
        return "Число должно быть от 0 до 99";
    };

    string spelling;

    // Число можно описать одним словом
    if (names.find(number) != names.end())
    {
        spelling = names[number];
        return spelling;
    }

    // Сборка названия числа из составных частей
    int tens = (number / 10) * 10;
    int units = number % 10;

    if (tens > 0)
    {
        spelling = names[tens] + " ";
    }
    spelling += names[units];
    return spelling;
}