#include<iostream>
#define MAX 100001
#define min(a,b) a>b?b:a;
using namespace std;
int dp[MAX];
int main(void) {
	int n, k=1, cnt = 0;
	cin >> n;
	dp[1] = 1;
	for (int i = 2; i <= n; i++) {
		int p = i;
		if (p - (k + 1)*(k + 1) >= 0) // �������� ���������� ���� ū ���� ã�� ���ǹ�
			k += 1;
		dp[i] = 999999999;
		int c = k;
		while (c > 0) {   
			if (p - c * c >= 0) {
				dp[i] = min(dp[p - c * c] + 1,dp[i]); // ���������� ���������� ���� ū ������ 1���� ���ʷ� ���鼭 ���������ڴ� dp�� �����ͼ� ��
				c--;
			} 
		}
	}
	cout << dp[n];
}
//https://www.acmicpc.net/problem/1699
//������ Ʋ�ȴ� ���� �� ���� 11052 ī�� �����ϱ� ������ ����ϰ� Ǯ�� �ȴٰ� �Ǵ��ϰ� 2Ʈ���� ���
//�Ʒ��������� n���� �� dp�� ���� ���� Ƚ������ �����ϰ� ������ ��
