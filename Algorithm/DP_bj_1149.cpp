#include<iostream>
#define MAX 1000
#define R 0
#define G 1
#define B 2

using namespace std;
int street[3][1000];
int dp[3][1000];

int min(int a,int  b) {
	return a > b ? b : a;
}
int main(void) {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> street[j][i];
		}
	}
	for (int i = 0; i < 3; i++) dp[i][0] = street[i][0];

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			if (j == R) //R�϶��� ���� DP�� min(G,B)�� ���ϸ� ��
				dp[R][i] = min(dp[G][i - 1], dp[B][i - 1]) + street[R][i];
			else if(j == G) //G�϶��� ���� DP�� min(R,B)�� ���ϸ� ��
				dp[G][i] = min(dp[R][i - 1], dp[B][i - 1]) + street[G][i];
			else //B�϶��� ���� DP�� min(R,G)�� ���ϸ� ��
				dp[B][i] = min(dp[R][i - 1], dp[G][i - 1]) + street[B][i];
		}
	}
	cout << min(min(dp[R][n - 1], dp[G][n - 1]), dp[B][n - 1]); //������ �Ÿ����� �ּڰ��� ������ DP�� solution
}
//https://www.acmicpc.net/problem/1149
//DP �̿�, ���� �ߺ����� ���� ���� DP�� �ּڰ��� ���� ����� ���ذ��� �������� 3���� �迭�� ���� ���� ���� �ּڰ��� ��