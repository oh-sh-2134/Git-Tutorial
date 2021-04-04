#include<iostream>
#include<vector>
#include<string>
using namespace std;



vector<int> failtable(string pattern) {
	int j = 0, patternsize=pattern.size();
	vector<int>table(patternsize, 0);
	for (int i = 1; i < patternsize; i++) {
		while (j > 0 && pattern[i] != pattern[j]) {
			j = table[j-1];
		}
		if (pattern[i] == pattern[j]) {
			table[i] = ++j;
		}
	}
	cout << "failtable"<<endl;
	for (int i = 0; i < patternsize; i++) {
		cout << table[i];
	}
	cout << "" << endl;
	return table;
}
void KMP(string pattern, string text) {
	int j = 0,patternsize=pattern.size(),textsize=text.size(),cnt=0;
	vector<int>table = failtable(pattern);
	vector<int>soltable(textsize,0);
	for (int i = 0; i < textsize; i++) {
		while (j > 0 && text[i] != pattern[j]) {
			j = table[j - 1];
		}
		if (text[i] == pattern[j]) {
			if (patternsize-1  == j) {
				soltable[0]= ++cnt;
				soltable[cnt] = i - patternsize + 2;
				j = table[j];
			}
			else
				j++;
		}
		cout << j;
	}
	cout << " "<< endl;
	cout << soltable[0]<<endl;
	for (int i = 1; i <= soltable[0]; i++) {
		cout << soltable[i]<<" ";
	}
}

int main() {
	string pattern, text;
	
	getline(cin, text);
	getline(cin, pattern);

	KMP(pattern,text);
}
//https://www.acmicpc.net/problem/1786
// ��� �׳� KMP �˰����� �ٽ� Ǫ�°ǵ� ���� ���̺� ����ٰ� Ž������ �ϴ� 
// �˰����� �ٽ�¥�ϱ� �򰥷��� ��û ���� Ʋ�ȴ�
// �ٽ��ѹ� ������ ö���� �ؾ��Ѵٴ� ���� ����