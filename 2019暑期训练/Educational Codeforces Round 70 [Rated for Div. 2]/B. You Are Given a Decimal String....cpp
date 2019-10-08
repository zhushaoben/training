#include<bits/stdc++.h>
using namespace std;
#define maxn 2000005
#define inf 0x3f3f3f3f
char s[maxn];
int a[maxn],f[15][15];
int dis[15];
void bfs(int a,int b,int s){
	for(int w=0;w<10;w++){ 
	for(int i=0;i<10;i++){
		int w1=dis[i];
		if(dis[i]==w)dis[(i+a)%10]=min((dis[(i+a)%10]?dis[(i+a)%10]:inf),w+1),dis[(i+b)%10]=min((dis[(i+b)%10]?dis[(i+b)%10]:inf),w+1);
		}
	} 
	if(!dis[s])dis[s]=inf;
}
int main(){
	scanf("%s",s);int l;
	for(l=0;s[l];l++)a[l]=s[l]-'0';l--;
	for(int i=0;i<l;i++){
		f[a[i]][a[i+1]]++;
	}
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			int w1=0;bool fl=1;
			for(int k=0;k<10;k++){
				for(int w=0;w<10;w++){
					memset(dis,0x3f,sizeof(dis));
					dis[k]=0;bfs(i,j,k);
					w1+=f[k][w]*(dis[w]-1);
					if(dis[w]==inf&&f[k][w]){
						fl=0;break;
					}
				}
				if(!fl)break;
			}
			if(fl)printf("%d ",w1);
			else printf("%d ",-1);
		}
		puts("");
	} 
	return 0;
}
