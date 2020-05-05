#include<bits/stdc++.h>
using namespace std;
void work(){
	int n,d=1,ans=-1;scanf("%d",&n);
	while(n>=d)d<<=1,ans++;
	printf("%d\n",ans);
	d=1,n--;
	while(n){
		if(n<=d*2)printf("%d ",n-d),n=0;
		else if(n<=d*4){
			printf("%d ",n/2-d);
			d=(n/2),n-=d;
		}
		else printf("%d ",d),n-=(d*=2);
	}
	puts("");
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
} 
