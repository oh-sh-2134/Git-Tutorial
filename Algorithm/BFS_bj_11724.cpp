#include<iostream>
#include<queue>
#define MAX 1001

using namespace std;
int n, m,cnt,s,d;
int field[MAX][MAX];
bool visted[MAX];
void dfs(int a) {
	visted[a] = true;
	for (int i = 1; i <= n; i++) {
		if (field[a][i] && !visted[i])
			dfs(i);
		if (i == n) return;
	}		
}
int main(void) {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		cin >> s >> d;
		field[s][d] = 1;
		field[d][s] = 1;
	}
	for (int i = 1; i <= n; i++) {
		if (!visted[i]) {
			dfs(i);
			cnt++;
		}
	}
	cout << cnt;
}
//https://www.acmicpc.net/problem/11724
//�������� bfs�� ������ Ǯ���� ����� ���������� vector�� �����ʰ� 2�����迭�� �����ؼ� Ǯ����
//dfs�� �����Ҹ� ���ϸ� �Ǵ� ������ ����