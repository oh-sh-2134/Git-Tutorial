#include<iostream>


using namespace std;

int N;
int sum;
int recu(int n){

	if(n<=1) return 1;

	sum = n*recu(n-1);

	return sum;
}

int main(){
	
	cin>>N;
	cout<<recu(N);

}
//https://www.acmicpc.net/problem/10872
//���� ���̶� ������ ����Լ� ���� ��