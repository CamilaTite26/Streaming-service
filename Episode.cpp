#include "Episode.h"  

Episode::Episode(){
    seasonNumber = 0;
    episodeNumber = 0;
    episodeTitle = "";
    episodeDuration = 0.0;
}
Episode::Episode(int id, string name, double duration, string genre, int seasonNum, int episodeNum, string title, double epDuration)
    : Video(id, name, duration, genre), seasonNumber(seasonNum), episodeNumber(episodeNum), episodeTitle(title), episodeDuration(epDuration) {}
void Episode::display() const {
    cout << "\n🎬  Episode\n";
    cout << "Episode ID: " << getId() << endl;
    cout << "Name: " << getName() << endl;
    cout << "Duration: " << getDuration() << " minutes" << endl;
    cout << "Genre: " << getGenre() << endl;
    cout << "Season Number: " << seasonNumber << endl;
    cout << "Episode Number: " << episodeNumber << endl;
    cout << "Episode Title: " << episodeTitle << endl;
    cout << "Episode Duration: " << episodeDuration << " minutes" << endl;
    cout << "Average Rating: " << getAverageRating() << endl;
}
int Episode::getSeasonNumber() {
    return seasonNumber;
}
int Episode::getEpisodeNumber()const {
    return episodeNumber;
}
string Episode::getEpisodeTitle()const{
    return episodeTitle;
}
double Episode::getEpisodeDuration(){
    return episodeDuration;
}
void Episode::setSeasonNumber(int seasonNum) {
    seasonNumber = seasonNum;
}
void Episode::setEpisodeNumber(int episodeNum) {
    episodeNumber = episodeNum;
}
void Episode::setEpisodeTitle(string title) {
    episodeTitle = title;
}
void Episode::setEpisodeDuration(double epDuration) {
    episodeDuration = epDuration;
}