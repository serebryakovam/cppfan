#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <string>
#include "HashTable.h"

 std::string TrimWord(const std::string& raw_word)
    {
    size_t begin_pos = 0;
    size_t word_length = raw_word.npos;

    for (size_t i = 0; i < raw_word.size(); i++)
    {
        if (isalpha(raw_word[i]))
        {
            begin_pos = i;
            break;
            }
        }

    for (size_t i = begin_pos; i < raw_word.size(); i++)
    {
         if (!isalpha(raw_word[i]))
         {
            word_length = i - begin_pos;
            break;
         }
    }

    return raw_word.substr(begin_pos, word_length);
}

int main()
{
    const int hsize = 1013;
    HashTable hashtable1(hsize);

    std::ifstream in_stream("cano.txt");
    for (std::string word; in_stream >> word; )
    {
        hashtable1.Add(word);
    }
    std::ofstream output_file("output6.txt");
    for (size_t i = 0; i < hashtable1.GetSize(); ++i)
    {
       output_file << hashtable1.GetData()[i].size() << std::endl;
    }
    return 0;
}