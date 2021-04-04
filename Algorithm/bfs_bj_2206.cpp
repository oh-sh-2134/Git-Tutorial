#include<iostream>
#include<queue>

#define MAX 1001

using namespace std;
int n, m;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1, 0,0 };

char field[MAX][MAX];
int cnt[MAX][MAX][2];

int bfs() {
	queue<int> q; // q�� �ʹ� ���� ����� pair�� ����ϴ� ����� �����ؾ� �� �� ����
	queue<bool>qb;
	q.push(0);
	q.push(0);
	qb.push(false);
	while (!q.empty()) {
		int y = q.front();
		q.pop();
		int x = q.front();
		q.pop();
		bool brk = qb.front();
		qb.pop();
		if (y == n - 1 && x == m - 1) return cnt[y][x][brk]+1;
		for (int i = 0; i < 4; i++) {

			int ny = y + dy[i];
			int nx = x + dx[i];
	
			if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
			if (field[ny][nx] == '0' &&  cnt[ny][nx][brk] == 0) { // 0�� ���� ���µ� �������� ���� ����
				cnt[ny][nx][brk] = cnt[y][x][brk] + 1;
				q.push(ny);
				q.push(nx);
				qb.push(brk);
			}
			if ((field[ny][nx] == '1') && !brk && cnt[ny][nx][true] == 0) { // ���� �������� �ѹ� �հ� �� �� �ִ� ���
				cnt[ny][nx][true] = cnt[y][x][brk] + 1;
				q.push(ny);
				q.push(nx);
				qb.push(true);

			}
		}
	}
	return -1;
}
int main(void) {
	cin >> n >> m;
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < m; x++) {
			cin >> field[y][x];
		}
	}
	cnt[0][0][1] = 1;
	cnt[0][0][1] = 1;
	cout << bfs();
}
//https://www.acmicpc.net/problem/2206
//bfs�� �̿��ؼ� ǰ 
//�׷��� input�� ���� �ȵ� ������ char�� �ްų� scanf�� �޾ƾ� �ϴµ� ���������ϴٰ� �� �ð�����
//���� �հ� ������ ���̽��� �׳ɰ��� ���̽��� �� ������ ���� �� �ִ� ���̽��� ����ؾ� ��
//3���� �迭���� �հ� ������ �Ͱ� �հ� �������� ���� ���̽��� �� ��ǥ�� ��� ��� �Ʒ��� �ݷʰ� �ش� ���̽�
/* �ݷ�
5 10
0000011000
1101011010
0000000010
1111111110
1111000000
���� : -1, 18
���� : 14
*/