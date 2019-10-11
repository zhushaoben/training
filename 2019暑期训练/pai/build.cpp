#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define maxn 300005
LL randint(LL l,LL r){
	return l+1ll*rand()*rand()*rand()%(r-l+1);
}
int a[maxn];
void work(){
	int n=randint(1,2500),m=randint(n,5000);
	printf("%d %d %d\n",n,m,);
	for(int i=2;i<=n;i++){
		int u=randint(1,i-1);
		printf("%d%d")
	}
}
int main(){
	int t=randint(1,1);
//	printf("%d\n",t);
	while(t--)work();
	return 0;
}
