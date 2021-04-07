#include<iostream>
#define MAX 500
using namespace std;

int DP[MAX][MAX];
int Triangle[MAX][MAX];
int n;
int max(int a, int b) {
	return a > b ? a : b;
}
int main(void) {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			cin >> Triangle[i][j];
		}
	}
	DP[0][0] = Triangle[0][0];
	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0) //x���� 0�ΰ�� ���� �밢���� �ϳ��ۿ� ����
				DP[i][j] = DP[i - 1][j]+Triangle[i][j];
			else // 0�� �ƴҶ��� 0�� -1���ϸ� ��
				DP[i][j] = max(DP[i - 1][j], DP[i - 1][j-1]) + Triangle[i][j];
		}
	}
	int sol = 0;
	for (int i = 0; i < n; i++) {
		if (sol <= DP[n - 1][i]) sol = DP[n - 1][i];
	}
	cout << sol;
}
//https://www.acmicpc.net/problem/1932
//�ﰢ�� ������ DP�� �ִ��� ���ؼ� �����س����� �Ǵ� ����
//������ y��� x������ ������ �밢���� �� �� �ִ°� ���δ� x���� -1 �Ʒ��δ� +1 �� �� 
//����Ҷ��� �ڽ��� y����κ��� ���� DP���� x���� ���� DP�� -1�� DP�� ���ϸ� ��