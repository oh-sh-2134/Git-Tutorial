#include<iostream>
#include<algorithm>
#define MAX 10001

using namespace std;

int DP[MAX];
int arr[MAX];
int n;
int idx;
int getmax(int a, int b, int c) { // 3���� ������ ���ǰ�� �ݵ�� �������� ������ ���ž����� ����
	int idx[3] = { a,b,c };		  // 3���� ������ ���ô� ���̽��϶� �迭�� ��� sort�ߴµ� �ƹ� �ɼǵ� ���� ������
	sort(idx, idx + 3);			  // ������������ sort�Ѵٴ°� ������������ ������ �ð����� ���ʿ� ����� �ʿ� ����
	return idx[2] + idx[1];
}

int main(void) {
	cin >> n;
	int cnt = 3;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	DP[0] = arr[0];
	DP[1] = arr[0] + arr[1];
	DP[2] = getmax(arr[0] , arr[1] , arr[2]);
	while (cnt < n) {
		DP[cnt] = max(DP[cnt - 3] + arr[cnt - 1], DP[cnt - 2]) + arr[cnt];
		DP[cnt] = max(DP[cnt], DP[cnt - 1]); // ������ �ڸ����� �ȸ��ô� ���̽��϶� �������� max�� �� �ؾ���
		cnt++;
	}
	cout << DP[n-1];
}
//https://www.acmicpc.net/problem/2156
//������ Ǯ���� ��� ������ �����Ұ�Ǯ���µ� ������ ���� �޶� ���������
// ���� �ڸ����� �ȸ��ð� ���� �� �ִ� ���̽��� ����ؾ���