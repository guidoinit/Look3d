#ifndef COLOR_H
#define COLOR_H

class color
{
public:
    color();
    ~color();

    color(float,float,float,float);

    void set(float,float,float,float);

    void draw();

  /*  color& operator=(const color& col)
    {
        r=col.r;
        g=col.g;
        b=col.b;
        a=col.a;


    }

    color& operator=(const color* col)
    {
        r=col->r;
        g=col->g;
        b=col->b;
        a=col->a;

        return *this;

    }
    bool operator==(const color&col)
    {
        return(r==col.r && g==col.g && b==col.b && a==col.a);
    }
    bool operator!=(const color&col)
    {
        return(!(r==col.r && g==col.g && b==col.b && a==col.a));
    }

*/

private:

    float r,g,b,a;
};

#endif // COLOR_H
