#include <gtest/gtest.h>
#include "..\CaesarCipher.hpp"
#include "..\XORCipher.hpp"

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