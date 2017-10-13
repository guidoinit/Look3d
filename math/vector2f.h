 /*Title:
      mjbWorld
   Copyright (c) 1998-2007 Martin John BakerThis program is free software; you can redistribute it and/or
   modify it under the terms of the GNU General public: License
   as published by the Free Software Foundation; either version 2
   of the License, or (at your option) any later version.This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
   GNU General public: License for more details.For information about the GNU General public: License see http://www.gnu.org/To discuss this program http://sourceforge.net/forum/forum.php?forum_id=122133
   also see website http://www.euclideanspace.com/
   *//*
   for theory see:
   http://www.euclideanspace.com/maths/vectors/index.htm    */

   #include <string>

    using namespace std;
   class vector2f
       {
       // double x,y;
        //static bool saveAsDouble = false ;
        public: double x;
        public: double y;
        //public:  clone();
        //public:  createArray(int size)[];
        //public:  get(int inst,nodeBean* nb); public: void set(property* in,int inst);
        public: string * outstring(int format);
        public: bool Equals(vector2f* v2);
       /** write to file
        * filter = information about output
           * mode values
           * 0 - output VRML97 modified values
           * 1 - output VRML97 original values
           * 2 - output xml (x3d)
           * 3 - output attribute in brackets
           * 4 - output with f prefix
           */

        //public: void write(filter* f,int mode,int indent);
        public: string* toStatic();
       /** used by mfparam.vrml2par
       */
        /** output as a string
        * mode values
        * 0 - output modified values
        * 1 - output original values
        * 2 - output attribute
        * 3 - output attribute in brackets
        * 4 - output with f prefix
        */

       //public: bool instring(filter* f,sfparam* sfp,nodeBean* n,int mode); public: bool instring(filter* f,String* s1); public: static Type* getEditClass()
       //{
            //return __typeof(sfvec2fEditor);
       //}
       // VRML only supports float but allow override if higher resolution required public: sfvec2f(); public: sfvec2f(float x1,float y1); public: sfvec2f(sfvec2f* p);// public: sfvec2f(Point2f p); public: String* vrmlType(); public: static String* vrmlType_s(){






 };
