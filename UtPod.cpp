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
#include "Song.h"
#include <cstdlib>
#include <stdint.h>
#include <ctime>
#include <string>
using namespace std;

      //Default constructor
      //set the memory size to MAX_MEMORY
      UtPod::UtPod(){
         songs=NULL;
         memSize=MAX_MEMORY;

         unsigned int currentTime = (unsigned)time(0);
         srand(currentTime);

      }

      //Constructor with size parameter
      //The user of the class will pass in a size.
      //If the size is greater than MAX_MEMORY or less than or equal to 0,
      //set the size to MAX_MEMORY.
      UtPod::UtPod(int size){

         songs=NULL;
         if(size>MAX_MEMORY || size <=0)
            size=MAX_MEMORY;
         else 
            memSize=size;

         unsigned int currentTime = (unsigned)time(0);
         srand(currentTime);
      }

      /* FUNCTION - int addSong
       * attempts to add a new song to the UtPod
           o returns a 0 if successful
           o returns -1 if not enough memory to add the song

       precondition: s is a valid Song

       input parms -

       output parms -
      */

      int UtPod::addSong(Song const &s){ //& means passing my reference
            
         if(s.getSize() > getRemainingMemory()){
            return NO_MEMORY;
         }
            SongNode *temp = new SongNode;
            temp->s=s;
            temp->next = songs;
            songs=temp;
            return SUCCESS;
         
      }


      /* FUNCTION - int removeSong
       * attempts to remove a song from the UtPod
       * removes the first instance of a song that is in the the UtPod multiple times
           o returns 0 if successful
           o returns -1 if nothing is removed


         input parms -

         output parms -
      */

      int  UtPod::removeSong(Song const &s){

         if(getRemainingMemory() == memSize){
            return NO_MEMORY;
         }else{
            SongNode *temp = songs;
            SongNode *n = new SongNode;
            while(temp!=NULL){
               if(temp->s == s){
                  if(temp == songs){
                     SongNode *songs2 = songs;
                     temp=temp->next;
                     songs=songs->next;
                     delete songs2;
                     return SUCCESS;
                  }else{
                     n->next=temp->next;
                     SongNode *temp2 = temp;
                     temp=temp->next;
                     delete temp2;
                     return SUCCESS;  
                  }                
               }
               n=temp;
               temp=temp->next;
            }
            return SUCCESS;
         }
         return NO_MEMORY;
      }


      /* FUNCTION - void shuffle
       *  shuffles the songs into random order
          o will do nothing if there are less than two songs in the current list

         input parms -

         output parms -
      */

      void  UtPod::shuffle(){
         
         if(getSongCount()<2)
            return;

         for(int a=0; a < (getSongCount() * 2); a++){

            SongNode *onePoint = songs;
            SongNode *twoPoint = songs;

            for(int i=0; i<rand()%getSongCount(); i++){
               
               onePoint=onePoint->next;
            }
            
            for(int j=0; j<rand()%getSongCount(); j++){

               twoPoint=twoPoint->next;
            }

            Song temp = twoPoint->s; 
            twoPoint->s=onePoint->s; // two = one
            onePoint->s=temp; // one=stwo
            

         }
      }

      int UtPod::getSongCount(){

         SongNode *pointer = songs;
         int count=0;
         while(pointer!=NULL){

            count++;
            pointer=pointer->next;
         }
         return count;
      }

      


      /* FUNCTION - void showSongList
       * prints the current list of songs in order from first to last to standard output
       * format - Title, Artist, size in MB (one song per line)

         input parms -

         output parms -
      */

      void  UtPod::showSongList(){

         SongNode *n = songs;
         while(n!=NULL){
            cout << n->s.getTitle() << ", " << n->s.getArtist() << ", "<< n->s.getSize() << "MB" << endl;
            n=n->next;
         }
      }


      /* FUNCTION - void sortSongList
       *  sorts the songs in ascending order
          o will do nothing if there are less than two songs in the current list

         input parms -

         output parms -
      */

      void UtPod::sortSongList(){

         if(getSongCount()<2)
            return;

         bool swap=false;

         SongNode *top=songs;
         SongNode *nul=NULL;

         do{

            swap=false;
            top=songs;

            while(top->next != nul){

              if(top->s > top->next->s){
                 
                  Song temp = top->s; 
                  top->s=top->next->s; // two = one
                  top->next->s=temp;
                  swap=true;
              } 
              top=top->next;
            }   
            nul=top;
            }while(swap);

         }


      /* FUNCTION - void clearMemory
       * clears all the songs from memory

         input parms -

         output parms -
      */
      void UtPod::clearMemory(){

         while(songs!=NULL){
            SongNode *songsTemp=songs;
            songs=songs->next;
            delete songsTemp;
         }
         return;
      }


      /* FUNCTION - int getRemainingMemory
       *  returns the amount of memory available for adding new songs

         input parms -

         output parms -
      */

      int  UtPod::getRemainingMemory(){

         SongNode *n = songs;
         int total=0;
         while(n!=NULL){

            total+=n->s.getSize();
            n=n->next;
         }
         return (memSize - total);
      }


      UtPod::~UtPod(){
         clearMemory();
      }
 