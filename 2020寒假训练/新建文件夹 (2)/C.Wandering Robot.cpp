#include<bits/stdc++.h>
using namespace std;
#define maxn 100005
#define LL long long
char s[maxn];
LL a(LL x){
	return x<0?-x:x;
}
void work(){
	int n,k;scanf("%d%d%s",&n,&k,s),k--;
	LL x=0,y=0,sx,sy,ans=0;
	for(int i=0;s[i];i++){
		switch(s[i]){
			case 'U':y++;break;
			case 'D':y--;break;
			case 'L':x--;break;
			default:x++;
		}
	}
	sx=x,sy=y;x=y=0;
	for(int i=0;s[i];i++){
		switch(s[i]){
			case 'U':y++;break;
			case 'D':y--;break;
			case 'L':x--;break;
			default:x++;
		}
		ans=max(ans,max(a(x)+a(y),a(x+sx*k)+a(y+sy*k)));
	}
	printf("%lld\n",ans);
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
}
