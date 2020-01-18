#include<bits/stdc++.h>
using namespace std;
#define maxn 16
int c[maxn][maxn];
int main(){
	int n,a,x,y,ans=0,w;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a);
		for(int j=0;j<a;j++){
			scanf("%d%d",&x,&y),x--;
			if(y)c[i][x]=1;else c[i][x]=-1;
		}
	}
	for(int i=0;i<(1<<n);i++){
		bool fl=1;w=0;
		for(int j=0;j<n;j++){
			if(i&(1<<j)){
				w++;
				for(int k=0;k<n;k++){
					if(c[j][k]==1&&(i&(1<<k))==0){fl=0;break;}
					if(c[j][k]==-1&&(i&(1<<k))){fl=0;break;}
				}
				if(!fl)break;
			}
		}
		if(fl)
		ans=max(ans,w);
	}
	printf("%d",ans);
	return 0;
}
