#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int a[N],nex[N],nex1[N],b[N],c[N],n;//nex:large nex1:small b:0000 c:1111
void read(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	memset(b,0,sizeof(int)*(n+5)),memset(c,0,sizeof(int)*(n+5));
	a[n+1]=1e9;
	for(int i=n;i;i--){
		int k=i+1;
		while(a[k]<a[i])k=nex[k];
		nex[i]=k;
	}a[n+1]=0;
	for(int i=n;i;i--){
		int k=i+1;
		while(a[k]>a[i])k=nex1[k];
		nex1[i]=k;
	}
}
void work(){
	read();
	a[0]=N-2,a[n+1]=N-1;
	for(int i=1;i<=n;i++){
		if(a[i]>a[i-1])continue;
		int k=nex[i],pre=i;
		while(a[k]<a[i-1]){
			int l=(k-i-1)/2;
			b[a[pre]+1]+=l,b[a[k]+1]-=l;
			pre=k;k=nex[k];
		}
		int l=(k-i-1)/2;
		b[a[pre]+1]+=l,b[a[i-1]+1]-=l;
	}
	a[n+1]=0,a[0]=0;
	for(int i=1;i<=n;i++){
		if(a[i]<a[i-1])continue;
		int k=nex1[i],pre=i;
		while(a[k]>a[i-1]){
			int l=(k-i-1)/2;
			c[a[pre]]+=l,c[a[k]]-=l;
			pre=k;k=nex1[k];
		}
		int l=(k-i-1)/2;
		c[a[pre]]+=l,c[a[i-1]]-=l;
	}
	for(int i=1;i<=n;i++)b[i]*=2,c[i]=2*c[i+1],b[i]+=b[i-1];
	for(int i=n;i;i--)c[i]+=c[i+1];
	for(int i=1;i<=n;i++){
		int x=a[i];
		if((x-1>=n-x&&x-1-n+x<=b[x])||(x-1<n-x&&n-x-x+1<=c[x]))putchar('1');
		else putchar('0');
	}
	puts("");
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
}
