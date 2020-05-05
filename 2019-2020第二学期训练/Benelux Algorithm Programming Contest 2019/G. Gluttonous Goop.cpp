#include<bits/stdc++.h>
using namespace std;
const int s1=300,s2=100;
char s3[25][25];
int que[1000000],s,t,T,r,c;long long ans=0;
int vis[1000000];
void bfs(){
	ans=t;
	while(1){
		int u=que[s++],x=u/s1,y=u%s1;
		if(vis[u]>T)break;
		for(int i=-1;i<2;i++)for(int j=-1;j<2;j++){
			int w=(x+i)*s1+y+j;
			if(!vis[w])vis[w]=vis[u]+1,que[t++]=w,ans++;
		}
	}
}
inline int calc(int x,int y){return (x+s2)*s1+y+s2;}
int main(){
	scanf("%d%d%d",&r,&c,&T);
	for(int i=0;i<r;i++){
		scanf("%s",s3[i]);
		for(int j=0;j<c;j++)if(s3[i][j]=='#')que[t++]=calc(i,j),vis[calc(i,j)]=1;
	}
	if(T<=80){bfs();return printf("%d",ans),0;}
	int L1=80,R1=-1;
	for(int i=0;i<r;i++){
		int L=c,R=-1;
		for(int j=0;j<c;j++){if(s3[i][j]=='#')L=min(L,j),R=j;}
		if(R!=-1){
			L1=min(L,L1),R1=max(R1,R);
			ans+=R1+T-(L1-T)+1;
		}
	}
	ans+=1ll*(2*T-c)*(R1+T-(L1-T)+1);
	L1=80,R1=-1;
	for(int i=r-1;~i;i--){
		int L=c,R=-1;
		for(int j=0;j<c;j++){if(s3[i][j]=='#')L=min(L,j),R=j;}
		if(R!=-1){
			L1=min(L,L1),R1=max(R1,R);
			ans+=R1+T-(L1-T)+1;
		}
	}
	printf("%lld",ans); 
	return 0;
}
