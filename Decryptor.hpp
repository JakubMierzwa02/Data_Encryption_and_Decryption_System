#ifndef DECRYPTOR_HPP
#define DECRYPTOR_HPP

#include <memory>
#include <string>
#include "Cipher.hpp"

// The Decryptor class is responsible for decrypting data using a specified decryption algorithm
class Decryptor
{
private:
    std::unique_ptr<Cipher> cipher;

public:
    Decryptor(std::unique_ptr<Cipher> cipher) : cipher(std::move(cipher))
    {

    }

    // Takes a string as input and returns the decrypted string
    std::string decryptData(const std::string& data)
    {
        return cipher->decrypt(data);
    }
};

#endif