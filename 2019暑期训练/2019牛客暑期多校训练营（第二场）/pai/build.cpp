#include<bits/stdc++.h>
using namespace std;
#define LL long long
long long randint(LL l,LL r){
	return l+1ll*rand()*rand()*rand()%(r-l+1);
}
int main(){
	srand(time(NULL));
	int n=4;printf("%d\n",n);
	for(int i=0;i<n;i++){
		printf("%d %d\n",randint(1,5),randint(1,5));
	}
	return 0;
}
