/*
题目大意：
每组输入给你一个k和两个字符串，从两个字符串中各选出一个等长的子串，
要求这两个子串上相同位置上不同元素的个数不能超过k，求选出的子串的最大长度是多少。

解法：
就是从一个字符串中从头开始选取子串在另一个字符串上进行尺取，
反过来再尺取一次即可。
*/ 
#include<bits/stdc++.h>
using namespace std;
#define maxn 4010
char s[maxn],s1[maxn];
int k;
int cal(char a[],char b[]){
	int ans=0;
	for(int i=0;b[i];i++){
		int l=0,w=0;
		for(int j=0;b[i+j]&&a[j];j++){
			if(b[i+j]!=a[j])w++;
			while(w>k)w-=(b[i+l]!=a[l]),l++;
			ans=max(ans,j-l+1);
		}
	}
	return ans;
}
void work(){
	scanf("%d%s%s",&k,s,s1);
	printf("%d\n",max(cal(s,s1),cal(s1,s)));
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
} 
