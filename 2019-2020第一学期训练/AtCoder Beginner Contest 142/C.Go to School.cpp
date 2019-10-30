#include<bits/stdc++.h>
using namespace std;
#define maxn 100000
int a[maxn+5];
int main(){
	int n,x;scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&x),a[x]=i;
	for(int i=1;i<=n;i++)printf("%d ",a[i]);
	return 0;
}
