#include<iostream>

using namespace std;


int n;
int recu(int n) {
	if (n==0) return 0;
	if (n == 1) return 1;
	return recu(n - 1) + recu(n - 2);
}

int main(void) {
	cin >> n;
	cout << recu(n);
}

//https://www.acmicpc.net/problem/10870
// �Ǻ���ġ ���� ����
// n�� �Է¹޾� 1������ ī��Ʈ�ϸ� ����� ��� ��� ��Ÿ���� �߻�
// �ڿ������� ��� Ÿ�� ��� ����