#include<iostream>
#include<queue>
#include<vector>
#include<stack>
#include<cstring>
#define MAX 20001
using namespace std;

vector<int> v[MAX];
int check[MAX];
bool visited[MAX];
int t, n, c, a, b;

void makeTree(int a, int b) {
	v[a].push_back(b);
	v[b].push_back(a);
}
bool dfs(int a) {
	stack<int> s;
	s.push(a);
	while (!s.empty()) {
		int scnt = s.size();
		for (int i = 0; i < scnt; i++) {
			int x = s.top();
			s.pop();
			if (visited[x]) continue;
			visited[x] = true;
			for (int j = 0; j < v[x].size(); j++) {
				int y = v[x][j];
				if (y > n) continue;;
				if (check[x] == check[y]) {
					return false; // �̺� �׷����� �ƴ϶�� �� �̻� Ž���� �ʿ� ����
				}
				s.push(y);
			}
		}
	}
	return true;
}
void bfs(int a) {
	int rvs = 1;
	queue<int>q;
	q.push(a);
	while (!q.empty()) {
		int cnt = q.size();
		for (int i = 0; i < cnt; i++) { // ���� ������ �湮�� �� �ֵ���
			int x = q.front();
			q.pop();
			if (check[x] != 0) continue;
			check[x] = rvs;
			for (int j = 0; j < v[x].size(); j++) {
				int y = v[x][j];
				if (y > n) continue;
				q.push(v[x][j]);
			}
		}
		rvs *= -1; // ���� ������ �����
	}
}



int main(void) {
	cin >> t;
	int sol[5] = { 1, 1,1,1,1 };
	for (int i = 0; i < t; i++) {
		cin >> n >> c;
		for (int j = 0; j < c; j++) {
			cin >> a >> b;
			makeTree(a, b);
		}
		if (n == 1) {
			sol[i] = true;
			continue;
		}
		for (int j = 1; j <= n; j++) {
			bfs(j);
		}
		for (int j = 1; j <= n; j++) {
			if (!dfs(j)) {
				sol[i] = 0;
				break; // �̺б׷����� �ƴ϶�� �� �̻� Ž���� �ʿ䰡 ����
			}
		}
		for (int j = 1; j <= n; j++) {
			v[j].clear();
		}
		memset(visited, false, sizeof(visited));
		memset(check, 0, sizeof(check));
	}
	for (int i = 0; i < t; i++) {
		if (sol[i]) cout << "YES\n";
		else cout << "NO\n";
	}
}
/*2
3 3
1 2
2 3
3 1
2 1
1 2
NO
YES*/
//https://www.acmicpc.net/problem/1707
//bfs�� ��ĥ �� bfs�� üũ ���� 
//�ڵ尡 �ʹ� ������ �������� ������ ���̽����� �ٽ�Ǫ�� �ɷ�...
