#include "Document.h"
#include <iostream>
#include <exception>
#include <fstream>
#include <algorithm> 



void Document::lineOne() { currLine=1; }
void Document::plus(int num) { currLine= currLine+num; }
void Document::moveLstLine() { currLine= editSong.size(); }
void Document::exit_() { exit(0); }

void Document::minus(int num) { 
    if((currLine-num)<0) throw std::out_of_range {"Row cannot be less than 0"};
    else 
        currLine= currLine-num; 
    }


void Document::addLine_before() {
    currLine--;
    std::string s;
    //printf("Please enter a sentence from the song :\n ");
    std::getline(std::cin,s);

    while (s!=".") {
        if(editSong.size()>0) {
        editSong.insert(editSong.begin()+currLine,s);
             std::getline(std::cin,s);  
              currLine++; 
            } 
            else if(editSong.size()==0) {
                editSong.push_back(s);
                 currLine++;
            }            
       }
  }


void Document::addLine_after() {
   
    std::string s;
    std::getline(std::cin,s);
    
    while (s!=".") {
        editSong.insert(editSong.begin()+currLine,s); 
            currLine++;
                 std::getline(std::cin,s);   
    }
}


//d
void Document::delete_line() {
   std::vector<std::string>::iterator it;
   it=editSong.begin();
   editSong.erase(it+currLine-1); 
}


void Document::write_toFile(std::string fileName){
   
  std::ofstream myFile;
  myFile.open (fileName);
  int i=0;
  
  while (i<= editSong.size()-1) {
     myFile<<editSong.at(i)<<"\n";
     i++;
  }
  myFile.close();
  }


//j
void Document::merge2Lines() {

std:: string l1=editSong.at(currLine-1);
std:: string l2=editSong.at(currLine);

std::vector<std::string>::iterator it;
it=editSong.begin();
editSong.erase(it+currLine);

editSong.at(currLine-1)=l1+" "+l2;
}

 
 // /text/
 void Document::text_(std::string text) {
  
  bool b=false;
  for(int i=currLine+1; i<editSong.size(); i++){
      std::string line= editSong.at(i);
      if(line.find(text)!= std::string::npos){
          b=true;
          currLine=i+1;
          break;
      }
  }
  if(!b) {
  for (int i = 0; i <=currLine; i++) {
      std::string line= editSong.at(i);
      if(line.find(text)!= std::string::npos){
          currLine=i+1;
          break;
         }
      }   
   }
}

// s/old/new
void Document::old_new(std::string _old, std::string _new) {

   std::string cut,before,after,final;
   int indx= editSong.at(currLine-1).find(_old); // indx is the index of the old word
    
    cut=editSong.at(currLine-1).substr(indx,_old.size()); // cut the old string from the current line
    before=editSong.at(currLine-1).substr(0,indx);
    after=editSong.at(currLine-1).substr(before.size()+_old.size()
                            ,editSong.at(currLine-1).length()-before.size()+_old.size());
    final=before+_new+after;
    editSong.at(currLine-1)=final;
}
