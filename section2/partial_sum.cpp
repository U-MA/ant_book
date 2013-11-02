#include <iostream>
#include <vector>
using namespace std;

int n;         // 整数のサイズ
vector<int> a; // 与えられる整数
int k;         // 指定する和

void input()
{
    cin >> n;

    a.resize(n);
    for (int i=0; i < n; i++)
        cin >> a[i];

    cin >> k;
}

bool solve(int sum, int i)
{
    if (i == n)
        return (sum == k);

    if(solve(sum+a[i], i+1)) // i 番目を加える
        return true;
    else
        return solve(sum, i+1);      // i 番目を加えない
}

int main()
{
    int sum = 0;

    input();

    if (solve(sum, 0))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}
