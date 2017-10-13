#include "l3d_modifier_extrude.h"
#include "l3d_include.h"
#include "mesh/l3d_id_picking.h"
#include "mesh/l3d_vertex.h"
#include "mesh/l3d_line.h"
#include "mesh/l3d_face3.h"
#include "mesh/l3d_face4.h"
#include "mesh/l3d_mesh.h"


using namespace l3d;
using namespace l3d::vertex3f;
using namespace l3d::edge;
using namespace l3d::face3;
using namespace l3d::face4;
using namespace l3d::mesh;
using namespace l3d::modifier;
l3d_modifier_extrude::l3d_modifier_extrude()
{
    _mesh=l3d_null;
}
void l3d_modifier_extrude::set_mesh(pl3d_mesh_struct _e)
{
    _mesh=_e;
}
void l3d_modifier_extrude::extrudevertex()
{
    if(_mesh==l3d_null)
        return;
    std::list<int> vadded;
    std::list<int>::iterator it;
    l3d_uint nsize=_mesh->_vertex.size();
    l3d_uint size=nsize;
    for( int ix= 0 ; ix < size ; ix++ )
    {
        pl3d_vertex_fast v=_mesh->_vertex.find(ix);
        if(v->_selected)
        {
            vadded.push_back(nsize++);
            extrudevertex(ix);
        }

    }


    for(it=vadded.begin();it!=vadded.end();++it)
    {
        pl3d_vertex_fast v=_mesh->_vertex.find((*it));
        v->selected(true);
    }
}
void l3d_modifier_extrude::extrudevertex(l3d_uint ix)
{
    pl3d_vertex_fast v=_mesh->_vertex.find(ix);


    v->selected(false);

    _mesh->addvertex(v->x,v->y,v->z);


    int nsize=_mesh->_vertex.size()-1;

    _mesh->_vertex.find(nsize)->selected(false);


    _mesh->addedge(ix,nsize);

}
void l3d_modifier_extrude::makeindex_quads()
{
    if (_mesh->_quad.size()==0)
        return;
    l3d_uint qindex,q2index;

    pl3d_face4_struct q=_mesh->_quad.find(0);

    if(!q)
        return;



    qindex=0;

    while(q)
    {

        if( !q->selected() )
        {
            qindex++;
            q=q->next;
            continue;
        }



        q->clear_lists();//to-do: is correct?

        int v0,v1,v2,v3;

        v0=q->_v0;
        v1=q->_v1;
        v2=q->_v2;
        v3=q->_v3;

        //v1-v3 sinistra
        pl3d_face4_struct q2=_mesh->_quad.find(0);

        q2index=0;
        while(q2)
        {
            if(q==q2 )
            {
                q2index++;
                q2=q2->next;
                continue;
            }


            int pv0,pv1,pv2,pv3;

            pv0=q2->_v0;
            pv1=q2->_v1;
            pv2=q2->_v2;
            pv3=q2->_v3;

            //    (q)
            //
            //         up
            //
            //     v0-----v1
            //     |       |
            //sin  |       |  des
            //     |       |
            //     v2-----v3
            //
            //       down
            //
            //
            //    (q2)
            //         up
            //
            //    pv0-----pv1
            //     |       |
            //sin  |       |  des
            //     |       |
            //    pv2-----pv3
            //
            //       down
            //
            // aggiunge a q un elemento nella lista des se
            // des(q)==sin(q2) ossia (v1==pv1 && v3==pv3)
            //



            if(q!=q2)
            {
                // to-do

                // v0-v2 sinistra

                if((v0==pv1 && v2==pv3) || (v2==pv1 && v0==pv3))
                    if(q2->selected())
                        q->add_sin(q2index);

                //v1-v3 destra

                if((v1==pv1 && v3==pv3) || (v3==pv1 && v1==pv3))
                    if(q2->selected())
                        q->add_des(q2index);


                //v2-v3 down

                if((v2==pv0 && v3==pv1) || (v3==pv0 && v2==pv1))
                    if(q2->selected())
                        q->add_down(q2index);

                //v0-v1 up

                if((v0==pv2 && v1==pv3) || (v1==pv2 && v0==pv3))
                    if(q2->selected())
                        q->add_up(q2index);



            }

            q2index++;
            q2=q2->next;

        }
        qindex++;
        q=q->next;







    }

}



void l3d_modifier_extrude::makeindex_edges()
{

    if(_mesh->_vertex.size()==0)
        return;


    int lsize=_mesh->_edges.size();

    if (lsize==0)
        return;

    pl3d_line_struct l1=_mesh->_edges.find(0),l2;
    while(l1)//for(int ix=0; ix < lsize;ix++)
    {


        if(!l1->selected())
        {

            l1=l1->next;
            continue;

        }


        l1->clear_np(); //?? to-do: is correct?

        int ivert=l1->v0;
        int ivert1=l1->v1;

        l2=_mesh->_edges.find(0);

        int iy=0;
        while(l2)//for(int iy=0; iy < lsize; iy++)
        {
            int v1,v2;


            v1=l2->v0;
            v2=l2->v1;

            if(l1!=l2 && (v1==ivert || v2==ivert  || v1==ivert1  || v2==ivert1))
            {

                // to-do: is correct?
                if((v1==ivert  || v2==ivert)  && l2->selected())
                    l1->addprev(iy);

                if((v1==ivert1 || v2==ivert1) && l2->selected())
                    l1->addnext(iy);


           }
           l2=l2->next;
           iy++;

        }
        l1=l1->next;
    }

}
l3d_bool l3d_modifier_extrude::isedge_perimeter(l3d_uint ix)
{
    l3d_uint start=ix,curredge=ix,nextedge=0;
    l3d_bool isperimeter=false;
    pl3d_line_struct lstart=_mesh->_edges.find(ix);
    nextedge=lstart->getnext(0);
    _ledge_perimeter.clear();
    _ledge_perimeter.push_back(start);
    do
    {
        pl3d_line_struct lnext;

        //lprev=_mesh->_edges.find(lstart->getprev(0));
         lnext=_mesh->_edges.find(nextedge);


        if(lnext->nextsize()==0 || lnext->prevsize()==0)
        {

            _ledge_perimeter.clear();
            return(false);

        }
        lstart=lnext;

        if(lnext->getnext(0)==curredge)
        {
            curredge=nextedge;
            nextedge=lnext->getprev(0);
        }
        else
        {
            curredge=nextedge;
            nextedge=lnext->getnext(0);
        }

        _ledge_perimeter.push_back(curredge);


    }while(lstart && (nextedge!=start));

    if(lstart->getnext(0)==start || lstart->getprev(0)==start)
        isperimeter=true;
    else
        _ledge_perimeter.clear();

    return(isperimeter);


}

l3d_bool l3d_modifier_extrude::isedgealone_sin(l3d_uint value)
{
    bool fls=false,fld=false;

    int ix=0;

    pl3d_line_struct line=_mesh->_edges.find(value);

    return(line->nextsize()>0 && line->prevsize()==0);
    /*
    while(!fld && ix<line->nextsize() )

    {
        pl3d_line_struct line2=_mesh->_edges.find(line->getnext(ix++));
        fld=line2->selected();

    }

    ix=0;

    while(!fls && ix<line->prevsize() )
    {
        pl3d_line_struct line2=_mesh->_edges.find(line->getprev(ix++));
        fls=line2->selected();

    }


    if(!fls && fld)
        return(true);
    else
        return (false);
        */
}
l3d_bool l3d_modifier_extrude::isedgealone_des(l3d_uint value)
{
    bool fls=false,fld=false;

    int ix=0;

    pl3d_line_struct line=_mesh->_edges.find(value);

    return(line->nextsize()==0 && line->prevsize()>0);

    /*while(!fld && ix<line->nextsize() )

    {
        pl3d_line_struct line2=_mesh->_edges.find(line->getnext(ix++));
        fld=line2->selected();

    }

    ix=0;

    while(!fls && ix<line->prevsize() )
    {
        pl3d_line_struct line2=_mesh->_edges.find(line->getprev(ix++));
        fls=line2->selected();

    }
    if(fls && !fld)
        return(true);
    else
        return (false);
        */
}
l3d_bool l3d_modifier_extrude::isquadalone(l3d_uint value)
{
    bool fl=false;

    pl3d_face4_struct q=_mesh->_quad.find(value);

    if(!q)
        return(false);
    //to-do: is correct?

    fl=(q->upsize()==0 && q->downsize()==0 && q->sinsize()==0 && q->dessize()==0);

    return(fl);

    //

}

l3d_bool l3d_modifier_extrude::isedgealone(l3d_uint value)
{
    bool fl=false;

    pl3d_line_struct l=_mesh->_edges.find(value);
    int ix=0;
    //to-do: is correct?

    return( l->nextsize()==0 && l->prevsize()==0 );
    /*
    while(!fl && ix<l->nextsize() )
    {
        pl3d_line_struct l2=_mesh->_edges.find(l->getnext(ix++));
        fl=l2->selected();

    }

    ix=0;
    while(!fl && ix<l->prevsize() )
    {
        pl3d_line_struct l2=_mesh->_edges.find(l->getprev(ix++));
        fl=l2->selected();

    }

    //fl=m_line[m_line[value].getprev(ix++)].selected();

    return (!fl);*/
}
l3d_bool l3d_modifier_extrude::isquadall()
{

    l3d_bool fl=true;
    pl3d_face4_struct q=_mesh->_quad.find(0);

    while(fl && q )
    {


        fl=q->selected();
        q=q->next;

    }


    return (fl);

}

l3d_bool l3d_modifier_extrude::isedgeall()
{

    l3d_bool fl=true;
    pl3d_line_struct l=_mesh->_edges.find(0);

    while(fl && l )
    {


        fl=l->selected();

        l=l->next;
    }


    return (fl);

}
void l3d_modifier_extrude::extrudeedge(std::list<int> _list)
{

    //to-do da controllare

    std::list<int>::iterator il;

    std::vector<int> vertici;
    std::vector<int>::iterator iv;
    int v1,v2;
    for(il=_list.begin();il!=_list.end();++il)
    {
        pl3d_line_struct e=_mesh->_edges.find((*il));

        v1=e->v0;
        v2=e->v1;

        if(vertici.size()==0)
        {
            vertici.push_back(v1);
            vertici.push_back(v2);
        }
        else if(v1==vertici[vertici.size()-1])
            vertici.push_back(v2);
        else if(v1==vertici[vertici.size()-2])
        {
            int ip=vertici[vertici.size()-1];
            vertici[vertici.size()-1]=vertici[vertici.size()-2];
            vertici[vertici.size()-2]=ip;

            vertici.push_back(v2);
        }

        else if(v2==vertici[vertici.size()-1])
            vertici.push_back(v1);

        else if(v2==vertici[vertici.size()-2])
        {
            int ip=vertici[vertici.size()-1];
            vertici[vertici.size()-1]=vertici[vertici.size()-2];
            vertici[vertici.size()-2]=ip;

            vertici.push_back(v1);
        }



    }
    int vsize=_mesh->_vertex.size();

    for(iv=vertici.begin(); iv != vertici.end(); ++iv)
    {
        pl3d_vertex_fast appv=_mesh->_vertex.find((*iv));
        pl3d_vertex_fast newv= new l3d_vertex_fast;

        *newv=*appv;


        appv->selected(false);

        newv->selected(false);

        _mesh->_vertex.add(newv);


    }
    int iy=0;
    int lsize=_mesh->_edges.size()+2;
    for(int ix=vsize; ix < _mesh->_vertex.size()-1; ix++)
    {
        l3d_uint v0,v1,v2,v3;
        //_mesh->addquad(vertici[iy],vertici[iy+1],ix,ix+1);

        v0=vertici[iy];
        v1=vertici[iy+1];
        v2=ix;
        v3=ix+1;

        //v2-----v3
        //|      |
        //|      |
        //|      |
        //v0-----v1

        //m_line[lsize].selected(true); ?? to-do
        _mesh->addquad(v0,v1,v2,v3,abcdCW);
        _ladded.push_back(_mesh->_edges.index(v2,v3));

        lsize+=4;

        iy++;
    }
}
void l3d_modifier_extrude::extrudeedge_perimeter(std::list<int> _list)
{

    //to-do da controllare

    std::list<int>::iterator il;

    std::vector<int> vertici;
    std::vector<int>::iterator iv;

    for(il=_list.begin();il!=_list.end();++il)
    {
        int v1,v2;
        pl3d_line_struct e=_mesh->_edges.find((*il));

        v1=e->v0;
        v2=e->v1;
        if((*il)+1==_list.size())
            break;

        if(vertici.size()==0)
        {
            vertici.push_back(v1);
            vertici.push_back(v2);
        }
        else if(v1==vertici[vertici.size()-1])
            vertici.push_back(v2);
        else if(v1==vertici[vertici.size()-2])
        {
            int ip=vertici[vertici.size()-1];
            vertici[vertici.size()-1]=vertici[vertici.size()-2];
            vertici[vertici.size()-2]=ip;

            vertici.push_back(v2);
        }

        else if(v2==vertici[vertici.size()-1])
            vertici.push_back(v1);

        else if(v2==vertici[vertici.size()-2])
        {
            int ip=vertici[vertici.size()-1];
            vertici[vertici.size()-1]=vertici[vertici.size()-2];
            vertici[vertici.size()-2]=ip;

            vertici.push_back(v1);
        }



    }
    int vsize=_mesh->_vertex.size();

    if (vertici[0]==vertici[vertici.size()-1])
        vertici.pop_back();

    for(iv=vertici.begin(); iv != vertici.end(); ++iv)
    {
        pl3d_vertex_fast appv=_mesh->_vertex.find((*iv));
        pl3d_vertex_fast newv= new l3d_vertex_fast;

        *newv=*appv;


        appv->selected(false);

        newv->selected(false);

        _mesh->_vertex.add(newv);


    }
    int iy=0;
    int lsize=_mesh->_edges.size()+2;
    l3d_uint v0,v1,v2,v3;
    for(int ix=vsize; ix < _mesh->_vertex.size()-1; ix++)
    {

        //_mesh->addquad(vertici[iy],vertici[iy+1],ix,ix+1);

        v0=vertici[iy];
        v1=vertici[iy+1];
        v2=ix;
        v3=ix+1;

        //v2-----v3
        //|      |
        //|      |
        //|      |
        //v0-----v1

        //m_line[lsize].selected(true); ?? to-do
        _mesh->addquad(v2,v3,v0,v1,abcdCW);
        _ladded.push_back(_mesh->_edges.index(v2,v3));

        lsize+=4;

        iy++;
    }

    v0=v1;
    v2=v3;
    v1=vertici[0];
    v3=vsize;
    _mesh->addquad(v2,v3,v0,v1,abcdCW);
    _ladded.push_back(_mesh->_edges.index(v2,v3));

}
void l3d_modifier_extrude::extrudeedge(int l)
{
    int v1,v2,i1,i2;

    pl3d_vertex_fast app1,app2;


    pl3d_line_struct e=_mesh->_edges.find(l);



    i1=e->v0;
    i2=e->v1;

    e->selected(false);


    _mesh->_vertex.find(i1)->selected(false);
    _mesh->_vertex.find(i2)->selected(false);

    app1=_mesh->_vertex.find(i1);
    app2=_mesh->_vertex.find(i2);
    //app1=local_vertex[v1];
    //app2=local_vertex[v2];


    v1=_mesh->_vertex.size();

    //aggiunge un vertice

    _mesh->addvertex(app1->x,app1->y,app1->z);
    //local_vertex.push_back(app1);



    //aggiunge un vertice

    v2=_mesh->_vertex.size();

    _mesh->addvertex(app2->x,app2->y,app2->z);
    //local_vertex.push_back(app1);




    //controllare il verso


    //pl3d_face4_struct q=new l3d_face4_struct;




    //l3d_uint numf=_mesh->_faces.size();

    /*pl3d_face3_struct f=new l3d_face3_struct;

    pl3d_face3_struct f2=new l3d_face3_struct;



    f->_alone=false;
    f->_erase=false;
    f->_selected=false;

    f2->_alone=false;
    f2->_erase=false;
    f2->_selected=false;

    */
    //
    //v1------v2
    //|  / \  |
    //|   |   |
    //|   |   |
    //i1------i2
    //
    /*f->v0=v1;
    f->v1=v2;
    f->v2=i1;

    f2->v0=v2;
    f2->v1=i2;
    f2->v2=i1;


    f->_pv0=_mesh->_vertex.find(v1);
    f->_pv1=_mesh->_vertex.find(v2);
    f->_pv2=_mesh->_vertex.find(i1);

    f2->_pv0=_mesh->_vertex.find(v2);
    f2->_pv1=_mesh->_vertex.find(i2);
    f2->_pv2=_mesh->_vertex.find(i1);

    _mesh->_faces.add(f);
    _mesh->_faces.add(f2);

    */
    //
    //v1------v2
    //|  / \  |
    //|   |   |
    //|   |   |
    //i1------i2
    //
    //verifica per inserimento del quad
    // 1)
    //    i1--normal
    //    |  /
    //    | /
    //    |/
    //    v1
    // in questa situazione ossia v1 è minore di i1 e la normale di i1 è maggiore di i1
    // inserisco (a,b,c,d) come (i1,i2,v1,v2)
    // 2)
    //    v1--normal
    //    |  /
    //    | /
    //    |/
    //    i1
    // in questa situazione ossia i1 è minore di v1 e la normale di v1 è maggiore di v1
    // inserisco (a,b,c,d) come (v1,v2,i1,i2)
    // 3)
    //    i1--normal
    //    |  /
    //    | /
    //    |/
    //    v1
    // in questa situazione ossia v1 è minore di i1 e la normale di i1 è minore di i1
    // inserisco (a,b,c,d) come (i2,i1,v2,v1)
    // 4)
    //    v1--normal
    //    |  /
    //    | /
    //    |/
    //    i1
    // in questa situazione ossia i1 è minore di v1 e la normale di v1 è minore di v1
    // inserisco (a,b,c,d) come (v2,v1,i2,i1)

    //soluzione semplice
    //
    // posso verificare se il quad di che apartiene a i1-i2 o v1-v2 abbia un linea
    // in i1-v2 o v1-i2, nel primo caso paso come (abcd) (v1,v2,i1,i2);
    // nel secondo caso paso come (abcd) (v2,v1,i2,i1)
    //
    //


    // passo 1: trovo il quad che apartiene alla linea i1-i2
    //

    pl3d_face4_struct qf=_mesh->_quad.first();
    while(qf)
    {

        if(qf->_l0==e || qf->_l1==e || qf->_l2==e || qf->_l3==e)
            break;

        qf=qf->next;
    }

    // in qf
    //
    //    _v0-_l0-_v1
    //    |         |
    //    |         |
    //   _l1       _l2
    //    |         |
    //    |         |
    //    _v2-_l3-_v3
    //
    //mi chieso se qf->_lf è 1. v0-v3 o 2. v1-v2
    //
    //
    //v1------v2
    //|  / \  |
    //|   |   |
    //|   |   |
    //i1------i2
    //
    //se 1. allora (a,b,c,d) (v2,v1,i2,i1)
    //
    //se 2. allora (a,b,c,d) (v1,v2,i1,i2)

    if(qf->_lf->v0==qf->_v0 && qf->_lf->v1==qf->_v2)
        _mesh->addquad(v2,v1,i2,i1,abcdCW);
    else
        _mesh->addquad(v1,v2,i1,i2,abcdCW);

    //add edges v1-i1 v1-v2 v2-i2 v2-i1
    _ladded.push_back(_mesh->_edges.index(v1,v2));

    /*_mesh->addedge(v1,v2);//first for the index of previus function


    _mesh->addedge(v1,i1);
    _mesh->addedge(v2,i2);
    _mesh->addedge(v2,i2);

    q->_erase=false;
    q->_selected=false;

    //
    //v1------v2
    //|  / \  |
    //|   |   |
    //|   |   |
    //i1------i2
    //
    q->_v0=v1;
    q->_v1=v2;
    q->_v2=i2;
    q->_v3=i1;

    q->_pv0=_mesh->_vertex.find(v1);
    q->_pv1=_mesh->_vertex.find(v2);
    q->_pv2=_mesh->_vertex.find(i2);
    q->_pv3=_mesh->_vertex.find(i1);


    q->_f0=_mesh->_faces.find(numf);
    q->_f1=_mesh->_faces.find(numf+1);

    q->_l0=_mesh->_edges.find(v1,v2);
    q->_l1=_mesh->_edges.find(v2,i2);
    q->_l2=_mesh->_edges.find(i2,i1);
    q->_l3=_mesh->_edges.find(i1,v1);

    _mesh->_quad.add(q);

    */
    //AddPoligon(v1,v2,i1,i2);

    //m_poly4[ip].setline(nl,nl+1,nl+2,nl+3); to-do

    //RemoveDoubleLines();











}
void l3d_modifier_extrude::extrudequad(l3d_uint iq)
{

    l3d_uint v0,v1,v2,v3,lastv;
    l3d_uint v10,v11,v12,v13;
    pl3d_vertex_fast vv0,vv1,vv2,vv3;
    pl3d_face4_struct quad=_mesh->_quad.find(iq);

    //se non esiste esci dalla funzione

    if(!quad)
        return;

    //deseleziono il quad

    quad->selected(false);

    //prelevo gli indici dei vertici del quad
    v0=quad->_v0;
    v1=quad->_v1;
    v2=quad->_v2;
    v3=quad->_v3;

    //prelevo i vertici associati agli indici

    vv0=quad->_pv0;
    vv1=quad->_pv1;
    vv2=quad->_pv2;
    vv3=quad->_pv3;

    //imposto i vertici a false

    vv0->selected(false);
    vv1->selected(false);
    vv2->selected(false);
    vv3->selected(false);

    //deseleziono le linee del quad

    quad->_l0->selected(false);
    quad->_l1->selected(false);
    quad->_l2->selected(false);
    quad->_l3->selected(false);

    //lastv contiene l'indice del primo vertice inserito
    lastv=_mesh->_vertex.size();
    v10=lastv;
    v11=lastv+1;
    v12=lastv+2;
    v13=lastv+3;

    //aggiungo quattro vertici copiandoli da vv0,vv1,vv2,vv3
    pl3d_vertex_fast appv= new l3d_vertex_fast;

    *appv=*vv0;

    _mesh->_vertex.add(appv);

    *appv=*vv1;

    _mesh->_vertex.add(appv);

    *appv=*vv2;

    _mesh->_vertex.add(appv);

    *appv=*vv3;

    _mesh->_vertex.add(appv);

    //
    //
    //   v13-------v12
    //   / |      /|
    //  /  |     / |
    // /  v3    /  |
    //v10-----v11 v2
    //|       |   /
    //|       |  /
    //|       | /
    //v0------v1
    //
    //aggiungo i quad ed elimino il quad estruso

    quad->_erase=true;//elimino

    //primo quad v0,v1,v10,v11 CW a=v0, b=v1, c=v10, d=v11
    _mesh->addquad(v0,v1,v10,v11,abcdCW);

    //secondo quad v1,v2,v11,v12 CW a=v1, b=v2, c=v11, d=v12
    _mesh->addquad(v1,v2,v11,v12,abcdCW);

    //terzo quad v2,v3,v12,v13 CW a=v2, b=v3, c=v12, d=v13
    _mesh->addquad(v2,v3,v12,v13,abcdCW);


    //quarto quad v3,v0,v13,v10 CW a=v3, b=v0, c=v13, d=v10
    _mesh->addquad(v3,v0,v13,v10,abcdCW);

    //aggiungo alla lista _qadded il piano superiore

    _qadded.push_back(_mesh->_quad.size());

    //aggiungo ultimo quad quello in alto v13,v12,v10,v11 CW a=v13,b=v12,c=v10,d=v11
    _mesh->addquad(v10,v11,v13,v12,abcdCW);

    //aggiungo alla lista _ladded le linee da selezionare

    _ladded.push_back(_mesh->_edges.index(v10,v11));
    _ladded.push_back(_mesh->_edges.index(v11,v12));
    _ladded.push_back(_mesh->_edges.index(v12,v13));
    _ladded.push_back(_mesh->_edges.index(v13,v10));













}
void l3d_modifier_extrude::extrudequad()
{
    std::list<int> qper;
    std::list<int>::iterator it;
    l3d_uint lsize2=_mesh->_quad.size();


    makeindex_quads();

    _ladded.clear();
    _qadded.clear();

    //verifico se tutti i quad sono stati selezionati

    if(isquadall())
    {
        //extrudo tutti i quad separatamente senza collegarli
        for(int ix=0; ix<lsize2;ix++)
        {
            extrudequad(ix);

            //seleziono linee e quad per il movimento





        }
        for(it=_ladded.begin();it!=_ladded.end();++it)
        {
            pl3d_line_struct pl2=_mesh->_edges.find((*it));
            pl2->selected(true);

            _mesh->_vertex.find(pl2->v0)->selected(true);
            _mesh->_vertex.find(pl2->v1)->selected(true);


        }

        for(it=_qadded.begin();it!=_qadded.end();++it)
        {
            pl3d_face4_struct q=_mesh->_quad.find((*it));

            q->selected(true);

        }
        //esco dalla funzione
        return;

    }
    pl3d_face4_struct q=_mesh->_quad.find(0);
    l3d_uint ix=0;
    while(q)
    {
        if(q->selected())
        {
            if(isquadalone(ix))
            {

                //extrudo il quad
                extrudequad(ix);


            }

            else

                //in questa situazione ho due o piu quad adiacenti selezionati

            {


            }


        }
        ix++;
        q=q->next;
    }
    //seleziono linee, vertici e quad aggiunto
    for(it=_ladded.begin();it!=_ladded.end();++it)
    {
        pl3d_line_struct pl2=_mesh->_edges.find((*it));
        pl2->selected(true);

        _mesh->_vertex.find(pl2->v0)->selected(true);
        _mesh->_vertex.find(pl2->v1)->selected(true);


    }

    for(it=_qadded.begin();it!=_qadded.end();++it)
    {
        pl3d_face4_struct q=_mesh->_quad.find((*it));

        q->selected(true);

    }


}
std::list<int> l3d_modifier_extrude::find_edges(l3d_uint il)

{
    std::list<int> lret;
    lret.clear();

    //inserisco la linea per l'estrusione

    lret.push_back(il);

    //deseleziono la linea
    _mesh->_edges.find(il)->selected(false);


    bool fl=false,fl2=false,endline;

    int in=0,in2,iy;

    //iy punta alla linea selezionata

    iy=il;

    endline=false;

    //ciclo per selezionare le linee successive alla prima selezionata

    do
    {
        fl=false;
        fl2=false;
        in=0;

        //pl punta alla prima linea selezionata

        pl3d_line_struct pl=_mesh->_edges.find(iy);

        // verifica se c'è una linea successiva selezionata
        // sulla lista della prima linea del puntatore next
        //while(!fl && in< pl->nextsize())
        //    fl=_mesh->_edges.find(pl->getnext(in++))->selected();

        in2=0;
        // verifico se c'è una linea successiva selezionata
        // sulla lista della prima linea del puntatore prev

        //while(!fl2 && in2< pl->prevsize())
        //    fl2=_mesh->_edges.find(pl->getprev(in2++))->selected();


        // è presente una linea successiva o sulla lista
        // next o prev
        if(pl->nextsize()>0 || pl->prevsize()>0)
        {

            if(pl->nextsize()>0)//c'è una linea sulla lista next
            {
                //aggiungo la linea alla lista lper
                lret.push_back(pl->getnext(0));

                // imposto la linea a non selezionata
                _mesh->_edges.find(pl->getnext(0))->selected(false);

                //  m_line[m_line[iy].getnext(in-1)].selected(false);

                //imposto iy per il ciclo successivo alla linea trovata sul
                //puntatore next
                int iyold=iy;
                iy=pl->getnext(0);
                //elimino il link a pl sulla linea iy

                pl3d_line_struct ll=_mesh->_edges.find(iy);

                if(ll->getnext(0)==iyold)
                    ll->delnext(0);

                if(ll->getprev(0)==iyold)
                    ll->delprev(0);


            }
            if(pl->prevsize()>0)// c'è una linea sulla lista prev
            {
                //aggiungo la linea alla lista lper
                lret.push_back(pl->getprev(0));

                //imposto la linea trovata
                //a selezione false per ciclo successivo

                _mesh->_edges.find(pl->getprev(0))->selected(false);

                //  m_line[m_line[iy].getprev(in2-1)].selected(false);

                //imposto iy alla linea trovata sulla lista
                //prev per cilco successivo
                int iyold=iy;
                iy=pl->getprev(0);

                pl3d_line_struct ll=_mesh->_edges.find(iy);

                if(ll->getnext(0)==iyold)
                    ll->delnext(0);

                if(ll->getprev(0)==iyold)
                    ll->delprev(0);


            }

            //reimposto pl a puntare sulla linea trovata
            //sulla lista next o prev
            //per verificare se si tratta della linea finale
            //aperta o chiusa

            pl=_mesh->_edges.find(iy);

            in=0;

            fl = (pl->nextsize()>0);
            fl2= (pl->prevsize()>0);

            //verifico se esiste sulla lista next una linea selezionata
            //while(!fl && in<pl->nextsize())
            //    fl=_mesh->_edges.find(pl->getnext(in++))->selected();

            //in2=0;

            //fl2=false;

            //verifico se esiste sulla lista prev una linea selezonata
            //while(!fl2 && in2< pl->prevsize())
            //    fl2=_mesh->_edges.find(pl->getprev(in2++))->selected();

            if(!fl && !fl2)// se non ci sono linee selezionate sulle liste
                            //prev o next esco dal ciclo

                endline=true;

            pl->selected(false);


        }



    }while(!endline);

    return(lret);

}

void l3d_modifier_extrude::extrudeedge()
{

    std::list<int> lper;
    std::list<int>::iterator it;
    int nsize=_mesh->_edges.size()+2;
    int lsize2=_mesh->_edges.size();

    makeindex_edges();

    _ladded.clear();
    if(isedgeall()&& (_mesh->_quad.size()>0 && _mesh->_faces.size()>0) )
    {





        for(int ix=0; ix<lsize2;ix++)
        {
            extrudeedge(ix);



        }
        for(it=_ladded.begin();it!=_ladded.end();++it)
        {
            pl3d_line_struct pl2=_mesh->_edges.find((*it));
            pl2->selected(true);

            _mesh->_vertex.find(pl2->v0)->selected(true);
            _mesh->_vertex.find(pl2->v1)->selected(true);


        }
        return;





    }
    int lsize,esize=_mesh->_edges.size();
    //lfinal.clear();
    for(int ix=0; ix<esize;ix++)
    {
        pl3d_line_struct pl=_mesh->_edges.find(ix);
        if(pl->selected())
        {
        //verificare se la linea è singola

            lsize=_mesh->_edges.size();

            pl->selected(false);

            if(isedgealone(ix))
            {

                //_ladded.push_back(lsize);
                nsize+=4;
                extrudeedge(ix);

            }
            else if ( isedgealone_sin(ix) || isedgealone_des(ix))
                //la linea è selezionata e ha a sinistra o a destra
                //un'altra linea selezionata
            {



                lper=find_edges(ix);
                //extrudo la lista delle linee trovate

                extrudeedge(lper);
                for(it=lper.begin();it!=lper.end();++it)
                {
                    //lfinal.push_back((*it));
                    _mesh->_edges.find((*it))->selected(false);

                }

            }

            else if(isedge_perimeter(ix))

            {
                extrudeedge_perimeter(_ledge_perimeter);
                for(it=_ledge_perimeter.begin();it!=_ledge_perimeter.end();++it)
                {
                    _mesh->_edges.find((*it))->selected(false);
                }

            }



        }

    }
    for(it=_ladded.begin();it!=_ladded.end();++it)
    {
        pl3d_line_struct pl2=_mesh->_edges.find((*it));
        pl2->selected(true);

        _mesh->_vertex.find(pl2->v0)->selected(true);
        _mesh->_vertex.find(pl2->v1)->selected(true);
        //pl2->_v0->selected(true);
        //pl2->_v1->selected(true);

    }

}
