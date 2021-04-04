#include<iostream>
#include<queue>
#include<stack>
using namespace std;

int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
int ice[301][301];
int check[301][301];
int n, m;
int cnt;

queue<int> q;

void push(int i, int j) { //������ �ִ� ��ǥ�� ť�� ����
	q.push(i);
	q.push(j);
}
bool dfs() { // dfs�� �̿��ؼ� ������ ���������� ���� üũ
	bool visited[301][301] = {false,};
	int div=0;
	stack<int>s;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (ice[i][j] > 0 && !visited[i][j]) { // ������ �����ϸ鼭 �湮���� ���� ��ǥ�϶�
				visited[i][j] = true;
				s.push(i);
				s.push(j);
				while (!s.empty()) {
					int x = s.top();
					s.pop();
					int y = s.top();
					s.pop();
						for (int c = 0; c < 4; c++) {
							int nx = x + dx[c];
							int ny = y + dy[c];
							if (!(nx < 0 || nx >= m || ny < 0 || ny >= n)) {
								if (ice[ny][nx] > 0 && !visited[ny][nx]) {
									visited[ny][nx] = true;
									s.push(y);
									s.push(x);
									s.push(ny);
									s.push(nx);

								}
							}
						}	
				}
				div++; // ����üũ ������ �ѹ� �̻� Ÿ�ԵǸ� ��� ������ üũ�ϱ� ������ 
			}
			if (div>1) return true; // div�� 2�̻󸸵Ǹ� �������� ������ Ȯ���ϰ� return
		}
	}
	return false;
}
void melt() { // ������ �ѹ��� �쿩 �ִ� �Լ�
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			while (check[i][j] && ice[i][j]) {
				check[i][j]--;
				ice[i][j]--;
			}
			check[i][j] = 0; // check�� �ʱ�ȭ �����ָ� �������� �� ���� ����
		}
	}

}
int bfs() {
	while (!q.empty()) {
		int size = q.size()/2; // x,y�� ť�� �ѹ��� �־ 2���� ���� 2�� �����������(�Ǽ��� �κ�)
		for (int c = 0; c < size; c++) {
			int y = q.front();
			q.pop();
			int x = q.front();
			q.pop();
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if(!(nx<0 || nx>=m || ny<0 || ny>=n)){
					if (ice[y][x]>0 && ice[ny][nx] == 0) {
						check[y][x]++;
					}
				}
			}
			if (ice[y][x] > 0) {
				push(y, x);
			}
		}
		melt();
		if(!q.empty()) cnt++;
		if (dfs()) return cnt;	
	}
	return 0;

}
int main(void) {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> ice[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (ice[i][j] != 0) {
				push(i, j);
			}
		}
	}
	cout<<bfs();

}
//https://www.acmicpc.net/problem/2573
//�� ������ ���� ��� �����ϰ� �Ǽ��� ���� �ߴ�
//�ٽ��� ������ �ϳ��� ������ �ȵȴٴ� ���̴�. melt�Լ��� ���� ������ �������� �ѹ��� �쿩��� �Ѵ�.
//Ȥ�ö� �ؾ������ ����ϴ� ���ú��ʹ� ��� ���ο� ������ �޾ƾ߰ڴ�.