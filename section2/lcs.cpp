#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int N;
int M;
string s, t;

const int MAX_N = 100;
const int MAX_M = 100;
int table[MAX_N][MAX_M];

void input()
{
    cin >> N;
    cin >> M;
    cin >> s;
    cin >> t;
}

void solve()
{
    for (int i=0; i < N; i++)
    {
        for (int j=0; j < M; j++)
        {
            if (s[i] == t[j])
                table[i+1][j+1] = table[i][j] + 1;
            else
                table[i+1][j+1] = max(table[i+1][j], table[i][j+1]);
        }
    }
    cout << table[N][M] << endl;
}

int main()
{
    cerr << "p.56 最長共通部分列問題" << endl;

    input();
    solve();
    return 0;
}
