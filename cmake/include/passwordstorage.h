#pragma once

#include <ostream>
#include "HashTable.h"
/*
std::string EncodeString(const std::string& string_to_encode);
std::string DecodeString(const std::string& string_to_decode);
*/

class PasswordStorage
{

    friend std::ostream& operator<<(std::ostream& out_stream, const PasswordStorage& storage);

public:
    PasswordStorage(const int size);
    void PrintTheDatabase(const PasswordStorage& password_storage) const;
    void GetThePassword() const;
    void ChangePassword();
    void Add(const PasswordStorageEntry& new_pair);
  

private:
    HashTable hashtable_;
    int password_hash = 201099;
};

std::ostream& operator<<(std::ostream& out_stream, const PasswordStorage& storage);
