#include<iostream>
#define MAX 31

using namespace std;

int l, r;

int sol() {
	int idx = 1;
	int a = r;
	int b = 1;
	int c = l;
	while (c > 0) {
		idx = idx * a / b;
		a--;
		b++;
		c--;
	}

	return idx;
}
int main(void) {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> l >> r;
		if (l == r) cout << 1 << "\n";
		else cout << sol() << "\n";
	}
}
//https://www.acmicpc.net/problem/1010
//������ �����ϴ� �޺���̼� �˰����̳� ;; DP�� Ǯ�����ؼ� �� DP�� �ε����� ���丮�� ���ڵ��� �־��ְ�
//���� ���̵� l �� ������ ���̵� r�� �޾Ƽ� DP[r]/(DP[l]*DP[l-r]) ���� �ٷιٷ� ���� ����Ϸ� �ߴµ� 
//���丮�� ���ڰ� 21���ص� 20�ڸ��� �Ǿ������ long long ���� ���� �� ���� ��
//�׷��� ���ÿ� �ִ� 13 29 �� �ذ��Ҷ� �ٷιٷ� �������ִ� ����� �������
//DP�� Ǯ������ ��ȭ���� ����� ����� ã�ƺ��� �����߰���