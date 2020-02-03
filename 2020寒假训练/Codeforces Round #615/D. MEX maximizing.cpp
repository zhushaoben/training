#include<bits/stdc++.h>
using namespace std;
#define maxn 400006
int a[maxn];
int main(){
	int q,x,now=0,w;scanf("%d%d",&q,&x);
	for(int i=0;i<q;i++){
		scanf("%d",&w),a[w%x]++;
		while(a[now%x])a[(now++)%x]--;
		printf("%d\n",now);
	}
	return 0;
}
