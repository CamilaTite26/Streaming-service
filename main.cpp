#include "Video.h"
#include "Movie.h"
#include "Serie.h"
#include "Episode.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <limits>

using namespace std;


void loadSeries(vector<Serie>& seriesList) {
    ifstream fileSeries("series_and_episodes.txt");
    if (!fileSeries) {
        cerr << "Error: No se pudo abrir series_and_episodes.txt\n";
        return;
    }

    seriesList.clear();
    int id;
    string name, genre;
    double duration;

    while (fileSeries >> id) {
        fileSeries.ignore();
        getline(fileSeries, name);
        fileSeries >> duration;
        fileSeries.ignore();
        getline(fileSeries, genre);

        Serie serie(id, name, duration, genre);

        int numEpisodes;
        fileSeries >> numEpisodes;
        fileSeries.ignore();

        for (int i = 0; i < numEpisodes; ++i) {
            int seasonNum, episodeNum;
            string episodeTitle;
            double episodeDuration;

            fileSeries >> seasonNum >> episodeNum;
            fileSeries.ignore();
            getline(fileSeries, episodeTitle);
            fileSeries >> episodeDuration;
            fileSeries.ignore();

            Episode ep(id, name, duration, genre, seasonNum, episodeNum, episodeTitle, episodeDuration);

            
            int numRatings;
            fileSeries >> numRatings;
            fileSeries.ignore();
            for (int r = 0; r < numRatings; ++r) {
                float rating;
                fileSeries >> rating;
                fileSeries.ignore();
                ep.addRating(rating);
            }

            serie.addEpisode(ep);
        }

        seriesList.push_back(serie);
    }

    fileSeries.close();
}

void loadMovies(vector<Movie>& moviesList) {
    ifstream fileMovies("BaseDeDatos_Peliculas.txt");
    if (!fileMovies) {
        cerr << "Error: No se pudo abrir BaseDeDatos_Peliculas.txt\n";
        return;
    }

    moviesList.clear();
    int id;
    string name, genre;
    double duration;

    while (fileMovies >> id) {
        fileMovies.ignore();
        getline(fileMovies, name);
        fileMovies >> duration;
        fileMovies.ignore();
        getline(fileMovies, genre);

        Movie movie(id, name, duration, genre);

        
        int numRatings;
        fileMovies >> numRatings;
        fileMovies.ignore();
        for (int i = 0; i < numRatings; ++i) {
            float rating;
            fileMovies >> rating;
            fileMovies.ignore();
            movie.addRating(rating);
        }

        moviesList.push_back(movie);
    }

    fileMovies.close();
}


float pedirCalificacion() {
    float rating;
    while (true) {
        cout << "Ingresa calificación (0 a 10): ";
        cin >> rating;
        if (cin.fail() || rating < 0 || rating > 10) {
            cout << "Entrada inválida. Debe ser un número entre 0 y 10.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        }
    }
    return rating;
}


void displayVideos(const vector<Serie>& seriesList, const vector<Movie>& moviesList) {
    int filterOption;
    cout << "Mostrar videos por:\n1. Calificación mínima\n2. Género\nOpción: ";
    cin >> filterOption;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if (filterOption == 1) {
        float minRating = pedirCalificacion();

        cout << "\nSeries con calificación >= " << minRating << ":\n";
        for (const auto& s : seriesList)
            if (s.getAverageRating() >= minRating)
                s.display();

        cout << "\nPelículas con calificación >= " << minRating << ":\n";
        for (const auto& m : moviesList)
            if (m.getAverageRating() >= minRating)
                m.display();

    } else if (filterOption == 2) {
        string genreSearch;
        cout << "Género a buscar: ";
        getline(cin, genreSearch);

        cout << "\nSeries del género '" << genreSearch << "':\n";
        for (const auto& s : seriesList)
            if (s.getGenre() == genreSearch)
                s.display();

        cout << "\nPelículas del género '" << genreSearch << "':\n";
        for (const auto& m : moviesList)
            if (m.getGenre() == genreSearch)
                m.display();

    } else {
        cout << "Opción inválida.\n";
    }
}


void showEpisodes(const vector<Serie>& seriesList) {
    string seriesName;
    cout << "Nombre de la serie: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, seriesName);

    float minRating = pedirCalificacion();

    bool found = false;
    for (const auto& s : seriesList) {
        if (s.getName() == seriesName) {
            found = true;
            cout << "\nEpisodios con calificación >= " << minRating << ":\n";
            for (const auto& ep : s.getEpisodes())
                if (ep.getAverageRating() >= minRating)
                    ep.display();
        }
    }
    if (!found) {
        cout << "No se encontró la serie '" << seriesName << "'.\n";
    }
}


void showMovies(const vector<Movie>& moviesList) {
    float minRating = pedirCalificacion();
    bool found = false;

    for (const auto& m : moviesList) {
        if (m.getAverageRating() >= minRating) {
            m.display();
            found = true;
        }
    }
    if (!found) cout << "No hay películas con esa calificación.\n";
}


void rateVideo(vector<Serie>& seriesList, vector<Movie>& moviesList) {
    string title;
    cout << "Título del video a calificar: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, title);

    float rating = pedirCalificacion();

 
    for (auto& m : moviesList) {
        if (m.getName() == title) {
            m.addRating(rating);
            cout << "Calificación agregada a la película '" << title << "'.\n";
            return;
        }
    }

    for (auto& s : seriesList) {
        for (auto& ep : s.getEpisodes()) {
            if (ep.getEpisodeTitle() == title) {
                ep.addRating(rating);
                cout << "Calificación agregada al episodio '" << title << "' de la serie '" << s.getName() << "'.\n";
                return;
            }
        }
    }

    cout << "No se encontró ningún video con ese título.\n";
}

int main() {
    vector<Serie> seriesList;
    vector<Movie> moviesList;

    
    loadSeries(seriesList);
    loadMovies(moviesList);

    int option;
    do {
        cout << "\n--- MENÚ ---\n";
        cout << "1. Mostrar videos por calificación o género\n";
        cout << "2. Mostrar episodios de una serie con cierta calificación\n";
        cout << "3. Mostrar películas con cierta calificación\n";
        cout << "4. Calificar un video\n";
        cout << "0. Salir\n";
        cout << "Selecciona una opción: ";
        cin >> option;

        if(cin.fail()){
            cout << "Entrada inválida.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            option = -1;
            continue;
        }

        switch (option) {
            case 1:
                displayVideos(seriesList, moviesList);
                break;
            case 2:
                showEpisodes(seriesList);
                break;
            case 3:
                showMovies(moviesList);
                break;
            case 4:
                rateVideo(seriesList, moviesList);
                break;
            case 0:
                cout << "Saliendo del programa...\n";
                break;
            default:
                cout << "Opción inválida.\n";
        }
    } while (option != 0);

    return 0;
}
