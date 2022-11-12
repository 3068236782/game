cmake_minimum_required(VERSION 3.17)
project(test)

set(CMAKE_CXX_STANDARD 14)

add_executable(test source_file/main.cpp
                    source_file/Man.cpp
                    header_file/Man.h
                    source_file/AI.cpp
                    header_file/AI.h
                    source_file/Chess.cpp
                    header_file/Chess.h
                    source_file/ChessGame.cpp
                    header_file/ChessGame.h)