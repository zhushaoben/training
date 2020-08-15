#include<bits/stdc++.h>
using namespace std;
const int N=5e3,inf=0x1f1f1f1f;
int f[N+5][10][10];
int a[]={1,1,4,5,1,4,1,9,1,9};
int main(){
	freopen("1.out","w",stdout);
	memset(f,0x1f,sizeof(f));
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			int x=i;long long w=0;
			while(x!=j){
				w=w*10+a[x];
				x=(x+1)%10;
			}
			w=w*10+a[j];
			if(w<=N)f[w][i][j]=min(f[w][i][j],(j-i+11)%10); 
		}
	} 
	for(int i=0;i<10;i++)f[a[i]][i][i]=1;
	for(int i=1;i<=N;i++){
		for(int j=1;j<=1;j++){
			for(int l=0;l<10;l++){
				for(int r=0;r<10;r++){
					for(int k=0;k<10;k++){
						f[i*j][l][r]=min(f[i*j][l][r],f[i][l][k]+f[j][k+1][r]);
						f[i*j][l][r]=min(f[i*j][l][r],f[j][l][k]+f[i][k+1][r]);
					}
				}
			}
		}
		for(int j=1;j<=i;j++){
			if(i+j>N)continue;
			for(int l=0;l<10;l++){
				for(int r=0;r<10;r++){
					for(int k=0;k<10;k++){
						f[i+j][l][r]=min(f[i+j][l][r],f[i][l][k]+f[j][k+1][r]);
						f[i+j][l][r]=min(f[i+j][l][r],f[j][l][k]+f[i][k+1][r]);
					}
				}
			}
		}
		for(int j=1;j<=i;j++){
			if(i*j>N)continue;
			for(int l=0;l<10;l++){
				for(int r=0;r<10;r++){
					for(int k=0;k<10;k++){
						f[i*j][l][r]=min(f[i*j][l][r],f[i][l][k]+f[j][k+1][r]);
						f[i*j][l][r]=min(f[i*j][l][r],f[j][l][k]+f[i][k+1][r]);
					}
				}
			}
		}
	}
	for(int i=1;i<=N;i++){
		int ans=inf;
		for(int r=0;r<10;r++)ans=min(ans,f[i][0][r]);
		printf("%d,",ans==inf?-1:ans);
	}
	return 0;
}
