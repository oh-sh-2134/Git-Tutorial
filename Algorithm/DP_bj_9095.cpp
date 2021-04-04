#include<iostream>
#include<algorithm>
#include<queue>
#define MAX 14
using namespace std;

int DP[MAX];
int field[MAX];
int add[3]={1,2,3}; // +1, +2, +3
int n, m;
void solution(int n){
	queue<int>q;
	q.push(0);
	while(!q.empty()){
	int x = q.front();
	q.pop();
		for(int i=0;i<3;i++){
			if(x + add[i] <=n){
				DP[x+add[i]]++; // DP�� �������� ������ ���� �ش��ϴ� �迭 ī��Ʈ�� �÷���
				q.push(x+add[i]);
			}
		}
	}

}

int main(void){
	int t;
	cin >> t;
	for(int i=0;i<t;i++){
		cin >> field[i];
		m = max(field[i],m); // ������ �ִ��� ���ڸ� ���ؼ� 12������ ��� ���� ��츦 ������ �ʰ� ��
	}

	solution(m);
	for(int i= 0;i<t;i++){
		cout << DP[field[i]]<<"\n";
	}
}
//https://www.acmicpc.net/problem/9095
//DP�� bfs�� �̿��ؼ� ������ ���ڿ� �����ϴ� ������� ���� ������
// MAX �������� ��Ȥ�� �־��µ� 0���� 12���� ���� ���� �Ϸ��ؼ� 13���� �ʿ��ϱ⶧���� MAX�� 14�� ����ϴµ� 
//13�����༭ ��� ����ó�� ���� 
