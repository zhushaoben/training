#include<bits/stdc++.h>
using namespace std;
#define maxn 100005
#define LL long long
int a[maxn],b[maxn],c[maxn],d[maxn],s1,s2,s3,s4;
LL k;
bool check(LL x){
	LL num=0;
	if(x<0){
		int r=s4;x=-x;
		for(int i=0;i<s1;i++){
			while(r&&1ll*a[i]*d[r-1]>=x)r--;
			num+=s4-r;
		}
		r=s3;
		for(int i=0;i<s2;i++){
			while(r&&1ll*b[i]*c[r-1]>=x)r--;
			num+=s3-r;
		}
	}
	else{
		num+=1ll*s1*s4+1ll*s2*s3;
		int r=0;
		for(int i=s1-1;~i;i--){
			while(r<s3&&1ll*a[i]*c[r]<=x)r++;
			num+=r;
		}
		r=0;
		for(int i=s2-1;~i;i--){
			while(r<s4&&1ll*b[i]*d[r]<=x)r++;
			num+=r;
		}
	}
	return num>=k;
}
int main(){
	int n,m,x;scanf("%d%d%lld",&n,&m,&k);
	k=1ll*n*m-k+1;
	for(int i=0;i<n;i++){
		scanf("%d",&x);
		if(x>0)a[s1++]=x;
		else b[s2++]=-x;
	}
	for(int i=0;i<m;i++){
		scanf("%d",&x);
		if(x>0)c[s3++]=x;
		else d[s4++]=-x;
	}
	sort(a,a+s1),sort(b,b+s2),sort(c,c+s3),sort(d,d+s4);
	LL l=-1e12,r=1e12,mid;
	while(l<=r){
		mid=(l+r)>>1;
		if(check(mid))r=mid-1;
		else l=mid+1;
	}
	printf("%lld",l);
	return 0;
}
