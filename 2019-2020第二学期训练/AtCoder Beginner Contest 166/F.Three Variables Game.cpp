#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
char s[10],ans[N],s1[10];
int main(){
	int n,a[3];
	scanf("%d%d%d%d%s",&n,a,a+1,a+2,s);
	if(a[s[0]-'A']+a[s[1]-'A']==0)return puts("No"),0;
	if(a[0]+a[1]+a[2]==1){
		ans[0]=a[s[0]-'A']==0?s[0]:s[1];
		swap(a[s[0]-'A'],a[s[1]-'A']);
		for(int i=1;i<n;i++){
			scanf("%s",s);
			if(a[s[0]-'A']+a[s[1]-'A']==0)return puts("No"),0;
			ans[i]=a[s[0]-'A']==0?s[0]:s[1];
			swap(a[s[0]-'A'],a[s[1]-'A']);
		}
		puts("Yes");
		for(int i=0;i<n;i++)printf("%c\n",ans[i]);
		return 0;
	}
	puts("Yes");
	for(int i=1;i<n;i++){
		int d;scanf("%s",s1);
		if(a[s[0]-'A']==a[s[1]-'A'])d=(s[1]==s1[0]||s[1]==s1[1]);
		else d=(a[s[0]-'A']>a[s[1]-'A']);
		a[s[d]-'A']++,a[s[!d]-'A']--;
		printf("%c\n",s[d]);
		s[0]=s1[0],s[1]=s1[1];
	}
	printf("%c\n",s[a[s[0]-'A']>0]);
	return 0;
} 
