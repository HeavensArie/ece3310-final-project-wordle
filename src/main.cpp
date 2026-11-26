#include <array>
#include <set>
#include "Trie.cpp"

using namespace std;

int main () {
    array<char, 5> correctLetters;
    set<char> invalidLetters;
    array<set<char>,5> invalidAtPosLetters;

    Trie trie;
    trie.insertWord("hello");
    trie.insertWord("heros");
    trie.insertWord("messy");
    trie.printAllWords();

}
