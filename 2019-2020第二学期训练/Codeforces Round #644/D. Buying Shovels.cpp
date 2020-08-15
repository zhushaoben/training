#include<bits/stdc++.h>
using namespace std;
void work(){
	int n,k;scanf("%d%d",&n,&k);
	int i;
	for(i=1;i*i<=n;i++)
		if(n%i==0)
			if(n/i<=k){printf("%d\n",i);return;}
	for(;i;i--)
		if(n%i==0)
			if(i<=k){printf("%d\n",n/i);return;}
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
}
