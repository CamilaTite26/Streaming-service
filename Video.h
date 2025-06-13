#ifndef VIDEO_H
#define VIDEO_H
#include <iostream>
#include <list>
#include <string>
using namespace std;

class Video {
protected:
    int id;
    string name;
    double duration;
    string genre;
    list<float> ratings;

public:
    Video();
    Video(int, string, double, string);
    virtual void display() const = 0;
    virtual void addRating(float);
    virtual void addRating(list<float>);
    double getAverageRating() const;
    string getName() const;
    int getId() const;
    void setName(string);
    void setId(int);
    void setDuration(double);
    void setGenre(string);
    double getDuration() const;
    string getGenre() const;
    bool operator==(const string &otherName) const;

};

#endif