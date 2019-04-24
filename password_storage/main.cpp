#include "passwordstorage.h"
#include "HashTable.h"
#include <iostream>


std::string EncodeString(const std::string& string_to_encode)
{
    std::string encoded_string = string_to_encode;
    for (size_t i = 0; i < encoded_string.size(); i++)
    {
        encoded_string[i] += (i + 1);
    }
    return encoded_string;
}

std::string DecodeString(const std::string& string_to_decode)
{
    std::string decoded_string = string_to_decode;
    for (size_t i = 0; i < decoded_string.size(); i++)
    {
        decoded_string[i] -= (i + 1);
    }
    return decoded_string;
}

int GetHashFromString(const std::string& value)
{
    if (value.size() == 0)
    {
        return 1;
    }

    int hash = value[0];
    for (size_t i = 1; i < value.size(); i++)
    {
        hash = (hash << 1) ^ value[i];
    }
    return hash;
}


enum program_type
{
    PRINT_THE_DATABASE = 0,
    GET_THE_PASSWORD = 1,
    CHANGE_PASSWORD = 2
};

int main()
{
    int user_choice = 0;
    std::cin >> user_choice;

    std::cout << "Enter 0 if you want to print the database." << std::endl;
    std::cout << "Enter 1 if you want to get the password to the exact login" << std::endl;
    std::cout << "Enter 2 if you want to change the password" << std::endl;

    const int pairs_number = 5;
    PasswordStorage password_storage(pairs_number);

    PasswordStorageEntry pair_1;
    pair_1.login = "EddardStark";
    pair_1.password = "SeanBean";
    password_storage.Add(pair_1);

    PasswordStorageEntry pair_2;
    pair_2.login = "JaimeLannister";
    pair_2.password = "NikolajCosterWaldau";
    password_storage.Add(pair_2);

    PasswordStorageEntry pair_3;
    pair_3.login = "DaenerysTargaryen";
    pair_3.password = "EmiliaClarke";
    password_storage.Add(pair_3);

    PasswordStorageEntry pair_4;
    pair_4.login = "JonSnow";
    pair_4.login = "KitHarington";
    password_storage.Add(pair_4);

    PasswordStorageEntry pair_5;
    pair_5.login = "JorahMormont";
    pair_5.password = "IainGlen";
    password_storage.Add(pair_5);

 
    switch (user_choice)
    {
    case PRINT_THE_DATABASE:
        password_storage.PrintTheDatabase(password_storage);
        break;
   case GET_THE_PASSWORD:
        password_storage.GetThePassword();
        break;
   case CHANGE_PASSWORD:
        password_storage.ChangePassword();
        break;
   default:
       std::cout << "Unknown type of the program.\n";
       std::cout << "Your input: " << user_choice << ". ";
       std::cout << "But you should enter 0, 1 or 2.\n";
       std::cout << "Exiting ..." << std::endl;
    }
}



