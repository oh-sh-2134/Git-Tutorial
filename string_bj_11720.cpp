#include<iostream>
#define MAX 100

using namespace std;
char str[MAX];

int main(void) {
	int n, tmp = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> str[i];
		tmp += str[i] - '0'; // �ƽ�Ű �ڵ��� ���̸� �̿���
	}
	cout << tmp;
}
//https://www.acmicpc.net/problem/11720
//�ֱ� ��Ʈ�� ���� ������ ���� Ǯ�����..
//�غ��ؾ��Ұ� �־ ����� ��..