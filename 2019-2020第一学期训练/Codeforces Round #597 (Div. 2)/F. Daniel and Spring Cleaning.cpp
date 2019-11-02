#include<bits/stdc++.h>
using namespace std;
#define LL long long
int f(int x,int r){//the number of integer y that in[0,r-1] and satisfied y^x=x+y
	int ans=0,w=0;
	for(int i=1;i<=r;i<<=1){
		if(r&i){
			r^=i;
			if(!(r&x))ans+=(1<<w);
		}
		if(!(x&i))w++;
	}
	return ans;
}
LL cal(int l,int r){//the number of integer pair (x,y) that in [l,r-1] satisfied x^y=x+y
	LL ans=0;
	if(l==r)return 0;
	if(l==0)return 2*r-1+cal(1,r);
	if(l&1)ans+=f(l,r)-f(l,l),l++;
	if(r&1)ans+=f(r-1,r)-f(r-1,l),r--;
	return ans*2+cal(l/2,r/2)*3;
}
void work(){
	int a,b;scanf("%d%d",&a,&b);
	printf("%lld\n",cal(a,b+1));
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
} 
