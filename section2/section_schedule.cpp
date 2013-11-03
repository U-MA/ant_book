#include <iostream>
#include <vector>
using namespace std;

int N;
vector< pair<int, int> > work;

void input()
{
    cin >> N;
    work.resize(N);
    for (int i=0; i < N; i++)
    {
        // 開始時刻をsecondに入れている
        cin >> work[i].second;
        cin >> work[i].first;
    }
}

void solve()
{
    sort(work.begin(), work.end());

    int t = 0, count = 0;
    for (int i=0; i < N; i++)
    {
        if (t < work[i].second)
        {
            t = work[i].first;
            count++;
        }
    }
    cout << count << endl;
}

int main()
{
    input();
    solve();
    return 0;
}
