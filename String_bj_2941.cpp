#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
	vector<string> croatian = { "c=","c-","dz=","d-","lj","nj","s=","z=" };
	int idx;
	string str;
	cin >> str;
	for (int i = 0; i < croatian.size(); i++)
	{
		while (1) {
			idx = str.find(croatian[i]); // �Է¹��� ���ڿ����� croatian� �ִ��� üũ 
			if (idx == string::npos) //�� �̻� ������ �׸�
				break;
			str.replace(idx, croatian[i].length(), "#"); //�ٲܹ��ڿ��� �ִٸ� ��ü
		}
	}
	cout << str.length();
}
//https://www.acmicpc.net/problem/2941
//replace �Լ��� �̿��ؼ� ũ�ξ�Ƽ�� ���ڿ��� #���� �ٲپ