

// C++ program to find the maximum repeating number

#include<iostream>
using namespace std;

// Returns maximum repeating element in arr[0..n-1].
// The array elements are in range from 0 to k-1
int maxRepeating(int* arr, int n, int k)
{
    int ans = 0;


    // Current maximum element.
    int currMax = -1;
    for (int i = 0; i < n; i++)
    {
        // As discussed in the approach.
        arr[arr[i] % k] += k;


        // Update the ans and currMax variables if satisfied.
        if (arr[arr[i] % k] > currMax)
        {
            currMax = arr[arr[i] % k];
            ans = arr[i] % k;
        }
    }



    // Return the ans.
    return ans;

    /* Uncomment this code to get the original array back
       for (int i = 0; i< n; i++)
          arr[i] = arr[i]%k; */

          // Return index of the maximum element
          //return result;
}

// Driver program to test above function
int main()
{
    int arr[] = { 2, 3, 3, 5, 3, 4, 1, 7,293,293,293,293 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 294;

    cout << "The maximum repeating number is " <<
        maxRepeating(arr, n, k) << endl;

    return 0;
}