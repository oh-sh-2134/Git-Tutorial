#include<iostream>
#define MAX 100001
using namespace std;

int max(int a, int b) { return a > b ? a : b; }
int dp[2][MAX];

int main(void) {
	int t; 
	cin>>t;
	while (t-- > 0) {
		int n;
		cin >>n;
		for (int i = 0; i <= 1; i++)
			for (int j = 1; j <= n; j++)
				cin >> dp[i][j];
		
		int topmax = dp[0][1];	
		int bottommax = dp[1][1];
		for (int i = 2; i <= n; i++) {
			dp[0][i] = bottommax + dp[0][i];
			dp[1][i] = topmax + dp[1][i];
			// �밢�����θ� ������ �� �ֱ⶧���� ������ bottommax�� ���� ���� ���� ���� ���� �Ʒ��� �ݴ��
			bottommax = max(bottommax, dp[1][i]);
			topmax = max(topmax, dp[0][i]);
		}	//�׸��� bottommax���� ���� ���� dp�� topmax�� ���ؼ� ū ���� topmax�� ���������
		cout<< max(bottommax,topmax) <<"\n";
	}
	return 0;
}
//https://www.acmicpc.net/problem/9465
//dp�� �����ϰ� Ǯ �� �ִ� ���� dp�� �޾Ƽ� ���ʰ� �Ʒ��ʿ����� �ִ��� �����س����� ��
//27����"\n"�ȳ־ ��ð����� �ݷʸ� ã�Ҵ�...