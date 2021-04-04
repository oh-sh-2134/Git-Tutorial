#include<iostream>
#include<queue>
#define MAX 101
using namespace std;

int n, m;
int dy[4] = { 1,-1,0,0 };
int dx[4] = { 0, 0,-1,1 };

char field[MAX][MAX];
int visited[MAX][MAX] = { 1, };
/* ó���� dfs�� Ǯ���µ� �ð��ʰ�;;
void dfs(int y, int x , int c) {
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (!(nx < 0 || nx >= m || ny < 0 || ny >= n)) {
			if (field[ny][nx] == '1') {
				field[ny][nx] = '0';
				if (visited[ny][nx] == 0 || visited[ny][nx] >= (c + 1)) {
					visited[ny][nx] = c + 1;
					dfs(ny, nx , c+1);
					cout << "dfs 1 \n";
					field[ny][nx] = '1';
				}
			}
		}
	}
	return;
}
*/
void bfs() {
	queue<int>q;
	q.push(0);
	q.push(0);
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		int y = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (!(nx < 0 || nx >= m || ny < 0 || ny >= n)) { //�̵�
				if (field[ny][nx] == '1') {
					field[ny][nx] = '0';
					if (visited[ny][nx] == 0) {
						// 1�� ����̰� �ִ� ����϶� ���� �׸��� �ߴµ� bfs������ ���� �ʿ���� q��
						// �ѹ����������� ī��Ʈ�� üũ�ϴ°� ����� ��
						visited[ny][nx] = visited[y][x] + 1;
						q.push(nx);
						q.push(ny);
						field[ny][nx] = '1';
					}
				}
			}
		}
	}
}
int main(void) {
	bool flag = false;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> field[i][j];
			if (field[i][j] != '1') flag = true;
		}
	}

	if (flag) {
		bfs();
		cout << visited[n-1][m-1];
	}
	else cout << n + m - 1;
}
// https://www.acmicpc.net/problem/2178
// dfs ���� ���� Ž�� ��������� ���� �ð� ���⵵ �̱⶧���� ù��° �� ���� �ִ� ��ΰ� ���� �������
// ���ϰ� ���� �ɸ� �� ������ bfs ���� ��쿡�� ù��°�� ������ ���� �ִ� ����̱� ������
// �ִ� �Ÿ��� ã�� ���������� bfs�� Ǫ�� ���� �´ٴ� ���� �˰� �Ǿ���.
