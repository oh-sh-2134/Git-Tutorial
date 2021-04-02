#include <iostream>
#include <string>

using namespace std;

int main(void) {
	int n;
	cin >> n;

	int count = n;
	while (n > 0) {
		string input;
		cin >> input;

		bool alphabet[26] = { false };
		bool flag = true;
		for (int i = 0; i < input.length(); i++) {
			int idx = input[i] - 'a';
			if (!alphabet[idx]) { //�湮�������� 
				alphabet[idx] = true; //�湮ó��
			}

			else if (alphabet[idx] && (input[i] != input[i - 1])) { //�׷�ܾ �ƴϸ�
				count -= 1; break; //���ָ��
			}
		}
		n--;
	}
	cout << count;

	return 0;
}
//https://www.acmicpc.net/problem/1316
//���ĺ� �����ŭ�� �迭�� ����� ���ĺ��� ���� �迭�� �湮ó�����ϰ�
//���ӵ��� ���� ���ĺ��� ���� �湮�ߴ��� üũ�ؼ� �湮 ������ ���ڿ��� �������� �ϳ��� ���ָ��