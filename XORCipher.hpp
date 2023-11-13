#ifndef XORCIPHER_HPP
#define XORCIPHER_HPP

#include <string>
#include "Cipher.hpp"

// The XORCipher class implements encryption and decryption using the XOR operation
class XORCipher : public Cipher
{
private:
    std::string key;

public:
    XORCipher(const std::string& key) : key(key)
    {

    }

    // Encrypts the given data using XOR encryption
    std::string encrypt(const std::string& data) override
    {
        std::string encrypted = data;
        for (size_t i = 0; i < data.length(); i++)
        {
            // XOR each byte with the key
            encrypted[i] = data[i] ^ key[i % key.length()];
        }
        return encrypted;
    }

    // Decrypts the given data using XOR encryption
    std::string decrypt(const std::string& data) override
    {
        // Since XOR is symmetric, encryption and decryption are the same
        return encrypt(data);
    }
};

#endif