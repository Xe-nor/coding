#include <iostream>
using namespace std;
int main()
{
    int num;
    int n;
    cin >> n;
    int a[10];
    int temp = a[0];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        if (temp > a[i])
        {
            temp = a[i];
        }
    }

   
    cout << temp;
}
