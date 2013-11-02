#include <iostream>
using namespace std;

const int MAX_N = 100;
const int MAX_M = 100;

char field[MAX_N][MAX_M];

int N; // 縦
int M; // 横

void input()
{
    cin >> N;
    cin >> M;

    for (int row=0; row < N; row++)
        for (int col=0; col < M; col++)
            cin >> field[row][col];
}

bool search(int row, int col)
{
    if (row < 0 || row >= N || col < 0 || col >= M)
        return false;

    int dr[8] = { -1, -1, -1,  0,  0, +1, +1, +1 };
    int dc[8] = { -1,  0,  1, -1,  1, -1,  0, +1 };

    if (field[row][col] == 'W')
    {
        field[row][col] = '.';
        for (int i=0; i < 8; i++)
            (void)search(row+dr[i], col+dc[i]);
        return true;
    }
    return false;
}


void solve()
{
    int count = 0;
    for (int i=0; i < N; i++)
    {
        for (int j=0; j < M; j++)
        {
            if (search(i, j))
                count++;
        }
    }
    cout << count << endl;
}

int main()
{
    cout << "p.35 Lake Counting(POJ No.2386)" << endl;

    input();
    solve();

    return 0;
}
