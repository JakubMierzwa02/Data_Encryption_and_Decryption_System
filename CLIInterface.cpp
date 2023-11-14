#include "CLIInterface.hpp"
#include "CaesarCipher.hpp"

CLIInterface::CLIInterface()
{
    ciphers["Caesar"] = std::make_unique<CaesarCipher>(3);
}

void CLIInterface::displayMenu()
{
    std::cout << "Select:\n";
    std::cout << "1. Encryption\n";
    std::cout << "2. Decryption\n";
    std::cout << "3. Exit\n";
}

std::string CLIInterface::getUserInput(const std::string& prompt)
{
    std::string input;
    std::cout << prompt;
    getline(std::cin, input);
    return input;
}

void CLIInterface::performEncryption()
{
    std::string algorithm = getUserInput("Select algorithm (Caesar, ...): ");
    std::string text = getUserInput("Enter the text to be encrypted: ");
    std::string encrypted = ciphers[algorithm]->encrypt(text);
    std::cout << "Encrypted text: " << encrypted << std::endl;
}

void CLIInterface::performDecryption()
{
    std::string algorithm = getUserInput("Select algorithm (Caesar, ...): ");
    std::string text = getUserInput("Enter the text to be decrypted: ");
    std::string decrypted = ciphers[algorithm]->decrypt(text);
    std::cout << "Decrypted text: " << decrypted << std::endl;
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