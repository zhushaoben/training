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
int main(){
	return 0;
} 
