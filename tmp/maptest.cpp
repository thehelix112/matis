#include <map>
#include <iostream>

class Blah{

    int id;

};


int main(int argc, char** argv){

    typedef std::map < std::string,
                Blah* > mapIdBlahType;

    mapIdBlahType map;

    std::cout << "non existent: " << map["nonexistent"] << std::endl;

    Blah *a = new Blah();
    map["a"] = a;

    std::cout << "existent: " << map["a"] << std::endl;
            


}
