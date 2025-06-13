# Video Management Project

This project was developed as part of my Object-Oriented Programming class.  

It is a simple application that manages videos, including movies and TV series with their episodes. The program allows users to:

- Load video data from files
- Display videos filtered by rating or genre
- Show episodes of a specific series with a minimum rating
- Show movies with a minimum rating
- Rate a video by its title and update its rating

## Features

- Implementation of inheritance and polymorphism with abstract classes
- Data encapsulation with proper access modifiers
- Overriding and overloading of methods
- Operator overloading (where applicable)
- Input validation for menu options and ratings
- Reading video and episode data from external files

## File Structure

- `Video.h` and `Video.cpp` — Abstract base class defining common video properties
- `Movie.h` and `Movie.cpp` — Class representing movies
- `Serie.h` and `Serie.cpp` — Class representing TV series containing episodes
- `Episode.h` and `Episode.cpp` — Class representing episodes, inheriting from Video
- `main.cpp` — Contains the main menu and program logic

## How to Use

1. Prepare the data files (`movies.txt` and `series_and_episodes.txt`) with the required format.
2. Compile the program using a C++ compiler.
3. Run the executable and use the menu to load data, display videos, and rate them.

## Author

This project was created by Camila Tite for the Object-Oriented Programming course.

