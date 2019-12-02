#include<bits/stdc++.h>
using namespace std;
#define maxn 1000005
char *s[maxn];
int *f[maxn],*f1[maxn],n,m;
int calc(int x1,int y1,int x2,int y2,int *f[]=f){return (f[x2][y2]-(x1?f[x1-1][y2]:0))-(y1?f[x2][y1-1]-(x1?f[x1-1][y1-1]:0):0);}
bool check(int x1,int y1,int x2,int y2){return calc(x1,y1,x2,y2)==(y2-y1+1)*(x2-x1+1);}
bool check1(int mi){
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++)f1[i][j]=(j?f1[i][j-1]:0)+(i>=mi&&i+mi<n&&j>=mi&&j+mi<m&&check(i-mi,j-mi,i+mi,j+mi));
		if(i)for(int j=0;j<m;j++)f1[i][j]+=f1[i-1][j];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if((s[i][j]=='X'&&calc(max(0,i-mi),max(0,j-mi),min(i+mi,n-1),min(j+mi,m-1),f1)==0)||(s[i][j]=='.'&&calc(max(0,i-mi),max(0,j-mi),min(i+mi,n-1),min(j+mi,m-1),f1)))return 0;
		}
	}
	return 1;
}
int main(){
	int mi;scanf("%d%d",&n,&m);mi=min(n,m);
	for(int i=0;i<n;i++){
		s[i]=new char[m+1],f[i]=new int[m+1],f1[i]=new int[m+1],scanf("%s",s[i]);
		for(int j=0,l=-1;j<m;j++){
			f[i][j]=(j?f[i][j-1]:0)+(s[i][j]=='X');
			if(l==-1&&s[i][j]=='X')l=j;
			if(s[i][j]=='X'&&s[i][j+1]!='X')mi=min(mi,j-l+1),l=-1;
		}
		if(i)for(int j=0;j<m;j++)f[i][j]+=f[i-1][j];
	}
	s[n]=new char[m+1]();
	for(int j=0;j<m;j++){
		for(int i=0,l=-1;i<n;i++){
			if(l==-1&&s[i][j]=='X')l=i;
			if(s[i][j]=='X'&&s[i+1][j]!='X')mi=min(mi,i-l+1),l=-1;
		}
	}
	int l=0,r=(mi-1/2),mid;
	while(l<=r){
		mid=(l+r)>>1;
		if(check1(mid))l=mid+1;
		else r=mid-1;
	}
	printf("%d\n",mi=r);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(i>=mi&&i+mi<n&&j>=mi&&j+mi<m&&check(i-mi,j-mi,i+mi,j+mi))putchar('X');
			else putchar('.');
		}
		puts("");
	}
	return 0;
} 
