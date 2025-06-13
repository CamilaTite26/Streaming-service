#include "Serie.h"

Serie::Serie()
{
}

void Serie::display() const {
    cout << "📺  Serie\n";
    cout << "Serie ID: " << getId() << endl;
    cout << "Name: " << getName() << endl;
    cout << "Duration: " << getDuration() << " minutes" << endl;
    cout << "Genre: " << getGenre() << endl;
    cout << "Average Rating: " << getAverageRating() << endl;

    cout << "Episodes:" << endl;
    for (const auto& episode : episodes) {
        episode.display();
    }
}
