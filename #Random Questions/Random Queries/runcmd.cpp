#include<iostream>
using namespace std;
#define subdot(filename) substr(0, filename.find_first_of("."))

int main(int argc, char **argv)
{
    if(argc !=  3)
    {
        cout << "Few args" << endl;
        return 0;
    }
    string hfile = argv[1];
    string usingfile = argv[2];
    string newfilename = usingfile.subdot(usingfile) + "_comb";
    string c1 = "g++ -c " + hfile;
    string c2 = "g++ -c " + usingfile;
    string c3 = "g++ -o " + newfilename + " " + hfile.subdot(hfile) + ".o " + usingfile.subdot(usingfile) + ".o";
    string c4 = newfilename + ".exe";
    system((const char*)&c1[0]);
    system((const char*)&c2[0]);
    system((const char*)&c3[0]);
    system((const char*)&c4[0]);
    return 0;
}