#include "Video.h"  

Video::Video(){
    id = 0;
    name = "";
    duration = 0.0;
    genre = "";

}

Video::Video(int id, string name, double duration, string genre) {
    this->id = id;
    this->name = name;
    this->duration = duration;
    this->genre = genre;
}
void Video::addRating(float rating) {
    ratings.push_back(rating);
}
double Video::getAverageRating()const {
    if (ratings.empty()) return 0.0;
    double sum = 0.0;
    for (float rating : ratings) {
        sum += rating;
    }
    return sum / ratings.size();
}
string Video::getName()const {
    return name;
}
int Video::getId()const {
    return id;
}
void Video::setName(string name) {
    this->name = name;
}
void Video::setId(int id) {
    this->id = id;
}
void Video::setDuration(double duration) {
    this->duration = duration;
}
void Video::setGenre(string genre) {
    this->genre = genre;
}
double Video::getDuration() const{
    return duration;
}
string Video::getGenre()const {
    return genre;
}
bool Video::operator==(const string& otherName) const {
    return this->name == otherName;
}