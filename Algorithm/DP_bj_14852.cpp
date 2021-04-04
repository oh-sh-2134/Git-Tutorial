#include<iostream>
#define MAX 1000001

using namespace std;

long long int DP[MAX][2];
int n;

long long int tiling(int x) {
	DP[0][0] = 1;
	DP[1][0] = 2;
	DP[2][0] = 7;
	for (int i = 3; i <= x; i++) {
		DP[i][1] = (DP[i - 3][0] + DP[i - 1][1]) % 1000000007;
		DP[i][0] = (3*DP[i-2][0] + 2*DP[i-1][0] + 2*DP[i][1]) % 1000000007;
	}
	return DP[x][0];
}

int main(void) {
	cin >> n;
	cout << tiling(n);
}
//https://www.acmicpc.net/problem/14852
//������ ��Ǯ�ھ ���ͳ��� �˾ƺ��鼭 Ǯ���µ�
//14�������� DP[i - 3][0] + DP[i - 1][1]�� ���ذ� �Ȱ��µ� ������ ����
//����� ��� �ᱹ ȥ�� �����ϰ� �ٸ�������� ���� ���� ������ �����.
//https://www.acmicpc.net/board/view/43033 ��ũ