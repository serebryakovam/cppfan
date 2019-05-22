#include "passwordstorage.h"
#include "HashTable.h"
#include <ostream>


PasswordStorage::PasswordStorage(const int size) : hashtable_(size)
{
};

void PasswordStorage::PrintTheDatabase(const PasswordStorage& password_storage) const
{
    std::cout << password_storage;
};

void PasswordStorage::GetThePassword() const
{
    std::cout << "Enter the login:" << std::endl;
    std::string login;
    std::cin >> login;
    if (hashtable_.Has(login) == true)
    {
        int login_hash = hashtable_.GetHash(login);
        std::cout << "Password: " << DecodeString(hashtable_.GetData()[login_hash][0].password) << std::endl;
    }
    else
    {
        std::cout << "Soory,the login is incorrect." << std::endl;
    }

};

void PasswordStorage::ChangePassword()
{
    std::string new_password_;
    std::cin >> new_password_;
    password_hash = GetHashFromString(new_password_);
   
};

void PasswordStorage::Add(const PasswordStorageEntry& new_pair)
{
    hashtable_.Add(new_pair);
};


std::ostream& operator<<(std::ostream& out_stream, const PasswordStorage& storage)
{
    for (size_t i = 0; i < storage.hashtable_.GetData().size(); i++)
    {
        if (!storage.hashtable_.GetData()[i].empty())
        {
            for (size_t j = 0; j < storage.hashtable_.GetData()[i].size(); j++)
            {
                out_stream << "User: " << DecodeString(storage.hashtable_.GetData()[i][j].login) << ","
                    << " Password: " << DecodeString(storage.hashtable_.GetData()[i][j].login) << "\n";
            }
        }
    }
    return out_stream;
}



