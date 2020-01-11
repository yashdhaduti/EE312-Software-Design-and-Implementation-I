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


#include "UtPod.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <stdint.h>
#include "Song.h"
using namespace std;

Song::Song(){
    num=0;
    name="";
    person="";
}

Song::Song(string artist, string title, int size){

    num=size;
    name=title;
    person=artist;

}


//get modules
string Song::getTitle() const{

    return name;
}

string Song::getArtist() const{
    return person;
}

int Song::getSize() const{

    return num;
}

//set modules
void Song::setTitle(string title){

    name=title;   
}

void Song::setArtist(string artist){

    person=artist;
}
void Song::setSize(int size){

    num=size;
}

//operator modules
bool Song::operator == (Song const &rhs) const{

    if(rhs.name == name && rhs.num == num && rhs.person == person){
        return true;
    }
    return false;
}

bool Song::operator<(Song const &rhs) const{


        if(person == rhs.person){
            if(name == rhs.name){
                if(num < rhs.num){
                    return true;
                }
                else return false;
            }
            else return name<rhs.name;
        }
        else return person<rhs.person;
}

bool Song::operator>(Song const &rhs) const{


        if(rhs.person == person){
            if(rhs.name == name){
                if(rhs.num < num){
                    return true;
                }
                else return false;
            }
            else return name>rhs.name;
        }
        else return person>rhs.person;
}