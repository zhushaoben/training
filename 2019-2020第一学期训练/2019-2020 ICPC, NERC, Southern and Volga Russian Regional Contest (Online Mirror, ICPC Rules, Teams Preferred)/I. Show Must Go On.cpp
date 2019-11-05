/*
we fix K as the number of people in the subset S 
and the people are sorted in increasing order of awkwardness.
Obviously, the first set that we should output is v1,...,vK

Consider a pointer that initially points to K and 
represents to the position of the K-th person in the set. 
We now consider two operations: 
- increase the position of the pointer by 1 
- fix the position of the pointer and grab a pointer to the previous person in the set.

then each set will be reach by only on way 
for example, for set 1,3,5 ,we can do these operations: 1,2,3¡ú1,2,4¡ú1,2,5¡ú1,3,5.
we take out the best set A from the heap,write down it and put back the sets that change from A


for each set wo only keep 6 numbers:sum,now,nex,pre,x,fa
sum: the sum of awkwardness
now: where current pointer points to
nex£»where is the fixed element to its right
pre: how many elements are before it
x: how many elements are in set
fa: the id of the previous sets
*/ 
#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define maxn 1000000
struct Node{
	LL sum;int now,nex,pre,x,fa;
	bool operator < (const Node &b)const{
		return sum>b.sum;
	} 
}ans1[maxn+5],u;
struct A{
	LL x;int id;
	bool operator < (const A &b)const{
		return x<b.x;
	}
}a[maxn+5];
LL k;
priority_queue<Node>q;
void Print(int x){
	for(int i=1;i<=ans1[x].pre;i++)printf("%d ",a[i].id);
	printf("%d ",a[ans1[x].now].id);
	while(1){
		int p=ans1[x].fa;if(p==-1)break; 
		if(ans1[p].now>ans1[x].now)printf("%d ",a[ans1[p].now].id);
		x=p;
	}
}
void work(){
	int n,m,ans=0,ma;scanf("%d%lld%d",&n,&k,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i].x),a[i].id=i;
	sort(a+1,a+n+1);LL sum=0;a[n+1]={0,0};
	for(int i=1;i<=n;i++){sum+=a[i].x;if(sum>k){ma=i;break;}}
	if(sum<=k)ma=n+1;
	for(int i=ma-1;i;i--){
		sum-=a[i+1].x;while(!q.empty())q.pop();
		q.push(Node{sum,i,n+1,i-1,i,-1});
		while(!q.empty()){
			u=ans1[ans++]=q.top();q.pop();if(ans>=m)break;
			//operate 1
			if(u.now<u.nex-1&&u.sum-a[u.now].x+a[u.now+1].x<=k)q.push(Node{u.sum-a[u.now].x+a[u.now+1].x,u.now+1,u.nex,u.pre,i,ans-1});
			//operate 2
			if(u.pre&&u.now>u.pre+1&&u.sum-a[u.pre].x+a[u.pre+1].x<=k)q.push(Node{u.sum-a[u.pre].x+a[u.pre+1].x,u.pre+1,u.now,u.pre-1,i,ans-1});
		}
		if(ans>=m)break;
	}
	printf("%d\n",ans);
	for(int i=0;i<ans;i++)printf("%d %lld\n",ans1[i].x,ans1[i].sum);
	if(ans)Print(ans-1),puts("");
}
int main(){
//	freopen("1.in","r",stdin);
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
}
