cmake_minimum_required(VERSION 3.23)
project(Lect10)

set(CMAKE_CXX_STANDARD 11)



add_executable(Sneaky Sneaky/sneaky_main.cpp Sneaky/Base.cpp Sneaky/Base.h Sneaky/Sneaky.cpp Sneaky/Sneaky.h)


add_executable(BookSalesDynamicBinding BookSalesDynamicBinding/Inheritance2.cpp BookSalesDynamicBinding/Quote.cpp BookSalesDynamicBinding/Quote.h BookSalesDynamicBinding/Bulk_quote.cpp BookSalesDynamicBinding/Bulk_quote.h BookSalesDynamicBinding/Disc_quote.h BookSalesDynamicBinding/Unfair_quote.cpp BookSalesDynamicBinding/Unfair_quote.h)