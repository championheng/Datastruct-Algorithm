#include <stdio.h>
#define max_n 100 //����涨���Ľ���� 
#define max_people 10000 //����涨������ڿ����� 
int n;//���������ʱ������ 
int peopletotal;//���� ����ʱ������
int peopleneed[max_n];//�ڵ�i������Ҫ������  
int gold[max_n];//��i�������ڳ��Ľ����� 
int maxgold[max_people][max_n];//����i������ǰj�������õ�������������-1��ʾδ֪ (����¼)
void init(int maxgold[][max_n])
{
	int i,j;
	for(i=0;i<max_people;i++)
	{
		for(j=0;j<max_n;j++)
		{
			maxgold[i][j]=-1;
		}
	}
}
int max(int x,int y)
{
	return (x>y?x:y);
 } 
int getmaxgold(int people,int minenum)
{
	int retmaxgold;//����ÿ��������ڵ����������� 
	if(maxgold[people][minenum]!=-1)//������¼������¼��Ž⣬-1Ϊδ֪ 
	{
		retmaxgold=maxgold[people][minenum];//ֱ�Ӵ���ǰ������Ĵ���Ѱ�Ҵ� 
	}
	else if(minenum==0)
	{
		if(people>=peopleneed[minenum])
		{
			retmaxgold=gold[minenum];
		}
		else
			retmaxgold=0;
	}
	else if(people>=peopleneed[minenum])
	{
		retmaxgold=max(getmaxgold(people-peopleneed[minenum],minenum-1)+gold[minenum],
		getmaxgold(people,minenum-1)); 
	}
	else
		getmaxgold(people,minenum-1);
	maxgold[people][minenum]=retmaxgold;//������¼ 
	return retmaxgold;
}
int main()
{
	int max,i;
	scanf("%d %d",&peopletotal,&n);//�����ڿ������Ϳ��� 
	init(maxgold);//�Ա���¼���г�ʼ�� 
	for(i=0;i<n;i++)
	{
		scanf("%d %d",&peopleneed[i],&gold[i]);
	} 
	max=getmaxgold(peopletotal,n-1);//ÿ�����ܵõ����������� ����̬�滮��ʼ��ת�Ʒ���ʽ��ʼ�� 
	printf("%d",max);
	return 0;
 }
