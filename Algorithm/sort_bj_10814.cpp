#include<iostream>
#include<string>


using namespace std;

int sorted[100000];
string nsorted[100000];

void merge(int a[], string b[],int start, int middle, int end){
	int i=start, k=start, j=middle+1;
	while(i<=middle && j<=end){
		if(a[i]>a[j]){
			sorted[k]=a[j];
			nsorted[k]=b[j];
			j++;
		}
		else if(a[i]<a[j]){
			sorted[k]=a[i];
			nsorted[k]=b[i];
			i++;
		}
		else{
			if(i>j){
				sorted[k]=a[j];
				nsorted[k]=b[j];
				j++;
			}
			else{
				sorted[k]=a[i];
				nsorted[k]=b[i];
				i++;
			}
		}
		k++;
	}
	if(i>middle){
		for(int m=j;m<=end;m++){
			sorted[k]=a[m];
			nsorted[k]=b[m];
			k++;
		}
	}
	else{
		for(int m=i;m<=middle;m++){
			sorted[k]=a[m];
			nsorted[k]=b[m];
			k++;
		}
	}
	for(int m=start; m<=end;m++){
		a[m]=sorted[m];
		b[m]=nsorted[m];
	}
}

void merge_sort(int a[], string b[], int start, int end){
	if(start<end){
		int middle=(start+end)/2;
		merge_sort(a,b,start,middle);
		merge_sort(a,b,middle+1,end);
		merge(a,b,start,middle,end);
	}
}

int main(void){
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N, arry[100000];
	string narry[100000];
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>arry[i];
		cin>>narry[i];
	}
	merge_sort(arry,narry,0,N-1);
	for(int i=0;i<N;i++){
		cout<<arry[i]<<" "<<narry[i]<<"\n";
	}
}
//https://www.acmicpc.net/problem/10814
//ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); �� �߰� ���� �ʾƼ� ��� �ð��ʰ��� ����.
// ���� �ڵ�� c++�� ǥ�� stream ���⸦ ���� �ӵ��� ������ �ϴ� ��Ȱ�� �Ѵٰ� �Ѵ�.
//���⸦ ������ c �ڵ�� �� �̻� ����� �� ���� �ȴ�.