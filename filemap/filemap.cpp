#include <iostream>
#include <fstream>
#include <map>
#include <string>

using namespace std;

string here_document = \
R"EOF(Medium Speed
Air 1100
Water 4900
Steel 16400
Copper 7500
Nylon 1150
Iron 8200
)EOF";

int main(int argc, const char* argv[]) {

    ofstream file_out;
    file_out.open("data.txt");
    file_out << here_document;
    here_document.clear();
    file_out.flush();
    file_out.close();

    std::ifstream file_in("data.txt");

   // cout << file_in.rdbuf(); // debug

    string key;
    int value;
    string valu1;
    map<string, int> my_map;
    //file_in.open();
    while (file_in >> key && file_in >> valu1) {
        cout << "Read: " << key << " " << valu1 << endl;
        value = atoi(valu1.c_str());
        my_map[key] = value;
    }

    remove("data.txt");
    file_in.close();
    for (auto& it : my_map)
        std::cout << it.first << " :" << it.second<<std::endl;

    //remove
    auto it = my_map.find("Medium");
    my_map.erase(it);
    std::cout << "----------after earase map key---------" << std::endl;
    for (auto& it : my_map)
        std::cout << it.first << " :" << it.second << std::endl;


    int x = 1000;
    char* p;
    p = (char*) & x;
    printf("Value of x is %d", *(int*)p);
    return 0;
    return 0;
}