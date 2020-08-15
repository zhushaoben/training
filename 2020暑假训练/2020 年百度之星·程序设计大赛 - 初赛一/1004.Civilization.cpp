#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b){
	return b?gcd(b,a%b):a;
}
int a[505][505],b[50],si;
void work(){
	int n,x,y,ans=1e9,w,w1,now,p;scanf("%d%d%d",&n,&x,&y);
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)scanf("%d",a[i]+j);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			si=0;
			for(int k=-3;k<4;k++){
				for(int l=-3;l<4;l++){
					int x1=i+k,y1=j+l;
					if(abs(k)+abs(l)>3||abs(k)+abs(l)==0)continue;
					if(x1>=1&&x1<=n&&y1>=1&&y1<=n)b[si++]=a[x1][y1];
				}
			}
			w=0,now=0,p=a[i][j];
			sort(b,b+si,greater<int>());
			for(int i=1;i<=8;i++){
				w1=(8*i*i-now-1)/p+1;
				now+=w1*p;
				w+=w1;p+=b[i-1];
			}
			ans=min(ans,w+(abs(i-x)+abs(j-y)-1)/2+(x!=i||y!=j));
		}
	}
	printf("%d\n",ans);
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
} 
