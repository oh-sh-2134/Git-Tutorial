#include<iostream>
#include<queue>
#include<cstring>

#define MAX 100

using namespace std;

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,-1,1 };

int cheese[MAX][MAX];
bool visited[MAX][MAX];
int n, m,cnt1,cnt2;

void bfs(int a, int b) {
	queue<pair<int, int>>q1;
	queue<pair<int, int>>q2;
	q1.push(make_pair(a, b));
	cnt2 = 0;
	while (!q1.empty()) {
		int x = q1.front().first;
		int y = q1.front().second;
		q1.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (!cheese[nx][ny]) q2.push(make_pair(x, y));
			if (cheese[nx][ny]&&(!visited[nx][ny])) {
				visited[nx][ny] = true;
				q1.push(make_pair(nx, ny));
				cnt2++;
			}
		}
	}
	while (!q2.empty()) {
		int x = q1.front().first;
		int y = q1.front().second;
		q2.pop();
		cheese[x][y] = 0;
	}
}
int main(void) {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> cheese[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (cheese[i][j] == 1) {
				visited[i][j] = true;
				bfs(i, j);
				memset(visited, false, sizeof(visited));
				cnt1++;
			}
		}
	}
	cout << cnt1 << "\n" << cnt2;
}
//https://www.acmicpc.net/problem/2636
//���Ϲ����� ����ϴٰ� �����ߴµ� ġ�� ���۾ȿ����� ġ� ���� �ʴ´ٴ� ���� ��ħ