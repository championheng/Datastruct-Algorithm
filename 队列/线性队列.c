#include <stdio.h>
#include <stdlib.h>
int *array;
int count;
void creat_queue(int size)
{
	array=(int *)malloc(sizeof(int)*size);
	if(array==NULL)
		exit(1);
		count=0;
}
void destory_queue()
{
	if(array)
	{
		free(array);
		array=NULL;
	}
}
void add(int value)
{
	array[count]=value;
	count++;
}
void top_queue()
{
	printf("��ʱ���ж�����Ԫ��Ϊ��%d\n",array[0]);
}
void del()
{
	int i;
	for(i=1;i<count;i++)
	{
		array[i-1]=array[i];
	}
	count--;
}
void empty()
{
	if(count==0)
		printf("���Ǹ��ն��С�\n");
	else
		printf("�������������%d��Ԫ�ء�\n",count);
}
void print()
{
	int i;
	printf("��ʱ�Ķ�������Ԫ�أ�\n");
	for(i=0;i<count;i++)
	{
		printf("%d ",array[i]);
	}
	printf("\n");
}
int main()
{
	int temp,i,size;
	scanf("%d",&size);
	creat_queue(size);
	empty();
	add(10);add(20);add(30);
	print();
	top_queue(); 
	del();
	top_queue();
	print();
	add(40);
	print();
	destory_queue();
	return 0;
}
