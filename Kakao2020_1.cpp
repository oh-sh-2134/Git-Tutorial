#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string s) {
	int n = s.length();
	int cnt = 0, i = 0;
	for (int k = 1; k <= n / 2; k++) { // ���� �� �ִ� ���ڿ��� �ѱ���
		if (i + k > n) { // ������ �������
			cnt += n - i;
			break;
		}
		// ���ϴ� �κ� ���
	
	}
	int answer = 0;
	return answer;
}

int main(void) {
	string s = "aabbaccc"; //7
	cout << solution(s);

}
//https://tech.kakao.com/2019/10/02/kakao-blind-recruitment-2020-round1/
//���ڿ��� ���̰� n�϶� 2/n ���� ũ�� �߶�� ��