#include<iostream>
#include<queue>
#define MAX 100

#define Cheese 1
#define Air 0
#define MeltedAir 5

using namespace std;


int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int m, n,cnt;
int arr[MAX][MAX];
int cntfield[MAX][MAX];


void Input()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}
	}
}

bool CheesCheck()
{
	bool flag = false;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if(arr[i][j] == 1) flag = true;
			cntfield[i][j] = 0;
		}
	}
	return flag;
}

void Airing()
{
	queue<pair<int,int>>q;
	q.push(make_pair(0,0));
	arr[0][0] = MeltedAir;

	while(!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		for(int i=0;i<4;i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
		
			if (x < 0 || y < 0 || x >= m || y >= n) continue;
			if (arr[ny][nx] == 0 ) arr[ny][nx] = MeltedAir;

		}
	}
		
}

void dfs(int a, int b)
{
	if (arr[a][b] == 1)
	{
		arr[a][b] = 2;
		for (int i = 0; i < 8; i++)
		{
			int y = a + dy[i];
			int x = b + dx[i];
			if (x < 0 || y < 0 || x >= m || y >= n) continue;
			dfs(y, x);
		}
	}

}

void solution()
{
	while(CheesCheck())
	{
		Airing();



	}

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (arr[i][j] == 1)
			{
				dfs(i, j);
				cnt++;	
			}
		}
	}
	cout << cnt;

}

int main(void)
{
	Input();
	solution();
}

//https://www.acmicpc.net/problem/2638
//���� ġ�� ������ �������� ���⿡ ��� ���� 2�� �̻��϶� ��´ٴ� ��
//���� ��� ���⸦ �����ϴ� �Լ�, ġ� �����ϴ��� Ȯ���ϴ� �Լ� ���� dfs�� solution�Լ� �����ؾ���