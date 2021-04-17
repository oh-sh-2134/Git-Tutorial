#include<iostream>
#include<queue>
#define MAX 51

using namespace std;

int land[MAX][MAX];
int n, m, cnt;;

int dx[8] = { 1,-1,0,0,1,1,-1,-1};
int dy[8] = { 0,0,-1,1,1, -1,1,-1};
//�밢���� �־ 8���� �����
void dfs(int x,int y) {
	queue<pair<int, int>>q;
	q.push(make_pair(x, y));
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 8; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (!(nx > 0 || nx<=n || ny >0 || ny <= m)) continue; //������ ����� 
			if (land[nx][ny]) {
				land[nx][ny] = 0;
				q.push(make_pair(nx, ny));
			}
		}
	}

}
int main(void) {
	while (1) {
		cin >> n >> m;
		if (n + m == 0)break;
		cnt = 0;
		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= n; j++) {
				cin >> land[i][j];
			}
		}
		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= n; j++) {
				if (land[i][j]){
					land[i][j] = 0;
					dfs(i,j);
					cnt++;
				}
			}
		}
		cout << cnt << "\n";
	}
}
//https://www.acmicpc.net/problem/4963
//���� ��ġ�� 1�� 0���� �ֱ⶧���� ���� �湮ó���� ���� visted�迭�� �������� �ʰ�
//ladn �迭�� �ѹ��� ó���طȰ� �迭 �ʱ�ȭ�� �湮�ϸ鼭 0���� �ٲ��ֱ⶧���� ���� ���� �ʾƵ� �� 