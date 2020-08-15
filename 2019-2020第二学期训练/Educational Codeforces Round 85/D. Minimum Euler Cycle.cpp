#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
void print(int l,int r,int l1,int r1){
	if(l1%2==0)printf("%d ",l1/2+l),l1++;
	for(int i=l1/2+l+1;i<=r1/2+l;i++)printf("%d %d ",l,i);
	if(r1&1)printf("%d ",l);
}
void work(){
	LL n,l,r,sum=0,pre=0;scanf("%lld%lld%lld",&n,&l,&r);
	for(int i=1;i<n;i++){
		sum+=2*(n-i);
		if(sum>=l&&pre<=r)print(i,n,max(1ll,l-pre),min(2*(n-i),r-pre));
		pre=sum;
	}
	if(r==n*(n-1)+1)printf("1");
	puts("");
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
}
