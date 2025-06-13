#ifndef EPISODE_H
#define EPISODE_H
#include <iostream>
using namespace std;
#include "Video.h"

class Episode : public Video
{
	private:
		int seasonNumber;
		int episodeNumber;
		string episodeTitle;
		double episodeDuration;

	public:

		Episode();
		Episode(int, string, double, string, int, int, string, double);
		void display()const override;
		int getSeasonNumber();
		int getEpisodeNumber()const;
		string getEpisodeTitle()const;
		double getEpisodeDuration();
		void setSeasonNumber(int);
		void setEpisodeNumber(int);
		void setEpisodeTitle(string);
		void setEpisodeDuration(double);


		
};
#endif
