#include<iostream>
#include<string>

using namespace std;
int arr[26];
int main(void) {
	string s;
	cin >> s;
	for (int i = 0; i < 26; i++) {
		arr[i] = -1; // �迭�� ��� -1�� �ʱ�ȭ
	}
	for (int i = 0; i < s.size(); i++) {
		if (arr[s[i] - 'a'] == -1) // �ƽ�Ű �ڵ��� ���� �̿��� �� �迭�� ����
			arr[s[i] - 'a'] = i;
	}
	for (int i = 0; i < 26; i++) {
		cout << arr[i] << " ";
	}
}
//https://www.acmicpc.net/problem/10809
//�ƽ�Ű �ڵ��� ���̸� �̿��ϴ� ���ڿ� ����