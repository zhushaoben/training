#include<bits/stdc++.h>
using namespace std;
#define maxn 100
char s[maxn+5][maxn+5],ans[]="1234567890ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
void work(){
	int r,c,k,num=0,w,w1,x=0,now=0;scanf("%d%d%d",&r,&c,&k);
	for(int i=0;i<r;i++){
		scanf("%s",s[i]);
		for(int j=0;s[i][j];j++)num+=(s[i][j]=='R');
	}
	w=num/k,w1=num%k;
	for(int i=0;i<r;i++){
		if(i&1){
			for(int j=0;j<c;j++){
				if(s[i][j]=='R')now++;
				if(now>w)now=((--w1)<0),x++;
				s[i][j]=ans[x];
			}
		}
		else for(int j=c-1;~j;j--){
			if(s[i][j]=='R')now++;
			if(now>w)now=((--w1)<0),x++;
			s[i][j]=ans[x];
		}
		puts(s[i]);
	}
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
} 
