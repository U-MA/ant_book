#include <iostream>
#include <queue>
using namespace std;

int N;
int L;
int P;
vector<int> A;
vector<int> B;

void input()
{
    cin >> N;
    cin >> L;
    cin >> P;
    A.resize(N);
    for (int i=0; i < N; i++)
        cin >> A[i];

    B.resize(N);
    for (int i=0; i < N; i++)
        cin >> B[i];
}

void solve()
{
    priority_queue<int> que;

    A.push_back(L);
    B.push_back(0);
    N++;

    int pos = 0;
    int ans = 0;
    int d = 0;
    for (int i=0; i < N; i++)
    {
        // 進む距離
        d = A[i] - pos;

        // 進んだ分だけ燃料を消費
        P -= d;

        // 今まで通ったGSの中の最大の供給量のところから供給
        while (P < 0)
        {
            if (que.empty())
            {
                cout << -1 << endl;
                return;
            }

            P += que.top();
            que.pop();
            ans++;
        }

        // 訪れたGSを追加
        que.push(B[i]);

        // 現在地の更新
        pos = A[i];
    }

    cout << ans << endl;
}

int main()
{
    cerr << "p.73 Expedition (POJ No.2431)" << endl;
    input();
    solve();
    return 0;
}
