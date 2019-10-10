#include<bits/stdc++.h>
using namespace std;
#define LL long long
LL randint(LL l,LL r){
	return l+(1ll*rand()*rand()*rand())%(r-l+1);
}
int main(){
	srand(time(NULL));
	int n=randint(18,18),n1=1<<n;printf("%d\n%d ",n,10001);
	for(int i=1;i<n1;i++)printf("%d ",randint(1,1000));
	return 0;
}
