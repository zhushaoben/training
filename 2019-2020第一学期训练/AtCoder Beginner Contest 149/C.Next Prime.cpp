#include<bits/stdc++.h>
using namespace std;
#define maxn 100500
int prime[maxn],si;
bool notprime[maxn];
int main(){
	int x;scanf("%d",&x);
	for(int i=2;;i++){
		if(!notprime[i]){
			if(i>=x)return printf("%d",i),0;
			prime[si++]=i;
		}
		for(int j=0;j<si;j++){
			if(1ll*i*prime[j]>=maxn)break;
			notprime[i*prime[j]]=1;
			if(i%prime[j]==0)break;
		}
	}
	return 0;
}
