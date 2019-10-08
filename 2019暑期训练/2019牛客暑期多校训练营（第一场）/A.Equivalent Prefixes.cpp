/******************************************************************
用单调栈求出两个序列中每个位置前面第一个比自己大的位置记为a[],b[] 
RMQ(u,l,r)=RMQ(v,l,r) for all 1 \leq l \leq r \leq m1≤l≤r≤m
即为a[i]==b[i] for all 1 \leq l \leq r \leq m1≤l≤r≤m
******************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define maxn 100000
struct Node{
	int id,x;
}st[maxn+5],st2[maxn+5];
int a[maxn+5],b[maxn+5],n,top,top2;
void insert(int id,Node st[],int &top,int a[]){
	while(top&&a[id]<st[top].x)a[st[top].id]=id,top--;
	st[++top]={id,a[id]};
}
void del(Node st[],int &top,int a[]){
	while(top)a[st[top].id]=-1,top--;
}
void work(){
	for(int i=0;i<n;i++)scanf("%d",a+i);
	for(int i=0;i<n;i++)scanf("%d",b+i);
	for(int i=n-1;~i;i--){
		insert(i,st,top,a);
		insert(i,st2,top2,b);
	}
	del(st,top,a),del(st2,top2,b);
	int ans=0;
	for(;ans<n;ans++){
		if(a[ans]!=b[ans])break;
	}
	printf("%d\n",ans);
}
int main(){
	while(~scanf("%d",&n))work();
	return 0;
} 
