#include<bits/stdc++.h>
using namespace std;
#define maxn 200000
int a[maxn+5],ma[maxn+5];
void work(){
	int n,m,p,s,maxa=0,maxp=0;scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",a+i),ma[i]=0,maxa=max(maxa,a[i]);ma[n]=0;
	scanf("%d",&m);
	for(int i=0;i<m;i++)scanf("%d%d",&p,&s),ma[s]=max(ma[s],p),maxp=max(maxp,p);
	if(maxa>maxp){puts("-1");return;}
	for(int i=n-1;i;i--)ma[i]=max(ma[i],ma[i+1]);
	int w=0,num=0,ans=1;
	for(int i=0;i<n;i++){
		num++,w=max(w,a[i]);
		if(ma[num]<w)ans++,w=a[i],num=1;
	}
	printf("%d\n",ans);
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
}
