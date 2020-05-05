#include<bits/stdc++.h>
using namespace std;
#define maxn 3005
bool vis[1<<26];
char s[maxn];int num[26];
int main(){
	int n,ans=0;scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%s",s),memset(num,0,sizeof(num));
		int w=0;
		for(int j=0;s[j];j++)num[s[j]-'a']++;
		for(int j=0;j<26;j++)if(num[j])w|=(1<<j);
		if(!vis[w])vis[w]=1,ans++;
	}
	printf("%d",ans);
	return 0;
}
