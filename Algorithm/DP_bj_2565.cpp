#include<iostream>
#include<queue>
#define MAX 500

using namespace std;


int A[MAX], B[MAX];
int cnt;
int min(int a, int b){
	return a > b ? b : a;
}

int sol() {
	queue<int> q;
	for (int i = 0; i < cnt; i++) {
		for (int j = i + 1; j < cnt; j++) {
			
			if (A[i] > A[j] && B[i] > B[j]) continue;
			if (A[i] < A[j] && B[i] < B[j]) continue;
			q.push[j];

		}
	}
}
int main(void) {
	
	cin >> cnt;
	for (int i = 0; i < cnt; i++) {
		cin >> A[i] >> B[i];
	}


}
//https://www.acmicpc.net/problem/2565
//0517 �������� A�� B�� ������ ���ʷ� ���س����� ��ġ�°� ����� ����� ����