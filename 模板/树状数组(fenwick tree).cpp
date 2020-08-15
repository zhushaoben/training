#include<bits/stdc++.h>
using namespace std;
const int N_FENWICK = 1e5;
int c[N_FENWICK+5];//c为树状数组 
inline int lowbit(int x){return x&(-x);}
void add(int x,int num){
	while(x<=N_FENWICK){
		c[x]+=num;
		x+=lowbit(x);//x+ lowbit(x)为x的父亲节点 
	}
}
int sum(int x){
	int ans=0;
	while(x){
		ans+=c[x];
		x-=lowbit(x);//c[i]存储i-lowbit[i]+1到i的数组的值，所以求前缀和要不断去掉最后一位 
	}
	return ans;
}
int main(){
	return 0;
}
