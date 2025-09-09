#include <stdio.h>
int FindMax(int arr[],int left,int right){
   int mid,maxLeft,maxRight;
   if (left == right) {
       return arr[left];      //base case
   }
   if(left<right){
       mid=(int)(left+right)/2;
       maxLeft = FindMax(arr,left,mid);
       maxRight = FindMax(arr,mid+1,right);
   }
   if(maxLeft>maxRight){
       return maxLeft;
   }
   else{
       return maxRight;
   }
}
int FindMin(int arr[],int left,int right){
   int mid,minLeft,minRight;
   if (left == right) {
       return arr[left];               //base case
   }
   if(left<right){
       mid=(int)(left+right)/2;
       minLeft = FindMin(arr,left,mid);
       minRight = FindMin(arr,mid+1,right);
   }
   if(minLeft<minRight){
       return minLeft;
   }
   else{
       return minRight;
   }
}
int main(){
   int n,i;
   printf("Enter the number of elements in the array: ");
   scanf("%d",&n);
   int arr[n];
   printf("Enter the elements of the array: \n");
   for(i=0;i<n;i++){
       scanf("%d",&arr[i]);
   }
   int max = FindMax(arr,0,n-1);
   printf("The maximum element in the array is: %d\n",max);
   int min=FindMin(arr,0,n-1);
   printf("The minimum element in the array is: %d\n",min);
   return 0;
}
