#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5,mo=1e9+7,MAX=N,N1=2e5;
int qpow(int a,int b){
	int ans=1;
	while(b){
		if(b&1)ans=1ll*ans*a%mo;
		a=1ll*a*a%mo,b>>=1;
	}
	return ans;
}
int P1[N],P[N],b[N],f[N];
int mu[MAX+10],smu[N];
bool check[MAX+10];  
int prime[MAX+10];  
void Moblus()  
{  
    memset(check,false,sizeof(check));  
    mu[1] = 1;  
    int tot = 0;  
    for(int i = 2; i <= MAX; i++)  
    {  
        if( !check[i] ){  
            prime[tot++] = i;  
            mu[i] = -1;  
        }  
        for(int j = 0; j < tot; j++)  
        {  
            if(i * prime[j] > MAX) break;  
            check[i * prime[j]] = true;  
            if( i % prime[j] == 0){  
                mu[i * prime[j]] = 0;  
                break;  
            }else{  
                mu[i * prime[j]] = -mu[i];  
            }  
        }  
    }  
}
int t,k,x; 
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int g[2005][2005];
void work(){
	int n,n1,ans=0;scanf("%d",&n),n1=sqrt(n);
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)for(int k=1;k<=n;k++) {
		int g1=g[i][g[j][k]];
		ans+=1ll*i*j%mo*k%mo*(smu[g1]-smu[g1-1])%mo;
		ans%=mo;
	}
	printf("%d\n",(ans+mo)%mo);
}
int main(){
	scanf("%d%d%d",&t,&k,&x);
	for(int i=1;i<N;i++)P[i]=qpow(i,k)+P[i-1],P1[i]=qpow(i,x);
	for(int i=1;i<=2000;i++)for(int j=1;j<=2000;j++)g[i][j]=gcd(i,j);
	Moblus();
	for(int i=1;i<N;i++)smu[i]=(abs(mu[i])*i+smu[i-1])%mo; 
	for(int i=1;i<N;i++)b[i]=qpow(P[i],x);
	for(int i=1;i<=N1;i++)
		for(int j=2*i;j<N;j+=i)(b[N1/i]-=1ll*P1[j/i]*b[N1/j]%mo)%=mo;
	while(t--)work(); 
	return 0;
} 
