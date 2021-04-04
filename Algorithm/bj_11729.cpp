#include <iostream>
using namespace std;
void hanoi(int n, int start, int to, int bypass)
{
    if(n == 1)
        printf("%d %d\n", start, to); // ���� ū ���Ǹ� ���� ��� 1->3���� �̵�
    else
    {
        hanoi(n-1,start,bypass,to); // n-1���� ������ 1->2�� �̵�
        printf("%d %d\n",start,to);
        hanoi(n-1,bypass,to,start); // n-1���� ������ 2->1�� �̵�
    }
}
int main() {
    int num;
    cin >> num;
    cout << (1<<num) -1 << "\n";
    hanoi(num,1,3,2);
}
//https://www.acmicpc.net/problem/11729
//�ٽ��� ���������� 1 -> 2�� �̵��ϴ� �� �ϳ�
//���� ū ������ 1->3���� �̵�, �������� 2->1�� �̵���Ű�� ��͸� ¥�°� �߿���
//����Լ��� Ǫ�� ������ ������ �� �� �غ��� �ҵ�
//n-1�� �ᱹ ��� �Ǵ����� �ľ��ϴ°� �߿���