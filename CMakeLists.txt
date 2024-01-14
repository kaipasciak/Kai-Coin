cmake_minimum_required(VERSION 3.24)
project(KaiCoin)

set(CMAKE_CXX_STANDARD 17)

# Find OpenSSL
find_package(OpenSSL REQUIRED)

# Define the target and its sources
add_executable(KaiCoin main.cpp Block.h Block.cpp Transaction.h Transaction.cpp Wallet.h Wallet.cpp Blockchain.cpp Blockchain.h Node.h Node.cpp)

# Link OpenSSL libraries to the KaiCoin target
target_link_libraries(KaiCoin PRIVATE OpenSSL::Crypto)

# Include directories for the target
target_include_directories(KaiCoin PRIVATE ${OPENSSL_INCLUDE_DIR})
