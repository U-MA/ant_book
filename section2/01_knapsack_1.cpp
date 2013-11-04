#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector< pair<int, int> > X;
int W;

const int MAX_N = 100;
const int MAX_W = 100;
int table[MAX_N][MAX_W];

void input()
{
    cin >> N;
    X.resize(N);
    for (int i=0; i < N; i++)
    {
        cin >> X[i].first;   // 重さ
        cin >> X[i].second;  // 価値
    }
    cin >> W;
}

int dp(int i, int w)
{
    if (table[i][w] >= 0)
        return table[i][w];

    int value;
    if (i == N)
        value = 0;
    else if (w < X[i].first) // i 番目の品物は使えない
        value = dp(i+1, w);
    else
        value = max(dp(i+1, w-X[i].first) + X[i].second, dp(i+1, w));

    return table[i][w] = value;
}

// 漸化式を用いたアルゴリズム
int solve2()
{
    for (int i= N-1; i >= 0; i--)
    {
        for (int j=0; j <= W; j++)
        {
            if (j < X[i].first)
            {
                table[i][j] = table[i+1][j];
            }
            else
            {
                table[i][j] = max(table[i+1][j], table[i+1][j-X[i].first] + X[i].second);
            }
        }
    }
    cout << table[0][W] << endl;
}

void solve()
{
    for (int i=0; i < MAX_N; i++) for (int j=0; j < MAX_W; j++) table[i][j] = -1;
    cout << dp(0, W) << endl;
}


int main()
{
    cerr << "p.52 01ナップサック問題" << endl;
    input();
    solve2();
    return 0;
}
