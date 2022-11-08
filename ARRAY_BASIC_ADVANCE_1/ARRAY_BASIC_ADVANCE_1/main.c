#include <stdio.h>
#include <stdlib.h>
struct Array
{
    int A[10];
    int size;
    int lenght;
};
void Display(struct Array arr)
{
    for(int i=0;i<arr.lenght;i++)
    {
        printf("%d ",arr.A[i]);
    }
}
void Append(struct Array *arr,int x)
{
    if(arr->lenght<arr->size)
    {
        arr->A[arr->lenght++]=x;
        
    }
        
}
void Insert (struct Array *arr ,int index,int x)
{
    if(index>=0&&index<=arr->lenght)
    {
        for(int i=arr->lenght;i>index;i--)
        {
            arr->A[i]=arr->A[i-1];
        }
        arr->A[index]=x;
        arr->lenght++;
    }
}
void Delete(struct Array *arr, int index)
{
    if(index>=0&&index<=arr->lenght)
    {
        for(int i=index;i<=arr->lenght;i++)
        {
            arr->A[index]=arr->A[i-1];
        }
        arr->lenght--;
    }
}
void Swap(int *x,int *y)
{
    int temp;
    temp=*x;
    *x= *y;
    *y=temp;
    
}
int LinearSearch(struct Array arr,int key)
{
    for(int i=0;i<arr.lenght;i++)
    {
     if(arr.A[i]==key)
         return 1;
    }
    return 0;
}
int BinarySearch(struct Array arr,int h,int l,int key)
{
    int low=l;
    int high=h;
    while (low<=high)
    {
        int mid=((low+high)/2);
        if(key==arr.A[mid])
            return 1;
        else if(key<arr.A[mid])
            high=mid;
        else
            low=mid;
        
    }return 0;
}
int get(struct Array arr,int index)
{
    if(index>=0&&index<=arr.lenght)
        return arr.A[index];
    return -1;
}
void set(struct Array *arr,int index,int x)
{
    if(index>=0&&index<=arr->lenght)
        arr->A[index]=x;
}
void maxmin(struct Array arr)
{
    int min=arr.A[0];
    int max=arr.A[0];
    for (int i=1;i<arr.lenght;i++)
    {
        if(arr.A[i]>max)
            max=arr.A[i];
        if(arr.A[i]<min)
            max=arr.A[i];
    }
    printf("\nmax is %d and min is %d\n\n",max,min);
    
}
void sum(struct Array arr)
{
    int i;
    int sum=0;
    for (i=0;i<arr.lenght;i++)
        sum+=arr.A[i];
    printf("sum is %d \nand avg is %d\n",sum,(sum/i));
}
void ReversingArray(struct Array * arr)
{
    //int temp;
    for(int i=0,j=arr->lenght-1;i<=j;i++,j--)
    {
//        temp=arr->A[i];
//        arr->A[i]=arr->A[j];
//        arr->A[j]=temp;
        Swap(&arr->A[i],&arr->A[j]);
        
    }
}
void ReversingArray2(struct Array *arr)
{
    int *b;
    int i ,j;
    b=(int*)malloc(arr->lenght*sizeof(int));
    for(i=arr->lenght-1,j=0;i>=0;j++,i--)
    {
        b[j]=arr->A[i];
    }
    for (i=0;i<arr->lenght;i++)
    {
        arr->A[i]=b[i];
    }
    
    
}
int IsSorted(struct Array arr)
{
    for(int i=0;i<arr.lenght-1;i++)
    {
        if(arr.A[i]>arr.A[i+1]){
            return 0;
        };
    }return 1;
}
void InsrtIfSorted(struct Array* arr,int x)
{
    int i=arr->lenght-1;
    if(arr->lenght==arr->size)
        return;
    while (i>0&&arr->A[i]>x) {
        arr->A[i+1]=arr->A[i];
        i--;
    }
    arr->A[i+1]=x;
    arr->lenght++;
}
void Rearrange(struct Array* arr)
{
    int i=0,j=arr->lenght-1;
    while(i<j)
    {
        while(arr->A[i]<0)i++;
        while (arr->A[j] >=0)j--;
        if(i<j)
            Swap(&arr->A[i], &arr->A[j]);
        
    }
    
}
int main ()
{
    struct Array arr={{1,-2,3,4,5,-9},10,6};
//    Append(&arr,100);
//    Insert(&arr, 2, 1111);
//    Delete(&arr, 0);
//    set(&arr, 2,100);
    Display(arr);
    //printf("\n\n\n");
    //ReversingArray(&arr);
   // ReversingArray2(&arr);
    //Display(arr);
  //  InsrtIfSorted(&arr,8);
    printf("\n\n\n");
    //printf("%d",IsSorted(arr));
    Rearrange(&arr);
    Display(arr);
//    printf("%d",LinearSearch(arr, 12));
//    printf("%d",BinarySearch(arr, 3,0,12));
//    maxmin(arr);
//    sum(arr);
    
    return 0;
}


