#ifndef CLIINTERFACE_HPP
#define CLIINTERFACE_HPP

#include "Cipher.hpp"
#include <iostream>
#include <string>
#include <map>
#include <memory>

class CLIInterface
{
private:
    std::map<std::string, std::unique_ptr<Cipher>> ciphers;

    void displayMenu();
    std::string getUserInput(const std::string& prompt);
    std::unique_ptr<Cipher> createCipherInstance(const std::string& algorithm, const std::string& key);
    void performEncryption();
    void performDecryption();

public:
    CLIInterface();
    void run();
};

#endif