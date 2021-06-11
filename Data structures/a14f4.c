#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char  StackElementType;           /*ο τύπος των στοιχείων της στοίβας
                                        ενδεικτικά τύπου int */
typedef struct StackNode *StackPointer;
typedef struct StackNode
{
	StackElementType Data;
    StackPointer Next;
} StackNode;

typedef enum {
    FALSE, TRUE
} boolean;

void CreateStack(StackPointer *Stack);
boolean EmptyStack(StackPointer Stack);
void Push(StackPointer *Stack, StackElementType Item);
void Pop(StackPointer *Stack, StackElementType *Item);









  int main()
{ StackPointer stack,currptr;
  StackElementType item;
  int n,i;
  boolean Found;
  char c[40];


    CreateStack(&stack);
    printf("EISAGETE MIA PARASTASH:");
    gets(c);
    Found=TRUE;
    i=0;
    while(i<40 && Found){

        if(c[i]=='{' || c[i]=='(' || c[i]=='[')
            {
                Push(&stack,c[i]);
            }
        else if(c[i]=='}' || c[i]==')' || c[i]==']')
        {
            if(EmptyStack(stack))
            {
                Found=FALSE;
                break;
            }
            else {

              Pop(&stack,&item);
              if(c[i]=='}' && item!='}' )
                {
                    Found=FALSE;
                    break;
                }
                else if(c[i]==')' && item!='(')
                {
                    Found=FALSE;
                     break;
                }
                else if(c[i]==']' && item!='[')
                {
                    Found=FALSE;
                     break;
                }
             }
        }
        i++;
    }
if(Found==FALSE)
{
    printf("WRONG");
}
else{
    printf("CORRECT\n");
}

}






void CreateStack(StackPointer *Stack)
/* Λειτουργία: Δημιουργεί μια κενή συνδεδεμένη στοίβα.
   Επιστρέφει: Μια κενή συνδεδεμένη στοίβα, Stack
*/
{
	*Stack = NULL;
}

boolean EmptyStack(StackPointer Stack)
/* Δέχεται:     Μια συνδεδεμένη στοίβα, Stack.
   Λειτουργία:  Ελέγχει αν η Stack είναι κενή.
   Επιστρέφει:  TRUE αν η στοίβα είναι κενή, FALSE διαφορετικά
*/
{
	return (Stack==NULL);
}

void Push(StackPointer *Stack, StackElementType Item)
/* Δέχεται:    Μια συνδεδεμένη στοίβα που η κορυφή της δεικτοδοτείται από τον
                δείκτη Stack και ένα στοιχείο Item.
   Λειτουργία: Εισάγει στην κορυφή της συνδεδεμένης στοίβας, το στοιχείο Item.
   Επιστρέφει: Την τροποποιημένη συνδεδεμένη στοίβα
*/
{
	StackPointer TempPtr;

    TempPtr= (StackPointer)malloc(sizeof(struct StackNode));
    TempPtr->Data = Item;
    TempPtr->Next = *Stack;
    *Stack = TempPtr;
}

void Pop(StackPointer *Stack, StackElementType *Item)
/* Δέχεται:    Μια συνδεδεμένη στοίβα που η κορυφή της δεικτοδοτείται από τον δείκτη Stack.
   Λειτουργία: Αφαιρεί από την κορυφή της συνδεδεμένης στοίβας,
                αν η στοίβα δεν είναι κενή, το στοιχείο Item.
   Επιστρέφει: Την τροποποιημένη συνδεδεμένη στοίβα και το στοιχείο Item.
   Έξοδος:     Μήνυμα κενής στοίβας, αν η συνδεδεμένη στοίβα είναι κενή
*/
{
    StackPointer TempPtr;

    if (EmptyStack(*Stack)) {
   	    printf("EMPTY Stack\n");
    }
   else
   {
        TempPtr = *Stack;
        *Item=TempPtr->Data;
        *Stack = TempPtr->Next;
        free(TempPtr);
    }
}




