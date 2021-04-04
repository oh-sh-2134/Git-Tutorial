#include <iostream> 
#include <string> 
#include <algorithm> 
using namespace std; 
string Add(string &s1, string &s2) { 
	string result(max(s1.size(), s2.size()), '0'); // ���� ū ����ŭ ũ�� ����
	bool carry = false; 
	for (int i = 0; i < result.size(); i++) 
	{ 
		int temp = carry;  // ���� ���꿡�� �ø��� �߻��� �߰� ����� ��
		carry = false; 
		if (i < s1.size()) 
			temp += s1[s1.size() - i - 1] - '0'; //string�� int�� �ٲٷ��� '0'�� ����� ��

		if (i < s2.size()) 
			temp += s2[s2.size() - i - 1] - '0';

		if (temp >= 10) {  // ���ؼ� �ø����� �߻��ϴ��� üũ
			carry = true; 
			temp -= 10; 
		} 
		result[result.size() - i - 1] = temp + '0'; //������ �ִ� �ڸ����� ��� result�� �߰�
	} 
	if (carry) // �ø����� �߻��ؼ� ���ο� �ڸ����� �߻��������� �߰�
		result.insert(result.begin(), '1'); 

	return result; 
} 

int main(void) { 
	ios_base::sync_with_stdio(0); cin.tie(0); 
	int N; cin >> N; 
	string a = "0", b = "1"; 
	if (N == 0) cout << a << "\n"; 
	else if (N == 1) cout << b << "\n"; 
	else { 
		string result; 
		for (int i = 0; i <= N - 2; i++) { 
			result = Add(a, b); 
			a = b; 
			b = result; 
		} 
		cout << result << "\n"; 
	} 
	return 0; 
}
//https://www.acmicpc.net/problem/10826
//���� ���� ���̶� ������� ����µ� �˰� ���� long long���ε� �޾Ƶ� 10000��° �迭�� ������ ���� ��
//string���� �������� �ø��� �߻��Ҷ��� üũ�ؼ� �����