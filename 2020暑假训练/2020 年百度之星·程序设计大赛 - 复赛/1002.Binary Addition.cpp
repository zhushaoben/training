#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
char s[N],t[N];
void work(){
	int n,ans=0,w;scanf("%d%s%s",&n,s,t);
	for(int i=0;i<n;i++)ans+=(s[i]!=t[i]);w=ans;
	s[n]=t[n]='0';
	for(int i=0;i<=n;i++){
		w-=(s[i]!=t[i]);
		ans=min(ans,w+(s[i]!='0')+1+(t[i]!='1'));
		w+=(s[i]!='1')+(t[i]!='0');
	}
	printf("%d\n",ans);
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
} 
