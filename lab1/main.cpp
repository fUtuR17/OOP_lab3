#include <iostream>
#include <unordered_map>
#include "../include/number_speller.h"

using namespace std;
int main()
{
    unsigned int number;
    cin >> number;
    cout << spell_number(number) << endl;
    return 0;
};
