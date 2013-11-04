#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


const int MAX_N = 100;
const int MAX_W = 100;
int dp[MAX_N][MAX_W];

int N;
vector< pair<int, int> > X;
int W;

void input()
{
    cin >> N;
    X.resize(N);
    for (int i=0; i < N; i++)
    {
        cin >> X[i].first;  // 重さ
        cin >> X[i].second; // 価値
    }
    cin >> W;
}


void solve()
{
    for (int i=0; i < N; i++)
    {
        for (int j=0; j <= W; j++)
        {
            for (int k=0; k * X[i].first <= j; k++)
            {
                dp[i+1][j] = max(dp[i+1][j], dp[i][j-k*X[i].first] + k * X[i].second);
            }
        }
    }
    cout << dp[N][W] << endl;
}

void solve2()
{
    for (int i=0; i < N; i++)
    {
        for (int j=0; j <= W; j++)
        {
            if (j < X[i].first)
            {
                dp[i+1][j] = dp[i][j];
            }
            else
            {
                dp[i+1][j] = max(dp[i][j], dp[i+1][j-X[i].first] + X[i].second);
            }
        }
    }
    cout << dp[N][W] << endl;
}

int main()
{
    cerr << "p.58 個数制限なしナップサック問題" << endl;
    input();
    solve2();
    return 0;
}
