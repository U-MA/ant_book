#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int N;
string S;

void input()
{
    cin >> N;
    S.resize(N);
    for (int i=0; i < N; i++)
        cin >> S[i];
}


void solve()
{
    string T(S);
    reverse(T.begin(), T.end());

    string str;

    int len = N;
    while (!S.empty())
    {
        if (S < T)
        {
            str += S[0];
            S = S.substr(1);
            T = T.substr(0, len-1);
            len--;
        }
        else
        {
            str += T[0];
            S = S.substr(0, len-1);
            T = T.substr(1);
            len--;
        }
    }
    cout << str.substr(0, 80) << endl;
    while (str.size() >= 80)
    {
        str = str.substr(80);
        cout << str.substr(0, 80) << endl;
    }
}


int main()
{
    input();
    solve();
    return 0;
}
