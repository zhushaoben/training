#include<bits/stdc++.h>
using namespace std;
bool check(char s[],char s1[]){
	int w=0;
	for(int i=0;s[i];i++)if(s[i]!=s1[i])w++;
	return w>1;
}
char s[20][20];
void work(){
	int n,m;scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)scanf("%s",s[i]);
	for(int i=0;i<m;i++){
		char c=s[0][i];
		for(int j=0;j<26;j++){
			s[0][i]=j+'a';bool fl=1;
			for(int k=1;k<n;k++)if(check(s[0],s[k])){fl=0;break;}
			if(fl){puts(s[0]);return;} 
		}
		s[0][i]=c;
	}
	puts("-1");
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
}
