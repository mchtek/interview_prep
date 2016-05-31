#include "util.h"

using namespace std;

int main() 
{
    unordered_map<string, int> mymap;
    unordered_map<string, int>::iterator itr;

    pair <string, int> p1 ( "abc", 1 );
    mymap.insert(p1);
    mymap.insert(make_pair("efg", 2));
    for (itr = mymap.begin(); itr != mymap.end(); itr++) {
        cout << itr->first;
    }
}
