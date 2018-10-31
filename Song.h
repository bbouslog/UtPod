//
// Song class
//
// Defines how a song is stored. Each song has an artist, title
// and size (in MB).
//
// Updated 10/31/18
// Brent Bouslog
//

#ifndef UTPOD_SONG_H
#define UTPOD_SONG_H

#include <string>

using namespace std;

class Song {

    private:
        static const int MAX_SIZE = 512;

        string title;
        string artist;
        int size;

    public:
	/*
         * Song constructor that will set size to 0 and title and artist to
         * arbitrary values.
         */
        Song();

	/*
         * Song constructor that will set each instance variable to its
         * its corresponding entry in the parameter list.
         *
         * Preconditions: artist and title must be non-empty
         */
        Song(string artist, string title, int size);

	/*
         * Returns the title of this instance of Song.
         */ 
        string getTitle() const {
            return title;
        };

	/*
         * Returns the artist of this instance of Song.
         */ 
        string getArtist() const {
            return artist;
        };

	/*
         * Returns the size of this instance of Song.
         */
        int getSize() const {
            return size;
        };
	
	/*
         * Sets the title of this instance of Song to the string specified by t.
         */ 
        void setTitle(string &t){
            title = t;
        };

	/*
         * Sets the artist of this instance of Song to the string specified by a.
         */ 
        void setArtist(string &a){
            artist = a;
        };

	/*
         * Sets the size of this instance of Song to the int specified by s.
         */ 
        void setSize(int s) {
            size = s;
        };

	/*
         * Returns a String representation of this instance of Song in the form
         * of "Artist: Title {Size MB}"
         */ 
        string toString() const;
	
	/*
         * Overrides the == operator such that it returns true if an only if
         * the artist, title, and size of the two Songs that are being compared
         * are the same. Otherwise, it returns false.
         */ 
        bool operator ==(Song const &rhs);

	/*
         * Overrides the > operator such that it returns true if the artist is
         * alphabetically greater than that of the right hand side. If the two
         * artists are the same, then it returns true if the title is
         * alphabetically greater than that of the right hand side. If the two
         * titles are the same, then it returns true if the size of this Song
         * is greater than that of the right hand side. Otherwise it returns
         * false.
         */ 
        bool operator >(Song const &rhs);

	/*
         * Overrides the < operator such that it returns true if the artist is
         * alphabetically less than that of the right hand side. If the two
         * artists are the same, then it returns true if the title is
         * alphabetically less than that of the right hand side. If the two
         * titles are the same, then it returns true if the size of this Song
         * is less than that of the right hand side. Otherwise it returns false.
         */ 
        bool operator <(Song const &rhs);

};

#endif //UTPOD_SONG_H
