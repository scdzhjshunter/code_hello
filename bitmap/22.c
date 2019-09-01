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
#define MAX_SIZE         100000                                            //�������λͼ�Ĵ�С�ǹ̶��ģ���������趨

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

int Get_all_one_bit(int *bit_arry)
{
	int i = 0;
	for(i = 0; i < MAX_SIZE; i++)
	{
		if(BIT_TEST(bit_arry, i))
		{
			printf("The id is %d\n",i);
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
int main(int argc, char *argv[])
{
	int ret = S_OK;
	int i = 0;
	int level = atoi(argv[1]);
	int location = atoi(argv[2]);  
	int *bit_arry = NULL;
	ret = Init_bit_map(bit_arry);
	if(S_ERR == ret)
	{
		printf("Malloc memmory fail\n");
		exit(-1);
	}
	
	/*��λ*/
	if(SET_BIT == level)
	{
		Set_bit_map(bit_arry, location);	
	}

	/*���ĳλ*/
	if(RESET_BIT == level)
	{
		Reset_bit_map(bit_arry, location);
	}
	
	/*����ĳλid��״̬*/
	if(TEST_BIT == level)
	{
		printf("The id status is %d", Get_bit_status_map(bit_arry, location));
	}

	/*��ȡ����״̬Ϊ1��id*/
	if(GET_ALL_BIT_ONE == level)
	{
		Get_all_one_bit(bit_arry);
	}
	
	/*�ͷ�*/
	if(NULL == bit_arry)
	{
		free(bit_arry);
		bit_arry = NULL;
	}

	return ret;
}
