#include<iostream>
#include<vector>
#include<string>

using namespace std;

vector<int> failtable(string pattern) {
	int patternsize = pattern.size();
	vector<int>table(patternsize, 0);
	int j = 0;
	for (int i = 1; i < patternsize; i++) {
		while (j > 0 && pattern[i] != pattern[j]) {
			j = table[j - 1];
		}
		if (pattern[i] == pattern[j]) {
			table[i] = ++j;
		}
	}
	return table;
}

int main() {
	int L;
	string S;
	cin >> L>>S;
	
	vector<int>table = failtable(S);
	
	cout << L-table[L-1];

}
//https://www.acmicpc.net/problem/3356
// ������ Ǯ���� ������ ������ ������ ���� �� ����� ������ Ǯ����� �� ����
