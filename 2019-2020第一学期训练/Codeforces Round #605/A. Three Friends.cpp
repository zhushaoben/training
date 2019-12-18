#include<bits/stdc++.h>
using namespace std;
void work(){
	int a,b,c,ans;scanf("%d%d%d",&a,&b,&c);
	if(a>b)swap(a,b);if(b>c)swap(b,c);if(a>b)swap(a,b);
	ans=max(0,(c-a)*2-4);
	printf("%d\n",ans);
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
} 
