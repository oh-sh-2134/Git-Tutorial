#include<iostream>
#include <stdlib.h>
#include <stack>
using namespace std;
int main() {
	int K, n;
	cin >> K;

	stack<int> s;
	for (int i = 0; i < K; i++) {
		cin >> n;
		if (n)
			s.push(n);
		else
			s.pop();
	}

	int sum = 0;
	while (!s.empty()) {
		sum += s.top();
		s.pop();
	}
	cout << sum;

}
//https://www.acmicpc.net/problem/10773
//�ð��� ��� ���ù��� �����ϰ� ǰ