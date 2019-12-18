#include<bits/stdc++.h>
using namespace std;
char s[200005],s1[3];
bool vis[26];
int main(){
	int n,k,x=0;long long ans=0;scanf("%d%d%s",&n,&k,s);
	for(int i=0;i<k;i++)scanf("%s",s1),vis[s1[0]-'a']=1;
	for(int i=0;s[i];i++){
		if(!vis[s[i]-'a']){
			ans+=1ll*x*(x+1)/2;
			x=0;
		}
		else x++;
	}
	ans+=1ll*x*(x+1)/2;
	printf("%lld",ans);
	return 0;
}
