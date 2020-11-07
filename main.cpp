#include "Editor.h"
#include <fstream>
#include <iostream>

int main (int argc, char* argv[]) {

Editor e;
switch (argc) {


case 2: {

std::fstream orgnl_file;
// in argv[1] there is the name of the text file, we open it and then read its lines 
orgnl_file.open(argv[1], std::ios::in);  

  if ( !orgnl_file.is_open() ) {
    std::cerr << argv[1] << " open error " << std::endl;
    exit(1);
  }
  else {
      std::string s;
      int i=0;
      while (getline(orgnl_file,s) && s!="") {
          e.myDoc.editSong.insert(e.myDoc.editSong.begin()+i,s);
          i++;
      }
      orgnl_file.close();
  } //end else

      e.myDoc.currLine=1;
      

}
     


}
e.myLoop();
}