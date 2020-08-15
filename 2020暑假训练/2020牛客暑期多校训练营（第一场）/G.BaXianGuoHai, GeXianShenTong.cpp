#include<bits/stdc++.h>
using namespace std;
int mo=998244353;
const int N=1e5+5,W=16,S=(1<<W)-1;
struct Node{
	long long a[3];
	Node operator * (Node &x){return Node{(a[0]*x.a[0]+a[1]*x.a[2]+a[2]*x.a[1])%mo,(a[1]*x.a[0]+a[2]*x.a[2]+a[0]*x.a[1])%mo,(a[2]*x.a[0]+a[0]*x.a[2]+a[1]*x.a[1])%mo};}
	void operator *= (Node &x){*this=*this*x;}
	friend Node operator ^ (Node a,int b){
		Node x={1,0,0};
		while(b){
			if(b&1)x=x*a;
			a=a*a,b>>=1;
		}
		return x;
	}
}v[N][20],tmp[1<<W];
int main(){
	int n,m,q;unsigned int z,a,b;scanf("%d%d%d%u%u%u",&n,&m,&q,&z,&a,&b);
	for(int i=1;i<=n;i++){
		for(int j=0;j<3;j++){
			z=z*a+b;
			v[i][0].a[j]=z%mo;
		}
		for(int j=1;j<m*2;j++)v[i][j]=v[i][j-1]^(1<<W);
	}
	while(q--){
		for(int i=S;~i;i--)tmp[i]={1,0,0};
		for(int i=1;i<=n;i++){
			for(int j=0;j<m;j++){
				z=z*a+b;
				tmp[z&S]*=v[i][j<<1];
				tmp[z>>W]*=v[i][j<<1|1];
			}
		}
		Node ans={1,0,0},w={1,0,0};
		for(int i=S;i;i--)w*=tmp[i],ans*=w;
		printf("%lld %lld %lld\n",ans.a[0],ans.a[1],ans.a[2]);
	}
	return 0;
}
