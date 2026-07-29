#include <iostream>
using namespace std;
#include <map>
#include <set>
using namespace std;

///https://www.geeksforgeeks.org/sorting-a-map-by-value-in-c-stl/
// Comparison function for sorting the
// set by increasing order of its pair's
// second value
struct comp {
    template <typename T>

    // Comparator function
    bool operator()(const T& l, const T& r) const
    {
        if (l.second != r.second) {
            return l.second < r.second;
        }
        return l.first < r.first;
    }
};

// Function to sort the map according
// to value in a (key-value) pairs
void sort(map<string, int>& M)
{

    // Declare set of pairs and insert
    // pairs according to the comparator
    // function comp()
    set<pair<string, int>, comp> S(M.begin(), M.end());

    // Print the sorted value
    for (auto& it : S) {
        cout << it.first << ' ' << it.second << endl;
    }
}

// Driver Code
int main()
{

    // Declare Map
    map<string, int> M;

    // Given Map
    M = { { "GfG", 3 }, { "To", 2 }, { "Welcome", 1 } };

    // Function Call
    sort(M);
    return 0;
}