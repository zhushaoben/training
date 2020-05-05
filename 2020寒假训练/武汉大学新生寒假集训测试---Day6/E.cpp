#include<bits/stdc++.h>
using namespace std;
#define maxn 300005
#define size 15000000
int pre[size+5],prim[size/5],prime_n,num[size+5];
void prime(){
    int m=size+1;
    for(int i=2;i<m;i++){
        if(pre[i]==0)prim[prime_n++]=i;
        for(int j=0;j<prime_n&&i*prim[j]<m;j++){
        	pre[prim[j]*i]=i;
            if(i%prim[j]==0)break;
        }
    }
}
int a[maxn];
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int main(){
	prime();
	int n,g;scanf("%d%d",&n,a);g=a[0];
	for(int i=1;i<n;i++){
		scanf("%d",a+i);
		g=gcd(g,a[i]);
	}
	for(int i=0;i<n;i++){
		int x=a[i]/g,pre1=0;
		while(pre[x]){
			if(x/pre[x]!=pre1)num[pre1=x/pre[x]]++;
			x=pre[x];
		}
		if(x!=pre1)num[x]++;
	}
	int ans=0;
	for(int i=0;i<prime_n;i++)ans=max(ans,num[prim[i]]);
	printf("%d",(ans==0)?-1:n-ans);
	return 0;
}
