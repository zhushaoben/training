#include<bits/stdc++.h>
using namespace std;
#define maxn 200005
int a[maxn];
void work(){
	int n,x,l=maxn,r=0;scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",&x),a[x]=i;
	for(int i=1;i<=n;i++){
		l=min(l,a[i]),r=max(r,a[i]);
		if(r-l+1==i)putchar('1');
		else putchar('0');
	}
	puts("");	
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
} 
