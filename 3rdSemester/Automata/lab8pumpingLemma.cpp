#include <iostream>
#include <stdlib.h>
using namespace std;

bool isLanguage(const string &word, int p, int q)
{
    int l0 = 0;
    while (l0 < word.size() && word[l0] == '0')
    {
        l0++;
    }

    int n = l0 / p;

    int l1 = 0;
    while (l0 < word.size() && word[l0] == '1')
    {
        l0++;
        l1++;
    }

    return (q * n == l1);
}

void LanguageCheck(int p, int q)
{
    int n = 3 + rand() % 7;
    string w, wx, wy, wz, wp;
    int xl, yl, zl;
    w = wx = wy = wz = wp = "";

    for (int i = 0; i < p; i++)
    {
        w += "0";
    }
    for (int i = 0; i < q; i++)
    {
        w += "1";
    }

    yl = (rand() % (n - 1 + 1)) + 1;
    xl = n - yl;
    zl = w.size() - xl - yl;

    // wx = w.substr(0, xl);
    // wy = w.substr(xl, yl);
    // wz = w.substr(xl + yl, zl);
    wx = w.substr(0, min(xl, static_cast<int>(w.size())));
    wy = w.substr(min(xl, static_cast<int>(w.size())), min(yl, static_cast<int>(w.size()) - xl));
    wz = w.substr(min(xl + yl, static_cast<int>(w.size())), min(zl, static_cast<int>(w.size()) - xl - yl));

    for (int i = 0; i < 100; i++)
    {
        wp = wx;
        for (int j = 0; j < i; j++)
        {
            wp += wy;
        }
        wp += wz;

         bool flag = isLanguage(wp,p,q);
        if(!flag){
            cout<<"String is not in Language ."<<endl;
            break;
        }
    }
    // Do something with the generated string 'wp' here if needed.
}

int main()
{
    string input;
    int p, q;

    cout << "Enter a the string: ";
    cin >> input;

    if (input == "0^n1^n")
    {
        p = q = 1;
    }
    else
    {
        p = 1;
        q = 2;
    }

    LanguageCheck(p, q);
    return 0;
}
