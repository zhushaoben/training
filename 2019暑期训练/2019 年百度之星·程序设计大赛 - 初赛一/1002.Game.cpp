#include<bits/stdc++.h>
using namespace std;
#define maxn 1005
int a[maxn];
void work(){
	int n,x,y,si=0,r,l,ans=0;scanf("%d",&n);
	scanf("%d%d",&l,&r);
	for(int i=1;i<n;i++){
		scanf("%d%d",&x,&y);
		if(x>r||y<l){
			if(x>r){
				ans+=(x-r)/2;
				if((x-r)&1){
					ans++,l=x,r=x+1;
				}
				else l=r=x;
			}
			else{
				ans+=(l-y)/2;
				if((l-y)&1){
					ans++,l=y-1,r=y;
				}
				else l=r=y;
			}
		}
		r=min(r,y),l=max(l,x);
	}
	printf("%d\n",ans);
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
} 
