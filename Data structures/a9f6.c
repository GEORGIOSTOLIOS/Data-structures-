#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define HMax 11              /*     �� ������� ��� ������ HashTable
                                ���������� ��� �� 5 */
#define VMax 30             /*�� ������� ��� ������,
                                ���������� ��� �� 30 */
#define EndOfList -1        /* ������ ��� ����������� �� ����� ��� ������
                                ��� ��� ���� ��������� ��������� */

typedef struct{

     int service;
     double amount;

     } ListElementType;

typedef struct {
	int RecKey;
	ListElementType Data;
	int Link;
} ListElm;

typedef struct  {
	int HashTable[HMax];   // ������� ������� ���� ��� ��������� ���������
    int Size;                // ������ �������� ��� ������ List
	int SubListPtr;          // D������� �� ��� �������� ���������
    int StackPtr;           // ������� ���� ��� ����� �������� ���� ��� ������ List
	ListElm List[VMax];
} HashListType;

typedef enum {
    FALSE, TRUE
} boolean;

void CreateHashList(HashListType *HList);
int HashKey(int Key);
boolean FullHashList(HashListType HList);
void SearchSynonymList(HashListType HList,int KeyArg,int *Loc,int *Pred);
void SearchHashList(HashListType HList,int KeyArg,int *Loc,int *Pred);
void AddRec(HashListType *HList,ListElm InRec);
void DeleteRec(HashListType *HList,int DelKey);


int main()
{
   int choice;
   char ch,c[26]="ABCDEFGHIJKLMNOPQRSTUVWXYZ",name[20],con;
   HashListType HList;
   ListElm AnItem;
   int AKey,i,j;
   int Loc, Pred;
   boolean flag;




   choice=5;
   while(choice!=4)
   {    printf("1. CREATE DATABASE\n");
        printf("2. INSERT APPOINTMENT\n");
        printf("3. PRINT CLIENT'S APPOINTMENTS\n");
        printf("4. EXIT\n");
        printf("CHOICE:");
        scanf("%d",&choice);

      if(choice==1)
      {
          CreateHashList(&HList);
      }
      else if(choice==2)

      {
           flag=TRUE;
           while(flag){
          printf("Enter the client's Name:");
          scanf("%s",name);
          printf("Enter the service:");
          printf("\n");
          printf("1-Whitening\n");
          printf("2-Cleaning\n");
          printf("3-Extraction\n");
          printf("choice of service:");
          scanf("%d",&AnItem.Data.service);
          printf("Enter the amount paid:");
          scanf("%lf",&AnItem.Data.amount);
          AnItem.RecKey=0;
          for(i=0; i<strlen(name); i++)
          {
                   for(j=0; j<26; j++)
                    {
                        if(name[i]==c[j])
                        {
                            AnItem.RecKey=AnItem.RecKey+(i+1)*(j+1);
                            break;
                        }
                    }
          }
          AddRec(&HList,AnItem);
          printf("Continue Y/N:");
          scanf(" %c",&con);
          getchar();
          while(con!='Y' && con!='N')
          {
             printf("Continue Y/N:");
             scanf(" %c",&con);
             getchar();

          }
          if(con=='N')flag=FALSE;









      } }
      else if(choice==3)
      {
          printf("Enter the client's Name:");
          scanf("%s",name);
          AKey=0;
          for(i=0; i<strlen(name); i++)
          {
                   for(j=0; j<26; j++)
                    {
                        if(name[i]==c[j])
                        {
                            AKey=AKey+(i+1)*(j+1);
                            break;
                        }
                    }
          }
          SearchHashList(HList,AKey,&Loc,&Pred);
          if(Loc!=-1)
          {
             printf("Service:%d\n",HList.List[Loc].Data.service);
             printf("Amount Paid:%.2f\n",HList.List[Loc].Data.amount);
          }
          else{
            printf("Not Found\n");
          }


      }
       } }



int HashKey(int Key)
/* �������:    ��� ���� Key ���� ��������.
   ����������: ������� ��� ���� ��������������� HValue ��� �� ������ Key.
   ����������: ��� ���� ��������������� HValue
*/
{
	return Key%HMax;
}

void CreateHashList(HashListType *HList)
/* ����������: ���������� ��� ���� HList.
   ����������: ��� ���� HList
*/
{
	int index;

	HList->Size=0;           //���������� ��� ���� �����
	HList->StackPtr=0;       //������� ��� ������ ��� ������� ��� ��������� ������

    /*����������� ��� ������ HashTable ��� ����� HList ���� ���� ��������� ���
        �� ���� �� ���� EndOfList (-1)*/
    index=0;
	while (index<HMax)
	{
		HList->HashTable[index]=EndOfList;
		index=index+1;
    }

     //���������� ��� ������� ��� ��������� ������ ��� ����� HList
    index=0;
	while(index < VMax-1)
	{
		HList->List[index].Link=index+1;
		HList->List[index].Data.amount=0;
		HList->List[index].Data.service=0;
		index=index+1;
	}
	HList->List[index].Link=EndOfList;


}

boolean FullHashList(HashListType HList)
/* �������:    ��� ���� HList.
   ����������: ������� �� � ����� List ��� ����� HList ����� ������.
   ����������: TRUE �� � ����� List ����� ������, FALSE �����������.
*/
{
	return(HList.Size==VMax);
}

void SearchSynonymList(HashListType HList,int KeyArg,int *Loc,int *Pred)
/* �������:     ��� ���� HList ��� ��� ���� �������� KeyArg.
    ����������: ������� ��� ������� �� ������ KeyArg ���� �������� ���������.
    ����������: �� ���� Loc ��� �������� ��� �� ���� Pred ��� ������������
                �������� ���� ��������
*/
{
	int Next;
	Next=HList.SubListPtr;
	*Loc=-1;
	*Pred=-1;
	while(Next!=EndOfList)
	{
		if (HList.List[Next].RecKey==KeyArg)
		{
			*Loc=Next;
			Next=EndOfList;
		}
		else
		{
			*Pred=Next;
			Next=HList.List[Next].Link;
		}
	}
}
void SearchHashList(HashListType HList,int KeyArg,int *Loc,int *Pred)
/* �������:     ��� ���� HList ��� ��� ���� �������� KeyArg.
    ����������: ������� ��� ������� �� ������ KeyArg ��� ���� HList.
    ����������: �� ���� Loc ��� �������� ��� �� ���� Pred ���
                ������������ �������� ��� ��������� ���� ����� ������.
                �� ��� ������� ������� �� ������ KeyArg ���� Loc=Pred=-1
*/
{
	int HVal;
	HVal=HashKey(KeyArg);
    if (HList.HashTable[HVal]==EndOfList)
	{
		*Pred=-1;
		*Loc=-1;
	}
	else
	{
		HList.SubListPtr=HList.HashTable[HVal];
		SearchSynonymList(HList,KeyArg,Loc,Pred);
	}
}

void AddRec(HashListType *HList,ListElm InRec)
/* �������:    ��� ���� HList ��� ��� ������� InRec.
   ����������: ������� ��� ������� InRec ��� ����� List, �� ��� ����� ������,
                ��� ���������� �� ���� HList.
   ����������: ��� ������������� ���� HList.
   ������:     ������ ������� ������, �� � List ����� ������, �����������,
                �� ������� ��� ������� �� �� ���� ������,
                �������� ����������� ���������
*/
{
	int Loc, Pred, New, HVal;

   // New=0;
	if(!(FullHashList(*HList)))
	{
		Loc=-1;
		Pred=-1;
		SearchHashList(*HList,InRec.RecKey,&Loc,&Pred);
		if(Loc==-1)
		{
			HList->Size=HList->Size +1;
			New=HList->StackPtr;
			HList->StackPtr=HList->List[New].Link;
			HList->List[New]=InRec;
			if (Pred==-1)
			{
			    HVal=HashKey(InRec.RecKey);
                HList->HashTable[HVal]=New;
				HList->List[New].Link=EndOfList;
			}
			else
			{
                HList->List[New].Link=HList->List[Pred].Link;
				HList->List[Pred].Link=New;
			}
		}

		else
		{
			printf("YPARXEI HDH EGGRAFH ME TO IDIO KLEIDI \n");
		}
	}
	else
	{
		printf("Full list...");
	}
}
void DeleteRec(HashListType *HList,int DelKey)
/* DEXETAI:    TH DOMH (HList) KAI To KLEIDI (DelKey) THS EGGRAFHS
               POY PROKEITAI NA DIAGRAFEI
   LEITOYRGIA: DIAGRAFEI, THN EGGRAFH ME KLEIDI (DelKey) APO TH
               LISTA (List), AN YPARXEI ENHMERWNEI THN DOMH HList
   EPISTREFEI: THN TROPOPOIHMENH DOMH (HList)
   EJODOS:     "DEN YPARXEI EGGRAFH ME KLEIDI" MHNYMA
*/
{
	int Loc, Pred, HVal;

	SearchHashList(*HList,DelKey,&Loc,&Pred);
	if(Loc!=-1)
	{
		if(Pred!=-1)
		{
			HList->List[Pred].Link=HList->List[Loc].Link;
		}
		else
		{
			HVal=HashKey(DelKey);
		    HList->HashTable[HVal]=HList->List[Loc].Link;
		}
		HList->List[Loc].Link=HList->StackPtr;
		HList->StackPtr=Loc;
		HList->Size=HList->Size -1;
	}
	else
	{
		printf("DEN YPARXEI  EGGRAFH ME KLEIDI %d \n",DelKey);
	}
}

