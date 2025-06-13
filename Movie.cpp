#include "Movie.h"  

Movie::Movie(){}
void Movie::display()const {
    cout << "📽️  Movie\n";
    cout << "Movie ID: " << getId() << endl;
    cout << "Name: " << getName() << endl;
    cout << "Duration: " << getDuration() << " minutes" << endl;
    cout << "Genre: " << getGenre() << endl;
    cout << "Average Rating: " << getAverageRating() << endl;
}