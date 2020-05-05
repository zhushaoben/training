#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+5;
int c[26][N];char s[N];
inline int lowbit(int x){return x&(-x);}
void add(int i,int x,int num){
    while(x<=N){
        c[i][x]+=num;
        x+=lowbit(x);
    }
}
int sum(int i,int x){
    int ans=0;
    while(x){
        ans+=c[i][x];
        x-=lowbit(x);
    }
    return ans;
}
int main(){
	int n,m,op,x,y;char y1[2];
	scanf("%d%s",&n,s+1);
	for(int i=1;s[i];i++)add(s[i]-'a',i,1);
	scanf("%d",&m);
	for(int i=0;i<m;i++){
		scanf("%d",&op);
		if(op==1){
			scanf("%d%s",&x,y1);
			add(s[x]-'a',x,-1);
			s[x]=*y1;add(s[x]-'a',x,1);
		} 
		else{
			int ans=0;
			scanf("%d%d",&x,&y);
			for(int i=0;i<26;i++)if(sum(i,y)-sum(i,x-1))ans++;
			printf("%d\n",ans);
		}
	}
	return 0;
}
