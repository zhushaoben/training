#include<bits/stdc++.h>
using namespace std;
#define LL long long
long long randint(LL l,LL r){
	return l+1ll*rand()*rand()*rand()%(r-l+1);
}
int main(){
	srand(time(NULL));
	int n=randint(1,14);printf("%d\n",n),n<<=1;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)printf("%d ",i==j?0:rand());
		puts("");
	}
	return 0;
}
