#include<bits/stdc++.h>
using namespace std;
#define maxn 1005
char s[maxn][105];
int x[maxn],y[maxn];
int op(char c){return c>'Z'?c-'a':c-'A'+26;}
char fop(int x){return x<26?x+'a':x+'A'-26;}
void change(char s[],char t[]){
	int j=0;
	for(int i=0;t[i];i++,j++){
		if(!s[j])j=0;
		t[i]=fop((op(t[i])-op(s[j])+52)%52);
	}
}
int main(){
	int n,m;scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++)scanf("%d%d",x+i,y+i);
	for(int i=1;i<=n;i++)scanf("%s",s[i]);
	for(int i=m-1;~i;i--)change(s[x[i]],s[y[i]]);
	for(int i=1;i<=n;i++)puts(s[i]);
	return 0;
}
