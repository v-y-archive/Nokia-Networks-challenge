/**
 * Write a function that counts the number of words in the text for each word
 * length (X words with 1-letter length, Y words with 2-letters length, etc.)
 */

#include <string>
#include <map>

std::map<int, int> countNumberOfWordsGroupingByLength(std::string string) {
    std::map<int, int> counterGroups;
    string += " ";
    for (unsigned int from = 0, to; ~(to = string.find(" ", from)); from = to + 1) {
        std::string word = string.substr(from, to - from);
        counterGroups[word.length()]++;
    }
    return counterGroups;
}