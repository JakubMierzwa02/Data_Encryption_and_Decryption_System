#ifndef VIGENERECIPHER_HPP
#define VIGENERECIPHER_HPP

#include "Cipher.hpp"
#include <string>
#include <cctype>

// The VigenereCipher class implements the Vigenere cipher for encryption and decryption
class VigenereCipher : public Cipher
{
private:
    std::string key;

    // Helper function to shift a single character by n positions
    char shiftChar(char c, int n)
    {
        if (!std::isalpha(c))
            return c;
        char base = std::isupper(c) ? 'A' : 'a';
        int alphaLength = 26;
        n = (n % alphaLength + alphaLength) % alphaLength;
        return (c - base + n) % alphaLength + base;
    }

public:
    VigenereCipher(const std::string& key) : key(key)
    {

    }

    // Encrypts the given data using the Vigenere cipher
    std::string encrypt(const std::string& data) override
    {
        std::string encrypted = data;
        for (size_t i = 0, j = 0; i < data.length(); i++)
        {
            if (std::isalpha(data[i]))
            {
                int keyShift = std::toupper(key[j % key.length()]) - 'A';
                encrypted[i] = shiftChar(data[i], keyShift);
                j++; // Increment j only if the character is a letter
            }
        }
        return encrypted;
    }

    // Decrypts the given data using the Vigenere cipher
    std::string decrypt(const std::string& data) override
    {
        std::string decrypted = data;
        for (size_t i = 0, j = 0; i < data.length(); i++)
        {
            if (std::isalpha(data[i]))
            {
                int keyShift = std::toupper(key[j % key.length()]) - 'A';
                decrypted[i] = shiftChar(data[i], -keyShift);
                j++; // Increment j only if the character is a letter
            }
        }
        return decrypted;
    }
};

#endif