#include <tinyxml2.h>

using namespace tinyxml2;

#include <iostream>

void visit(XMLElement* elem) {
    std::cout << elem->Name() << std::endl;
    auto attr = elem->FirstAttribute();
    while (attr != NULL) {
        std::cout << attr->Name() << " : " << attr->Value() << std::endl;
        attr = attr->Next();
    }
    auto child = elem->FirstChildElement();
    while (child != NULL) {
        visit(child);
        child = child->NextSiblingElement();
    }
}
int main(int argc, char** argv) {
    XMLDocument doc;
    doc.LoadFile(argv[1]);
    visit(doc.RootElement());
    return 0;
}