#include<iostream>
//#include<bits/stdc++.h>
using namespace std;
/*
int duplicates(int a[],int n)
{
    int j =0;
    for(int i =0;i<n-1;i++)

        if(a[i]!=a[i+1])

            a[j++] = a[i];
            //j = j++;


    a[j++] = a[n-1];
    return j;
}

int main()
{
    int a[] = {1,2,3,4,5,1,2,4,1,6};
    int len = sizeof(a)/sizeof(a[0]);

    int si = duplicates(a,len);

    for(int j =0;j<si;j++)
    std::cout<<a[j]<<" ";
    return 0;
}
*/

int duplicates(int arr[], int n)
{
    if (n == 0 || n == 1)
        return n;

    int j = 0;

    for (int i = 0; i < n; i++) {
        for (j = i + 1; j < n;)
        {
            if (arr[i] == arr[j])
            {
                for (int k = j; k < n - 1; ++k)
                    arr[k] = arr[k + 1];

                --n;
            }
            else
                ++j;
        }
    }

    return n;
}

// Driver code
int main()
{
    int arr[] = { 1,2,13,4,5,1,2,4,1,6 };//{10, 20, 20, 30, 40, 40, 40, 50, 50};
    int n = sizeof(arr) / sizeof(arr[0]);
    // std::sort(arr,arr+n);
    n = duplicates(arr, n);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}