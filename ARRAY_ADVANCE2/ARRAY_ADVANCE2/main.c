#include<stdio.h>
#include <stdlib.h>
struct Array
{
    int A[20];
    int size;
    int lenght;
};
struct Array *Merge(struct Array *arr1,struct Array * arr2)
{
    int i=0,j=0,k=0;
    struct Array *arr3;
    
    arr3=(struct Array*)malloc(sizeof(struct Array));
    
    while(i<arr1->lenght &&j<arr2->lenght)
    {
        if(arr1->A[i]<arr2->A[j])
            arr3->A[k++]=arr1->A[i++];
        else
            arr3->A[k++]=arr2->A[j++];
    }
    for(;i<arr1->lenght;i++)
        arr3->A[k]=arr1->A[i];
    for (; j<arr2->lenght; j++) {
        arr3->A[k]=arr2->A[j];
    }
    arr3->lenght=arr2->lenght+arr1->lenght;
        
    return arr3;
}
struct Array *Union(struct Array *arr1,struct Array * arr2)
{
    int i=0,j=0,k=0;
    struct Array *arr3;
    
    arr3=(struct Array*)malloc(sizeof(struct Array));
    
    while(i<arr1->lenght &&j<arr2->lenght)
    {
        if(arr1->A[i]<arr2->A[j])
            arr3->A[k++]=arr1->A[i++];
        else if(arr1->A[i]>arr2->A[j])
            arr3->A[k++]=arr2->A[j++];
        else
        {
            arr3->A[k++]=arr1->A[i++];
            j++;
        }
    }
    for(;i<arr1->lenght;i++)
        arr3->A[k++]=arr1->A[i];
    for (; j<arr2->lenght; j++) {
        arr3->A[k++]=arr2->A[j];
    }
    arr3->lenght=k;
    arr3->size=20;
    return arr3;
}
struct Array *Intersection(struct Array *arr1,struct Array * arr2)
{
    int i=0,j=0,k=0;
    struct Array *arr3;
    
    arr3=(struct Array*)malloc(sizeof(struct Array));
    
    while(i<arr1->lenght &&j<arr2->lenght)
    {
        if(arr1->A[i]<arr2->A[j])
            i++;
        else if(arr1->A[i]>arr2->A[j])
            j++;
        else if(arr1->A[i]==arr2->A[j])
        {
            arr3->A[k++]=arr1->A[i++];
            j++;
        }
    }
//    for(;i<arr1->lenght;i++)
//        arr3->A[k++]=arr1->A[i];
//    for (; j<arr2->lenght; j++) {
//        arr3->A[k++]=arr2->A[j];
//    }
    arr3->lenght=k;
    arr3->size=20;
    return arr3;
}
struct Array *Difference(struct Array *arr1,struct Array * arr2)
{
    int i=0,j=0,k=0;
    struct Array *arr3;
    
    arr3=(struct Array*)malloc(sizeof(struct Array));
    
    while(i<arr1->lenght &&j<arr2->lenght)
    {
        if(arr1->A[i]<arr2->A[j])
            arr3->A[k++]=arr1->A[i++];
        else if(arr1->A[i]>arr2->A[j])
            arr3->A[k++]=arr2->A[j++];
        else if(arr1->A[i]==arr2->A[j])
        {
            i++;
            j++;
        }
    }
   for(;i<arr1->lenght;i++)
       arr3->A[k++]=arr1->A[i];
//    for (; j<arr2->lenght; j++) {
//        arr3->A[k++]=arr2->A[j];
//    }
    arr3->lenght=k;
    arr3->size=20;
    return arr3;
}
void Display(struct Array *arr)
{
    for(int i=0;i<arr->lenght;i++)
    {
        printf("%d ",arr->A[i]);
    }
}

int main ()
{
    struct Array arr1={{1,3,5,7,13,14},10,6};
    struct Array arr2={{1,7,2,4,6},10,5};
    struct Array *arr3;
    //arr3=(Merge(&arr1, &arr2));
//    arr3=(Union(&arr1, &arr2));
   // arr3=(Intersection(&arr1, &arr2));
    arr3=(Difference(&arr1, &arr2));

    Display(arr3);
    
    printf("aa");
    
}
