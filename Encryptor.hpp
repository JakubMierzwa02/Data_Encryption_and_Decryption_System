#ifndef ENCRYPTOR_HPP
#define ENCRYPTOR_HPP

#include <memory>
#include <string>

#include "Cipher.hpp"

// The Encryptor class is responsible for encrypting data using a specified encryption algorithm
class Encryptor
{
private:
    // A pointer to a Cipher object, which implements the actual encryption algorithm
    std::unique_ptr<Cipher> cipher;

public:
    Encryptor(std::unique_ptr<Cipher> cipher) : cipher(std::move(cipher))
    {

    }

    // Takes a string as input and returns the encrypted string
    std::string encryptData(const std::string& data)
    {
        return cipher->encrypt(data);
    }
};

#endif