#include<iostream>
#define MAX 100001
#define Moduler 9901
using namespace std;
int dp[MAX][2];
int main(void) {
	int n;
	cin >> n;
	dp[1][0] = 1;
	dp[1][1] = 1;
	dp[1][2] = 1;
	for(int i = 2; i <= n; i++) {
		dp[i][0] = (dp[i - 1][1] + dp[i - 1][2]) % Moduler;
		dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % Moduler;
		dp[i][2] = (dp[i - 1][1] + dp[i - 1][0] + dp[i - 1][2]) % Moduler;
	}
	cout << (dp[n][0] + dp[n][1] + dp[n][2]) % Moduler;
}
/*https://www.acmicpc.net/problem/1309
	�̹����� ���ڰ� ���ʿ츮, �����ʿ츮 , ���°��� ����� Ǯ��Ǵ� ������
	1�϶��� ������ ���� �׸��� ������ �ϳ��� ��� �ۿ� ����
	2�϶��� 2���츮�� ���ʿ� ���ڸ� ���ԵǸ� 1���츮�� �����ʿ� ���ڰ� ���� ���� 1���츮�� ���ڰ� ���� ��� �� �ΰ����̰�,
	2���츮�� �����ʿ� ���ڸ� ���°�쵵 ���ʰ� �������� ������ �ƹ����� ���� �ʴ� ���� 1�� �츮���� ������, ����, ���°�� �� ��������
	���̽��� ���Եǰ� �ȴ�. �̳����� ��ȭ���� ����� ���Ͱ��� ��ȭ���� ����
	MAX���� 0���ϳ��� ������ �ٿ���� ������ ���µ� ���̹����ΰ��� PC�� �������� ���� ã�Ҵ�...��
*/