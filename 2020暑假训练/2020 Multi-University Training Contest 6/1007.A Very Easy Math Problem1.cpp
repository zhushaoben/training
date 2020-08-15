#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5,mo=1e9+7,MAX=N;
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
void work(){
	int n,n1,ans=0;scanf("%d",&n),n1=sqrt(n);
	if(n<100){
		for(int i=n;i>=1;i--){
			f[i]=1ll*qpow(P1[n/i],x)*qpow(P[i],x)%mo;
			for(int j=i*2;j<=n;j+=i)(f[i]-=f[j])%=mo;
			(ans+=1ll*f[i]*(smu[i]-smu[i-1])%mo)%=mo;
		}
		printf("%d",(ans+mo)%mo);
		return;
	}
	for(int i=1;i<n1;i++)
		(ans+=1ll*b[n/i]*(smu[i]-smu[i-1]+mo)%mo)%=mo;
	for(int i=1;i<=n1;i++){
		int l=n/i,r=n/(i+1)+1;
		(ans+=1ll*b[i]*(smu[r]-smu[l-1]+mo)%mo)%=mo;
	}
	printf("%d\n",ans);
}
int main(){
	scanf("%d%d%d",&t,&k,&x);
	for(int i=1;i<N;i++)P[i]=qpow(i,k),P1[i]=P[i]+P1[i-1];
	for(int i=1;i<N;i++)b[i]=qpow(P1[i],x);
	for(int i=1;i<N;i++){
		b[i]=(b[i]+mo)%mo;
		for(int j=2*i;j<N;j+=i)(b[j]-=1ll*P[j/i]*b[i]%mo)%=mo;
	}
	Moblus();
	for(int i=1;i<N;i++)smu[i]=(abs(mu[i])*i+smu[i-1])%mo; 
	while(t--)work(); 
	return 0;
} 
