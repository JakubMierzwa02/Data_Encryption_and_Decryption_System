#include <iostream>
#include <string>

#include "Cipher.hpp"
#include "XORCipher.hpp"

int main()
{
    std::string input;
    std::string encrypted;
    std::string decrypted;

    std::cout << "Data Encryption and Decryption System" << std::endl;
    std::cout << "Enter the data to encrypt: ";
    getline(std::cin, input);
    XORCipher cipher("123");

    std::cout << "Encrypted Data: " << cipher.encrypt(input) << std::endl;

    std::cout << "Decrypted Data: " << decrypted << std::endl;

    return 0;
}