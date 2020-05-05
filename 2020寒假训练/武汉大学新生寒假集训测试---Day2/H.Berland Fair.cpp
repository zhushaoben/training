#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define maxn 200005
int a[maxn*2],n1,n,pre[maxn],nex[maxn];
int lowbit(int x){return x&(-x);}
void add(int x,int num,LL c[]){
    while(x<=n1){
        c[x]+=num;
        x+=lowbit(x);
    }
}
LL sum(int x,LL c[]){
//	if(x<=0)return 0;
    LL ans=0;
    while(x){
        ans+=c[x];
        x-=lowbit(x);
    }
    return ans;
}
LL c[maxn*2],d[maxn*2],ans;
LL check(int l,int r){
	return sum(r,c)-sum(l-1,c);
}
void work(int &now,LL &t){
	int l=now,r=now+n-1,mid;
	while(l<=r){
		mid=(l+r)>>1;
		if(check(now,mid)>t)r=mid-1;
		else l=mid+1;
	}
	ans+=sum(r,d)-sum(now-1,d),t-=check(now,r);
	if(r!=now-1)now=nex[(r-1)%n+1];
}
void del(int x){
	nex[pre[x]]=nex[x],pre[nex[x]]=pre[x];
	add(x,-a[x],c),add(x+n,-a[x],c),add(x,-1,d),add(x+n,-1,d);
}
int main(){
	LL t,si;int now=1;scanf("%d%lld",&n,&t),n1=n*2,si=n;
	for(int i=1;i<=n;i++){
		scanf("%d",a+i),a[i+n]=a[i],pre[i]=i-1,nex[i]=i+1;
		add(i,a[i],c),add(i+n,a[i],c),add(i,1,d),add(i+n,1,d);
	}
	nex[n]=1,pre[1]=n;
	while(si){
		ans+=si*(t/sum(n,c));t%=sum(n,c);
		work(now,t);
		while(si&&a[now]>t){
			si--,del(now),now=nex[now];
		}
	}
	printf("%lld",ans);
	return 0;
}
