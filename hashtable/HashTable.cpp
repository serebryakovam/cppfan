#include "HashTable.h"
#include <iostream>
#include <vector>
#include <string>

int HashTable::GetHash1(const std::string& value)
{
    return 1;
}

int HashTable::GetHash2(const std::string& value)
{
    return value[0];
}

int HashTable::GetHash3(const std::string& value)
{
    return value.size();
}

int HashTable::GetHash4(const std::string& value)
{
    int hash = 0;
    for (int i = 0; i < value.size(); i++)
    {
    hash += value[i];
    }
    return hash;
    }

int HashTable::GetHash5(const std::string& value)
{
    int hash = 0;
    for (int i = 0; i < value.size(); i++)
    {
        hash += (value[i] << 2) * 179;
    }
    return hash;
}

int HashTable::GetHash6(const std::string& value)
{
    if (value.size() == 0)
    {
        return 1;
    }
    int hash = value[0];
    for (int i = 1; i < value.size(); i++)
    {
        hash = (hash << 1) ^ value[i];
    }
    return hash;
}

HashTable::HashTable(const int size)
{
    int hsize = 1013;
    for (int i = 0; i < hsize; i++)
    {
        std::vector<std::string> new_vector;
        data_.push_back(new_vector);
    }
}

void HashTable::Add(const std::string& value)
{
    int hash = GetHash(value);
    if (this->Has(value) == 0)
    {
        data_[hash].push_back(value);
    }
}

void HashTable::Remove(const std::string& value)
{
    int hash = GetHash(value);
    for (int i = 0; i < data_.size(); i++)
    {
        if (data_[hash][i] == value)
        {
            data_.erase(data_.begin() + i);
        }
    }
}

size_t HashTable::GetSize(const int key)
{
    return data_[key].size();
}

int HashTable::GetHash(const std::string& value) const
{
    return GetHash6(value) % data_.size();
}

bool HashTable::Has(const std::string& value) const
{
    int hash = GetHash(value);
    for (int i = 0; i < data_[hash].size(); i++)
    {
        if (data_[hash][i] == value)
        {
            return true;
        }
    }
    return false;
}

const std::vector<std::vector<std::string>>& HashTable::GetData() const
{
    return data_;
}