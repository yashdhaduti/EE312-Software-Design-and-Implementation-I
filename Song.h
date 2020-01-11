/* Student information for project:
 *
 * Replace <Harish Rajanala> with your name.
 *
 * On my honor, <Harish Rajanala>, this programming project is my own work
 * and I have not provided this code to any other student.
 *gdb
 * Name: Sai Harish Rajanala
 * email address: harishrajanala@utexas.edu 
 * UTEID: shr546  
 * Section 5 digit ID: 16035
 *
 */

/* Student information for project:
 *
 * Replace <Yash Dhaduti> with your name.
 *
 * On my honor, <Yash Dhaduti>, this programming project is my own work
 * and I have not provided this code to any other student.
 *gdb
 * Name: Yash Dhaduti
 * email address: yashdhaduti@utexas.edu 
 * UTEID: ysd97  
 * Section 5 digit ID: 16040
 *
 */

#ifndef SONG_H
#define SONG_H

#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

class Song{

    private:
        string name;
        string person;
        int num;
    
    public:
        Song();
        Song(string artist,string title, int size);
        string getTitle() const;
        string getArtist() const;
        int getSize() const;
        void setTitle(string title);
        void setArtist(string artist);
        void setSize(int size);
        bool operator == (Song const &rhs) const;
        bool operator < (Song const &rhs) const;
        bool operator > (Song const &rhs) const;
};

#endif