#include <stdio.h>
#define N 10020
int parent[N],rank[N],resex[N];
// ��ʼ��n��Ԫ��
void init(int n)
{
    for(int i=0;i<n;i++)
    {
        parent[i]=i;
        rank[i]=0;   // ��ʼ���ĸ߶�Ϊ0
    }
}

int find(int x)
{
    int k, j, r;
    r = x;
    while(r != parent[r])     //���Ҹ��ڵ�
        r = parent[r];      //�ҵ����ڵ㣬��r��¼��
    k = x;        
    while(k != r)             //�ǵݹ�·��ѹ������
    {
        j = parent[k];         //��j�ݴ�parent[k]�ĸ��ڵ�
        parent[k] = r;        //parent[x]ָ����ڵ�
        k = j;                    //k�Ƶ����ڵ�
    }
    return r;         //���ظ��ڵ��ֵ            
}

// �ϲ�x��y�����ļ���
void unite(int x,int y)
{
    x=find(x);
    y=find(y);
    if(x==y) return ;
    if(rank[x]<rank[y])
        parent[x]=y;  // �ϲ��Ǵ�rankС����rank�������
    else
    {
        parent[y]=x;
        if(rank[x]==rank[y]) rank[x]++;
    }
}
int main()
{
	int n,m,z,x,y;
	scanf("%d%d",&n,&m);
	init(n);
	for(int i=0;i<m;i++){
		scanf("%d%d%d",&z,&x,&y);
		if(z==1)unite(x,y);
		if(z==2){
			x=find(x);
			y=find(y);
			if(x==y)printf("Y\n");
			else printf("N\n");
		}
	}
	
	return 0;
}
