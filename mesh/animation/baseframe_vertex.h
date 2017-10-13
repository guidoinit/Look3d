#ifndef BASEFRAME_VERTEX_H
#define BASEFRAME_VERTEX_H

class baseframe_vertex
{
private:
        int _fstart;
        int _fend;
public:
        baseframe_vertex(int fstart,int fend);
        baseframe_vertex(void);
        ~baseframe_vertex(void);
//	virtual void Serialize(CArchive &ar);

        int getstart();
        int getend();

        void setstart(int);
        void setend(int);

        baseframe_vertex(const baseframe_vertex& bf)
        {
                _fstart=bf._fstart;
                _fend=bf._fend;

        }

        baseframe_vertex operator=(baseframe_vertex& bf)
        {
                _fstart=bf._fstart;
                _fend=bf._fend;

                return *this;
        }
};

#endif // BASEFRAME_VERTEX_H
