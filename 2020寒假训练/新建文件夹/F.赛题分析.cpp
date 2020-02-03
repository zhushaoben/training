#include<bits/stdc++.h>
using namespace std;
void work(){
	int n,m,mi1=1e7,mi2=1e7,x;scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)scanf("%d",&x),mi1=min(mi1,x);
	for(int i=0;i<m;i++)scanf("%d",&x),mi2=min(mi2,x);
	printf("Shortest judge solution: %d bytes.\n",mi1);
	if(mi2<1e7)printf("Shortest team solution: %d bytes.\n",mi2);
	else puts("Shortest team solution: N/A bytes.");
}
int main(){
	int t;scanf("%d",&t);
	for(int i=1;i<=t;i++){
		printf("Problem %d:\n",1000+i);
		work();
	}
	return 0;
} 
