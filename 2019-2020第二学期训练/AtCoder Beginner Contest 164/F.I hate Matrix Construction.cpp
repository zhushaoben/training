#include<bits/stdc++.h>
using namespace std;
const int N=505;
typedef long long LL;
int s[N],t[N],n;unsigned long long u[N],v[N],a[N][N];
bool work(){
	for(int i=0;i<64;i++){
		for(int j=1;j<=n;j++)
			if(s[j]==0&&(u[j]&(1ull<<i)))for(int k=1;k<=n;k++)a[j][k]|=(1ull<<i);
		for(int j=1;j<=n;j++)
			if(t[j]==0&&(v[j]&(1ull<<i)))for(int k=1;k<=n;k++)a[k][j]|=(1ull<<i);
		for(int j=1;j<=n;j++){
			if(!(s[j]==1&&(u[j]&(1ull<<i))))continue;
			int w=0;
			for(int k=1;k<=n;k++)
				if((a[j][k]&(1ull<<i))||(v[k]&(1ull<<i))){w=k;break;}
			if(w){a[j][w]|=(1ull<<i);continue;}
			for(int k=1;k<=n;k++){
				if(t[k]==1)continue;int num=0;
				for(int l=1;l<=n;l++)if(a[l][k]&(1ull<<i))num++;
				if(num<n-1){w=k;break;}
			}
			if(!w)return 0;
			a[j][w]|=(1ull<<i);
		}
		for(int j=1;j<=n;j++){
			if(t[j]==1&&(v[j]&(1ull<<i))){
				int w=0;
				for(int k=1;k<=n;k++)
					if((a[k][j]&(1ull<<i))||(u[k]&(1ull<<i))){w=k;break;}
				if(w){a[w][j]|=(1ull<<i);continue;}
				for(int k=1;k<=n;k++){
					if(s[k]==1)continue;int num=0;
					for(int l=1;l<=n;l++)if(a[k][l]&(1ull<<i))num++;
					if(num<n-1){w=k;break;}
				}
				if(!w)return 0;
				a[w][j]|=(1ull<<i);
			}
		}
		for(int j=1;j<=n;j++){
			unsigned long long w=(1ull<<i);
			if(s[j]==0)for(int k=1;k<=n;k++)w&=a[j][k];
			else{
				w=0;
				for(int k=1;k<=n;k++)w|=a[j][k]&(1ull<<i);
			}
			if(w!=(u[j]&(1ull<<i)))return 0;
		}
		for(int j=1;j<=n;j++){
			unsigned long long w=(1ull<<i);
			if(t[j]==0)for(int k=1;k<=n;k++)w&=a[k][j];
			else{
				w=0;
				for(int k=1;k<=n;k++)w|=a[k][j]&(1ull<<i);
			}
			if(w!=(v[j]&(1ull<<i)))return 0;
		}
	}
	return 1;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",s+i);
	for(int i=1;i<=n;i++)scanf("%d",t+i);
	for(int i=1;i<=n;i++)scanf("%llu",u+i);
	for(int i=1;i<=n;i++)scanf("%llu",v+i);
	if(!work())return puts("-1"),0;
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)printf("%llu%c",a[i][j],j==n?'\n':' ');
	return 0;
}

