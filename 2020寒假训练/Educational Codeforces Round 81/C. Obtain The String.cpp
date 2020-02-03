#include<bits/stdc++.h>
using namespace std;
#define maxn 100005
char s[maxn],t[maxn];
int nex[maxn][26],la[26];
void work(){
	scanf("%s%s",s+1,t);
	for(int i=0;i<26;i++)nex[0][i]=0,la[i]=0;
	int l,ans=1;for(l=1;s[l];l++){
		int x=s[l]-'a';for(int i=0;i<26;i++)nex[l][i]=0;
		for(int j=la[x];j<l;j++)nex[j][x]=l;la[x]=l;
	}
	int now=0;
	for(int i=0;t[i];i++){
		int x=t[i]-'a';
		if(!nex[0][x]){puts("-1");return;}
		if(!nex[now][x])now=0,ans++;
		now=nex[now][x];
	}
	printf("%d\n",ans);
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
} 
