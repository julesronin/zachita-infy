#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <cmath>

using namespace std;

void count(string l)
{
    unordered_map<char, int> map;
    int t = 0;
    for (const char& x : l)
    {
        map[x]++;
    }
    for (auto& x : map)
    {
        cout << "Буква " << x.first << " встречается " << x.second << " раз(а); " << endl;
    }
}

void count2(string q, string s)
{
    unordered_map<char, int> map1;
    unordered_map<char, int> map2;
    int i;
    for (const char& x : q)
    {
        map1[x]++;
    }
    for (const char& t : s)
    {
        map2[t]++;
    }
        for (auto& x : map1)
        {
            for (auto& t : map2)
            {
                if (x.second == t.second)
                {
                    for (i = 0; i <= s.length(); i++)
                    {
                        if (s[i] >= 'a' && s[i] <= 'z' && s[i] >= 'A' && s[i] <= 'Z')
                            s[i] = x.first;
                    }
                }
                
            }
        }
    cout << q;
}

int main()
{
    setlocale(LC_ALL, "Rus");
    string s, l;
    int n;
    cout << "Введите текст для зашифровки с помощью шифра Цезаря: \n";
    getline(cin, s);
    cout << "Введите значение ключа: \n";
    cin >> n;
    l = s;
    for (auto& x : s)
    {
        if (x >= 'a' && x <= 'z')
            x = ((x - 'a' + n) % 26) + 'a';
        else if (x >= 'A' && x <= 'Z')
            x = ((x - 'A' + n) % 26) + 'A';
    }
    cout << "Зашифрованное сообщение: \n" << s;
    cout << "\nПодсчитывание частоты появления каждой буквы в исходном тексте: \n";
    count(l);
    cout << "Подсчитывание частоты появления каждой буквы в зашифрованном тексте: \n";
    count(s);
    cout << "Расшифрованное сообщение: \n";
    count2(l, s);
}
