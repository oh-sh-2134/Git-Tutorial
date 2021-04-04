#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;
#define MAX 101

int field[MAX][MAX];
bool visited[MAX][MAX];
int temp[MAX];
int Maxh;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int n;

bool exection() { //������ ���̰� ��� ���� ��츦 ���� ����ó�� �Լ�
	int e = field[0][0];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (e != field[i][j]) return true;
		}
	}
	return false;
}
void set(int p) {// ���� ���̸� ���ڷ� �޾Ƽ� ħ�� �� ������ �湮ó���ϰ� ��
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (field[i][j] <= p) {
				visited [i][j] = true;
				
			}
			else visited[i][j] = false;
		}
	}
}

int dfs() { // stack���� dfs����Ǫ�� ����
	int cnt = 0;
	stack<int>s;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visited[i][j] == false) {
				visited[i][j] = true;
				s.push(j);
				s.push(i);
				cnt++;

			}
			while (!s.empty()) {
				int y = s.top();
				s.pop();
				int x = s.top();
				s.pop();				
				for (int k = 0; k < 4; k++) {
					int nx = x + dx[k];
					int ny = y + dy[k];
					if (!(nx < 0 || nx >= n || ny < 0 || ny >= n)) {
						if (visited[ny][nx]==false) {
							visited[ny][nx] = true;
							s.push(x);
							s.push(y);
							s.push(nx);
							s.push(ny);
							
						}
					}
				}
			}
			
			

		}
	}
	return cnt;
	
}


int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> field[i][j];
			if (field[i][j] > Maxh) // ������ �ִ� ���̸� ���ϴ� ���ǹ�
				Maxh = field[i][j];
		}
	}
	if(exection()){
		
		for (int i = 0; i <= Maxh; i++) {
			set(i); // ���� ���̿� ���� ħ�� ����
			temp[i]=dfs(); // ���������� �� ��ȯ
		}
		sort(temp, temp + Maxh);
		cout << temp[Maxh - 1];
	}
	else cout << 1;
}
//https://www.acmicpc.net/problem/2468
//����� �Ǽ��� �� 3�ð� �����Ծ���
//��Ż ����� �����ϴ� ������ �ʿ���
//0���� �ִ� ���̱��� �ݺ����� ���� ħ���ϸ� �湮ǥ�ø� �ϴ� ������� ���� Ǯ����
//������ ���̽��� �ϳ��� �迭�� ��Ƶΰ� �������� sort()�Լ��� �ִ밪 ����
//��� ���� �����϶� �ݷʵ� ó����