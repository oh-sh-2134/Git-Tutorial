#include<iostream>
#include<string>
#define MAX 1001

using namespace std;
/*
string dp[MAX][10];
int max(int a, int b) {
	return a > b ? a : b;
}
int main(void) {
	int n;
	cin >> n;
	for (int i = 0; i < 10; i++) {
		if (i == 9) dp[0][9] = "10";
		else dp[0][i] = (i+1) + '0';
	}

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < 10; j++) {
			if (j == 0) dp[i][j] ='1';
			else {
				string s1=dp[i - 1][j], s2=dp[i][j - 1], s3(max(s1.size(),s2.size()),'0');
				int temp;
				bool carry=false;
				for(int k = 0 ; k< s3.size(); k++){
				
					temp = 0;
					if (carry) temp += 1;
					carry = false;

					if (k<s1.size()) {
						temp += s1[s1.size() - 1 - k] - '0';
					}

					if (k<s2.size()) {
						temp += s2[s2.size() - 1 - k] - '0';
					}
					
					if (temp >= 10) {
						temp -= 10;
						carry = true;
					}
					s3[s3.size() - 1 - k] = temp + '0';
				}
				if (carry) s3.insert(s3.begin(),'1');
				dp[i][j]=s3;
			}
		}
	}
	cout << dp[n-1][9];
}
*/
int dp[MAX][10];

int main(void) {
	int n;
	cin >> n;
	for (int i = 1; i <= 10; i++) {
		dp[1][i] = i; // 1�̻��̶� ù��°�� ó���ϴ� �κ�
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= 10; j++) {
			if (j == 1) dp[i][j] = 1;
			else dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % 10007;
		}
	}
	cout << dp[n][10];
}
//https://www.acmicpc.net/problem/11057
//DP�� �����ں��� ���� �� �ִ� ���������� �����س����� dp[i][j] = dp[i - 1][j] + dp[i][j - 1] �� ����
//10007�� ������ ���� �Ⱥ��� ū���ޱ� ���� ó�� stringó���ؼ�
//������ �ؾ��ϴ� �� �˰� ��Ǭ������ 2�ð��̳� �� ����ִٰ� �ݷʵ� ���µ� ���� �ȳ��ͼ�
//�ٸ���� �ڵ� �����ߴµ� �̰� ����...