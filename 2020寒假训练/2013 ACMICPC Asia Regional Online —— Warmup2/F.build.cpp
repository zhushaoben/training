#include<bits/stdc++.h>
using namespace std;
#define LL long long
long long randint(LL l,LL r){
	return l+1ll*rand()*rand()*rand()%(r-l+1);
}
const int N=500;
void work(){
	int n=randint(1,N),m=randint(1,N),R=randint(0,(min(n,m)-1)/2),Q=randint(1,2e3);
	printf("%d %d %d %d\n",n,m,R,Q);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++)printf("%d ",randint(1,3));
		puts("");
	}for(int i=0;i<n;i++){
		for(int j=0;j<m;j++)printf("%d ",randint(1,3));
		puts("");
	}
	for(int i=0;i<Q;i++)printf("%d %d\n",randint(0,1e6),randint(0,1e6));
}
int main(){
	srand(time(NULL));
	int t=randint(1,10);
	printf("%d\n",t);
	while(t--)work();
	return 0;
}
