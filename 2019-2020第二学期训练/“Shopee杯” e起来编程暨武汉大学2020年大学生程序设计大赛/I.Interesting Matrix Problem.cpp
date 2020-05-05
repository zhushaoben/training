#include<bits/stdc++.h>
using namespace std;
int k,n,m;
bool check(int x){
	if(x==0)return 0;
	int x1=sqrt(x);long long num=0;
	int n1=min(n,x1),m1=min(m,x1);
	for(int i=1;i<=n1;i++)num+=min(m,x/i);
	for(int i=1;i<=m1;i++)num+=min(n,x/i);
	num-=1ll*n1*m1;
	return num>=k;
}
void work(){
	int q;scanf("%d%d%d",&n,&m,&q);
	for(int i=0;i<q;i++){
		scanf("%d",&k);
		int l=0,r=k,mid;
		while(l<=r){
			mid=(l+r)>>1;
			if(check(mid))r=mid-1;
			else l=mid+1;
		}
		printf("%d\n",l);
	}
}
int main(){
	int T=1;
//	scanf("%d",&T);
	while(T--)work();
	return 0;
} 
