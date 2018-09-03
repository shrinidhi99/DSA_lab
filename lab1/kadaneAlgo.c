// Maximum sum of contigous subarray in the given array
// This can be solved using
// 1)Kadane's Algo - O(n)
// 2)Divide and Conquer method - O(nlogn)
// 3)Brute force - O(n^2)

//By Kadane's Algo

#include<stdio.h>

int maxsubarray(int A[],int n);

void main()
{
    int n,i;
    printf("enter the size of array\n");
    scanf("%d",&n);
    int A[n];
    printf("Enter the elements\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&A[i]);
    }
    int ans=maxsubarray(A,n);   //passing array to maxsubarray function
    printf("%d",ans);           //printing the result
}

int maxsubarray(int A[],int n)  //kadane's algorithm
{
    int sum=0,ans=0,i;

    for(i=0;i<n;i++)
    {
        if(sum+A[i] > 0)
        {
            sum+=A[i];
        }
        else
        {
            sum=0;
        }
        if(ans < sum)
            ans=sum;
    }
    return ans;
}
