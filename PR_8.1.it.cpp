// PR_8.1.it.cpp
// Єфіменко Софія
// Лабораторна робота № 8.1
// Пошук та заміна символів у літерному рядку.
// Ітераційний спосіб (сканування рядка вручну).
// Варіант 8

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

// Перевірка, чи входять усі символи з cs у рядок s (стор. 84 методички)
bool Include(const char* s, const char* cs)
{
    bool b, r = true;
    for (int i = 0; cs[i] != '\0'; i++)
    {
        b = false;
        for (int j = 0; s[j] != '\0'; j++)
            if (cs[i] == s[j])
            {
                b = true;
                break;
            }
        r = r && b;
    }
    return r;
}

// Заміна кожної групи букв "while" на "**" (стор. 100-101 методички)
char* Change(char* str)
{
    size_t len = strlen(str);
    if (len < 5)
        return str;

    char* tmp = new char[len + 1];
    char* t = tmp;
    tmp[0] = '\0';

    size_t i = 0;
    while (i < len && str[i + 4] != 0)
    {
        if (str[i] == 'w' && str[i + 1] == 'h' && str[i + 2] == 'i' &&
            str[i + 3] == 'l' && str[i + 4] == 'e')
        {
            strcat(t, "**");
            t += 2;
            i += 5;
        }
        else
        {
            *t++ = str[i++];
            *t = '\0';
        }
    }
    while (str[i] != 0)
    {
        *t++ = str[i++];
    }
    *t = '\0';

    strcpy(str, tmp);
    return tmp;
}

int main()
{
    char str[101];
    cout << "Enter string:" << endl;
    cin.getline(str, 100);

    const char* cs = "while";
    if (Include(str, cs))
        cout << "String contains all letters from 'while': Yes" << endl;
    else
        cout << "String contains all letters from 'while': No" << endl;

    char* dest = new char[151];
    dest = Change(str);

    cout << "Modified string (param) : " << str << endl;
    cout << "Modified string (result): " << dest << endl;

    return 0;
}
