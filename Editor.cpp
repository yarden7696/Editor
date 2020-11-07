#include "Editor.h"
#include <iostream>
#include <string>




void Editor::myLoop() {

//printf("Enter a command to edit the song :\n");
while (true){
   
std::string choice;
std::getline (std::cin,choice);


if (choice=="1")  // move to line 1
    myDoc.lineOne();
  

else if (choice.at(0)=='+') { // adding +num to the current line
    int num= stoi(choice.substr(1,choice.size()-1));
    myDoc.plus(num);
}


else if (choice.at(0)=='-') { // decrease -num to the current line
   int num= stoi(choice.substr(1,choice.size()-1));
   myDoc.minus(num);
}

 
else if (choice=="$") // move to the last line in the song
   myDoc.moveLstLine();
   
 
else if (choice=="a") { // adding line/s *AFTER* the current line 
  myDoc.addLine_after();
}


else if (choice=="i") { // adding line/s *BEFORE* the current line 
      myDoc.addLine_before();
}
        
 else if (choice=="c") { // replace the current line with another
 myDoc.delete_line();
 myDoc.addLine_before();

}       
    
else if (choice.at(0)=='w') {
    std::string fileName=choice.substr(2,choice.size()-1);
    myDoc.write_toFile(fileName);
}

else if (choice=="d") { myDoc.delete_line(); }

else if (choice=="j") { myDoc.merge2Lines(); }

else if (choice=="q") { myDoc.exit_(); }
   
else if (choice.at(0)=='/') {

   std::string s = choice.substr(1,choice.size()-2);
   myDoc.text_(s); 
}

else if (choice.at(0)=='s') {
    
    int counter=0;
    std::string _old,_new;
    for (int i = 2; i <choice.size()-1; i++) {
        if(choice.at(i)!='/') counter++;
        else { 
            _old=choice.substr(2,counter);
            _new=choice.substr(counter+3,choice.size()-counter-4);
            myDoc.old_new(_old,_new);
            break;
        }
    }
}

else
    break;


}
}// end myLoop












