#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define maxs (1<<11)
struct Node{
	char s[maxs];
	int size,next;//分别存节点中元素个数和下一个节点 
}a[maxs];
int remain[maxs],pos;
void init(){
	for(int i=0;i<maxs;i++)remain[i]=i;
	pos=1;
}
int newnode(){//返回一个未使用的节点 
	return remain[pos++];
}
void delnode(int x){//将x加到未使用的节点中 
	remain[--pos]=x;
}
void Find(int &part,int &size){//查找第size个字符的节点，并存在part(哪个节点)，size(节点中的第几个字符)中 
	for(part=1;part&&size>a[part].size;part=a[part].next){
		size-=a[part].size;
	}
}
void transfer(int old,int ne,int x){//将old的第x个字符之后分给ne 
	a[ne].next=a[old].next,a[ne].size=a[old].size-x;
	a[old].next=ne,a[old].size=x;
	memcpy(a[ne].s,a[old].s+x,a[ne].size);
}
void split(int part,int x){//将part节点从x处一分为二(x分到前面的节点中) 
	if(!part||x==a[part].size)return;
	int t=newnode();
	transfer(part,t,x);
}
void merge(int x,int y){//合并x,y 
	memcpy(a[x].s+a[x].size,a[y].s,a[y].size);
	a[x].next=a[y].next,a[x].size+=a[y].size;
	delnode(y);
}
void maintain(int x){//维护 
	for(;x;x=a[x].next){
		for(int y=a[x].next;y&&a[x].size+a[y].size<=maxs;y=a[x].next){
			merge(x,y);
		}
	}
}
void insert(int l,char *s,int size){//在l之后插入size个字符 
	int mark,pre=0,next,i;
	Find(pre,l);split(pre,l);
	mark=pre;
	next=a[pre].next;
	for(i=0;i+maxs<=size;i+=maxs){
		a[pre].next=newnode();
		pre=a[pre].next; 
		a[pre].size=maxs;
		memcpy(a[pre].s,s+i,maxs);
	}
	if(size-i){
		a[pre].next=newnode();
		pre=a[pre].next; 
		a[pre].size=size-i;
		memcpy(a[pre].s,s+i,a[pre].size);
	}
	a[pre].next=next;
	maintain(mark); 
}
void earse(int l,int size){//删除l后的size个字符 
	int pre=0,next;
	Find(pre,l);split(pre,l);
	for(next=a[pre].next;next&&size>a[next].size;next=a[pre].next){
		size-=a[next].size;a[pre].next=a[next].next;delnode(next);
	}
	split(next,size);
	a[pre].next=a[next].next;delnode(next);
	maintain(pre);
}
void copy(int l,int size,char *s){//将l后的size个字符存在s中 
	int pre=0,next,k,i=0;
	Find(pre,l);
	i=k=min(a[pre].size-l,size);
	memcpy(s,a[pre].s+l,k);
	for(next=a[pre].next;next&&i<size;next=a[next].next){
		k=min(a[next].size,size-i);
		memcpy(s+i,a[next].s,k);i+=k;
	}
}
int main(){
	return 0;
}
