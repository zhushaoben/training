#include<bits/stdc++.h>
using namespace std;
int ans,ans1[100000];
void work(){
	int n;scanf("%d",&n);ans=1;
	for(int i=1;i*i<=n;i++){
		ans1[ans++]=i;
		if(n/i!=i)ans1[ans++]=n/i;
	}
	printf("%d\n0 ",ans);
	for(int i=1;i<ans;i++)if(i&1)printf("%d ",ans1[i]);
	for(int i=ans-1;i;i--)if(!(i&1))printf("%d ",ans1[i]);
	puts("");
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
} 
