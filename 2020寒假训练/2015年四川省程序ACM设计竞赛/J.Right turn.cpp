#include<bits/stdc++.h>
using namespace std;
#define maxn 1005
int n,x[maxn],y[maxn];
void work(){
	for(int i=1;i<=n;i++)scanf("%d%d",x+i,y+i);
	int ans=0,nowx=0,nowy=0,dr=0,nex;
	while(ans<=4*n+1){
		nex=0;
		if(dr==0){
			for(int i=1;i<=n;i++)if(y[i]==nowy&&x[i]>nowx&&(!nex||x[i]<x[nex]))nex=i;
			if(!nex)break;nowx=x[nex]-1;
		}
		else if(dr==1){
			for(int i=1;i<=n;i++)if(x[i]==nowx&&y[i]<nowy&&(!nex||y[i]>y[nex]))nex=i;
			if(!nex)break;nowy=y[nex]+1;
		}
		else if(dr==2){
			for(int i=1;i<=n;i++)if(y[i]==nowy&&x[i]<nowx&&(!nex||x[i]>x[nex]))nex=i;
			if(!nex)break;nowx=x[nex]+1;
		}
		else{
			for(int i=1;i<=n;i++)if(x[i]==nowx&&y[i]>nowy&&(!nex||y[i]<y[nex]))nex=i;
			if(!nex)break;nowy=y[nex]-1;
		}
		dr=(dr+1)%4,ans++;
	}
	printf("%d\n",ans<=4*n+1?ans:-1);
}
int main(){
	while(~scanf("%d",&n))work();
	return 0;
} 
