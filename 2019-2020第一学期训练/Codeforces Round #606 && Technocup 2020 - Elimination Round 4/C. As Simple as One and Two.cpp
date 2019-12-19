#include<bits/stdc++.h>
using namespace std;
#define maxn 150005
char s[maxn],s1[3][10]={"one","two","twone"};
int ans[maxn];
bool check(char *s,char *t){
	for(int i=0;t[i];i++){
		if(s[i]!=t[i])return 0;
	}
	return 1;
}
void work(){
	int ans1=0;scanf("%s",s);
	for(int i=0;s[i];i++){
		if(check(s+i,s1[2])){ans[ans1++]=i+3,s[i+2]='z';}
		else if(check(s+i,s1[1])||check(s+i,s1[0]))ans[ans1++]=i+2,s[i+1]='z';
	}
	printf("%d\n",ans1);
	for(int i=0;i<ans1;i++)printf("%d ",ans[i]);puts("");
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
}
