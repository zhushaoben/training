#include<bits/stdc++.h>
using namespace std;
#define maxn 100000
char s[maxn+5];
int f[55][55][2],fi[55],si;
int main(){
	int n,k,a,b,c;scanf("%d%d%d%d%d%s",&n,&k,&a,&b,&c,s+1),n++;
	s[n]='#';
	for(int i=1;s[i];i++){
		if(s[i]=='#')fi[++si]=i;
	}
	for(int i=1;i<=si;i++){
		f[i][i][0]=-1000;
		for(int j=0;j<i;j++){
			if(s[fi[i]-1]=='.'&&s[fi[i]+1]=='.'){
				f[i][j+1][1]=f[i-1][j][0]+(fi[i]-fi[i-1]-2)/2;
				if(fi[i]-fi[i-1]>2)f[i][j+1][1]=max(f[i][j+1][1],f[i-1][j][1]+(fi[i]-fi[i-1]-3)/2);
			}
			else f[i][j+1][1]=-1000;
			f[i][j][0]=max(f[i-1][j][1]+(fi[i]-fi[i-1]-2)/2,f[i-1][j][0]+(fi[i]-fi[i-1]-1)/2);
		}
	}
	int ans=0,w,w1;
	for(int i=0;i<=si;i++){
		int w2=max(f[si][i][0],f[si][i][1]);
		ans=max(ans,w=i*c+w2*b+min(k,(w1=n-i*3-(si-i)-w2*2))*a);
		if(w1<k){
			int w3=max(0,w2-(k-w1)/2);
			ans=max(ans,i*c+w3*b+min(k,(n-i*3-(si-i)-w3*2))*a),
			w3=max(0,w2-(k-w1+1)/2);
			ans=max(ans,i*c+w3*b+min(k,(n-i*3-(si-i)-w3*2))*a);
		}
	}
	printf("%d",ans);
	return 0;
}
