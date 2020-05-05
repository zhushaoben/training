#include<bits/stdc++.h>
using namespace std;
const int N=105;
char s[N][N];
int f[N][N];
int main(){
	int h,w;scanf("%d%d",&h,&w);
	for(int i=1;i<=h;i++)scanf("%s",s[i]+1);
	memset(f,0x1f,sizeof(f));f[0][1]=0;
	for(int i=1;i<=h;i++){
		for(int j=1;j<=w;j++){
			if(s[i][j]=='#'){
				f[i][j]=min(f[i-1][j]+(s[i-1][j]!='#'),f[i][j-1]+(s[i][j-1]!='#'));
			}
			else{
				f[i][j]=min(f[i-1][j],f[i][j-1]);
			}
		}
	}
	printf("%d",f[h][w]);
	return 0;
} 
