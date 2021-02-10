#include<iostream>
#include<stdlib.h>

using namespace std;

int n;
int b[15];
int cont;

bool promising(int s){
	for (int i = 0; i < s; i++) {
		if ((b[s] == b[i]) | (s - i == abs(b[s] - b[i])))
			return false;
	}
	return true;
	
}

void check(int s) {
	if (s == n) {
		cont++;
		return;
	}

	for (int i = 0; i < n; i++) {
		b[s] = i;
		if (promising(s)) {
			check(s + 1);
		}
		
	}
}

int main(void) {
	cin >> n;
	check(0);
	cout << cont;
}

//https://www.acmicpc.net/problem/9663
// �̷�ã�� ������ Ǯ��� ������ ��Ʈ��ŷ�� �ʿ��� �� ���Ƽ� ���� ��
