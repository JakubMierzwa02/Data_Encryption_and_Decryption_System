#include <gtest/gtest.h>
#include "..\CaesarCipher.hpp"
#include "..\XORCipher.hpp"
#include "..\VigenereCipher.hpp"
#include "..\VernamCipher.hpp"

TEST(CaesarCipherTest, Encrypt)
{
    CaesarCipher cipher(3);
    std::string originalText = "hello";
    std::string encryptedText = cipher.encrypt(originalText);
    ASSERT_EQ("khoor", encryptedText);
}

TEST(CaesarCipherTest, Decrypt)
{
    CaesarCipher cipher(3);
    std::string encryptedText = "khoor";
    std::string decryptedText = cipher.decrypt(encryptedText);
    ASSERT_EQ("hello", decryptedText);
}

TEST(XORCipherTest, Encrypt) 
{
    XORCipher cipher("123");
    std::string originalText = "hello";
    std::string encryptedText = cipher.encrypt(originalText);
    std::string expectedEncryption = "YW_]]";
    ASSERT_EQ(expectedEncryption, encryptedText);
}

TEST(XORCipherTest, Decrypt) 
{
    XORCipher cipher("123");
    std::string encryptedText = "YW_]]";
    std::string decryptedText = cipher.decrypt(encryptedText);
    ASSERT_EQ("hello", decryptedText);
}

TEST(VigenereCipherTest, Encrypt)
{
    VigenereCipher cipher("KEY");
    std::string originalText = "HELLOWORLD";
    std::string encryptedText = cipher.encrypt(originalText);
    ASSERT_EQ("RIJVSUYVJN", encryptedText);
}

TEST(VigenereCipherTest, Decrypt)
{
    VigenereCipher cipher("KEY");
    std::string encryptedText = "RIJVSUYVJN";
    std::string decryptedText = cipher.decrypt(encryptedText);
    ASSERT_EQ("HELLOWORLD", decryptedText);
}

TEST(VernamCipherTest, Encrypt)
{
    VernamCipher cipher("MYSECRETKEY");
    std::string originalText = "HELLOWORLD!";
    std::string encryptedText = cipher.encrypt(originalText);
    std::string expectedEncryption = "\x5\x1C\x1F\t\f\x5\n\x6\a\x1x";
    ASSERT_EQ(expectedEncryption, encryptedText);
}

TEST(VernamCipherTest, Decrypt)
{
    VernamCipher cipher("MYSECRETKEY");
    std::string encryptedText = "\x5\x1C\x1F\t\f\x5\n\x6\a\x1x";
    std::string decryptedText = cipher.decrypt(encryptedText);
    ASSERT_EQ("HELLOWORLD!", decryptedText);
}