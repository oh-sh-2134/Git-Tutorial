#include<iostream>
#include<queue>
#define MAX 100
using namespace std;
long long int DP[MAX];
queue<int>q;
int max(int a, int b) {
	return a > b ? a : b;
}
int main(void) {
	int n,a;
	int top=0;
	cin >> n;
	for (int i = 0; i < n; i++) { //������̽����� ����ϴ°� DP�� �������� ���� ���� ���� ã�Ƽ� �� ����ŭ�� DP�� ���ϸ� ��
		cin >> a;					//������ ���̽��� queue�� �����Ͽ� �������� ������� ���
		q.push(a);
		top = max(top,a);
	}
	DP[0] = 1;
	DP[1] = 1;
	DP[2] = 1;
	for (int i = 3; i <= top; i++) {
		DP[i] = DP[i - 2] + DP[i - 3]; // ��ȭ��
	}
	for (int i = 0; i < n; i++) {
		cout << DP[q.front()-1]<<"\n";
		q.pop();
	}
}
//https://www.acmicpc.net/problem/9461
//��Ģ�� ã�Ƽ� ��ȭ���� �߼���� �Ǵ� ����
//ó������ �׸��� ���� 8��°���� ���� �����ϰ� �� ���� ���ʹ� DP[i] = DP[i-1] + DP[i-4] �� ���ϵ��� ������µ� Ʋ��
//���̿� ����� ���������� ��ȭ���� �߸��Ȱ� Ȯ���ϰ� ���� �� �����ߴµ��� Ʋ��
//79��°���� 24��Ѱ� ������ 80��°���� int ������ ��� long long ���� �����ؼ� ����