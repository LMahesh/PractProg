// summarraynotadjacent.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

// Function to return max sum such that 
// no two elements are adjacent 
int FindMaxSum(vector<int> arr, int n)
{
    int incl = arr[0];
    int excl = 0;
    int excl_new;
    int i;

    for (i = 1; i < n; i++) {
        // Current max excluding i
        excl_new = max(incl, excl);

        // Current max including i
        incl = excl + arr[i];
        excl = excl_new;
                                            // { 5, 5, 10, 100, 10, 5 }

        std::cout << incl << " :" << excl << std::endl;
    }

    // Return max of incl and excl
    return max(incl, excl);
}

// Driver code

int main()
{
    vector<int> arr = { 5, 5, 10, 100, 10, 5 };
    int N = arr.size();

    // Function call
    cout << FindMaxSum(arr, N);
    return 0;
} 
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
