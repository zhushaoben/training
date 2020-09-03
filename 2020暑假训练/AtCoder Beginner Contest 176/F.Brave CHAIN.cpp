#include<bits/stdc++.h>
using namespace std;
const int N=2e3+5;
int a[N*3],f[N][N],ma[N],t,mx;
struct Node{int x,y,z;}op[N<<2];
int main(){
	int n,n1,ans1=0;scanf("%d",&n),n1=3*n-1;
	for(int i=0;i<=n1;i++)scanf("%d",a+i);
	memset(f,0x8f,sizeof(f)),memset(ma,0x8f,sizeof(ma));
	ma[a[0]]=ma[a[1]]=f[a[0]][a[1]]=f[a[1]][a[0]]=0;
	for(int i=2;i<n1;i+=3){
		if(a[i]==a[i+1]&&a[i]==a[i+2]){ans1++;continue;}
		if(a[i]==a[i+2])swap(a[i+1],a[i+2]);
		if(a[i+1]==a[i+2])swap(a[i+2],a[i]);
		if(a[i]==a[i+1]){
			for(int j=1;j<=n;j++)op[t++]={a[i+2],j,f[j][a[i]]+1},op[t++]={j,a[i],ma[j]},op[t++]={j,a[i+2],ma[j]};
			op[t++]={a[i],a[i],max(f[a[i+2]][a[i+2]]+1,mx)};
		}
		else{
			for(int j=1;j<=n;j++)op[t++]={j,a[i],ma[j]},op[t++]={j,a[i+1],ma[j]},op[t++]={j,a[i+2],ma[j]};
			op[t++]={a[i],a[i+1],max(f[a[i+2]][a[i+2]]+1,mx)};
			op[t++]={a[i],a[i+2],max(f[a[i+1]][a[i+1]]+1,mx)};
			op[t++]={a[i+2],a[i+1],max(f[a[i]][a[i]]+1,mx)};
		}
		while(t--){
			int x=op[t].x,y=op[t].y,z=op[t].z;
			f[x][y]=f[y][x]=max(z,f[x][y]);
			ma[x]=max(ma[x],z),ma[y]=max(ma[y],z),mx=max(mx,z);
		}t++;
	}
	printf("%d",max(mx,f[a[n1]][a[n1]]+1)+ans1);
	return 0;
}
