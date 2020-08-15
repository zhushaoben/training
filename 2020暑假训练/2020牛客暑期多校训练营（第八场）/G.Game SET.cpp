#include<bits/stdc++.h>
#define ll long long
#define clr(x,i) memset(x,i,sizeof(x))
using namespace std;
const int N=100005;
bitset<256>S[1<<8][1<<8],w,w1;
inline int read()
{
    int x=0,f=1; char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1; ch=getchar();}
    while(ch>='0'&&ch<='9') {x=x*10+ch-'0',ch=getchar();}
    return x*f;
}
int n,m,a[N];
char s[55];
int calc(int k,int l,int r)
{
	if(l == r) return 3;
	if(k == 0) return s[l+1] == 'n' ? 0 : (s[l+1] == 'w' ? 1 : 2);
	if(k == 1) return s[l+1] == 'i' ? 0 : (s[l+1] == 'q' ? 1 : 2);
	if(k == 2) return s[l+1] == 'o' ? 0 : (s[l+1] == 't' ? 1 : 2);
	if(k == 3) return s[l+1] == 'e' ? 0 : (s[l+1] == 'r' ? 1 : 2);
}

void pre(){
	for(int i=0;i<255;i++)
		for(int j=i+1;j<255;j++)
			for(int k=j+1;k<=255;k++){
				int x=i,y=j,z=k,fl=1,x1,y1,z1;
				for(int l=0;l<4;l++,x>>=2,y>>=2,z>>=2){
					x1=x&3,y1=y&3,z1=z&3;
					if(x1==3||y1==3||z1==3)continue;
					if(x1==y1&&y1==z1)continue;
					if(x1!=y1&&y1!=z1&&x1!=z1)continue;
					fl=0;
				}
				if(fl)S[i][j][k]=1,S[i][k][j]=1,S[j][k][i]=1;
			}
}
void solve(int cas)
{
	n=read();w.reset();
	for(int i=0; i<n; i++) {
		scanf("%s",s+1); m=strlen(s+1);
		int l,r,t=0,x=0;
		for(l=1; l<=m; l++) {
			r=l; while(s[r]!=']') r++;
			x<<=2; x+=calc(t, l+1, r-1);
			l=r; t++;
		}
		w.set(a[i]=x);
	}
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			int x=a[i],y=a[j];if(x>y)swap(x,y);
			w1=w&S[x][y];
			if(w1.any()){
				for(int k=j+1;k<n;k++)
				if(w1[a[k]]){
					printf("Case #%d: %d %d %d\n",cas,i+1,j+1,k+1);
					return;
				}
				
			}
		}
	}
	printf("Case #%d: -1\n",cas);
}
int main(){
	pre();
	int T=read();
	for(int i=1; i<=T; i++) {
		solve(i);
	}
}
