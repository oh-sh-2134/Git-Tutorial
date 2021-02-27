#include<iostream>

#define MAX 501
using namespace std;

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int field[MAX][MAX];
int dp[MAX][MAX];
int n;
int maxcnt;
int ch(int a, int b) {
	if (a > b) {
		return a;
	}
	return b;
}
int dfs(int y, int x) {

	if (dp[y][x] != 0) return dp[y][x]; //dp�� �������ִ� ���� �ִ°��
	dp[y][x]=1; // �湮�� ��湮�� ���� �ʰ��ϱ� ����

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (!(nx < 0 || nx >= n || ny < 0 || ny >= n)) {
			if (field[y][x] < field[ny][nx]) {
				dp[y][x] = ch(dfs(ny, nx) + 1, dp[y][x]); //�ι� ������� �ʰ� �ϱ����� dp�� ����� ������ ���
			}
		}
	}
	return dp[y][x];
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> field[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			maxcnt = ch(maxcnt , dfs(i, j));
		}
	}
	cout << maxcnt;
}
//https://www.acmicpc.net/problem/1937
// dfs�� ��Ǯ���� dp���� �����ߴµ� ������ Ǭ�������� �����𸣰� dp������ ����ϰ� �־���;;