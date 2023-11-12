#include <iostream>
#include <string>

int main()
{
    std::string input;
    std::string encrypted;
    std::string decrypted;

    std::cout << "Data Encryption and Decryption System" << std::endl;
    std::cout << "Enter the data to encrypt: ";
    getline(std::cin, input);

    std::cout << "Encrypted Data: " << encrypted << std::endl;

    std::cout << "Decrypted Data: " << decrypted << std::endl;

    return 0;
}