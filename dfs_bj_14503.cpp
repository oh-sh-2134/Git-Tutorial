#include<iostream>
#define MAX 51
using namespace std;

int n, m;
int r, c, d;
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};
int cnt=1;
int field[MAX][MAX];
int flag=0;

void dfs(int y, int x, int p) {
	if (field[y][x] == 1) return; //���ϰ�� �׳ɵ��ư�
	if (field[y][x] == 0) { // �湮 �������� �湮ó��
		field[y][x] = 2;
		cnt++;
	}
	int k = p;
	int ny, nx;
	for (int i = 0; i < 4; i++) {
		k = (k + 3) % 4; // �������� 
		ny = y + dy[k];
		nx = x + dx[k];
		if (field[ny][nx] == 0){ // �湮 ���� �ʾ����� �̵�
			dfs(ny, nx, k);
			return;
		}
	}
	ny = y + dy[(k + 2) % 4]; // ������ �ٲ��� �ʰ� ����
	nx = x + dx[(k + 2) % 4];
	dfs(ny, nx, k);

	return;
}

int main(void) {
	cin >> n >> m;
	cin >> r >> c >> d;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> field[i][j];
		}
	}
	field[r][c] = 2;
	dfs(r, c, d);
	cout << cnt;
}
//https://www.acmicpc.net/problem/14503
// ��͹����̸鼭 dfs ������ ���� �湮ó���� ���ٰ� �����ϸ� �ȵǴ°� �ٽ��ΰ� ����
// �湮������ ������ �� ������ ������ ������ ����