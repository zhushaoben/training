inline int maxbit(int data[], int n){//返回data数组中最大的数的长度 
    int d=1,p(10); //d保存最大的位数
    for(int i=0;i<n;i++){
        while(data[i]>=p||-data[i]>=p){
            p=(p+(p<<2))<<1,d++;
        }
    }
    return d;
}
inline void radixsort(int data[], int n){//data为原始数组也是结果数组，n为数组长度 
    int d=maxbit(data,n),tmp[n];//d为数组中最大的数的长度
    int count[20]; //计数器    因为有负数，所以开到20； 
    int radix = 1;
    for(int i=0;i<d;i++){ //进行d次排序
        for(int j=1;j<20;j++)
            count[j]=0; //每次分配前清空计数器
        for(int j=0,k;j<n;j++){//统计每个桶中的记录数
            k=(data[j]/radix) % 10+10;//因为有负数所以+10 
            count[k]++;
        }
        for(int j=2;j<20;j++)
            count[j]=count[j-1]+count[j]; //将tmp中的位置依次分配给每个桶,count[j]为第j个桶的结束位置 
        for(int j=n-1,k;j>=0; j--){ //将所有桶中记录依次收集到tmp中
			k = (data[j] / radix) % 10+10; //统计每个桶中的记录数
            tmp[count[k]-1]=data[j];
            count[k]--;
        }
        memcpy(data,tmp,n*4);//将临时数组的内容复制到data中
        radix=(radix+(radix<<2))<<1;
    }
}
int a[] = {1, 1, 10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};
inline int getdigit(int x,int d){//开到int最大九位 
    return ((x/a[d])%10)+10;//返回桶号
}
void msd_radixsort(int arr[],int begin,int end,int d){//分别为要排序的数组，开始和结束位置，最大数据长度 
	const int radix = 21;//因为遍历子桶时需要下一个桶的边界索引，所以多开一个桶 
	int count[radix], i, j; 
	//初始化 
	memset(count,0,sizeof(count));
	//分配桶存储空间
	int *bucket = (int *) malloc((end-begin+1) * sizeof(int));
	//统计各桶需要装的元素的个数  
	for(i = begin;i <= end; ++i){
		count[getdigit(arr[i], d)]++;
	}
	//求出桶的边界索引，count[i]值为第i个桶的右边界索引+1
	for(i = 1; i < radix; ++i)   {
		count[i] = count[i] + count[i-1];    
	}
	//这里要从右向左扫描，保证排序稳定性 
	for(i = end;i >= begin; --i){
		j = getdigit(arr[i], d);		//求出关键码的第d位的数字， 例如：576的第3位是5   
		bucket[count[j]-1] = arr[i];	//放入对应的桶中，count[j]-1是第j个桶的右边界索引   
		--count[j];						//第j个桶放下一个元素的位置(右边界索引+1)   
	}
	//注意：此时count[i]为第i个桶左边界
	//从各个桶中收集数据  
	for(i = begin, j = 0;i <= end; ++i, ++j){
		arr[i] = bucket[j];
	}    
	//释放存储空间
	free(bucket);   
	//对各个子桶中数据进行再排序
	for(i = 1;i < radix-1; i++){
		int p1 = begin + count[i];			//第i个桶的左边界
		int p2 = begin + count[i+1]-1;		//第i个桶的右边界   
		if(p1 < p2 && d > 1){
			msd_radixsort(arr, p1, p2, d-1);//对第i个桶递归调用，进行基数排序，数位降 1    
		}
	}
}
