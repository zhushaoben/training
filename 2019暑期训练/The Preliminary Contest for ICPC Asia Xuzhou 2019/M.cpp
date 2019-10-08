#include<bits/stdc++.h>
using namespace std;
#define maxn 1000005
int nex[27][maxn],la[26];
char s[maxn],s1[maxn];
int main(){
	int n,m;scanf("%d%d%s%s",&n,&m,s+1,s1+1);
	for(int i=0;i<26;i++)la[i]=n+1+m;
	for(int i=n;i;i--){
		int x=s[i]-'a';nex[26][i]=n+m+1;la[x]=i;
		for(int j=25;~j;j--)nex[j][i]=min(nex[j+1][i],la[j]);
	}
	int j=1,x=s1[1]-'a';
	int ans=-1;
//	for(int i=x+1;i<26;i++)ans=max(ans,n-la[i]+1);
	bool fl=1;
	for(int i=1;i<=m;i++,j++){
		ans=max(ans,i+n-nex[s1[i]-'a'+1][j]);
		while(j<=n&&s[j]<s1[i])j++;
		if(j>n){fl=0;break;}
		if(s[j]>s1[i]){ans=max(ans,i+n-j);fl=0;break;}
	}
	if(fl&&j<=n)ans=max(ans,m+n-j+1);
	printf("%d\n",ans);
	return 0;
} 
