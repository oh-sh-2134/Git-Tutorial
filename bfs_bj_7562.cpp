#include<iostream>
#include<queue>
#include<cstring>

#define MAX 300

using namespace std;

int dx[8] = { 2,2,-2,-2,-1,1,-1,1 }; // ����Ʈ�� �̵��� �°� �����̴� �迭����
int dy[8] = { 1,-1,1,-1,2,2,-2,-2 };
int field[MAX][MAX];

int n, m,tn,tm;
int b;
int bfs() {
	queue<pair<int,int>>q;
	q.push(pair<int,int>(n,m));
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		if ((x == tn) && (y == tm)) return field[tn][tm]; // ��ǥ������ �������� ��
		if (n == tn && m == tm) return 0; // ����Ʈ�� ��ġ�� ��ǥ������ ���� ��
		for (int i = 0; i < 8; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= b || ny < 0 || ny >= b) continue;
			if (field[nx][ny] == 0) {
				field[nx][ny] = field[x][y] + 1;
				q.push(pair<int, int>(nx, ny));
			}
		}

	}
	return field[tn][tm];
}
int main(void) {
	int k;
	queue<int>cntQ;
	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> b;
		cin >> n >> m;
		cin >> tn >> tm;
		cntQ.push(bfs()); // �������̽��� �־��� ��� q�� ����
		for (int p = 0; p < b; p++) {
			for (int q = 0; q < b; q++) {
				cout << field[p][q]<< " ";
			}
			cout << endl;
		}
		for(int j=0;j<b;j++)
			memset(field[j], 0, sizeof(field[j])); // �������̽��� ���� �޸� ������ ��
	}
	for (int i = 0; i < k; i++) {
		cout << cntQ.front()<<"\n";
		cntQ.pop();
	}
}
//https://www.acmicpc.net/problem/7562
//bfs�� �̿��ϸ� �����ϰ� Ǯ �� ����
//pair�� ����غôµ� ������ ���� ��� �̿� ���� ,�Ǽ� ����