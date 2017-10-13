#ifndef VERTEXLIST_H
#define VERTEXLIST_H

#include <list>

using namespace std;

class vertexlist
{
public:
    vertexlist();
    vertexlist(list<int> _l);
    ~vertexlist();


    void add(int e);
    int get(int i);

    void empty();

    int size();

private:
    list<int> _list;

};

#endif // VERTEXLIST_H
