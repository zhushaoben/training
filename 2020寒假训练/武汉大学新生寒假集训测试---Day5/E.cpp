#include<bits/stdc++.h>
using namespace std;
#define maxn 1005
struct Node{
	int l,b;
	bool operator < (const Node &c)const{
		return b>c.b;
	}
}a[maxn];
int n,k,f[maxn];
int work(){
	for(int i=0;i<n;i++)scanf("%d",&a[i].l);
	for(int i=0;i<n;i++)scanf("%d",&a[i].b);
	sort(a,a+n);memset(f,0,sizeof(f));
	for(int i=0;i<n;i++){
		for(int j=min(i,k-1);~j;j--){
			f[j+1]=max(f[j+1],f[j]+a[i].l-a[i].b*j);
		}
	}
	printf("%d\n",f[k]);
	return 0;
}
int main(){
	while(~scanf("%d%d",&n,&k))work();
	return 0;
}
