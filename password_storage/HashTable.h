#pragma once
#include <iostream>
#include <vector>
#include <string>

std::string EncodeString(const std::string& string_to_encode);
std::string DecodeString(const std::string& string_to_decode);
int GetHashFromString(const std::string& value);


struct PasswordStorageEntry
{
    std::string login;
    std::string password;
};

class HashTable
{
public:

    HashTable(const int size);

    void Add(const PasswordStorageEntry& new_pair);
   // void Remove(const std::string& value);
    bool Has(const std::string& value) const;
    int GetHash(const std::string& value) const;
    
    const std::vector<std::vector<PasswordStorageEntry>>&  GetData() const;
    
    size_t GetSize(const int index) const;

private:
    std::vector<std::vector<PasswordStorageEntry>> data_;
};