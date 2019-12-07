#include<bits/stdc++.h>
using namespace std;
#define maxn 1005
char s[maxn*maxn],ans[maxn],ans1[maxn][maxn];
int n,l,k,L,R;
void build(int l1,int r1,int x){
	if(x==l){
		for(int i=l1;i<=r1;i++)puts(ans);
		return;
	}
	for(int i=l1;i<=r1;){
		if(s[L+i-l1]!=s[L-l1+r1]){
			int j=i;
			while(s[L+i-l1]==s[L+j-l1])j++;
			for(int k=j-1;k>=i;k--){
				sprintf(ans1[k],"%s",ans);sprintf(ans1[k]+x,"%c",s[L+i-l1]);
				for(int j=x+1;j<l;j++)sprintf(ans1[k]+j,"%c",s[R--]);
			}
			for(int k=i;k<j;k++)puts(ans1[k]);
			i=j;continue;
		}
		ans[x]=s[L+i-l1],L+=r1-l1+1,build(i,r1,x+1);
		return;
	}
}
int main(){
	scanf("%d%d%d%s",&n,&l,&k,s);
	sort(s,s+n*l);
	L=0,R=n*l-1;
	build(0,k-1,0);
	for(int i=k;i<n;i++){
		for(int j=0;j<l;j++)putchar(s[L++]);
		puts("");
	}
	return 0;
}
