#include<iostream>
#define MAX 1001
using namespace std;

int DP[MAX];
int n;

int tile(int i) {
	if (i == 1) return 1;
	if (i == 2) return 3; // n-2�� �����ϴ� ���̽��� 2,2 �ϳ��� 2,1 1,2 ���� �ΰ��� ä��� �� ������
						// return �ϴ� ���̽������� ������ 2ĭ�� ���Ҵٰ� �����ؼ� 3���� ���̽�
	if (DP[i] != 0) return DP[i];
	return DP[i] = (tile(i - 1) + 2*tile(i - 2))%10007; 
}								// 2���ϴ� ������2,2 �� ä��� ����� 1,2�� �ΰ� ä��� ��� 2,1�� ä��� 
								// i == 1 ���̽��� ������
								
int main(void) {
	cin >> n;
	cout << tile(n);
}
// https://www.acmicpc.net/problem/11727
// Ÿ�ϸ� ���� 2