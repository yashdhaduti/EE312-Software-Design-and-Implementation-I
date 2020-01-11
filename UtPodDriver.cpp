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

/* utPod_driver.cpp
Demo Driver for the UtPod.

Roger Priebe
EE 312 10/16/18

This is a basic driver for the UtPod.

You will want to do more complete testing.

*/
#include <cstdlib>
#include <iostream>
#include "Song.h"
#include "UtPod.h"
#include <string>
using namespace std;

int main(int argc, char *argv[])
{
    UtPod t;
    
    t.showSongList();
    
    Song s1("Beatles", "Hey Jude1", 4);
    int result=t.addSong(s1);
    
    cout << "result = " << result << endl;
    
    t.showSongList();
          
    Song s2("Beatles", "Hey Jude2", 5);
    result = t.addSong(s2);
    cout << "result = " << result << endl;
    
    t.showSongList();
       
    Song s3("Beatles", "Hey Jude3", 6);
    result = t.addSong(s3);
    cout << "result = " << result << endl;
       
    Song s4("Beatles", "Hey Jude4", 7);
    result = t.addSong(s4);
    cout << "result = " << result << endl;
       
    Song s5("Beatles", "Hey Jude5", 241);
    result = t.addSong(s5);
    cout << "add result = " << result << endl;
    
    t.showSongList();
    
    
    result = t.removeSong(s2);
    cout << "delete result = " << result << endl;
    t.showSongList(); 

    result = t.removeSong(s3);
    cout << "delete result = " << result << endl;

    t.showSongList();
    
    result = t.removeSong(s1);
    cout << "delete result = " << result << endl;

    t.showSongList();
 
    result = t.removeSong(s5);
    cout << "delete result = " << result << endl;

    t.showSongList();
    
    result = t.removeSong(s4);
    cout << "delete result = " << result << endl;
    
    
    t.showSongList();
    
    result = t.addSong(s5);
    cout << "add result = " << result << endl;
    
    t.showSongList();
    cout << "memory = " << t.getRemainingMemory() << endl;

    cout << endl;

    t.clearMemory();

    UtPod t2(400);

    result=t2.removeSong(s5);
    cout<<"remove when nothing in Pod = "<<result<<endl;

    Song dontPlay("Travis Scott", "Don't Play", 4);
    result = t2.addSong(dontPlay);
    cout << "add Don't Play result = " << result << endl;

    Song motPatch("Huncho Jack", "Motorcycle Patches", 3);
    result = t2.addSong(motPatch);
    cout << "add Motorcycle Patches result = " << result << endl;

    Song darkKnight("Trippie Redd", "Dark Knight Dummo", 4);
    result = t2.addSong(darkKnight);
    cout << "add Dark Knight Dummo result = " << result << endl;

    Song dangWorld("Mustard", "Dangerous World", 2);
    result = t2.addSong(dangWorld);
    cout << "add Dangerous World result = " << result << endl;

    Song notNet("Travis Scott", "Nothing But Net", 3);
    result = t2.addSong(notNet);
    cout << "add Nothing But Net result = " << result << endl;

    Song modSlave("Huncho Jack", "Modern Slavery", 6);
    t2.addSong(modSlave);
    cout<<endl;
    t2.showSongList();

    Song swerve("A Boogie Wit da Hoodie", "Swervin", 3); 
    result = t2.addSong(swerve);
    cout<<"add Swervin result = "<<result<<endl;
    
    t2.shuffle();
    t2.showSongList();
    cout<<endl;
    t2.sortSongList();
    t2.showSongList();
    cout<<endl;
    cout<<t2.getRemainingMemory()<<endl;

    Song cudi("Playboi Carti", "Kid cudi", 375);
    result = t2.addSong(cudi);

    cout<<"add cudi result = "<<result<<endl<<t2.getRemainingMemory()<<endl;

    result = t2.addSong(s5);
    cout<<result<<endl;

    return 0;
}