#include<iostream>
#define MAX 16

using namespace std;
int tc,top;
int DP[MAX];
int arr[MAX][2];
int max(int a, int b) {
	return a > b ? a : b;
}
int work() {
	for (int i = 0; i < tc; i++) {
		if (tc < arr[i][0] + i) continue;
		if (DP[i] <top) {
			int f = i;
			int idx=0;
			while (f>0) { // �ִ��� ã���� ù��° ���ұ��� ������ 
				if (DP[f]) // ���� ������
					idx = max(idx, DP[f]); // ũ���
				f--;
			}
			DP[i] = idx;
		}
		DP[i + arr[i][0]] = max(DP[i] + arr[i][1], DP[i + arr[i][0]]);
		//�̵��������� ũ�Ⱑ ���� Ŀ���� 
		if (top < DP[i + arr[i][0]])
			top = DP[i + arr[i][0]];
	}
	return top;
}
int main(void) {
	cin >> tc;
	for (int i = 0; i < tc; i++) {
		cin >> arr[i][0] >> arr[i][1];
	}
	cout << work();
	
}
//https://www.acmicpc.net/problem/14501
//�� ����Ŭ�� �ִ� ���� ã�� ����� ����� �߰� ã�Ƴ���
//ó������ DP[i]��°�� ���� ������(0)�� �ڷΰ��� �ִ��� ������ �Դµ�
//�Ʒ��� �ݷ��� ����� ���� ������ ���� ���ƴ�.. ���� DP[i]�� �ִ��� �������� �ʴ´ٴ� ����
/*7
2 10
5 1
5 1
5 1
5 1
5 1
1 10
���� 11
���� 20
*/