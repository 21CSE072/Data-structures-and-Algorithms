#include <stdio.h>
int main()
{
   int n,search,ans;
   printf("enter the number of elements");
   scanf("%d",&n);
   int arr[n];
   printf("enter the elements");
   for(int i=0;i<n;i++)
   {
       scanf("%d",&arr[i]);
   }
   printf("enter the search element");
   scanf("%d",&search);
   //binary search
   int low=0,high=n-1,mid;
   while(low<=high)
   {
       mid=(low+high)/2;
       if(arr[mid]==search)
       {
          if(arr[mid-1]==search)
          {
              ans=mid-1;//for upper bound check mid+1
          }
          else
          {
              ans=mid;
          }
          break;
       }
       else if(search<arr[mid])
       {
           high=mid-1;
       }
       else
       {
           low=mid+1;
       }
   }
   printf("%d",ans);
   return 0;
}
