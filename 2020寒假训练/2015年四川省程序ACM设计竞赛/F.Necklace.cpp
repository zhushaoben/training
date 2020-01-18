#include<bits/stdc++.h>
using namespace std;
#define maxn 100005
#define N 10000
int n,a[maxn],ans,f1[maxn],f2[maxn],c[N+5];
int lowbit(int x){return x&(-x);}
void add(int x,int num){
    while(x<=N){
        c[x]=max(c[x],num);
        x+=lowbit(x);
    }
}
int sum(int x){
    int ans=0;
    while(x){
        ans=max(ans,c[x]);
        x-=lowbit(x);
    }
    return ans;
}
void calc(int x){
	memset(c,0,sizeof(c)),memset(f1,0,sizeof(f1)),memset(f2,0,sizeof(f2));
	for(int i=(n+x-1)%n;i!=x;i=(i+n-1)%n){
		if(a[i])f1[i]=sum(a[i])+N-a[i],add(a[i],f1[i]);
		f1[i]=max(f1[i],f1[(i+1)%n]);
	}
	memset(c,0,sizeof(c));
	for(int i=(x+1)%n;i!=x;i=(i+1)%n){
		if(a[i])f2[i]=sum(a[i])+N-a[i],add(a[i],f2[i]);
		f2[i]=max(f2[i],f2[(i+n-1)%n]);
	}
	for(int i=0;i<n;i++){
		ans=max(ans,N+f1[i]+f2[(n-1+i)%n]);
	}
}
void work(){
	ans=N;
	for(int i=0;i<n;i++)scanf("%d",a+i),a[i]=N-a[i];
	for(int i=0;i<n;i++){
		if(!a[i])calc(i);
	}
	printf("%d\n",ans);
}
int main(){
	while(~scanf("%d",&n))work();
	return 0;
}
