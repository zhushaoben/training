#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5;
int p[N];
int main(){
	int n,pre=1,a,b;scanf("%d",&n);
	for(int i=2;i<=n;i++){
		printf("? %d %d\n",pre,i),fflush(stdout);
		scanf("%d",&a);
		printf("? %d %d\n",i,pre),fflush(stdout);
		scanf("%d",&b);
		if(a>b)p[pre]=a,pre=i;
		else p[i]=b;
	}
	p[pre]=n;printf("!");
	for(int i=1;i<=n;i++)printf(" %d",p[i]);
	return 0;
}
