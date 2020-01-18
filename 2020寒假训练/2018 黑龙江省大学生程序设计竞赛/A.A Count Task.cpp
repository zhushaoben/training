#include<bits/stdc++.h>
using namespace std;
#define maxn 100005
char s[maxn];
void work(){
	int now=1;scanf("%s",s);
	long long ans=0;
	for(int i=1;s[i];i++){
		if(s[i]==s[i-1])now++;
		else{
			ans+=1ll*now*(now+1)/2;
			now=1;
		}
	}
	ans+=1ll*now*(now+1)/2;
	printf("%lld\n",ans);
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
} 
