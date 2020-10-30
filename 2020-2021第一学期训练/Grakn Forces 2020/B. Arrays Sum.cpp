#include<bits/stdc++.h>
using namespace std;
void work(){
	int num=-1,pre=-1,x,n,k;scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++){
		scanf("%d",&x);
		num+=(x!=pre),pre=x;
	}
	k--;
	if(!num){puts("1");return;}
	if(!k){puts("-1");return;}
	printf("%d\n",(num-1)/k+1);
	
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
}
