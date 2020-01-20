#include<bits/stdc++.h>
using namespace std;
#define maxn 10005
#define mo 1000000007
int a[maxn],inv[1000005],num[1000005];
void Inverse(int p,int a[],int n){ 
    a[1]=1;
    for(int i=2;i<=n;i++){
        a[i]=1ll*(p-p/i)*a[p%i]%p;
    }
}
int main(){
	int n,x,w,sum=1,ans=0;scanf("%d",&n);
	Inverse(mo,inv,1000000);
	for(int i=0;i<n;i++){
		scanf("%d",a+i),x=a[i];
		for(int j=2;j*j<=x;j++){
			w=0;while(x%j==0)x/=j,w++;
			num[j]=max(w,num[j]);
		}
		if(x)num[x]=max(1,num[x]);
	}
	for(int j=2;j<=1000000;j++){
		for(int k=0;k<num[j];k++)sum=1ll*sum*j%mo;
	}
	for(int i=0;i<n;i++){
		(ans+=1ll*sum*inv[a[i]]%mo)%=mo;
	}
	printf("%d",ans);
	return 0;
}
