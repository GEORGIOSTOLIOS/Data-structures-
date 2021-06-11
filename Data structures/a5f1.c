#include <stdio.h>
#include <stdlib.h>


#define megisto_plithos 1500          //������� ������ ��������� �������

typedef enum {
    FALSE, TRUE
} boolean;

typedef boolean typos_synolou[megisto_plithos];
typedef int stoixeio_synolou;

void Dimiourgia(typos_synolou synolo);
void Katholiko(typos_synolou synolo);
void Eisagogi(stoixeio_synolou stoixeio, typos_synolou synolo);
void Diagrafi(stoixeio_synolou stoixeio, typos_synolou synolo);
boolean Melos(stoixeio_synolou stoixeio, typos_synolou synolo);
boolean KenoSynolo(typos_synolou synolo);
boolean IsaSynola(typos_synolou s1, typos_synolou s2);
boolean Yposynolo(typos_synolou s1, typos_synolou s2);
void EnosiSynolou(typos_synolou s1, typos_synolou s2, typos_synolou enosi);
void TomiSynolou(typos_synolou s1, typos_synolou s2, typos_synolou tomi);
void DiaforaSynolou(typos_synolou s1, typos_synolou s2, typos_synolou diafora);
boolean isFibonacci (stoixeio_synolou n,typos_synolou S);
void createFibonacciSet(stoixeio_synolou threshold,typos_synolou S);
void displayset(typos_synolou set);





int main (){
stoixeio_synolou max,num;
typos_synolou S;

Dimiourgia(S);
printf("give a number from 2 to 1000:");
scanf("%d",&max);
while( max>1000  || max<2)
{
    printf("give a number from 2 to 1000:");
     scanf("%d",&max);
}
printf("\n");
createFibonacciSet(max,S);
displayset(S);
printf("Enter number to check:");
scanf("%d",&num);
if(isFibonacci(num,S))
{
    printf("FIBONACCI");
    printf("\n");
}
else
{
    printf("NOT FIBONACCI");
    printf("\n");
}
while(num!=-1)
{   printf("Enter number to check:");
    scanf("%d",&num);
if(isFibonacci(num,S))
{
    printf("FIBONACCI");
    printf("\n");
}
else
{
    printf("NOT FIBONACCI");
    printf("\n");
}
}

     }

boolean isFibonacci (stoixeio_synolou n,typos_synolou S)
{
    return Melos(n,S);
}
void createFibonacciSet(stoixeio_synolou threshold,typos_synolou S)
{       int a,b,c,tempb,tempc;

        a=0;
        b=1;
        c=a+b;
        tempb=b;
        Eisagogi(a,S);
        Eisagogi(b,S);
        Eisagogi(c,S);
        while(c<threshold)
        {

            a=b;
            b=c;

            c=a+b;
            if(c>threshold)break;
            Eisagogi(c,S);
        }


}


void Dimiourgia(typos_synolou synolo)
/* ����������: ���������� ��� ������ ����� ��������, ������ �� ���� ������.
   ����������: �� ���� ������
*/
{
    stoixeio_synolou i;

    for (i = 0; i < megisto_plithos; i++)
        synolo[i] = FALSE;
}

void Katholiko(typos_synolou synolo)
/* �������:     ��� ������.
   ����������: ���������� ��� ������ �� ��� �� �������� �������,
                ���� ���� �������� ��� ����� �������� ��� ������������.
   ����������: �� �������� ������ ��� �������������
*/
{
    stoixeio_synolou i;

    for (i = 0; i < megisto_plithos; i++)
        synolo[i] = TRUE;
}

void Eisagogi(stoixeio_synolou stoixeio, typos_synolou synolo)
/* �������:    ��� ������ ��� ��� ��������.
   ����������: ������� �� �������� ��� ������.
   ����������: �� ������������� ������
*/
{
    synolo[stoixeio] = TRUE;
}

void Diagrafi(stoixeio_synolou stoixeio, typos_synolou synolo)
/* �������:     ��� ������ ��� ��� ��������.
   ����������:  ��������� �� �������� ��� �� ������.
   ����������:  �� ������������� ������
*/
{
    synolo[stoixeio] = FALSE;
}

boolean Melos(stoixeio_synolou stoixeio, typos_synolou synolo)
/* �������:    ��� ������ ��� ��� ��������.
   ����������: ������� �� �� �������� ����� ����� ��� �������.
   ����������: ���������� TRUE �� �� �������� ����� ����� ��� ��� FALSE �����������
*/
{
    return synolo[stoixeio];
}

boolean KenoSynolo(typos_synolou synolo)
/*
�������: ��� ������.
 ����������: ������� �� �� ������ ����� ����.
 ����������: ���������� TRUE �� �� ������ ����� ���� ��� FALSE �����������
*/
{
    stoixeio_synolou i;
    boolean keno;

    keno=TRUE;
    i = 0;

    while (i < megisto_plithos  && keno) {
        if (Melos(i, synolo))
            keno = FALSE;
        else
            i++;
    }
    return keno;
}

boolean IsaSynola(typos_synolou s1, typos_synolou s2)
/* �������:     ��� ������ s1 ��� s2.
   ����������: ������� �� �� ��� ������ ����� ���.
   ����������: ���������� TRUE �� �� ��� ������ ����� �� ���� �������� ��� FALSE �����������
*/
{
    stoixeio_synolou i;
    boolean isa;

    isa = TRUE;
    i=0;
    while (i < megisto_plithos && isa)
        if (Melos(i,s1) != Melos(i,s2))
            isa = FALSE;
        else
            i++;
    return isa;
}

boolean Yposynolo(typos_synolou s1, typos_synolou s2)
/* �������:     ��� ������ s1 ��� s2.
   ����������: ������� �� �� ������ s1 ����� ��������� ��� s2.
   ����������: ���������� true �� �� ������ s1 ����� ��� ��������� ��� s2,
                ������ �� ���� �������� ��� s1 ����� ��� �������� ��� s2
*/
{
    stoixeio_synolou i;
    boolean yposyn;

    yposyn = TRUE;
    i=0;
    while (i < megisto_plithos && yposyn)
        if (Melos(i, s1) && !Melos(i, s2))
            yposyn = FALSE;
        else
            i++;
    return yposyn;
}

void EnosiSynolou(typos_synolou s1, typos_synolou s2, typos_synolou enosi)
/* �������:     ��� ������ s1 ��� s2.
   ����������: ���������� ��� ��� ������ �� �� �������� ��� ������� � ��� s1 �
                ��� s2 � ��� ��� ��� ������.
   ����������: ���������� �� ������ enosi ��� ��������� ��� ��� ����� ��� ������� s1 ��� s2
*/
{
    stoixeio_synolou i;

    for (i = 0; i < megisto_plithos; i++)
        enosi[i] = Melos(i, s1) || Melos(i, s2);
}

void TomiSynolou(typos_synolou s1, typos_synolou s2, typos_synolou tomi)
/* �������:     ��� ������ s1 ��� s2.
   ����������: ���������� ��� ��� ������ �� �� �������� ��� ������� ��� ��� ��� ������ s1 ��� s2.
   ����������: ���������� �� ������ tomi ��� ��������� ��� ��� ���� ��� ������� s1 ��� s2
*/
{
    stoixeio_synolou i;

    for (i = 0; i < megisto_plithos; i++)
        tomi[i] = Melos(i, s1) && Melos(i, s2);
}

void DiaforaSynolou(typos_synolou s1, typos_synolou s2, typos_synolou diafora)
/* �������: ��� ������ s1 ��� s2.
 ����������: ���������� ��� ��� ������ �� �� �������� ��� ������� ��� ������ s1 ��� ��� ������� ��� s2.
 ����������: ���������� �� ������ diafora ��� ��������� ��� ��� ������� ��� ������� s1-s2.
*/
{
    stoixeio_synolou i;

    for (i = 0; i < megisto_plithos; i++)
        diafora[i] = Melos(i, s1) && (!Melos(i, s2));
}

void displayset(typos_synolou set)
{
	stoixeio_synolou i;

	for (i=0;i < megisto_plithos;i++)
	{
		if(Melos(i,set))
			printf(" %d",i);
	}
	printf("\n");
}
