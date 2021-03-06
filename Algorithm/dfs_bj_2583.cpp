#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 100

using namespace std;

bool arr[MAX][MAX];
vector<int>sol;
int n, m, k;
int fx, fy, sx, sy, c;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

void paint()
{
	int px = fx > sx ? fx : sx;
	int qx = fx < sx ? fx : sx;
	int py = fy > sy ? fy : sy;
	int qy = fy < sy ? fy : sy;
	for (int i = qx; i < px; i++)
	{
		for (int j = qy; j < py; j++)
		{
			arr[i][j] = true;
		}
	}

}

void Input()
{
	cin >> n >> m >> k;
	for (int i = 0; i < k; i++)
	{
		cin >> fx >> fy >> sx >> sy;
		paint();
	}
}

void dfs(int a, int b)
{
	if (arr[a][b] == false) {
		arr[a][b] = true;
		++c;
		for (int i = 0; i < 4; i++) {
			int x = dx[i] + a;
			int y = dy[i] + b;
			if (x >= 0 && y >= 0 && x < m && y < n) {
				dfs(x, y);
			}
		}
	}
	return;
}

void solution()
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			c = 0;
			dfs(i, j);
			if (c != 0) 
				sol.push_back(c);
		}
	}
	cout << sol.size() << "\n";
	sort(sol.begin(), sol.end());
	for (int i = 0; i < sol.size(); i++)
		cout << sol[i] << " ";
	
}

int main(void)
{
	Input();
	solution();
}
//https://www.acmicpc.net/problem/2583
//모눈종이의 모든 점을 돌아다니며 색칠안된 부분을 dfs 돌려 vector에 넣어 처리예정
//x축 y축이 헷갈려서 오탑처리에 대해 오래 고민함..
