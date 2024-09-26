struct SSTable{
	int *elem;//动态数组基址
	int TableLen;//表的长度
};
/*一般线性表的顺序查找kp278*/
int Search_Seq(SSTable ST,int key){
	ST.elem[0]=key;//哨兵
	for(int i = ST.TableLen;ST.elem[i]!=key;i--)//从后往前找
	return i;//找不到就返回0
}
/*二分查找，折半查找*/
int Binary_Search(SSTable L,int key){
	int low=0,high=L.TableLen-1,mid;
	while(low<=high){
		mid=(low+high)/2;
		if(L.elem[mid]==key) return mid;
		else if(L.elem[mid]<key) high=mid-1;//从前部分继续查找
		else low=mid+1;//从后半部分继续查找
	}
	return -1;//查找失败，返回-1；
}
