#include <iostream>
#include <string>
using namespace std;

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		string s;
		cin >> s;
		int a = s[0] - '0';
		int b = s[2] - '0';
		cout << a + b << '\n';
	}
	return 0;
}
//https://www.acmicpc.net/problem/10953
//10���Ϸθ� �ޱ⶧���� ��Ʈ������ �޾Ƽ� ù��°�� ����° �ε����� �����ָ��
//ȸ�翡�� �Ľ����α׷� ����� �迡 �ѹ��غ���