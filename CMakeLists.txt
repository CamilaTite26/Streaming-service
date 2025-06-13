cmake_minimum_required(VERSION 3.29)
project(Streaming_service)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Streaming_service
    Episode.cpp
    Episode.h
    main.cpp
    Movie.cpp
    Movie.h
    Serie.cpp
    Serie.h
    Video.cpp
    Video.h)
