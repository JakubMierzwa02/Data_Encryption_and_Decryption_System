#ifndef CIPHER_HPP
#define CIPHER_HPP

#include <string>

// The Cipher class is an abstract base class that defines the interface for encryption and decryption
class Cipher
{
    public:
        virtual std::string encrypt(const std::string& data) = 0;
        virtual std::string decrypt(const std::string& data) = 0;
        virtual ~Cipher() {}
};

#endif