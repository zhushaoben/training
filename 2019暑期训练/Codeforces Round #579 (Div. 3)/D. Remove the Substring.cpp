#include<bits/stdc++.h>
using namespace std;
#define maxn 200005
char s[maxn],s1[maxn],s2[maxn];
int f[maxn],f1[maxn];
int  len2,len1;
void kmp(char* s , char* t){
    len2 = strlen(t);len1=strlen(s);
    int i , j = 0 ;
    for( j=0,i=0 ; i < len1 && j < len2 ; )
    {
    	if(s[i]==t[j])f[j]=i,i++,j++;
        else i++;
    }
}
void kmp1(char* s , char* t){
    int i , j = 0 ;
    for( j=0,i=0 ; i < len1 && j < len2 ; )
    {
        if(s[i]==t[j]) f1[len2-j-1]=len1-i-1,j++,i++;
        else i++;
    }
}
void S(char *s){
	int len=strlen(s);
	for(int i=0;i<len;i++)s2[i]=s[i];
	for(int i=0;i<len;i++)s[i]=s2[len-i-1];
} 
int main(){
	scanf("%s%s",s,s1);
	kmp(s,s1);
	S(s),S(s1);
	kmp1(s,s1);int ans=f1[0];
	f1[len2]=len1;
	for(int i=0;s1[i];i++){
		ans=max(ans,f1[i+1]-f[i]-1);
	}
	printf("%d",ans);
	return 0;
}
