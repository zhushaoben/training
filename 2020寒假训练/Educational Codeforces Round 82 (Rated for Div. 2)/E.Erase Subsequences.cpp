#include<bits/stdc++.h>
using namespace std;
#define maxn 405
char s[maxn],t[maxn];
int nex[maxn][26],la[26],l1,l2,f[maxn][maxn];
bool work1(int x){
	memset(f,-1,sizeof(f));
	int x1=l2-x;f[0][0]=0;
	for(int i=0;i<=x;i++){
		for(int j=0;j<=x1;j++){
			if(i&&f[i-1][j]!=-1){
				int w=t[i]-'a';
				if(nex[f[i-1][j]][w])f[i][j]=min(f[i][j]!=-1?f[i][j]:maxn*10,nex[f[i-1][j]][w]);
			}
			if(j&&f[i][j-1]!=-1){
				int w=t[j+x]-'a';
				if(nex[f[i][j-1]][w])f[i][j]=min(f[i][j]!=-1?f[i][j]:maxn*10,nex[f[i][j-1]][w]);
			}
		}
	}
	return f[x][x1]!=-1;
}
void work(){
	scanf("%s%s",s+1,t+1);memset(nex,0,sizeof(nex)),memset(la,0,sizeof(la));
	l1=strlen(s+1),l2=strlen(t+1);
	for(int i=1;s[i];i++){
		int x=s[i]-'a';
		for(int j=la[x];j<i;j++)nex[j][x]=i;
		la[x]=i;
	}
	if(l2==1){
		if(nex[0][t[1]-'a'])puts("YES");
		else puts("NO");return;
	}
	for(int i=1;i<l2;i++){
		if(work1(i)){puts("YES");return;}
	}
	puts("NO");
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
}
