#include <iostream>
using namespace std;

int c1, c5, c10, c50, c100, c500; // コインの枚数
int A; // 金額

void input()
{
    cin >> c1;
    cin >> c5;
    cin >> c10;
    cin >> c50;
    cin >> c100;
    cin >> c500;
    cin >> A;
}

void solve()
{
    int count = 0;
    while (A > 0)
    {
        if (A >= 500 && c500 > 0)
        {
            c500--;
            A -= 500;
        }
        else if (A >= 100 && c100 > 0)
        {
            c100--;
            A -= 100;
        }
        else if (A >= 50 && c50 > 0)
        {
            c50--;
            A -= 50;
        }
        else if (A >= 10 && c10 > 0)
        {
            c10--;
            A -= 10;
        }
        else if (A >= 5 && c5 > 0)
        {
            c5--;
            A -= 5;
        }
        else if (A >= 1 && c1 > 0)
        {
            c1--;
            A -= 1;
        }
        count++;
    }
    cout << count << endl;
}


int main()
{
    input();
    solve();
    return 0;
}
