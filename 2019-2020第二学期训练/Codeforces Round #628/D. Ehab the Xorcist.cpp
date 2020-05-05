#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int main(){
	LL u,v;scanf("%lld%lld",&u,&v);
	if(u+v==0)return puts("0"),0;
	if(u==v)return printf("1\n%lld",u),0;
	if(u>v||(v-u)&1)return puts("-1"),0;
	LL w=(v-u)>>1;
	if(w&u){
		printf("3\n%lld %lld %lld\n",w,w,u);
	}
	else{
		printf("2\n%lld %lld\n",w,u^w);
	}
	return 0;
}
