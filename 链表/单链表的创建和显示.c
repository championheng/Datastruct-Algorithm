#include <stdio.h>
#include <stdlib.h> 
struct STUDENT{
	char name[20];
	int number;
	struct student *p;
};
struct STUDENT *Create()
{
	int count=0;
	struct STUDENT *pHead=NULL,*pEnd,*pNew;
	pNew=(struct STUDENT*)malloc(sizeof(struct STUDENT));
	pEnd=pNew;
	scanf("%s",pNew->name);
	scanf("%d",&pNew->number);
	while(pNew->number!=0)
	{
		count++;
		if(count==1)
		{
			pNew->p=pHead;
			pEnd=pNew;
			pHead=pEnd;
		}
		else
		{
			pNew->p=NULL;
			pEnd->p=pNew;
			pEnd=pNew;//Ųλ
		}
		pNew=(struct STUDENT*)malloc(sizeof(struct STUDENT));
		scanf("%s",pNew->name);
		scanf("%d",&pNew->number);
	}
	free(pNew);
	return pHead;
}
void print(struct STUDENT *pHead)
{
	struct STUDENT *Temp;
	int index=1;
	Temp=pHead;;
	while(Temp!=NULL)
	{
		printf("��%d��ѧ����������\n",index);
		printf("%s",Temp->name);
		printf("��%d��ѧ����ѧ�ţ�\n",index);
		printf("%d",Temp->number);
		Temp=Temp->p;
		index++;
	}
}
int main()
{
	struct STUDENT *pHead=Create();
	print(pHead);
} 
