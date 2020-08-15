#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
char s[N],t[N];
int main(){
	int ans=0;scanf("%s%s",s,t);
	for(int i=0;s[i];i++)ans+=s[i]!=t[i];
	printf("%d\n",ans);
	return 0;
}
