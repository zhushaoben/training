#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int a[N];
void work(){
	int n,g=0,ma,id,x;scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	for(int i=1;i<=n;i++){
		ma=gcd(a[i],g),id=i;
		for(int j=i+1;j<=n;j++){
			x=gcd(a[j],g);
			if(x>ma)ma=x,id=j;
		}
		swap(a[id],a[i]),g=ma;
	}
	for(int i=1;i<=n;i++)printf("%d ",a[i]);
	puts("");
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
}
