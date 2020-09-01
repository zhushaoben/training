#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int prim[N/5],prime_n,midiv[N+5]; 
void prime(){
    for(int i=2;i<=N;i++){
        if(!midiv[i])prim[prime_n++]=i,midiv[i]=i;//没有筛掉的为素数
        for(int j=0;j<prime_n&&i*prim[j]<=N;j++){
            midiv[prim[j]*i]=prim[j];//筛掉
            if(i%prim[j]==0)break;//后面的数最小因数一定小于等于prim[j]
        }
    }
}
int gcd(int a,int b){
	return b?gcd(b,a%b):a;
}
int num[N+5];
int main(){
	int n,x;scanf("%d",&n);
	prime();
	for(int i=0;i<n;i++){
		scanf("%d",&x);
		while(x>1){num[midiv[x]]++;int w=midiv[x];while(x%w==0)x/=w;}
	}
	int ma=0;
	for(int i=1;i<=N;i++)ma=max(ma,num[i]);
	if(ma==n)puts("not coprime");
	else if(ma>1)puts("setwise coprime");
	else puts("pairwise coprime");
	return 0;
}
