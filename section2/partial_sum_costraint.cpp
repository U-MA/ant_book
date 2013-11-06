#include <iostream>
#include <vector>
using namespace std;

int N;
vector < pair<int, int> > X;
int K;

const int MAX_N = 100;
const int MAX_K = 100000;
bool dp[MAX_N][MAX_K];

void input()
{
    cin >> N;
    X.resize(N);
    for (int i=0; i < N; i++)
    {
        cin >> X[i].first;
        cin >> X[i].second;
    }
    cin >> K;
}

void solve()
{
    dp[0][0] = true;
    for (int i=0; i < N; i++)
    {
        for (int j=0; j <= K; j++)
        {
            for (int k=0; k <= X[i].second && k * X[i].first <= j; k++)
            {
                dp[i+1][j] |= dp[i][j - k * X[i].first];
            }
        }
    }
    if (dp[N][K])
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}

int main()
{
    cerr << "p.62 個数制限つき部分和問題" << endl;
    input();
    solve();
    return 0;
}
