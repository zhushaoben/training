#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define maxs (1<<11)
struct Node{
	char s[maxs];
	int size,next;//�ֱ��ڵ���Ԫ�ظ�������һ���ڵ� 
}a[maxs];
int remain[maxs],pos;
void init(){
	for(int i=0;i<maxs;i++)remain[i]=i;
	pos=1;
}
int newnode(){//����һ��δʹ�õĽڵ� 
	return remain[pos++];
}
void delnode(int x){//��x�ӵ�δʹ�õĽڵ��� 
	remain[--pos]=x;
}
void Find(int &part,int &size){//���ҵ�size���ַ��Ľڵ㣬������part(�ĸ��ڵ�)��size(�ڵ��еĵڼ����ַ�)�� 
	for(part=1;part&&size>a[part].size;part=a[part].next){
		size-=a[part].size;
	}
}
void transfer(int old,int ne,int x){//��old�ĵ�x���ַ�֮��ָ�ne 
	a[ne].next=a[old].next,a[ne].size=a[old].size-x;
	a[old].next=ne,a[old].size=x;
	memcpy(a[ne].s,a[old].s+x,a[ne].size);
}
void split(int part,int x){//��part�ڵ��x��һ��Ϊ��(x�ֵ�ǰ��Ľڵ���) 
	if(!part||x==a[part].size)return;
	int t=newnode();
	transfer(part,t,x);
}
void merge(int x,int y){//�ϲ�x,y 
	memcpy(a[x].s+a[x].size,a[y].s,a[y].size);
	a[x].next=a[y].next,a[x].size+=a[y].size;
	delnode(y);
}
void maintain(int x){//ά�� 
	for(;x;x=a[x].next){
		for(int y=a[x].next;y&&a[x].size+a[y].size<=maxs;y=a[x].next){
			merge(x,y);
		}
	}
}
void insert(int l,char *s,int size){//��l֮�����size���ַ� 
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
void earse(int l,int size){//ɾ��l���size���ַ� 
	int pre=0,next;
	Find(pre,l);split(pre,l);
	for(next=a[pre].next;next&&size>a[next].size;next=a[pre].next){
		size-=a[next].size;a[pre].next=a[next].next;delnode(next);
	}
	split(next,size);
	a[pre].next=a[next].next;delnode(next);
	maintain(pre);
}
void copy(int l,int size,char *s){//��l���size���ַ�����s�� 
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
