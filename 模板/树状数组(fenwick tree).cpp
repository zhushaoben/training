#include<bits/stdc++.h>
using namespace std;
const int N_FENWICK = 1e5;
int c[N_FENWICK+5];//cΪ��״���� 
inline int lowbit(int x){return x&(-x);}
void add(int x,int num){
	while(x<=N_FENWICK){
		c[x]+=num;
		x+=lowbit(x);//x+ lowbit(x)Ϊx�ĸ��׽ڵ� 
	}
}
int sum(int x){
	int ans=0;
	while(x){
		ans+=c[x];
		x-=lowbit(x);//c[i]�洢i-lowbit[i]+1��i�������ֵ��������ǰ׺��Ҫ����ȥ�����һλ 
	}
	return ans;
}
int main(){
	return 0;
}
