/*
 * Name:
 * Date Submitted:
 * Assignment Name:
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <stdbool.h>
#include <algorithm>    // std::sort

using namespace std;

vector<string> loadWordlist(string filename);

/*Implement the following function:
  anagram() takes a word (string) and a wordlist of all words (vector of strings)
  and builds a dictionary/map where the key is a specific number of times each
  letter occurs in a word and the associated value is a vector of strings
  containing all words using those letters (anagrams).
  The value returned is a vector of strings containing the corresponding
  set of anagrams
*/
vector<string> anagram(string word, vector<string> wordlist);

int main()
{
    vector<string> words;
    vector<string> anagrams;
    string inputWord;
    words=loadWordlist("wordlist.txt");
    cout << "Find single-word anagrams for the following word: ";
    cin >> inputWord;
    anagrams = anagram(inputWord, words);
    for (int i=0; i<anagrams.size(); i++)
    {
        cout << anagrams[i] << endl;
    }
    return 0;
}

vector<string> loadWordlist(string filename)
{
    vector<string> words;
    ifstream inFile;
    string word;
    inFile.open(filename);
    if(inFile.is_open())
    {
        while(getline(inFile,word))
        {
            if(word.length() > 0)
            {
                words.push_back(word);
            }
        }
        inFile.close();
    }
    return words;
}

//Implement this function
vector<string> anagram(string word, vector<string> wordlist)
{
    
    vector<string> anagrams;
    
    int wordlen = word.length();
    
    
    //Scans through the wordlist vector
    for(int i = 0; i < wordlist.size(); i++) {
        
        //Checks if anagram, 1 by default, 0 if no
        int anagram = 1;
        
        int word2len = wordlist[i].length();
        
        
        //If the lengths are the same
        if(wordlen == word2len) {
            
            string wordlistword = wordlist[i];
            
            sort(word.begin(), word.end());
            sort(wordlist[i].begin(), wordlist[i].end());

            
            for(int j = 0; j < wordlen; j++) {
                if(word[j] != wordlist[i][j]) {
                    anagram = 0;
                }
            }
            
            
            if(anagram == 1) {
                anagrams.push_back(wordlistword);
            }
            
        }
        
        
    }
    
    return anagrams;
    
}