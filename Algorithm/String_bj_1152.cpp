#include<iostream>
#include<string>

using namespace std;
string s;

int main(void) {
	int cnt = 0;
	bool flag = true;
	getline(cin, s);

	
	for (int i = 0; i < s.size(); i++) {
		
		if ('A' <= s[i] && s[i] <= 'z') {
			if (flag) {
				cnt++;
				flag = false;
			}
		}
		else
			flag = true;
	}
	cout << cnt;
}
//https://www.acmicpc.net/problem/1152
//ó������ ' '���ڿ� üũ�ϴ� ������� �ߴµ� �׷��� ������ ä��� ���ڿ��� ������ �� ī���� ��
//���ڿ��� ��ҹ��� ���ĺ��� ���� �ۿ� ���⶧���� ���ĺ� �̿��� ���ڿ��� ������ �÷��׸� �̿��ؼ� ī���� ��