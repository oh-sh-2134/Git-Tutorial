#include<iostream>

using namespace std;

int n, m;
int arry[7];

void dfs(int a) {
	if (a == m) {
		for (int i = 0; i < m; i++) {
			cout << arry[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 1; i <= n; i++) {
		arry[a] = i;
		dfs(a + 1);
	}
	
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	dfs(0);
}
//https://www.acmicpc.net/problem/15651
// �ð� �ʰ��� ��� ���� �ٶ��� ���� ã�ƺôµ�
// endl�� ���۸� ����� �ϱ⶧���� endl ���� "\n"�� �ξ� �����ٴ� ���� ���