#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 10000000;

const int MAX_N = 100;
const int MAX_V = 100;
int dp[MAX_N+1][MAX_N*MAX_V+1];

int N;
vector< pair<int, int> > X;
int W;

int input()
{
    cin >> N;
    X.resize(N);
    for (int i=0; i < N; i++)
    {
        cin >> X[i].first;
        cin >> X[i].second;
    }
    cin >> W;
}

void solve()
{
    fill(dp[0], dp[0] + MAX_N * MAX_V + 1, INF);

    dp[0][0] = 0;
    for (int i=0; i < N; i++)
    {
        for (int j=0; j <= MAX_N * MAX_V; j++)
        {
            if (j < X[i].second)
            {
                dp[i+1][j] = dp[i][j];
            }
            else
            {
                dp[i+1][j] = min(dp[i][j], dp[i][j - X[i].second] + X[i].first);
            }
        }
    }

    int res = 0;
    for (int i=0; i <= MAX_N * MAX_V; i++) if (dp[N][i] <= W) res = i;

    cout << res << endl;
}

int main()
{
    cerr << "p.60 01ナップサック問題その２" << endl;
    input();
    solve();
    return 0;
}
