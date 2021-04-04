#include<iostream>
#include<string>

using namespace std;

int max(int a, int b) {
	return a > b ? a : b;
}
int main(void) {
	string s1, s2;
	cin >> s1 >> s2;
	string s3(max(s1.size(), s2.size()),'0');
	int temp = 0;
	bool carry = false;
	for (int i = 0; i < s3.size(); i++) {
		int temp = carry;
		carry = false;

		if (s1.size() > i) {
			temp += s1[s1.size() - i - 1] - '0';
		}

		if (s2.size() > i) {
			temp += s2[s2.size() - i - 1] - '0';
		}

		if (temp >= 10) {
			carry = true;
			temp -= 10;
		}
		s3[s3.size() - i - 1] = temp + '0';
	}
	if (carry) {
		s3.insert(s3.begin(), '1');
	}
	cout << s3;
}
//https://www.acmicpc.net/problem/10757
//���ڰ� Ŀ�� ������ ������ ���� �� ���� �����̴�.
//string���� �޾Ƽ� ������ �迭�� �����Ͽ� �ø� �߻��� ó���ϴ� �������� ǰ
//���� Ǯ���� �ĺ���ġ4�� ������ ���� ��