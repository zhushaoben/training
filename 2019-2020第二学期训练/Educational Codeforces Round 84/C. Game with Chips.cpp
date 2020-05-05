#include<bits/stdc++.h>
using namespace std;
const int N=205;
int x[N],y[N];
char s[N*N*2];
int main(){
	int n,m,k,ans=0,x1,y1;scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<k;i++)scanf("%d%d",x+i,y+i);
	for(int i=0;i<k;i++){
		scanf("%d%d",&x1,&y1);
		for(int j=0;j<ans;j++){
			if(s[j]=='D'&&x[i]<n)x[i]++;
			if(s[j]=='U'&&x[i]>1)x[i]--;
			if(s[j]=='L'&&y[i]>1)y[i]--;
			if(s[j]=='R'&&y[i]<m)y[i]++;
		}
		for(int j=x[i];j<x1;j++)s[ans++]='D';
		for(int j=x[i];j>x1;j--)s[ans++]='U';
		for(int j=y[i];j<y1;j++)s[ans++]='R';
		for(int j=y[i];j>y1;j--)s[ans++]='L';
	}
	printf("%d\n%s",ans,s);
	return 0;
}
