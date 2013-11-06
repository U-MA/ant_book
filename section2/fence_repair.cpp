#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;


int N;
vector <int> L;

void input()
{
    cin >> N;
    L.resize(N);
    for (int i=0; i < N; i++)
        cin >> L[i];
}

void solve()
{
    int ans = 0;
    while (N > 1)
    {
        sort(L.begin(), L.end());
        cerr << "L: ";
        for (int i=0; i < N; i++)
            cerr << L[i] << " ";
        cerr << endl;

        ans += L[0] + L[1];
        L[0] += L[1];
        L[1] = L[N-1];
        L.resize(N-1);
        N--;
    }
    cout << ans << endl;
}

void solve2()
{
    priority_queue<int, vector<int>, greater<int> > que;

    for (int i=0; i < N; i++)
    {
        que.push(L[i]);
    }

    long long ans = 0;
    while (que.size() > 1)
    {
        // 1,2番目に小さい板を取り出す
        int l1 = que.top(); que.pop();
        int l2 = que.top(); que.pop();

        ans += l1+l2;
        que.push(l1+l2);
    }

    cout << ans << endl;
}


int main()
{
    input();
    solve2();
    return 0;
}
