#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ULL;
ULL c[105][105];
struct Poly{
	ULL a[64];
	Poly(){memset(a,0,sizeof(a));}
	ULL &operator [] (int x){return a[x];}
	Poly operator * (Poly b){
		Poly ans;
		for(int i=0;i<64;i++)
			for(int j=64-i-1;j>=0;j--)ans[i+j]+=a[i]*b[j];
		return ans;
	}
	
};
Poly add(Poly a,ULL n){
	Poly res;
	for(int i=0;i<64;i++){
		ULL p=1;
		for(int j=i;j<64;j++){
			res[i]+=a[j]*c[j][i]*p;
			p*=n;
		}
	}
	return res;
}
Poly calc(ULL n){
	Poly res;
	if(n==0)return res[0]=1,res;
	if(n&1){
		res[0]=2*n-1,res[1]=2;
		return res*calc(n-1);
	}
	res=calc(n>>1);
	return res*add(res,n/2);
}
void work(){
	ULL n;scanf("%llu",&n);
	printf("%llu\n",calc(n)[0]);
}
int main(){
	c[0][0]=1;
	for(int i=1;i<=100;i++){
		c[i][0] = 1;
		for(int j=1;j<=i;j++)
			c[i][j]=c[i-1][j-1]+c[i-1][j];
	}
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
} 
