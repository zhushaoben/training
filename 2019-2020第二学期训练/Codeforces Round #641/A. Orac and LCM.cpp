#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int prim[100],si,mi[100],mi1[100];
int main(){
	int n,x,x1,w;scanf("%d",&n);
	for(int i=0;i<2;i++){
		x1=x;scanf("%d",&x);
		for(int j=0;j<si;j++){
			w=0;while(x%prim[j]==0)x/=prim[j],w++;
			if(w<mi[j])mi1[j]=mi[j],mi[j]=w;
			else if(w<mi1[j])mi1[j]=w;
		}
		for(int j=2;j*j<=x;j++){
			if(x%j==0){
				w=0;while(x%j==0)x/=j,w++;
				prim[si]=j,mi[si]=w,mi1[si++]=1e9;
			}
		}
		if(x>1)prim[si]=x,mi[si]=1,mi1[si++]=1e9;
	}
	x=x1;
	for(int j=0;j<si;j++){
		if(mi1[j]!=1e9)continue;
		w=0;while(x%prim[j]==0)x/=prim[j],w++;
			if(w<mi[j])mi1[j]=mi[j],mi[j]=w;
			else if(w<mi1[j])mi1[j]=w;
	}
	for(int i=2;i<n;i++){
		scanf("%d",&x);
		for(int j=0;j<si;j++){
			w=0;while(x%prim[j]==0)x/=prim[j],w++;
			if(w<mi[j])mi1[j]=mi[j],mi[j]=w;
			else if(w<mi1[j])mi1[j]=w;
		}
	}
	long long ans=1;
	for(int j=0;j<si;j++){
		for(int k=0;k<mi1[j];k++)ans*=prim[j];
	}
	printf("%lld",ans);
	
	return 0;
} 
