cmake_minimum_required(VERSION 3.0)

project(Medusa)

include_directories(src/)

add_library(
    medusa-vm
    
    src/medusa/compiler/parser.c
    src/medusa/compiler/parser.h

    src/medusa/executor/codegen.c
    src/medusa/executor/codegen.h
)

add_executable(medusa src/main.c)

target_link_libraries(medusa medusa-vm)
