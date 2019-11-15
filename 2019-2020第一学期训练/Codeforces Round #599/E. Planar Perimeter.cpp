/*
if we have two patches with n and m sides
then we can sew them to one patches with n+m-2~max(n-m+2,m-n+2) sides
we sort the numbers in decreasing order and sew them one by one
*/ 
#include<bits/stdc++.h>
using namespace std;
#define maxn 100000
struct Node{
	int x,id;
	bool operator < (const Node &b)const{
		return x>b.x;
	} 
}a[maxn+5];
vector<int>ans[maxn+5];
int que[maxn*4+5],S,T,ans1;
void sew(int x,int si,int si1){
	for(int i=1;i<si;i++)ans[x].push_back(que[--T]);
	ans[x].push_back(que[T-1]);
	for(int i=si+1;i<si1;i++)ans[x].push_back(que[T++]=++ans1);
	ans[x].push_back(que[T++]=que[S++]);
}
int main(){
	int n;scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",a+i),a[i].id=i;
	sort(a,a+n);a[n]={3,0};
	for(int i=0;i<a[0].x;i++)que[T++]=++ans1,ans[a[0].id].push_back(ans1);
	for(int i=1;i<n;i++){
		int w=a[i].x,si=min((T-S+w-a[i+1].x)/2,w-1);
		sew(a[i].id,si,w);
	}
	printf("%d\n",ans1);
	for(int i=0;i<n;i++){for(int j:ans[i])printf("%d ",j);puts("");}
	return 0;
}
