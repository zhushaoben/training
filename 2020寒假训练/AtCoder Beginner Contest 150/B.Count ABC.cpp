#include<bits/stdc++.h>
using namespace std;
char s[100];
int main(){
	int ans=0;scanf("%*d%s",s);
	for(int i=0;s[i];i++)if(s[i]=='A'&&s[i+1]=='B'&&s[i+2]=='C')ans++;
	printf("%d",ans);
	return 0;
}
