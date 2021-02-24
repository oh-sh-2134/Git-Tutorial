#include<iostream>
#include<queue>
#define MAX 1000001
using namespace std;

int s, g, f, u, d;
int h[MAX] = { 0, };
bool flag = false;


void bfs(){
	queue<int>q;
	q.push(s);
	h[s] = 1;
	while (!q.empty()) {
		int y = q.front();
		q.pop();
		if (y == g) { // ���� ���������� flag
			flag = true;
			return;
		}
		for (int i = 0; i < 2; i++) {
			int ny;

			if (i == 0)  ny = y + u;  // �ö� ��
			else if(i == 1) ny = y - d; // ������ ��

			if (ny > 0 && ny <= f && h[ny]==0) { // f�� �ִ� ���̰� 1�� �̻��̿��� ��
				q.push(ny);
				h[ny] = h[y] + 1;
			}
		}
	}
	return;
}

int main() {
	cin >> f >> s >> g >> u >> d;

	bfs();
	if (flag)cout << h[g] - 1;
	else cout << "use the stairs";
}
//https://www.acmicpc.net/problem/5014
//�����ϰ� Ǯ����.