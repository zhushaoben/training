#include<cstdio>
#define maxk 2000001//maxk为滑动窗口最长长度 
struct HumdrumQueue{
	int s,t,k,a[maxk],id[maxk];//a为存储数据，id为入队顺序,s,t分别为队首,队尾+1,k为滑动窗口长度 
	int top(){//返回队首 
		if(s==t)return 0;//为空就返回0 
		return a[s];
	}
	void pop(){//队首出队 
		if(s!=t)s++;
	}
	void insert(int x,int i){//加入x,当前是第i个数据 
		while(s!=t&&a[t-1]>=x){//队尾不满足单调的出队 
			t--;
			if(t==-1)t=k;
		}
		if(i-id[s]>=k)pop();//队首如果不属于滑动窗口,则出队 
		a[t]=x,id[t++]=i,t%=maxk;//因为队列中元素不大于maxk，所以使用循环队列 
	}
}q;

const int N=1e5+5;
struct Q{
	int q[N],id[N],s,t,k;
	void init(){s=t=0;}
	void insert(int x,int i){
		while(s<t&&i-id[s]>=k)s++;
		while(s<t&&x>q[t-1])t--;
		q[t]=x,id[t]=i;t++;
	}
	int top(){return q[s];}
}q;
int main(){
	return 0;
} 
