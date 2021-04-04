#include<iostream>
#include<vector>
#include<queue>


using namespace std;

vector<int>sum[101];
//bool visited[101];
int ch, pr;
//int cnt=1;
int cnt[101];
void maketree(int a, int b) {
	sum[a].push_back(b);
	sum[b].push_back(a);
}
/*
bool promising(int c) {
	queue<int> p;
	p.push(c);
	while (!p.empty()) {
		int x = p.front();
		p.pop();
		for (int i = 0; i < sum[x].size(); i++) {
			int y = sum[x][i];
			if (!visited[y]) {
				if (y == ch) return true;
				p.push(y);
			}
		}
	}
	return false;
}

void bfs() {
	queue<int> q;
	q.push(pr);
	visited[pr] = true;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int i = 0; i < sum[x].size(); i++) {
			int y = sum[x][i];
			if (!visited[y] && promising(y)) {
				cnt++;
				if (y == ch) return;
				visited[y] = true;
				q.push(y);
			}
		}
	}

}*/
int bfs() {
	queue<int> q;
	q.push(pr);
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		if (x == ch) return cnt[x];
		for (int i = 0; i < sum[x].size(); i++) {
			int y = sum[x][i];
			if (cnt[y]==0 ) {
				cnt[y] = cnt[x] + 1;
				q.push(y);
				
			}
		}
	}
	return -1;

}
int main(void) {
	int n,k;
	int a, b;
	cin >> n;
	cin >> ch >> pr;
	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> a >> b;
		maketree(a, b);
	}
	cout << bfs();


}

//https://www.acmicpc.net/problem/2644
// ���õ� �޸��ʰ�;;
// ��Ʈ��ŷ�� �̿��Ϸ� �ߴµ� �ð��� �ָ��ؼ�
// �ٸ������ Ǯ�̸� ������
// �湮�� ��带 �湮 ó���ϴ� ���� �ƴϰ� ���� ���� �������� +1�� �Ͽ� �̼� ���