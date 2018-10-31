//
// Song.cpp
//
// Defines how the functions laid out by Song.h are implemented.
//
// Updated 10/31/18
// Brent Bouslog
//

#include <stdlib.h>
#include <stdio.h>
#include <string>
#include "Song.h"

Song::Song()
{
    // Arbitrary Title and Artist to start
    title = "ZZZ";
    artist = "ZZZ";
    size = MAX_SIZE;
}

Song::Song(string _artist, string _title, int _size)
{
    artist = _artist;
    title = _title;
    // Making sure _size is a valid size	
    if(_size < MAX_SIZE && _size >= 0)
        size = _size;
    else if(_size < 0)
	size = 0;
    else
	size = MAX_SIZE;
}

string Song::toString() const
{
    char num[16];
    // Converting size to a string
    sprintf(num, "%d", size);

    string toReturn = artist + ": " + title + " {Size: " + num + " MB}";

    return toReturn;
}

bool Song::operator==(Song const &rhs)
{
    if(artist.compare(rhs.artist) == 0 && title.compare(rhs.title) == 0 && size == rhs.size)
        return true;
    return false;
}

bool Song::operator<(Song const &rhs)
{
    if(artist.compare(rhs.artist) < 0)
        return true;
    else if(title.compare(rhs.title) < 0 && artist.compare(rhs.artist) == 0)
        return true;
    else if(size < rhs.size && title.compare(rhs.title) == 0 && artist.compare(rhs.artist) == 0)
        return true;
    return false;
}

bool Song::operator>(Song const &rhs)
{
    if(artist.compare(rhs.artist) > 0)
        return true;
    else if(title.compare(rhs.title) > 0 && artist.compare(rhs.artist) == 0)
        return true;
    else if(size > rhs.size && title.compare(rhs.title) == 0 && artist.compare(rhs.artist) == 0)
        return true;
    return false;
}
