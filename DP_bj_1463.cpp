#include<iostream>
#include<algorithm>
#define MAX 1000001

using namespace std;
int DP[MAX];

int main() {
	int n;
	cin >> n;
	DP[1] = 0;
	
	for (int cnt = 2; cnt <= n; cnt++) {
		DP[cnt] = DP[cnt - 1] + 1;
		if (cnt % 2 == 0) {
			DP[cnt] = min(DP[cnt / 2]+1, DP[cnt]);
			//cnt-1 ���� ���̽����� cnt/2��°���� + 1�� ����� ���� �����־����
			//2�� 3���� �������� 1�� ���� �ּڰ��� �Ǵ� ���̽��� ����
			//571�� ���ε��
			//571 - 570 - 190 - 95 - 94 - 47 - 13 - 12 - 4 - 2 - 1
			//571 - 570 - 190 - 189 - 63 - 21 - 7 - 6 - 3 - 1
			//�ݷ� (���� �Խ��� ��ó)642, 643 , 734, 740, 842
		}
		if (cnt % 3 == 0) {
			DP[cnt] = min(DP[cnt / 3]+1, DP[cnt]);
		}
	
	}
	cout << DP[n];
}
//https://www.acmicpc.net/problem/1463
// ���� ���̽� ������ �� Ʋ������ �𸣰� ���� ����ϴ� ���ͳ��� ������ ����
// �ʹ��� ��ư�;;