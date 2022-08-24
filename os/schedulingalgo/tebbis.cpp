#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    string ans;
    int counta = 0, countb = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == 'A')
            counta++;
        else
            countb++;
        if (counta == 4 && countb < 4)
        {
            ans += 'A';
            counta = 0;
            countb = 0;
        }
        else if (countb == 4 && counta < 4)
        {
            ans += 'B';
            counta = 0;
            countb = 0;
        }
        else if (counta == 3 && countb == 3)
        {
            int tempa = 0, tempb = 0;
            for (int j = i + 1; j < s.length() - 2; j++)
            {
                if (s[j] == 'A' && s[j + 1] == 'A')
                {
                    ans += 'A';
                    counta = 0;
                    countb = 0;
                    break;
                }
                else if (s[j] == 'B' && s[j + 1] == 'B')
                {
                    ans += 'B';
                    counta = 0;
                    countb = 0;
                    break;
                }
                else if (j == s.length() - 2)
                {
                    goto xy;
                }
            }
        }
    }
xy:
    cout << ans;
}