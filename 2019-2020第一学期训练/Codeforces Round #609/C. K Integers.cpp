#include<bits/stdc++.h>
using namespace std;
#define maxn 200005
#define LL long long
int a[maxn],x[maxn];
LL ans1[maxn],ans2[maxn];
int c[100005];//cΪ��״���� 
int lowbit(int x){
    return x&(-x);
}
void add(int x,int num){
    while(x<=maxn){
        c[x]+=num;
        x+=lowbit(x);//x+ lowbit(x)Ϊx�ĸ��׽ڵ� 
    }
}
int Sum(int x){
    int ans=0;
    while(x){
        ans+=c[x];
        x-=lowbit(x);//c[i]�洢i-lowbit[i]+1��i�������ֵ��������ǰ׺��Ҫ����ȥ�����һλ 
    }
    return ans;
}
int main(){
	int n;scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",a+i),x[a[i]]=i;
	add(x[1],1);
	for(int i=2;i<=n;i++){
		ans1[i]=ans1[i-1]+(i-Sum(x[i])-1);
	}
	memset(c,0,sizeof(c));
	for(int i=1;i<=n;i++){
		
	}
	return 0;
}
