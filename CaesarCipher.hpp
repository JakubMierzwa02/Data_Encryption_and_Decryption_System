#ifndef CAESARCIPHER_HPP
#define CAESARCIPHER_HPP

#include <string>
#include "Cipher.hpp"

// The CaesarCipher class implements the Caesar cipher encryption and decryption
class CaesarCipher : public Cipher
{
private:
    int shift;

public:
    CaesarCipher(int shift) : shift(shift % 26)
    {

    }

    // Encrypts the given data using the Caesar cipher
    std::string encrypt(const std::string& data) override
    {
        std::string encrypted = data;
        for (char &c : encrypted)
        {
            if (isalpha(c))
            {
                char base = islower(c) ? 'a' : 'A';
                c = (c - base + shift) % 26 + base;
            }
        }
        return encrypted;
    }

    // Decrypts the given data using the Caesar cipher
    std::string decrypt(const std::string& data) override
    {
        std::string decrypted = data;
        for (char &c : decrypted)
        {
            if (isalpha(c))
            {
                char base = islower(c) ? 'a' : 'A';
                c = (c - base - shift + 26) % 26 + base;
            }
        }
        return decrypted;
    }
};

#endif