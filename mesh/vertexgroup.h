#ifndef VERTEXGROUP_H
#define VERTEXGROUP_H
#include <vector>
#include <list>
#include <string>

using namespace std;

class vertexgroup
{
public:
    vertexgroup();

    vertexgroup(const vertexgroup& v)
    {

        _id=v._id;
        _list=v._list;
        _list_line=v._list_line;
        _list_poly=v._list_poly;
        _name=v._name;

    }
    vertexgroup& operator=(const vertexgroup& v)
    {
        _id=v._id;
        _list=v._list;
        _list_line=v._list_line;
        _list_poly=v._list_poly;
        _name=v._name;

        return (*this);

    }

    void add(int v);

    int get(int index);

    string getname();

    list<int> getlist();
    list<int> getlist_line();
    list<int> getlist_poly();

    void set(list<int> l);
    void setline(list<int> line);
    void setpoly(list<int> poly);

    void clear();


    vertexgroup(string name,int id,list<int> _list);
private:
    list<int> _list;
    list<int> _list_line;
    list<int> _list_poly;

    string _name;
    int _id;
};

#endif // VERTEXGROUP_H
