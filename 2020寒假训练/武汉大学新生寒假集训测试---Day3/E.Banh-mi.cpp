#include<bits/stdc++.h>
using namespace std;
#define maxn 100005
#define mo 1000000007
char s[maxn];int a[maxn],b[maxn],c[maxn];
int main(){
	int n,q,l,r,x,y;scanf("%d%d%s",&n,&q,s+1);
	for(int i=1;s[i];i++)a[i]=s[i]-'0',a[i]+=a[i-1];
	c[0]=1;
	for(int i=1;i<=n;i++){
		b[i]=(b[i-1]*2+1)%mo;
		c[i]=c[i-1]*2%mo;
	}
	for(int i=0;i<q;i++){
		scanf("%d%d",&l,&r);
		x=a[r]-a[l-1],y=r-l+1-x;
		printf("%d\n",1ll*b[x]*c[y]%mo);
	}
	return 0;
}
