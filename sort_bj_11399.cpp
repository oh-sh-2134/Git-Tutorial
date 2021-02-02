#include<iostream>
#define MAX 1000

using namespace std;
int sorted[MAX];

void merge(int arry[], int start, int middle, int end) {
	int i = start, j = middle + 1,k=start;
	while (i <= middle && j <= end) {
		if (arry[i] <= arry[j]) {
			sorted[k]=arry[i];
			i++;
		}
		else {
			sorted[k] = arry[j];
			j++;
		}
		k++;
	}
	if (j > end) {
		for (int p = i; p <= middle; p++) {
			sorted[k] = arry[p];
			k++;
		}
	}
	else {
		for (int p = j; p <= end; p++) {
			sorted[k] = arry[p];
			k++;
		}
	}
	for (int p = start; p <= end; p++) {
		arry[p] = sorted[p];
	}
	
}

void merge_sort(int arry[], int start, int end) {
	if (start < end) {
		int middle = (start + end) / 2;
		merge_sort(arry, start, middle);
		merge_sort(arry, middle+1, end);
		merge(arry, start, middle, end);
	}
}

int main() {
	//freopen("test.txt", "r", stdin);
	int N, P[1000],sum=0,stack=0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> P[i];
	}
	merge_sort(P,0,N-1);
	for (int i = 0; i < N; i++) {
		sum += P[i];
		stack += sum;
	}
	
	cout << stack;
	
}
//https://www.acmicpc.net/problem/11399
// ���� �ڵ带 ������ ¥�鼭�� �����°� ����� �Ǽ��� ���� �ð��� ���� ���´�.
//����� �Ǽ��� ���� �ʰ� �ܿ��� �ڿ������� ġ������ ������ �����غ��鼭 Ÿ��������