#pragma once
#include <iostream>
#include <vector>
#include <string>


int GetHash1(const std::string& value);
int GetHash2(const std::string& value);
int GetHash3(const std::string& value);
int GetHash4(const std::string& value);
int GetHash5(const std::string& value);
int GetHash6(const std::string& value);


class HashTable
{
public:

    HashTable(const int size);

    void Add(const std::string& value);
    void Remove(const std::string& value);
    bool Has(const std::string& value) const;
    int GetHash(const std::string& value) const;
    
    const std::vector<std::vector<std::string>>& GetData() const;
    
    size_t GetSize();

private:
    std::vector<std::vector<std::string>> data_;
};