struct SSTable{
	int *elem;//��̬�����ַ
	int TableLen;//��ĳ���
};
/*һ�����Ա��˳�����kp278*/
int Search_Seq(SSTable ST,int key){
	ST.elem[0]=key;//�ڱ�
	for(int i = ST.TableLen;ST.elem[i]!=key;i--)//�Ӻ���ǰ��
	return i;//�Ҳ����ͷ���0
}
/*���ֲ��ң��۰����*/
int Binary_Search(SSTable L,int key){
	int low=0,high=L.TableLen-1,mid;
	while(low<=high){
		mid=(low+high)/2;
		if(L.elem[mid]==key) return mid;
		else if(L.elem[mid]<key) high=mid-1;//��ǰ���ּ�������
		else low=mid+1;//�Ӻ�벿�ּ�������
	}
	return -1;//����ʧ�ܣ�����-1��
}
