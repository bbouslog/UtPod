//
// Created by bab72 on 10/22/2018.
//

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "UtPod.h"

using namespace std;

UtPod::UtPod()
{
    songs = NULL;
    memSize = MAX_MEMORY;
}

UtPod::UtPod(int _size)
{
    songs = NULL;
    if(_size >= 0 && _size <= MAX_MEMORY)
        memSize = _size;
    else
        memSize = MAX_MEMORY;
}

UtPod::UtPod(const UtPod &otherPod)
{
    struct SongNode *temp = otherPod.songs;

    memSize = otherPod.memSize;
    songs = NULL;

    while(temp != NULL)
    {
        addSong(temp->s);
        temp = temp->next;
    }
}

int UtPod::addSong(Song const &_s)
{
    string artist (_s.getArtist());
    string title (_s.getTitle());
    int size = _s.getSize();
    
    // Making sure there is memory available for the new Song
    if(getRemainingMemory() - _s.getSize() >= 0) {
        struct SongNode *newSong;

        newSong = new SongNode;

        newSong->s.setSize(size);
        newSong->s.setArtist(artist);
        newSong->s.setTitle(title);

        newSong->next = songs;

        songs = newSong;

        return SUCCESS;
    }
    else
        return NO_MEMORY;
}

int UtPod::removeSong(Song const &_s)
{
    struct SongNode *temp;
    struct SongNode *prev;

    temp = songs;
    prev = NULL;

    while(temp != NULL)
    {
        if(temp->s == _s)
        {
	    // Therefore, not removing the head pointer
            if(prev != NULL) {
                prev->next = temp->next;
                delete temp;
            }
	    // Removing the head pointer
            else
            {
                songs = songs->next;
                delete temp;
            }

            return SUCCESS;
        }
        prev = temp;
        temp = temp->next;
    }

    return NOT_FOUND;
}

void UtPod::shuffle()
{
    if(songs != NULL) {
        struct SongNode *temp1;
        struct SongNode *temp2;
        int size = getNumSongs();

	// Number of shuffles
        int iterations = 1000000;

        srand(time(NULL));

        while (iterations > 0) {
            temp1 = songs;
            temp2 = songs;

            int rand1 = rand() % size;
            int rand2 = rand() % size;

	    // Getting to two random nodes in the list
            for (int i = 0; i < rand1 || i < rand2; i++) {
                if (i < rand1)
                    temp1 = temp1->next;
                if (i < rand2)
                    temp2 = temp2->next;
            }

            swap(temp1, temp2);

            iterations--;
        }
    }
}

void UtPod::showSongList()
{
    struct SongNode *temp;
    temp = songs;

    while(temp != NULL)
    {
	cout << temp->s.toString() << '\n';
        temp = temp->next;
    }
}

void UtPod::sortSongList()
{
    struct SongNode *temp;
    struct SongNode *smallest;
    struct SongNode *firstInRemainingList;

    firstInRemainingList = songs;
    
    // Iterate until we hit the end of the list
    while(firstInRemainingList != NULL) {
        // Temp is our iterating variable
	temp = firstInRemainingList;
        smallest = firstInRemainingList;
        while (temp != NULL) {
	    // Want to find the smallest node in the remaining list
            if(temp->s < smallest->s)
                smallest = temp;
            temp = temp->next;
        }
	// Put smallest node at the front (end up in biggest to smallest order)
        swap(firstInRemainingList, smallest);
	// Make the list smaller
        firstInRemainingList = firstInRemainingList->next;
    }
}

void UtPod::clearMemory()
{
    struct SongNode *temp;

    while(songs != NULL)
    {
        temp = songs;
        songs = songs->next;
        delete temp;
    }
}

int UtPod::getRemainingMemory()
{
    int remainingMemory = getTotalMemory();
    struct SongNode *temp = songs;

    while(temp != NULL)
    {
        remainingMemory -= temp->s.getSize();
        temp = temp->next;
    }

    return remainingMemory;
}

int UtPod::getNumSongs()
{
    struct SongNode *temp = songs;
    int numSongs = 0;

    while(temp != NULL)
    {
        numSongs++;
        temp = temp->next;
    }

    return numSongs;
}

void UtPod::swap(SongNode *s1, SongNode *s2)
{
    Song tempSong (s1->s.getArtist(), s1->s.getTitle(), s1->s.getSize());

    s1->s = s2->s;
    s2->s = tempSong;
}

UtPod& UtPod::operator =(const UtPod &rhs)
{
    if(this != &rhs)
    {
        struct SongNode *temp = rhs.songs;
	// Need to get rid of what was there before
        clearMemory();
        memSize = rhs.memSize;

        while(temp != NULL)
        {
            addSong(temp->s);
            temp = temp->next;
        }
    }
    return *this;
}

UtPod::~UtPod()
{
    clearMemory();
}
