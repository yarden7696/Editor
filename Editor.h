#include "Document.h"

class Editor {
public:
    Document myDoc;
public:
    Editor()=default;
    Editor(Document doc):myDoc(doc){}
    void myLoop();
};
