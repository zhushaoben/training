#include<bits/stdc++.h>
using namespace std;
#define maxn 30
#define eps 1e-6
double a[200][200];
map<string,int>mp;
int gauss_jordan(int n){
	int r,w=0;
	for(int i=0;i<n&&w<n;w++,i++){
		int r=w;
		for(int j=w+1;j<n;j++)if(fabs(a[j][i])>fabs(a[r][i]))r=j;
		if(fabs(a[r][i])<eps){w--;continue;}
		if(r!=w)for(int j=0;j<=n;j++)swap(a[r][j],a[w][j]);
		for(int k=0;k<n;k++){
			if(k!=w)
			for(int j=n;j>=w;j--)a[k][j]-=a[k][i]/a[w][i]*a[w][j];
		}
	}
	return w;
}
int main(){
	int x,n,y,si=0,t=0;string s;
	while(~scanf("%d",&x)&&x){
		scanf("%d",&n),t++;
		for(int i=0;i<n;i++){
			cin>>s>>y;
			if(!mp[s])mp[s]=++si;
			a[mp[s]-1][t-1]+=y*x;
		}
	}
	a[si][0]=1e3,a[si][t]=1e3;
	gauss_jordan(max(si+1,t));
	for(int i=0;i<t;i++)a[i][t]/=a[i][i];
	for(int i=1;i<=1000;i++){
		bool fl=1;
		for(int j=0;j<t;j++){
			a[j][t]*=i;
			if(abs(a[j][t]-floor(a[j][t]+eps))>eps*2){fl=0,a[j][t]/=i;break;}
			a[j][t]/=i;
		}
		if(fl){
			for(int j=0;j<t;j++)a[j][t]*=i,printf("%d ",(int)floor(a[j][t]+eps));
			break;
		}
	}
	return 0;
}
