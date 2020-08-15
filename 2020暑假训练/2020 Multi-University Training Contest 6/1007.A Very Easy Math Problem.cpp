#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5,mo=1e9+7,MAX=N,N1=N-5;
int qpow(int a,int b){
	int ans=1;
	while(b){
		if(b&1)ans=1ll*ans*a%mo;
		a=1ll*a*a%mo,b>>=1;
	}
	return ans;
}
int P1[N],P[N],b[N];
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
void work(){
	int n,ans=0;scanf("%d",&n);
	for(int l=1,r;l<=n;l=r+1){
		int i=n/l;r=n/i;
		(ans+=1ll*b[i]*(smu[r]-smu[l-1])%mo)%=mo;
	}
	printf("%d\n",(ans%mo+mo)%mo);
}
int main(){
//	freopen("3.out","w",stdout);
	scanf("%d%d%d",&t,&k,&x);
	for(int i=1;i<N;i++)P[i]=(qpow(i,k)+P[i-1])%mo,P1[i]=qpow(i,1ll*x*k%(mo-1));
	Moblus();
	for(int i=1;i<N;i++)smu[i]=(1ll*abs(mu[i])*i*P1[i]%mo+smu[i-1])%mo; 
	for(int i=1;i<N;i++)b[i]=qpow(P[i],x);
	for(int i=N1;i;i--){
		if(N1/i==N1/(i+1))continue;
		for(int j=2*i;j<=N1;j+=i)(b[N1/i]-=1ll*P1[j/i]*b[N1/j]%mo)%=mo;
	}
//	for(int i=448;i<=500;i++)printf("%d ",b[i]);exit(0);
	while(t--)work(); 
	return 0;
} 
