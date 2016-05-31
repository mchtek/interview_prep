#include "util.h"

using namespace std;

// DAG: weighted Representation
class edge {
public:
    edge(int end_vertex, int weight) {
        end_v = end_vertex;
        weight = weight;
    }

    int end_v;
    int weight;
};

int main() 
{
    // 0 -> 1 -> 2
    // |    |    
    // 3 -> 4
    std::vector< std::list<edge> > adjlist(5);;
    adjlist[0].push_back(edge(1,4));
    adjlist[0].push_back(edge(3,4));
    adjlist[1].push_back(edge(4,4));
    adjlist[1].push_back(edge(2,4));
    adjlist[3].push_back(edge(4,4));

    for (std::vector< std::list<edge> >::iterator vitr = adjlist.begin(); vitr != adjlist.end(); ++vitr) {
        // vitr points to head of the linked list
        for (std::list<edge>::iterator itr = (*vitr).begin(); itr != (*vitr).end(); ++itr) {
            cout << " -> " << itr->end_v;
        }
        cout << endl;;
    }
   

}
