#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int ans[N],si;
void work(){
	int n,n1;long long x,y,x1;scanf("%d%lld%lld",&n,&x,&y);
	si=0;if(x+y>n+1||x*y<n){puts("NO");return;}
	puts("YES");x1=x;n1=n;
	for(int i=1;i<=n1;i++){
		if((n-1)>(x-1)*y)break;
		n--,x--,ans[si++]=i;
	}
	long long w=x1-x,w1=y-(x*y-n);
	for(int i=w+w1;i>w;i--)ans[si++]=i;w+=w1;
	for(int i=2;i<=x;i++){
		for(int i=w+y;i>w;i--)ans[si++]=i;
		w+=y;
	}
	printf("%d",ans[0]);
	for(int i=1;i<si;i++)printf(" %d",ans[i]);
	puts("");
}
int main(){
//	freopen("1.in","w",stdout);
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
}
