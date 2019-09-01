/*******************************************************************************
**
**  hjs   2019.05.25
**
*******************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#define S_OK             0
#define S_ERR            1
#define MAX_SIZE         10000                                           //�������λͼ�Ĵ�С�ǹ̶��ģ���������趨

#define BIT_INT          32          										//����int������Ϊλͼ����
#define BIT_SLOT(a)      ((a)/BIT_INT) 
#define BIT_MASK(a)      (1 << ((a)%BIT_INT))
#define BIT_SET(a,b)     ((a)[BIT_SLOT(b)] |= BIT_MASK(b))
#define BIT_CLEAR(a,b)   ((a)[BIT_SLOT(b)]  &= ~BIT_MASK(b))
#define BIT_TEST(a,b)    (((a)[BIT_SLOT(b)] & BIT_MASK(b)) >> ((b)%BIT_INT))

#define SET_BIT          1
#define RESET_BIT        2
#define TEST_BIT         3
#define GET_ALL_BIT_ONE  4

/***
***��ʼ��λͼ
***/
int Init_bit_map(int *bit_arry)
{
	int ret = S_OK;
	
	bit_arry = (int *)malloc(sizeof(int)*MAX_SIZE);
	if(NULL == bit_arry)
	{
		return S_ERR;
	}
	memset(bit_arry, 0x0, MAX_SIZE);
	
	return S_OK;
}

/***
***��ĳλ
***/
void Set_bit_map(int *bit_arry, int bit_location)
{
	BIT_SET(bit_arry, bit_location);
}


/***
***���ĳλ
***/
void Reset_bit_map(int *bit_arry, int bit_location)
{
	BIT_CLEAR(bit_arry, bit_location);
}


/***
***��ȡĳλ״̬
***/
bool Get_bit_status_map(int *bit_arry, int bit_location)
{
	bool ret =  BIT_TEST(bit_arry, bit_location);
	return ret;
}

/*��ȡ����Ϊ1��λͼ*/
int Get_all_one_bit(int *bit_arry)
{
	int i = 0;
	int size = sizeof(int)*MAX_SIZE;
	for(i = 0; i < size; i++)
	{
		if(BIT_TEST(bit_arry, i))
		{
			printf("The all one id is %d\n",i);
		}
	}
}

/***
***
��һ������ ȷ������
*** SET_BIT          1  ��λ
*** RESET_BIT        2  ���ĳλ
*** TEST_BIT         3  ��ȡĳλ״̬
*** GET_ALL_BIT_ONE  4  ��ȡ����Ϊ1��λͼ
***  
�ڶ�������
*** location ȷ��Ҫ�õ�λ
***/
int main()
{
	int ret = S_OK;
	int *bit_arry = NULL;
	bit_arry = (int *)malloc(sizeof(int)*MAX_SIZE);
	
	Set_bit_map(bit_arry, 123);
	Set_bit_map(bit_arry, 1234);	
	printf("after set: the 123 id status is %d\n", Get_bit_status_map(bit_arry, 123));
	Reset_bit_map(bit_arry, 123);
	printf("after reset: the 123 id status is %d\n", Get_bit_status_map(bit_arry, 123));
	Set_bit_map(bit_arry, 23);
	Get_all_one_bit(bit_arry);
	
	if(NULL == bit_arry)
	{
		free(bit_arry);
		bit_arry = NULL;
	}

	return ret;
}
