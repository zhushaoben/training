#include<bits/stdc++.h>
using namespace std;
#define LL long long
long long randint(LL l,LL r){
	return l+1ll*rand()*rand()*rand()%(r-l+1);
}
void work(){
	int n=randint(1,1),m=randint(1,1e18);printf("%d %d\n",n,m);
	for(int i=0;i<n;i++){
		printf("%d ",randint(1,10));
	}
}
int main(){
	srand(time(NULL));
	int t=randint(1,100);
	while(t--)work();
	return 0;
}
