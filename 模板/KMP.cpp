#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
bool v[1234];
inline void Next(const char a[],int next[],int l){//a为字符串，l为字符串长度 ,next为前缀的最大相同前后缀长度
	for(int i=1,k=0;i<l;i++){//i表示当前计算到第i个前缀，k表示上一个最大相同前后缀长度 
		while(k>0&&a[i]!=a[k]){//上一个最大相同前后缀长度并且不相等 
			k=next[k-1];
		}
		if(a[i]==a[k])k++;//相等就为上一个最大相同前后缀长度+1，不相等就是0； 
		next[i]=k;
	}
}
inline void kmp(const char a[],const char b[],int next[],int l1,int l2){//a为文章,b为要查找的串，l1是a的长度,l2是b的长度 
	for(int i=0,q=0;i<l1;i++){
		while(q>0&&b[q]!=a[i])q=next[q-1];//如果不相等，则b后移到第一个仍然能匹配成功位置（相当于b串的比较位置前移到next[q-1]+1,这里因为是从0开始所以比较位置前移到next[q-1]） 
		if(b[q]==a[i])q++;//相等就向后比较 
		if(q==l2){//成功匹配 
			v[i]=1;//i为成功匹配的a末尾的位置，可以进行其他操作 
		}
	}
}
char a[]="ABCDABAB",b[]="ABCDABD";
int next[124];
int main(){
	int l1=strlen(a),l2=strlen(b);
	Next(b,next,l2);
	kmp(a,b,next,l1,l2);
	return 0;
}
