#include <iostream>
using namespace std;
#define MAX 201
#define Mod 1000000000
int dp[MAX][MAX];
int n, k, i, j;

void Input()
{
	cin >> n >> k;
}

void solution()
{
	for (i = 0; i <= n; i++) dp[1][i] = 1;
	for (i = 0; i <= k; i++) dp[i][0] = 1;

	for (i = 2; i <= k; i++) {
		for (j = 1; j <= n; j++) {
			dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % Mod;
		}
	}
}
int main() 
{
	Input();
	solution();
	cout << dp[k][n];
}
//https://www.acmicpc.net/problem/2225
//������ �迭�� dp[k][n]�� k���� �̿��ؼ� n���ڸ� ����� ��� �ǹ�
/*
2���� ���ؼ� 2�� �Ǵ� ����� ���� ã�ƺ���
dp[1][0] + dp[1][2]
dp[1][1] + dp[1][1]
dp[1][2] + dp[1][0]
���̽�
dp[k-1][n-0]
dp[k-1][n-1]
dp[k-1][n-2] �� ����� ������ ��� ��
��ȭ���� dp[k][n] = dp[k-1][n-0] + dp[k-1][n-1] ... + dp[k-1][n-n] �̵ǰ�
dp[k-1][0]���� dp[k-1][n-1]�� ��� ���� ���� dp[k][n-1]�� ���� �߰������� dp[k-1][n]�� �����ָ� ��
*/