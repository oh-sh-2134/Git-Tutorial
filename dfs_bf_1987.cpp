#include<iostream>
#include<stack>
#include<vector>
#define MAX 21
using namespace std;

int c, r;
char field[MAX][MAX];

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

/*
char alpa[26];
int MaxCnt;
int cnt;
bool go;

bool alpaCheck(char a, int n) {
	for (int i = 0; i <= n; i++) {
		if(alpa[i] == a) return false;
	}
	return true;
}

int dfs() {
	stack<int> st;
	stack<char> as;
	st.push(0);
	st.push(0);
	as.push(field[0][0]);
	while (!st.empty()) {
		go = false;
		int x = st.top();
		st.pop();
		int y = st.top();
		st.pop();
		char a = as.top();
		as.pop();
		alpa[cnt] = a;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (!(nx < 0 || nx >= c || ny < 0 || ny >= r)) {
				if (alpaCheck(field[ny][nx], cnt)) {
					st.push(ny);
					st.push(nx);
					as.push(field[ny][nx]);
					go = true;
				}
			}
		}
		if (go) {
			cnt++;
			if (MaxCnt < cnt) MaxCnt = cnt;
		
		}
		else 
			cnt--;



	}
	return MaxCnt + 1;
}

int main() {
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++)
			cin >> field[i][j];
	}
	cout << dfs();
}
 --- ó�� § �ڵ��ε� dfs�� �̿��ؼ� ���������� 26�� �迭�� ���ĺ��� �ϳ��� �ְ� �ߺ� �Ǹ� �� ���� �ʰ� 
 --- �ִ� ���̱����� ���� MaxCnt�� �־ ���Ϸ��ߴµ� �ð� �ʰ��� ����.
 --- ������ alpaCheck �Լ��� ��θ� �ϳ� ã�� ������ for���� �ѹ��� ���� �Ǵµ� �ð� ���⵵�� Ŀ���� �����ɸ��� �� �غ��δ�
 --- �� ���������� ���� �ڵ带 �����ϴ� ���� �Ʒ��� ���� for���� ������ �ʰ� bool�� �迭�� �ð����⵵�� O(1)�� ����� ����� ���� ��
 --- �ð����⵵ ����ϴ� ����� �߰������� �޸� ����ϴ� ����� �����ϰ� ������ �ʿ��� ����
*/


bool alpa[26];
int MaxCnt;

int Max(int a, int b) { if (a > b) return a; else return b; }

void dfs(int x, int y, int cnt) {
	MaxCnt =Max(cnt, MaxCnt);
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (!(nx < 0 || nx >= c || ny < 0 || ny >= r)) {
			if (!alpa[field[ny][nx] - 'A']) {
				alpa[field[ny][nx] - 'A'] = true;
				dfs(nx, ny, cnt+1);
				alpa[field[ny][nx] - 'A'] = false;
			}
		}
	}
}

int main() {
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++)
			cin >> field[i][j];
	}
	for (int i = 0; i < 26; i++) {
		alpa[i] = false;
	}
	alpa[field[0][0] - 'A'] = true;
	dfs(0, 0, 1);
	cout << MaxCnt;
}