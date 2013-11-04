#include <iostream>
#include <vector>
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


int main()
{
    cerr << "Fence Repair(POJ No.3253)" << endl;
    
    input();
    solve();
    return 0;
}
