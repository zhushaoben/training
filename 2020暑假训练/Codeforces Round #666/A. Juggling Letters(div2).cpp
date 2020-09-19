#include<bits/stdc++.h>
using namespace std;
char s[1005];
int num[26];
void work(){
	int n;scanf("%d",&n);
	memset(num,0,sizeof(num));
	for(int i=0;i<n;i++){
		scanf("%s",s);
		for(int j=0;s[j];j++)num[s[j]-'a']++;
	}
	for(int i=0;i<26;i++){
		if(num[i]%n){puts("NO");return;}
	}
	puts("YES");
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
} 
