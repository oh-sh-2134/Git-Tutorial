#include<iostream>
#define MAX 1001
using namespace std;

int n;

int DP[MAX];

int tile(int i) {
	if (i == 1) return 1;
	if (i == 2) return 2;
	if (DP[i] != 0) return DP[i]; // �̹� ��� ������ �ٽ� ������
	return DP[i] = (tile(i - 1) + tile(i - 2))%10007;
}
int main(void) {
	cin >> n;
	cout << tile(n);
}
//https://www.acmicpc.net/problem/11726
//dp�� �⺻���� Ÿ�ϸ�