#ifndef Movie_h
#define Movie_h
#include <iostream>
using namespace std;
#include "Video.h"

class Movie : public Video {
	public:
	Movie();
	Movie(int id, string name, double duration, string genre) : Video(id, name, duration, genre) {}
	void display() const override;
	
};

#endif
