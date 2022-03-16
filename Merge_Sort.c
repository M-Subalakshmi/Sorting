#include <stdio.h>
void merge(int arr[],int l,int m,int r){
    int n1=m-l+1;
    int n2=r-m;
    int l1[n1],l2[n2];
    for(int i=0;i<n1;i++) l1[i]=arr[i+l];
    for(int j=0;j<n2;j++) l2[j]=arr[j+m+1];
    int i=0,j=0,k=l;
    while(i<n1 && j<n2){
        if(l1[i]<=l2[j]){
            arr[k]=l1[i];
            i++;
        }
        else{
            arr[k]=l2[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        arr[k++]=l1[i++];
    }
    while(j<n2){
        arr[k++]=l2[j++];
    }
}
void sort(int arr[],int l,int r){
    if(l<r){
        int m=(l+r)/2;
        sort(arr,l,m);
        sort(arr,m+1,r);
        merge(arr,l,m,r);
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    sort(a,0,n-1);
    
    for(int i=0;i<n;i++) printf("%d ",a[i]);
}
