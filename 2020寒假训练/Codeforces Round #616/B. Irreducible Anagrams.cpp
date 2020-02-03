#include<bits/stdc++.h>
using namespace std;
#define maxn 200005
int num[26][maxn];
char s[maxn];
int main(){
	int q,l,r,w;scanf("%s%d",s+1,&q);
	for(int i=1;s[i];i++){
		num[s[i]-'a'][i]++;
		for(int j=0;j<26;j++)num[j][i]+=num[j][i-1];
	}
	for(int i=0;i<q;i++){
		scanf("%d%d",&l,&r);
		if(s[l]!=s[r]||l==r)puts("Yes");
		else{
			w=0;
			for(int j=0;j<26;j++)if(num[j][r]-num[j][l-1])w++;
			if(w>2)puts("Yes");
			else puts("No");
		}
	}
	return 0;
}
