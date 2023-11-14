#ifndef VERNAMCIPHER_HPP
#define VERNAMCIPHER_HPP

#include "Cipher.hpp"
#include <string>
#include <stdexcept>

// The VernamCipher class implements the Vernam cipher for encryption and decryption
class VernamCipher : public Cipher
{
private:
    std::string key;

public:
    VernamCipher(const std::string& key) : key(key)
    {

    }

    // Encrypts the given data using the Vernam cipher
    std::string encrypt(const std::string& data) override
    {
        std::string encrypted = data;

        // Ensure the key is of the same length as the data
        if (data.length() != key.length())
            throw std::invalid_argument("Key must be the same length as the data");

        for (size_t i = 0; i < data.length(); i++)
        {
            encrypted[i] = data[i] ^ key[i];
        }
        return encrypted;
    }

    // Decrypts the given data using the Vernam cipher
    std::string decrypt(const std::string& data) override
    {
        return encrypt(data);
    }
};

#endif