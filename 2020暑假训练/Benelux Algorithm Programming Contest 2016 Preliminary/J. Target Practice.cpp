#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
struct Node{int x,y;}a[N];
int n,st[N],top;
bool check(int i,int j,int k){return 1ll*(a[i].y-a[j].y)*(a[i].x-a[k].x)==1ll*(a[i].x-a[j].x)*(a[i].y-a[k].y);}
bool work(int x,int y){
	top=0;
	for(int i=0;i<n;i++){
		if(i==x||i==y||check(x,y,i))continue;
		else st[top++]=i;
	}
	for(int i=2;i<top;i++)if(!check(st[i-2],st[i-1],st[i]))return 0;
	return 1;
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d%d",&a[i].x,&a[i].y);
	if(n<5||work(1,2)||work(1,3)||work(2,3))puts("success");
	else puts("failure");
	return 0;
}
