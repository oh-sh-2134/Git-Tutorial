#include<iostream>

using namespace std;
int k, n;

int Sol(int a, int b) {
	if (b == 1)
		return 1;
	if (a == 0)
		return b;
	return (Sol(a - 1, b) + Sol(a, b - 1));
}

int main() {
	int T, k, n;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> k >> n;
		cout << Sol(k, n) << "\n";
	}
}
//https://www.acmicpc.net/problem/2775
//k���� nȣ�ǿ� ����� k-1�� nȣ�ǰ� k�� n-1ȣ���� �ο����� ���� ������ ����� ����
//��ȭ�ĸ� �� ã���� ����ǰ