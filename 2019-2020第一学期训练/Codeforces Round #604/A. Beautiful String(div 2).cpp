#include<bits/stdc++.h>
using namespace std;
#define maxn 100005
char s[maxn];
void work(){
	scanf("%s",s+1);
	for(int i=1;s[i];i++){
		if(s[i]==s[i-1]){puts("-1");return;}
		if(s[i]=='?')for(int j='a';j<='c';j++){
			if(s[i-1]!=j&&s[i+1]!=j){s[i]=j;break;}
		}
	}
	puts(s+1);
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
}
