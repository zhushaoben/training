#include<bits/stdc++.h>
using namespace std;
#define maxn 2505
#define LL long long
int x[maxn],y[maxn];
struct Node{
	int x,y;
}a[maxn],c;
LL cross(LL x1,LL y1,LL x2,LL y2){return (x1*y2-x2*y1);}
LL compare(Node a,Node b,Node c){return cross((b.x-a.x),(b.y-a.y),(c.x-a.x),(c.y-a.y));}
bool cmp2(Node a,Node b) {
    return compare(c,a,b)>0;
}
void work(){
	int n;scanf("%d",&n);
	LL ans=0;
	for(int i=0;i<n;i++)scanf("%d%d",x+i,y+i);
	for(int q=0;q<n;q++){
		for(int j=0;j<n;j++){
			if(q==j)continue;
			else a[j-(j>q)]={x[j]-x[q],y[j]-y[q]};
		}
		sort(a,a+n-1,cmp2);
		int k=0;ans+=1ll*(n-1)*(n-2)*(n-3)/3;
		for(int i=0;i<n-1;i++){
			while((i==k||compare(a[n-1],a[i],a[k])>0)&&(k+1)%(n-1)!=i)k=(k+1)%(n-1);
			int w=k-i+(k<i?n-1:0)-1+(compare(a[n-1],a[i],a[k])>0);
			ans-=w*(w-1);
		}
	}
	printf("%lld",ans*(n-4)/4);
}
int main(){
	int t=1;
//	scanf("%d",&t);
	while(t--)work();
	return 0;
}
