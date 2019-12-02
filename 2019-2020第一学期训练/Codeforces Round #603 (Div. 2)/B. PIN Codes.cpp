#include<bits/stdc++.h>
using namespace std;
char s[100][10];
int judge(int i,int j){
	int w1=0;
	for(int k=0;s[i][k];k++)if(s[i][k]!=s[j][k])w1=k;
	return w1;
}
bool vis[10];
void work(){
	int n,ans=0,x;scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%s",s[i]);
	for(int i=0;i<n;i++){
		for(int j=0;j<10;j++)vis[j]=0;
		for(int j=0;j<n;j++)if(i!=j&&(x=judge(i,j))==0)vis[s[j][0]-'0']=1;
		if(vis[s[i][0]-'0']){
			ans++;
			for(int j=0;j<10;j++)if(!vis[j]){s[i][0]=j+'0';break;}
		}
	}
	printf("%d\n",ans);
	for(int i=0;i<n;i++)puts(s[i]);
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
} 
