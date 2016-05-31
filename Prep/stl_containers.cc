#include "util.h"

using namespace std;

int main()
{
    // Sequential Containers: vector, deque, list, forward list, array
    vector<int> vec;
    vec.push_back(1);
    vec.push_back(5);
    vec.push_back(7);

    // Print vector
    cout << "Using Itr, vec elements are:" << endl;
    for (vector<int>::iterator itr = vec.begin(); itr != vec.end();
         itr++) {
        cout << *itr << " ";
    }
    cout << "\nUsing indexing, vec elements are:" << endl;
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }

    // List ops
    list<int> mylist; 
    mylist.push_back(7);
    mylist.push_front(1);
    
    list<int>::iterator itr = find(mylist.begin(), mylist.end(), 7);
    mylist.insert(itr, 5);

    cout << "\nUsing indexing, my elements are:" << endl;
    for (list<int>::iterator itr = mylist.begin(); itr != mylist.end();
         itr++) {
        cout << *itr << " ";
    }

    // Associative Containers: set, multiset, map, multimap
    multimap<int, char> mymap;
    mymap.insert(make_pair(7, 'c'));
    mymap.insert(make_pair(1, 'a'));
    mymap.insert(make_pair(5, 'b'));
    
    cout << "\nMy map elements are:" << endl;
    for (multimap<int, char>::iterator itr = mymap.begin();
         itr != mymap.end();
         itr++) {
        cout << itr->first << " => " << itr->second << " ";
    }

    // Unordereed Containers: Unordered set, map also
    // called associative arrays
    unordered_map<char, int> umap;
    umap['a'] = 1;
    umap['b'] = 2;
    
    cout << "\nMy map elements are:" << endl;
    cout << umap['a'] << "  " << umap['b'] << " ";
}
