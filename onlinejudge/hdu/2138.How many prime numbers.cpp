#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int prim[]={2,3,5,7,11,13,17,19,21,61};
LL qpow(LL a,LL b,LL p){
	LL ans=1;
	while(b){
		if(b&1)ans=ans*a%p;
		a=a*a%p,b>>=1;
	}
	return ans;
}
/* 
int Miller_Rabin(int x) {
    if(x<2) return 0;
    if(x==2||x==3||x==5||x==7) return 1;
    int i,j,k=x-1,cnt=0,now;
    while(!(k&1)) k>>=1,++cnt;
    //先把所有的2给提出来，然后在一个一个乘上去，这样比直接做快
    for(i=0;i<10;++i) {
        if(qpow(prim[i],x-1,x)!=1) return 0; //费马小定理
        now=qpow(prim[i],k,x);
        if(now==1||now==x-1) continue;
        now=1ll*now*now%x;
        for(j=1;j<=cnt;++j,now=1ll*now*now%x)
            if(now==x-1) break;
        if(j>cnt) return 0;
    }
    return 1;
}
*/
bool Miller_Rabin(LL x){
	for(int i=0;i<10;i++)if(x==prim[i])return 1;
	if(x%2==0)return 0;
	LL k=x-1,l=0;
	while(!(k&1))k>>=1,l++;
	for(int i=0;i<10;i++){
		LL b=qpow(prim[i],k,x),c;
		for(int j=1;j<=l;j++){
			c=b*b%x;
			if(c==1&&b!=1&&b!=x-1)return 0;
			b=c;
		}
		if(b!=1)return 0;
	}
	return 1;
} 
int n;
void work(){
	int ans=0,x;
	for(int i=0;i<n;i++)scanf("%d",&x),ans+=Miller_Rabin(x);
	printf("%d\n",ans);
}
int main(){
	while(~scanf("%d",&n))work();
	return 0;
} 
