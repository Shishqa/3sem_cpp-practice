cmake_minimum_required(VERSION 3.0)

# TODO: make MSVC compile options
add_compile_options(-W -Wall -Wextra -Werror 
                    -Wpedantic -pedantic-errors)

add_library(ShishGL INTERFACE)
