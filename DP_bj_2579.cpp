#include<iostream>
#include<algorithm>
#define MAX 301
using namespace std;
int DP[MAX],field[MAX];
int n;


int main(void) {
	cin >> n;
	int cnt = 2;
	for (int i = 0; i < n; i++) {
		cin >> field[i];
	}

	DP[0] = field[0];
	DP[1] = field[0] + field[1];
	DP[2] = field[0] + field[2];
	while (n > cnt ) {
		DP[cnt] = max(DP[cnt - 3] + field[cnt - 1], DP[cnt - 2]) + field[cnt];
		// 4��° ��ܿ� �ö����� ���� ���� ���̽��� ã�� ���ؼ� 
		// �������� �ʾ��� ���� �������� ���� ���ϰ� ���� ���� + ���� ��� ������ DP�� ����� ����
		cnt++;
	}
	cout << DP[n-1];

}
//https://www.acmicpc.net/problem/2579
//�ᱹ���� ������ +4���� �ִ��� ������ ���̽��� ���� ���� ������ ��� ���̽�
//����� 3���� ���̽������� ���� �Է��ϰ� 4�����ʹ� while������ üũ�ϸ� ��