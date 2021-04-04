#include<iostream>
#include<queue>

#define MAX 100001
using namespace std;


int visited[MAX]; // �湮�� ī��Ʈ�� ���ÿ� ���� �� �ְ� int arry�� ����

int bfs(int s, int b) {
	queue<int> q;
	q.push(s);
	while (!q.empty()) {
		int x = q.front();
		if (x == b) return visited[b];
		q.pop();
		for (int i = 0; i < 3; i++) {
			int nx = 0;
			if (i == 0) nx = x + 1;
			else if(i==1) nx = x  - 1;
			else if(i==2) nx =  2*x;

			if (!(nx < 0 || nx -1  > MAX )) {
				if (visited[nx] == 0) {
					q.push(nx);
					visited[nx] = visited[x] + 1;
				}
			}
		}
	}
	return visited[b];
}

int main(void) {
	int su, bro;
	cin >> su >> bro;
	cout << bfs(su, bro);
}
//https://www.acmicpc.net/problem/1697
// bfs�� Ǫ�°� ���� ����ߴµ� �İ��� �� �ȳ���
//���ͳ� ��������