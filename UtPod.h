/*
 * UtPod class
 *
 * Defines a UtPod that holds a list of songs and has a maximum memory size.
 *
 * Updated 10/31/18
 * Brent Bouslog
 */

#ifndef UTPOD_H
#define UTPOD_H
#include "Song.h"

//UtPod class declaration
class UtPod
{
private:
    static const int MAX_MEMORY = 512;
    static const int SUCCESS = 0;
    static const int NO_MEMORY = -1;
    static const int NOT_FOUND = -2;

    struct SongNode
    {
        Song s;
        SongNode *next;
    };

    SongNode *songs;  //the head pointer

    int memSize;

    /* FUNCTION - int getNumSongs
     * returns the number of songs in the list of Songs

     input parms -

     output parms - Returns the number of songs in the list of Songs
     */
    int getNumSongs();

    /* FUNCTION - void swap
     * Swaps the songs in the SongNodes pointed to by the two parameters.
     * After the function ends, s1 will have the song that was originally in
     * s2 and vice versa.

     input parms - s1: a pointer to a SongNode whose Song one wishes to switch
		   s2: a pointer to a SongNode whose Song one wishes to switch

     output parms -
     */
    void swap(SongNode *s1, SongNode *s2);

public:
    //Default constructor
    //set the memory size to MAX_MEMORY
    UtPod();

    //Constructor with size parameter
    //The user of the class will pass in a size.
    //If the size is greater than MAX_MEMORY or less than or equal to 0,
    //set the size to MAX_MEMORY.
    UtPod(int size);
    
    /*
     * Copy Constructor
     *
     * Will copy over the list of songs in otherPod to this UtPod and set the
     * size to be the same size as otherPod. Basically it just creates a mirror
     * image of the other UtPod.
     */
    UtPod(const UtPod &otherPod);

    /* FUNCTION - int addSong
     * attempts to add a new song to the UtPod
         o returns a 0 if successful
         o returns -1 if not enough memory to add the song

     precondition: s is a valid Song

     input parms - s: a valid song that is to be added to the list

     output parms - 0 if successful or -1 if there is not enough memory
    */

    int addSong(Song const &s);


    /* FUNCTION - int removeSong
     * attempts to remove a song from the UtPod
     * removes the first instance of a song that is in the the UtPod multiple times
         o returns 0 if successful
         o returns -2 if nothing is removed


       input parms - s: A song that one wishes to be removed from the list

       output parms - 0 if successful or -2 if it is not in the list
    */

    int removeSong(Song const &s);


    /* FUNCTION - void shuffle
     *  shuffles the songs into random order
        o will do nothing if there are less than two songs in the current list

       input parms -

       output parms -
    */

    void shuffle();


    /* FUNCTION - void showSongList
     * prints the current list of songs in order from first to last to standard output
     * format - Title, Artist, size in MB (one song per line)

       input parms -

       output parms -
    */

    void showSongList();


    /* FUNCTION - void sortSongList
     *  sorts the songs in ascending order
        o will do nothing if there are less than two songs in the current list

       input parms -

       output parms -
    */

    void sortSongList();


    /* FUNCTION - void clearMemory
     * clears all the songs from memory

       input parms -

       output parms -
    */
    void clearMemory();


    /* FUNCTION - int getTotalMemory
     *  returns the total amount of memory in the UtPod
        o will do nothing if there are less than two songs in the current list

       input parms -

       output parms - returns the size of the UtPod
    */

    int getTotalMemory() {
        return memSize;
    }



    /* FUNCTION - int getRemainingMemory
     *  returns the amount of memory available for adding new songs

       input parms -

       output parms - returns the difference between the total memory and the
	              memory that is already being used
    */
    int getRemainingMemory();

    /*
     * Overrides the = operator such that if someone wishes to make one UtPod
     * equal to another UtPod, the list of songs of the UtPod on the right hand
     * side will be copied over to this UtPod and the size of the memory will be
     * set to that of the right hand side.
     */ 
    UtPod& operator =(const UtPod &rhs);

    /*
     * Deconstructor
     * Frees all the memory that is still being taken up by the list of songs
     * in UtPod before the conclusion of the program.
     */ 
    ~UtPod();

};



#endif
