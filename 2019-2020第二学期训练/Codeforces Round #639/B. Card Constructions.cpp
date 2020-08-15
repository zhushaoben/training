#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL calc(LL l,LL r,LL d){
	return (l+r)*(r-l+d)/d/2;
}
void work(){
	int n,ans=0;scanf("%d",&n);
	while(n>1){
		for(int i=1;;i++)if(calc(2,3*i-1,3)>n){n-=calc(2,3*i-4,3);break;}
		ans++;
	}
	printf("%d\n",ans);
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
}
