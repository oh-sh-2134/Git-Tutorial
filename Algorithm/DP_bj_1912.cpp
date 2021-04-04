#include<iostream>

#define MAX 100001

using namespace std;

int midx;
int arr[MAX];
int DP[MAX];

int max(int a, int b) {
	return a > b ? a : b;
}
int main(void) {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	DP[0] = arr[0];
	midx = DP[0];
	for (int i = 1; i < n; i++) {
		DP[i] = max(DP[i - 1] + arr[i], arr[i]); //������ �տ� ������ ���� ���ߴµ��� ������ ���� ũ�ٸ� ���� ���� ��� ������
		midx = max(DP[i], midx);           //���� ������ �� �ִ�.
	}
	cout << midx;
}
//https://www.acmicpc.net/problem/1912
//���ɽð��� ���� �����ߴ� ���̵� �Ϻ��ϴٰ� �����ߴµ� ���� �����ͼ� Ȯ���غ��� ��ƴ�� �־���.
//ó���� �����ߴ� ���̵��� DP �����̱⶧���� �� ����Ŭ�� Ǯ������ �Ѵٰ� �����߰�
//������ ���̵��� ����ߴµ� ���ƴ� ���� ū ������ ���������� ���� ������ ������ ������ �������Ѵٴ� ���� üũ�ϴ� �κ���
//�ٽ��̶�� ���� ����Ҵ�. ���̵� �Ӹ��θ� �������� ���� ������ �Ἥ �����ϴ� ������ ����.
