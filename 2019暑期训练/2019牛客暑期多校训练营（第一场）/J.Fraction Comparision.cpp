#include<bits/stdc++.h>
using namespace std;
#define LL long long
LL x,y,a,b;
void put(LL a,LL b){
	if(a==b)puts("=");
	else if(a>b)puts(">");
	else puts("<");
}
void work(){
	if(x/a!=y/b){put(x/a,y/b);return;}
	x%=a,y%=b;x*=b,y*=a;put(x,y);
}
int main(){
	while(~scanf("%lld%lld%lld%lld",&x,&a,&y,&b))work();
	return 0;
} 
