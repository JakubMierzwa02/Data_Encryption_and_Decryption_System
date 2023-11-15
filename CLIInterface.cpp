#include "CLIInterface.hpp"
#include "CaesarCipher.hpp"
#include "XORCipher.hpp"
#include "VigenereCipher.hpp"
#include "VernamCipher.hpp"

CLIInterface::CLIInterface()
{
    ciphers["Caesar"] = std::make_unique<CaesarCipher>(0);
    ciphers["XOR"] = std::make_unique<XORCipher>("key");
    ciphers["Vigenere"] = std::make_unique<VigenereCipher>("key");
    ciphers["Vernam"] = std::make_unique<VernamCipher>("key");
}

void CLIInterface::displayMenu()
{
    std::cout << "Select:\n";
    std::cout << "1. Encryption\n";
    std::cout << "2. Decryption\n";
    std::cout << "3. Exit\n";
    std::cout << "Available algorithms: Caesar, XOR, Vigenere, Vernam\n";
}

std::string CLIInterface::getUserInput(const std::string& prompt)
{
    std::string input;
    std::cout << prompt;
    getline(std::cin, input);
    return input;
}

std::unique_ptr<Cipher> CLIInterface::createCipherInstance(const std::string& algorithm, const std::string& key)
{
    if (algorithm == "Caesar")
    {
        int shift = std::stoi(key);
        return std::make_unique<CaesarCipher>(shift);
    }
    else if (algorithm == "XOR")
        return std::make_unique<XORCipher>(key);
    else if (algorithm == "Vigenere")
        return std::make_unique<VigenereCipher>(key);
    else if (algorithm == "Vernam")
        return std::make_unique<VernamCipher>(key);
    return nullptr;
}

void CLIInterface::performEncryption()
{
    std::string algorithm = getUserInput("Select algorithm (Caesar, XOR, Vigenere, Vernam): ");
    std::string key = getUserInput("Enter the key: ");
    std::string text = getUserInput("Enter the text to be encrypted: ");

    auto cipher = createCipherInstance(algorithm, key);
    if (cipher)
    {
        std::string encrypted = cipher->encrypt(text);
        std::cout << "Encrypted text: " << encrypted << std::endl;
    }
    else
        std::cout << "Unknown algorithm" << std::endl;
}

void CLIInterface::performDecryption()
{
    std::string algorithm = getUserInput("Select algorithm (Caesar, XOR, Vigenere, Vernam): ");
    std::string key = getUserInput("Enter the key: ");
    std::string text = getUserInput("Enter the text to be decrypted: ");
    
    auto cipher = createCipherInstance(algorithm, key);
    if (cipher)
    {
        std::string decrypted = cipher->decrypt(text);
        std::cout << "Decrypted text: " << decrypted << std::endl;
    }
    else
        std::cout << "Unknown algorithm" << std::endl;
}

void CLIInterface::run()
{
    while (true)
    {
        displayMenu();
        std::string choice = getUserInput("Select number: ");
        if (choice == "1")
            performEncryption();
        else if (choice == "2")
            performDecryption();
        else if (choice == "3")
            break;
        else
            std::cout << "Invalid input. Try again\n";
    }
}