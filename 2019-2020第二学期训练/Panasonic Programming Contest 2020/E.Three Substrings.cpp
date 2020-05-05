#include<bits/stdc++.h>
using namespace std;
const int N=2005;
char s[3][N];
int l[3];
bool vis[9][N];
void work(bool vis[],char a[],char b[]){
	for(int i=0;a[i];i++)
		for(int j=0;a[i+j]&&b[j];j++)
			if(a[i+j]!='?'&&b[j]!='?'&&a[i+j]!=b[j]){vis[i]=1;break;}
}
bool check(int i,int j,int a,int b){
	if(a>b)swap(i,j),swap(a,b);
	b-=a;
	return b>=l[i]||!vis[i*3+j][b];
}
bool judge(int j,int k){
	return check(0,1,0,j)&&check(0,2,0,k)&&check(1,2,j,k);
}
int main(){
	scanf("%s%s%s",s[0],s[1],s[2]);
	for(int i=0;i<3;i++)l[i]=strlen(s[i]);
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			if(i!=j)work(vis[i*3+j],s[i],s[j]);
	int ans=N*10;
	for(int i=-l[2]-l[1];i<=l[0]+l[2];i++)
		for(int j=-l[2]-l[1];j<=l[0]+l[1];j++)
			if(judge(i,j))ans=min(ans,max(l[0],max(l[1]+i,l[2]+j))-min(0,min(i,j)));
	printf("%d",ans);
	return 0;
}
