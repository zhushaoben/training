#include<cstdio>
#define maxn 1000005
struct MonotonicStack {//��������ջ 
	int a[maxn],top;
	MonotonicStack(){
		top=0;
	}
	void pop(){//ջ������ 
		if(top)top--;
	}
	int size(){//����վ��Ԫ�ظ��� 
		return top;
	}
	void insert(int x){//����x 
		while(top&&a[top]<=x)top--;//�������㵥���ĵ��� 
		a[++top]=x;
	}
}S;
int main(){
	return 0;	
}
