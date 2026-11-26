#include <array>
#include <memory>
#include <string>
#include <unordered_map>
#include <vector>
#include <set>
#include <iostream>

using namespace std;

class Trie {
    private:
        struct TrieNode {
            unordered_map<char, TrieNode*> children;
            int level;
            bool isValid = true;

            TrieNode(int nodeLevel = 0) : level (nodeLevel) {}

            bool hasChild(char letter) {
                //auto itr = children.find(letter);
                return children.find(letter) != children.end();
            }

            TrieNode* getChildNode(char letter){
                auto itr = children.find(letter);
                if(itr == children.end()) {
                    return nullptr;
                }
                return  itr->second;
            }

        };

        TrieNode root;

    public:
        //Adds word into the trie
        void insertWord(const string& newWord){
            if(newWord.size() == 5) {
                TrieNode* currNode = &root;
                for(char letter : newWord) {
                    if(currNode->hasChild(letter)){
                        currNode = currNode->getChildNode(letter);
                    } else { // Letter doesn't exist as a child
                        TrieNode* newLetterNode = new TrieNode(currNode->level + 1);
                        currNode->children.insert({letter, newLetterNode});
                        currNode = newLetterNode;
                    }
                }
            } else {
                cout << "Invalid String Length. Please enter a word with 5 letters";
            }

        }

        //Prints all words in trie
        void printAllWords() const{
            vector<string> allWords = getAllWords();
            for(string word: allWords) {
                cout << word << " ";
            }

        }

        //Returns all words in a vector
        vector<string> getAllWords() const{
            vector<string> allWords;
            string word = "";
            const TrieNode* currNode = &root;
            getAllWordsHelper(currNode, word, allWords);
            return allWords;
        }

        //Uses recursion to build words based on trie nodes
        void getAllWordsHelper(const TrieNode* currNode, string& word, vector<string>& allWords) const{
            if(currNode->level >= 5) {
                allWords.push_back(word);
                return;
            } else {
                for(const auto& line : currNode->children) {
                    char currChar = line.first;
                    TrieNode* currNode = line.second;
                    word.push_back(currChar);
                    getAllWordsHelper(currNode, word, allWords);
                    word.pop_back();
                }
            }

        }

};