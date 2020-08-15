#include<bits/stdc++.h>
using namespace std;
#define LL long long
long long randint(LL l,LL r){
	return l+1ll*rand()*rand()*rand()%(r-l+1);
}
const int N=8;
void work(){
	int n=randint(N,N),l=randint(1,n),k=randint(1,l);
	printf("%d %d %d\n",n,l,k);
	for(int i=0;i<n;i++)printf("%d ",randint(1,1e9));
	puts("");
}
int main(){
//	prime();
	srand(time(NULL));
	int t=randint(1,1);
	printf("%d\n",t);
	while(t--)work();
	return 0;
}
