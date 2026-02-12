#include<stdio.h>
#include<stdlib.h>
typedef struct{
    int *data;
    int size;
    int cap;

} ArrayList;
void initList(ArrayList *list,int  initCap)
{
    list->data=(int *)malloc(initCap*sizeof(int));
    list->size=0;
    list->cap=initCap;
}
void resize(ArrayList *list)
{
    list->cap*=2;
    list->data= (int*)realloc(list->data, list->cap*sizeof(int));
}
void insertLast(ArrayList *list, int val)
{
    if (list->size==list->cap)
    {
        resize(list);
    }
    list->data[list->size++]=val;
//    list->size++;
}
void insertFirst(ArrayList *list, int val)
{
    for (int i=list->size; i>0; i--)
    {
        list->data[i]=list->data[i-1];
    }
    list->data[0]=val;
    list->size++;
}
void delLast(ArrayList *list)
{
    list->data[list->size-1]=0;
    list->size--;
}
void anyPos(ArrayList *list, int pos, int val)
{
    if (pos<=list->size)
    {
        for (int i=size; i>=pos; i--)
        {
            list->data[i]=list->data[i-1];
        }
        list->data[pos]=val;
    }
}

int main()
{
    ArrayList list;
    initList(&list, 2);
//    if (list.size==list.cap)
//    {
//        resize(&list);
//    }
    printf("%d", list.cap);
}
