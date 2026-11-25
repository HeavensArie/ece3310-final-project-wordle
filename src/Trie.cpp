#pragma once

#include <array>
#include <memory>
#include <string>
#include <unordered_map>
using namespace std;

class Trie {
    private:
        struct TrieNode {
            unordered_map<char, unique_ptr<TrieNode>> children;
            int level;
            bool isValid = true;

            bool hasChild(char letter) {
                children.contains(letter);
            }

            TrieNode* getChildNode(char letter){
                auto itr = children.find(letter);
                if(itr == children.end()) {
                    return nullptr;
                }
                return  itr -> second.get();
            }

        };

        TrieNode root;

    public:
        void insertWord(string& newWord){
            TrieNode* currNode = &root;
            for(char letter : newWord) {
                if(currNode->hasChild(letter)){
                    currNode = currNode->getChildNode(letter);
                } else { // Letter doesn't exist as a child
                    auto newLetter = make_unique<TrieNode>();
                    newLetter->level = currNode->level + 1;
                }
            }
        }

};