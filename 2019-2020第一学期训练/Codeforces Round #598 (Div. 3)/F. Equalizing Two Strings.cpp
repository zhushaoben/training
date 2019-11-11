#include<bits/stdc++.h>
using namespace std;
#define maxn 200000
char s[maxn+5],t[maxn+5];
int a[27],b[27],p[27];
int work(){
	int n;scanf("%d%s%s",&n,s,t);
	for(int i=0;i<27;i++)a[i]=b[i]=0;
	for(int i=0;s[i];i++)a[s[i]-'a']++,b[t[i]-'a']++,p[t[i]-'a']=i;
	bool fl=0;int num=0;
	for(int i=0;i<27;i++)if(a[i]!=b[i])return puts("NO"),0;else if(a[i]>1)fl=1;
	if(fl)return puts("YES"),0;
	for(int i=0;s[i];i++){
		num+=p[s[i]-'a']-i;
//		assert(p[s[i]-'a']>=i);assert(p[s[i]-'a']<n);
		for(int j=p[s[i]-'a']-1;j>=i;j--)p[t[j]-'a']++,swap(t[j],t[j+1]);
	}
	if(num&1)return puts("NO"),0;
	return puts("YES"),0;
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
}
