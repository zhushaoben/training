#include<bits/stdc++.h>
using namespace std;
#define maxn 200005
int fp[maxn];
int main(){
	int n,x,ma=0;scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&x),fp[x]=i;
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&x);
		printf("%d ",max(0,fp[x]-ma));
		ma=max(fp[x],ma);
	}
	return 0;
}
