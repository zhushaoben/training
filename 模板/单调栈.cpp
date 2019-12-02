#include<cstdio>
#define maxn 1000005
struct MonotonicStack {//单调递增栈 
	int a[maxn],top;
	MonotonicStack(){
		top=0;
	}
	void pop(){//栈顶弹出 
		if(top)top--;
	}
	int size(){//返回站内元素个数 
		return top;
	}
	void insert(int x){//插入x 
		while(top&&a[top]<=x)top--;//将不满足单调的弹出 
		a[++top]=x;
	}
}S;
int main(){
	return 0;	
}
