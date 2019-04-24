#include "HashTable.h"
#include <iostream>

HashTable::HashTable(const int size)
{
    const int hsize = 1013;
    for (int i = 0; i < hsize; i++)
    {
        std::vector<PasswordStorageEntry> new_;
        data_.push_back(new_);
    }
}

void HashTable::Add(const PasswordStorageEntry& new_pair)
{
    PasswordStorageEntry encode;
    encode.login = EncodeString(new_pair.login);
    encode.password = EncodeString(new_pair.password);

    if (Has(encode.login) == 0)
    {
        data_[GetHash(encode.login)].push_back(encode);
    }
}


size_t HashTable::GetSize(const int index) const
{
    return data_[index].size();
}

int HashTable::GetHash(const std::string& value) const
{
    return GetHashFromString(value) % data_.size();
}

bool HashTable::Has(const std::string& value) const
{
    const int hash = GetHash(EncodeString(value));
    for (int i = 0; i < data_[hash].size(); i++)
    {
        if (data_[hash][i].login == value)
        {
            return true;
        }
    }
    return false;
}

const std::vector<std::vector<PasswordStorageEntry>>&  HashTable::GetData() const
{
    return data_;
}
