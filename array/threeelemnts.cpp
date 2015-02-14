#include <stdio.h>
#include<iostream>
#define INT_SIZE 32

using namespace std;

int getSingle(int arr[], int n)
{
    // Initialize result
    int result = 0;

    int x, sum;

    // Iterate through every bit
    for (int i = 0; i < INT_SIZE; i++)
    {
      // Find sum of set bits at ith position in all
      // array elements
      sum = 0;
      x = (1 << i);
      //cout<<x<<" ";
      for (int j=0; j< n; j++ )
      {
          //int m=arr[j] & x;
          //cout<<m<<" ";
          if (arr[j] & x)
            sum++;
      }
      //cout<<"\n";

      // The bits with sum not multiple of 3, are the
      // bits of element with single occurrence.
      if (sum % 3){
        cout<<sum<<" "<<result<<" "<<x<<" ";
        result |= x;
        cout<<result<<endl;
      }
    }

    return result;
}

// Driver program to test above function
int main()
{
    int arr[] = {12, 1, 12, 3, 12, 1, 1, 2, 3, 2, 2, 3, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("The element with single occurrence is %d ",
            getSingle(arr, n));
    return 0;
}
