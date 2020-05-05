#include<bits/stdc++.h>
using namespace std;
#define maxn 1005
char s[maxn][maxn];
int a[8][2]={{1,1},{1,2},{1,3},{2,1},{2,3},{3,1},{3,2},{3,3}};
int main(){
	int n,m;scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)scanf("%s",s[i]);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(s[i][j]=='#'){
				bool w=0;
				for(int k=0;k<8;k++){
					bool fl=1;
					for(int l=0;l<8;l++){
						int x=a[l][0]+i-a[k][0],y=a[l][1]+j-a[k][1];
						if(x>=n||y>=m||x<0||y<0||s[x][y]!='#'){fl=0;break;}
					}
					if(fl){w=1;break;}
				}
				if(!w)
					return puts("NO"),0;
			}
		}
	}
	puts("YES");
	return 0;
}
