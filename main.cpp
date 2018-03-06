#include <iostream>
#include <rapidxml.h>
#include <rapidxml_utils.h>
using namespace std;

class RenoiseModule {
public:
    RenoiseModule(std::string basedir) {
        rapidxml::file<> f(songbase + "/song.xml");
        rapidxml::xml_document<> document;
        document.parse<0>(f.data());
        rapidxml::xml_node<> *initialnode = (document.first_node());
        rapidxml::xml_node<> *snode = tagSearch(initialnode, "RenoiseSong");
    }

private:
    rapidxml::xml_node<>* tagSearch(rapidxml::xml_node<> *currentnode, std::string tagname) {
        while (currentnode != NULL) {
            if (strcmp(currentnode->name(), tagname.c_str()) == 0) {
                break;
            }
            currentnode = currentnode->next_sibling();
        }
        return currentnode;
    }

    int loadGlobalSongData(rapidxml::xml_document<> ) {

    }
};

int main()
{
    if(argc > 1) {
        std::string songbase = argv[0];
        std::cout << "Opening song at basedir: " << songbase << std::endl;
        RenoiseModule module(songbase);
    }
    return 0;
}
