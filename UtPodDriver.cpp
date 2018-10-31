/* utPod_driver.cpp
Demo Driver for the UtPod.

Roger Priebe
EE 312 10/16/18

This is a basic driver for the UtPod.

You will want to do more complete testing.

*/
#include <cstdlib>
#include <iostream>
#include <fstream>
#include "Song.h"
#include "UtPod.h"

using namespace std;

int main(int argc, char *argv[])
{
    UtPod t;
    Song s;
    int count = 0;

    string line;
    ifstream myfile ("tester.txt");
    // Reading file with commands for testing
    if(myfile.is_open())
    {
        while(getline(myfile, line))
        {
	    // Getting rid of \n or \r characters
	    if(line[line.length() - 1] == '\n' || line[line.length() - 1] == '\r')
		line = line.substr(0, line.length() - 1);
	    if(line[line.length() - 1] == '\n' || line[line.length() - 1] == '\r')
		line = line.substr(0, line.length() - 1);

            if(line.substr(0,3) == string ("add"))
                count = 0;
            else if(line.substr(0,6) == string ("remove"))
                count = 3;
	    else if(line.substr(0,5) == string ("print"))
                count = 6;
            else if(line.substr(0,4) == string ("wait")){
                string mystr;
                while(mystr != "1") {
                    cout << "\nPress '1' to continue\n";
                    getline(cin, mystr);
		    // Exit Code
		    if(mystr == "0")
		    {
			myfile.close();
			return 0;			
                    }
		}
            }
            else if(count == 0) {
                s.setArtist(line);
                count++;
            }
            else if(count == 1) {
                s.setTitle(line);
                count++;
            }
            else if(count == 2) {
                s.setSize(atoi(line.c_str()));
                int errorCode = t.addSong(s);
                if(errorCode != 0)
                    cout << "\nError Code: " << errorCode << "\n";
                count = -1;
            }
            else if(count == 3) {
                s.setArtist(line);
                count++;
            }
            else if(count == 4) {
                s.setTitle(line);
                count++;
            }
            else if(count == 5) {
                s.setSize(atoi(line.c_str()));
                int errorCode = t.removeSong(s);
                if(errorCode != 0)
                    cout << "Error Code: " << errorCode << "\n";
                count = -1;
            }
            else if(count == 6) {
                cout << line << "\n\n";
                count = -1;
            }
            else if(line.substr(0,4) == string ("show")) {
                t.showSongList();
            }
            else if(line.substr(0,5) == string ("break")) {
                cout << "\n#######################\n";
            }
            else if(line.substr(0,4) == string ("sort")) {
                t.sortSongList();
            }
            else if(line.substr(0,7) == string ("shuffle")) {
                t.shuffle();
            }
            else if(line.substr(0,4) == string ("size")) {
                cout << "Size: " << (t.getTotalMemory() - t.getRemainingMemory());
                cout << "\nSize Left: " << t.getRemainingMemory();
            }
            else if(line.substr(0,5) == string ("clear"))
            {
                t.clearMemory();
            }

        }
        myfile.close();
    }
    
    cout << '\n';

    UtPod t2 (t);

    t2.showSongList();
    cout << '\n';

    UtPod t3;
    t3 = t;

    t3.showSongList();
    cout << '\n';

    return 0;
}


