#include<iostream>
#define MAX 9
using namespace std;

int n, m;
int arry[9] = {9,9,9,9,9,9,9,9,9};
bool visited[9];

void dfs(int index) {
	int cnt=0;
	if (index == m) {
		for (int i = 0; i < m; i++) {
			if (arry[i] < arry[i+1]) {
				cnt = cnt + 1;

			}
				
			else 
				return;
		}
		if(cnt==m){
			for (int i = 0; i <m; i++) {
				cout << arry[i] << " ";
			}
		}
		//cout << cnt;
		cout << endl;
		return;
	}
	
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			visited[i] = true;
			arry[index] = i;
			dfs(index + 1);
			visited[i] = false;
		}
	}
	
}
int main() {
	cin >> n >> m;
	dfs(0);
}
//https://www.acmicpc.net/problem/15650
//���� �ߴ� �������� ������ ����̶�� ������ �޷ȴµ�
// ó���� �迭�� ���� �ְ� ���ڷ� �ʱ�ȭ ���� �ʾƼ� ������ Ǫ�µ� �ð��� �� �ɸ�