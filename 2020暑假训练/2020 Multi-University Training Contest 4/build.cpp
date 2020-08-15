#include<bits/stdc++.h>
using namespace std;
#define LL long long
long long randint(LL l,LL r){
	return l+1ll*rand()*rand()*rand()%(r-l+1);
}
const int maxn=2e5+5,N=1e3;
void work(){
	int n=randint(N,N),m=n;
	printf("%d %d\n",n,m);
	for(int i=1;i<=n;i++)printf("%d %lld\n",i%(n-800)+800,randint(-1e9,1e9));
	for(int i=1;i<=m;i++)printf("%d %lld\n",i%(n-800)+800,randint(-1e9,1e9));
}
int main(){
	freopen("1.in","w",stdout);
	srand(time(NULL));
	int t=randint(5,5);
	printf("%d\n",t);
	while(t--)work();
	return 0;
}
