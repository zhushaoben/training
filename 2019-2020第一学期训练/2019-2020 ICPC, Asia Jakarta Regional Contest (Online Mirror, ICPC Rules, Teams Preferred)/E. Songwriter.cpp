#include<bits/stdc++.h>
using namespace std;
#define maxn 100000
int a[maxn+5],l[maxn+5],r[maxn+5];
int main(){
	int n,L,R,k;scanf("%d%d%d%d",&n,&L,&R,&k);
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	l[n]=L,r[n]=R;
	for(int i=n-1;i>=1;i--){
		if(a[i]>a[i+1])l[i]=l[i+1]+1,r[i]=min(R,r[i+1]+k);
		else if(a[i]<a[i+1])r[i]=r[i+1]-1,l[i]=max(L,l[i+1]-k);
		else l[i]=l[i+1],r[i]=r[i+1];
		if(l[i]>r[i]){puts("-1");return 0;}
	}
	for(int i=2;i<=n;i++){
		if(a[i]>a[i-1])l[i]=max(l[i-1]+1,l[i]),r[i]=min(r[i],min(R,r[i-1]+k));
		else if(a[i]<a[i-1])r[i]=min(r[i],r[i-1]-1),l[i]=max(l[i],max(L,l[i-1]-k));
		else l[i]=l[i-1],r[i]=r[i-1];
		if(l[i]>r[i]){puts("-1");return 0;}
	}
	for(int i=1;i<=n;i++)printf("%d ",l[i]);
	return 0;
}
