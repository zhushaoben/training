#include<bits/stdc++.h>
using namespace std;
const int N=5e3+5;
int n,m,k;
struct Q{
	int q[N],id[N],s,t;
	void init(){s=t=0;}
	void insert(int x,int i){
		while(s<t&&i-id[s]>=k)s++;
		while(s<t&&x>q[t-1])t--;
		q[t]=x,id[t]=i;t++;
	}
	int top(){return q[s];}
}q;
int gcd[N][N],f[N][N];
void get_gcd(int n,int m){
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(!gcd[i][j])
			for(int k=min(n/i,m/j),i1=k*i,j1=k*j;k;k--,i1-=i,j1-=j)gcd[i1][j1]=k;
}
int main(){
    scanf("%d%d%d",&n,&m,&k);
    get_gcd(n,m);
    long long ans=0;
    /*
    for(int j=1;j<=m;j++){
    	q.init();
    	for(int i=1;i<=n;i++)q.insert(i*j/gcd[i][j],i),f[i][j]=q.top();
	}
    for(int i=k;i<=n;i++){
    	q.init();
    	for(int j=1;j<=m;j++){
    		q.insert(f[i][j],j);
    		if(j>=k)ans+=q.top();
		}
	}
	*/
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)f[i][j]=(k==1?i*j/gcd[i][j]:max(max(f[i-1][j],f[i][j-1]),i*j/gcd[i][j]));
	for(int i=k;i<=n;i++)for(int j=k;j<=m;j++)ans+=f[i][j];
	printf("%lld",ans);
    return 0;
}
