#ifndef Serie_h
#define Serie_h
#include <iostream>
#include <list>
#include "Video.h"
#include "Episode.h"

using namespace std;

class Serie : public Video
{
protected:
    list<Episode> episodes;

public:
    Serie();
    Serie(int id, string name, double duration, string genre) : Video(id, name, duration, genre) {}

    void display() const override;

    void addEpisode(const Episode& ep) {
        episodes.push_back(ep);
    }


    const list<Episode>& getEpisodes() const {
        return episodes;
    }

    list<Episode>& getEpisodes() {
        return episodes;
    }
};

#endif
