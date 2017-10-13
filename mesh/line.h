#ifndef LINE_H
#define LINE_H
#include <iostream>
#include <fstream>
#include <list>

class line
{
private:
        //static const int nvertici=2;
        int m_vertice[2];
        int m_iname;
        bool m_bselected;
        std::list<int> m_next;
        std::list<int> m_prev;


public:
        line();
        line(int,int);
        line(int []);
        bool m_berase;

        void clear_np();
        void addnext(int);
        void addprev(int);
        int nextsize();
        int prevsize();
        int getnext(int value);
        int getprev(int value);


        void SetLine(int,int);
        void SetName(int);
        int GetName();
        int GetVertice(int);
        int get(int);
        void SetSelected(bool);
        bool selected();
        void selected(bool value);
        bool IsSelected();
        line(const line& l)
        {
                m_vertice[0]=l.m_vertice[0];
                m_vertice[1]=l.m_vertice[1];
                m_berase=l.m_berase;
                m_next=l.m_next;
                m_prev=l.m_prev;

                m_iname=l.m_iname;

                m_bselected=l.m_bselected;

                std::list<int>::iterator il;
               /* m_next.clear();
                for(il=l.m_next.begin();il!=l.m_next.end();++il)
                {
                    m_next.push_back((*il));

                }
                m_prev.clear();
                for(il=l.m_prev.begin();il!=l.m_prev.end();++il)
                {
                    m_prev.push_back((*il));

                }*/

        }
        line& operator=(const line& l )
        {
                m_vertice[0]=l.m_vertice[0];
                m_vertice[1]=l.m_vertice[1];
                m_berase=l.m_berase;

                m_next=l.m_next;
                m_prev=l.m_prev;


                m_iname=l.m_iname;

                m_bselected=l.m_bselected;

                std::list<int>::iterator il;
                /*
                m_next.clear();
                for(il=l.m_next.begin();il!=l.m_next.end();++il)
                {
                    m_next.push_back((*il));

                }
                m_prev.clear();
                for(il=l.m_prev.begin();il!=l.m_prev.end();++il)
                {
                    m_prev.push_back((*il));

                }

                */
                return *this;
        }

        void serialize(std::ifstream*  ar)
        {
            if(ar->is_open())
            {
                ar->read((char*)&m_vertice,sizeof(int)*2);
                //(*ar) >> m_vertice[0];
                //(*ar) >> m_vertice[1];
                m_bselected=false;
                m_iname=0;
                m_next.clear();
                m_prev.clear();
            }
            else
            {


            }


        }
        void serialize(std::ofstream*  ar)
        {
            if(ar->is_open())
            {
                ar->write((char*)&m_vertice,sizeof(int)*2);
                /*
                (*ar) << m_vertice [0];
                (*ar) << m_vertice[1];
                */
            }
            else
            {


            }


        }
        virtual ~line();


};

#endif // LINE_H
