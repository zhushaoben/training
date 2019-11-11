#include<bits/stdc++.h>
using namespace std;
#define mo 1000000007
#define maxn 100000
#define LL long long
struct Edge{
	int next,to;
}edge[maxn*2+5];
int fi[maxn+5],se;
inline void add_edge(int u,int v){edge[++se].next=fi[u],edge[se].to=v,fi[u]=se;}
inline void add(int u,int v){add_edge(u,v),add_edge(v,u);}
LL Pow(LL a,int b){
	LL ans=1;
	while(b){
		if(b&1)(ans*=a)%=mo;
		b>>=1;(a*=a)%=mo;
	}
	return ans;
}
LL f[maxn+5][3];
//0:can't connected to its fa
//1:must connected to its fa
//2:else
void dfs(int x,int fa){
	LL sum=1,w,w1=0,w2=0,sum1=1,w3=0,son=0,num0=0,num1=0,w4,w5[2];
	for(int i=fi[x];i;i=edge[i].next){
		int v=edge[i].to;if(v==fa)continue;
		dfs(v,x),son++;
		if(!f[v][0]){num0++,w4=(f[v][1]+f[v][2])%mo;}
		else (sum1*=f[v][0])%=mo;(w3+=Pow(f[v][0],mo-2)*(f[v][1]+f[v][2]))%=mo;
		if(f[v][0]+f[v][2]==0){if(num1<2)w5[num1++]=(f[v][1]+f[v][2])%mo;}
		else (sum*=(f[v][0]+f[v][2]))%=mo,w=Pow((f[v][0]+f[v][2])%mo,mo-2)*(f[v][1]+f[v][2])%mo,(w1+=w)%=mo,(w2+=w*w)%=mo;
	}
	if(num0)f[x][2]=(num0>1?0:sum1*w4)%mo;
	else f[x][2]=(sum1*w3%mo+sum1)%mo;
	if(num1){
		if(num1==1)f[x][0]=sum*w1%mo*w5[0]%mo,f[x][1]=(w5[0]*sum%mo+mo+(num0?0:sum1)-f[x][2])%mo;
		else f[x][0]=num1>2?0:(sum*w5[0]%mo*w5[1]%mo),f[x][1]=0;
	}
	else f[x][0]=sum*(w1*w1%mo-w2+mo)%mo*Pow(2,mo-2)%mo,
	f[x][1]=(sum*w1%mo+mo+(num0?0:sum1)-f[x][2])%mo;
}
int main(){
	int n,u,v;scanf("%d",&n);
	for(int i=1;i<n;i++)scanf("%d%d",&u,&v),add(u,v);
	dfs(1,0);
	printf("%lld",(f[1][0]+f[1][2])%mo);
	return 0;
} 
