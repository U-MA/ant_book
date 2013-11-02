#include <iostream>
#include <string>
#include <queue>
using namespace std;

const int MAX_N = 100;
const int MAX_M = 100;

int N, M;

int maze[MAX_N][MAX_M];

int sx, sy; // Start の座標
int gx, gy; // Goal の座標

int dist[MAX_N][MAX_M]; // Start からの最短距離を格納

typedef pair<int, int> P;


void input()
{
    cin >> N;
    cin >> M;

    for (int row=0; row < N; row++)
    {
        string str;
        cin >> str;
        for (int col=0; col < M; col++)
        {
            maze[row][col] = str[col];

            if (maze[row][col] == 'S')
            {
                sx = row;
                sy = col;
            }
            else if (maze[row][col] == 'G')
            {
                gx = row;
                gy = col;
            }
        }
    }
}

int search()
{
    const int INF = 100000;
    for (int i=0; i < N; i++) for (int j=0; j < M; j++) dist[i][j] = INF;

    int dx[4] = {  0,  0, -1, +1 };
    int dy[4] = { -1, +1,  0,  0 };

    queue<P> que;

    que.push(P(sx, sy));
    dist[sx][sy] = 0;

    while (que.size())
    {
        P p = que.front();
        que.pop();

        if (p.first == gx && p.second == gy) break;

        for (int i=0; i < 4; i++)
        {
            int x = p.first + dx[i];
            int y = p.second + dy[i];

            if (0 <= x && x < M && 0 <= y && y < N && maze[x][y] != '#' && dist[x][y] == INF)
            {
                que.push(P(x, y));
                dist[x][y] = dist[p.first][p.second] + 1;
            }
        }
    }
    return dist[gx][gy];
}

void solve()
{
    cout << search() << endl;
}


int main()
{
    input();
    solve();
    return 0;
}
