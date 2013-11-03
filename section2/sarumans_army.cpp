#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, R;
vector<int> X;

bool input()
{
    cin >> R;
    cin >> N;

    if (R == -1 && N == -1) return false;

    X.resize(N);
    for (int i=0; i < N; i++)
        cin >> X[i];

    return true;
}


void solve()
{
    // X をソートしておく
    sort(X.begin(), X.end());

    int i=0, count=0;
    while (i < N)
    {
        int x = X[i++];

        while (i < N && X[i] <= x + R) i++;

        int p = X[i-1];

        while (i < N && X[i] <= p + R) i++;

        count++;
    }


    cout << count << endl;
}


int main()
{
    while(input())
        solve();

    return 0;
}
