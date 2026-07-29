// PrintAnagram.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//Input::::        { "cat", "dog", "tac", "god", "act" };
//
//output::      [dog, god][cat, tac, act]


#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include  <algorithm>

using namespace std;

void printAnagrams(string arr[], int size)
{
    unordered_map<string, vector<string> > map;

    // Loop over all words
    for (int i = 0; i < size; i++) {

        // Convert to char array, sort and
        // then re-convert to string
        string word = arr[i];
        
       /* char letters[sizeof(word) + 1];
        strcpy_s(letters, word.c_str());
        sort(letters, letters + word.size() + 1);
        string newWord = "";
        for (int i = 0; i < word.size() + 1; i++) {
            newWord += letters[i];
        }
        */
        string letters = word;
        sort(letters.begin(), letters.end());
        string newWord = letters;
       
        
        // Calculate hashcode of string
        // after sorting
        if (map.find(newWord) != map.end()) {
            map[newWord].push_back(word);
        }
        else {

            // This is the first time we are
            // adding a word for a specific
            // hashcode
            vector<string> words;
            words.push_back(word);
            map[newWord] = words;
        }
    }

    // Print all the values where size is > 1
    // If you want to print non-anagrams,
    // just print the values having size = 1
   // unordered_map<string, vector<string> >::iterator it;
   // for (it = map.begin(); it != map.end(); it++) {
        for(auto &it:map)
        {
        vector<string> values = map[it.first];
        if (values.size() > 1) {
            cout << "[";
            for (int i = 0; i < values.size() - 1; i++) {
                cout << values[i] << ", ";
            }
            cout << values[values.size() - 1];
            cout << "]";
        }
    }
}

// Driver code
int main()
{
    string arr[] = { "cat", "dog", "tac", "god", "act" };
    int size = sizeof(arr) / sizeof(arr[0]);

    printAnagrams(arr, size);

    return 0;
}
