#include<bits/stdc++.h>
using namespace std;
int ans,a[1000000];
void work1(int n,int m){
	if(!n||!m)return;
	if(n>m)swap(n,m);
	for(int i=0;i<n;i++)a[ans++]=n;
	work1(n,m-n);
}
void work(){
	int n,m;scanf("%d%d",&n,&m);ans=0;
	work1(n,m);
	printf("%d\n",ans);
	for(int i=0;i<ans;i++)printf("%d ",a[i]);
	puts("");
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
}
