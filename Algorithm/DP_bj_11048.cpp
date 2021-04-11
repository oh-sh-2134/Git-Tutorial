#include<iostream>
#include<queue>
#define MAX 1001

using namespace std;

int dp[MAX][MAX];

int max(int a, int b) {
	return a > b ? a : b;
}

int main(void) {
	int n,m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> dp[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		for(int j = 1;j <= m; j++){
			dp[i][j] += max(dp[i][j - 1], max(dp[i - 1][j], dp[i - 1][j - 1]));
			/* (i, j)�� �̵������� ��ÿ� (i-1,j),(i,j-1),(i-1,j-1)�� ����Ǿ� �ִ� dp �߿���
				���� ū ���� ã�Ƽ� ���ذ��� �ǰ� �߰� �迭�� �ʿ���� ������ �̷ο�
				��������鼭 �ִ밪�� ����� ���� ��
			*/
		}
	}
	
	cout << dp[n][m];

}
//https://www.acmicpc.net/problem/11048
//��ü�� �̵��ϸ� �ش� �̷�ĭ�� �ִ��� ���� ������ �� dp�̿�