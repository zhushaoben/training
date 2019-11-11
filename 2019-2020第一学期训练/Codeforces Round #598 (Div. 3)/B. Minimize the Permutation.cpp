#include<bits/stdc++.h>
using namespace std;
#define maxn 100
int a[maxn+5],b[maxn+5],x,n;
void work(int l){
	x++;if(l>=n||x>=n)return;
	while(b[x]<l)x++;
	for(int i=b[x]-1;i>=l;i--)b[a[i]]++,swap(a[i],a[i+1]);
	work(b[x]+(b[x]==l));
}
void work(){
	scanf("%d",&n);x=0;
	for(int i=1;i<=n;i++)scanf("%d",a+i),b[a[i]]=i;
	b[n+1]=n+1;work(1);
	for(int i=1;i<=n;i++)printf("%d ",a[i]);
	puts("");
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
}
