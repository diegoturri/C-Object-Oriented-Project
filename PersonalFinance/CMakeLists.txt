cmake_minimum_required(VERSION 3.23)
project(PersonalFinance)

set(CMAKE_CXX_STANDARD 14)

add_executable(PersonalFinance main.cpp classes/Wallet.cpp classes/Wallet.h classes/Transaction.cpp classes/Transaction.h classes/Comparator.cpp classes/Comparator.h)
