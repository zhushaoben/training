#include<bits/stdc++.h>
using namespace std;
char s[20];
int f[30][30];
int main(){
	int n;scanf("%d",&n);
	memset(f,0xcf,sizeof(f));
	for(int i=0;i<26;i++)f[i][i]=0;
	for(int i=0;i<n;i++){
		scanf("%s",s);
		int l=0;for(;s[l];l++);
		for(int j=0;j<26;j++){
			f[j][s[l-1]-'a']=max(f[j][s[l-1]-'a'],f[j][s[0]-'a']+l);
		}
	}
	int ans=0;
	for(int i=0;i<26;i++)ans=max(ans,f[i][i]);
	printf("%d\n",ans);
	return 0;
}
