#include<iostream>
#include<queue>

using namespace std;

int dx[6] = { 1,-1,0,0,0,0, };
int dy[6] = { 0,0,1,-1,0,0 };
int dz[6] = { 0,0,0,0,1,-1 };

int arry[101][101][101];
int cnt;
int m, n, h;

queue<int> qx;
queue<int> qy;
queue<int> qz;
bool check() {
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				if (arry[i][j][k] == 0) return true;
			}
		}
	}
	return false;
}
int bfs() {
	
	while (!qx.empty()) {
		int size = qx.size();
		for (int j = 0; j<size; j++) {
			for (int i = 0; i < 6; i++) {
				int nx = qx.front() + dx[i];
				int ny = qy.front() + dy[i];
				int nz = qz.front() + dz[i];
				if (!(nx < 0 || nx >= m || ny < 0 || ny >= n || nz < 0 || nz >= h)) {
					if (arry[nz][ny][nx] == 0) {
						qx.push(nx);
						qy.push(ny);
						qz.push(nz);
						arry[nz][ny][nx] = 1;
					}
				}
			}
			qx.pop();
			qy.pop();
			qz.pop();
		}
		if(!qx.empty()) cnt++; // ���ʿ� �丶�䰡 ��� �;� ���� ���
	}
	if (check()) 	return -1;
	return cnt;

}

int main(void) {
	
	cin >> m >> n >> h;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				cin >> arry[i][j][k];
			}
		}
	}
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				if (arry[i][j][k] == 1) {
					qx.push(k);
					qy.push(j);
					qz.push(i);
				}
			}
		}
	}

	cout << bfs();
}
//https://www.acmicpc.net/problem/7569
//queue�� �̿��� bfs�� Ǯ����
// xyz�� ť�� ���� ���� ���� �丶�並 ���� ť�� �ְ�
// ���� �丶�� �������� xyz���� ���� ���� �丶�並 üũ �ϴ� ���
// check()�Լ��� �̿��ؼ� ��� ���� �� ���� ��츦 Ȯ��