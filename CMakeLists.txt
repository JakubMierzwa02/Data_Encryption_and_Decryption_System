cmake_minimum_required(VERSION 3.8)

set(This Data_Encryption)

project(${This} C CXX)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 14)

enable_testing()

add_subdirectory(googletest)

set(Headers
    Cipher.hpp
    Encryptor.hpp
    Decryptor.hpp
    CaesarCipher.hpp
    XORCipher.hpp
    VigenereCipher.hpp
    VernamCipher.hpp
    CLIInterface.hpp
)

set(Sources
    main.cpp
    CLIInterface.cpp
)

add_library(${This} STATIC ${Sources} ${Headers})

add_subdirectory(test)