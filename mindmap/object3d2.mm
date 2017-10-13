<map version="0.9.0">
<!-- To view this file, download free mind mapping software FreeMind from http://freemind.sourceforge.net -->
<node CREATED="1352905264723" ID="ID_1219618491" MODIFIED="1352905985365">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      <b><font size="5" color="#3333ff">Look3D:</font><font size="5" color="#ff3333">&#160;</font><font size="5" color="#6633ff">Mesh </font></b>
    </p>
    <table style="border-left-width: 0; border-top-style: solid; border-left-style: solid; border-top-width: 0; border-bottom-style: solid; border-right-style: solid; border-right-width: 0; border-bottom-width: 0; width: 80%" border="0">
      <tr>
        <td style="border-left-width: 1; border-top-style: solid; border-left-style: solid; border-top-width: 1; border-bottom-style: solid; border-right-style: solid; border-right-width: 1; border-bottom-width: 1; width: 50%" valign="top">
          <p style="margin-right: 1; margin-left: 1; margin-top: 1; margin-bottom: 1">
            Nome classe
          </p>
        </td>
        <td style="border-left-width: 1; border-top-style: solid; border-left-style: solid; border-top-width: 1; border-bottom-style: solid; border-right-style: solid; border-right-width: 1; border-bottom-width: 1; width: 50%" valign="top">
          <p style="margin-right: 1; margin-left: 1; margin-top: 1; margin-bottom: 1">
            object3d
          </p>
        </td>
      </tr>
      <tr>
        <td style="border-left-width: 1; border-top-style: solid; border-left-style: solid; border-top-width: 1; border-bottom-style: solid; border-right-style: solid; border-right-width: 1; border-bottom-width: 1; width: 50%" valign="top">
          <p style="margin-right: 1; margin-left: 1; margin-top: 1; margin-bottom: 1">
            scopo
          </p>
        </td>
        <td style="border-left-width: 1; border-top-style: solid; border-left-style: solid; border-top-width: 1; border-bottom-style: solid; border-right-style: solid; border-right-width: 1; border-bottom-width: 1; width: 50%" valign="top">
          <p style="margin-right: 1; margin-left: 1; margin-top: 1; margin-bottom: 1">
            creazione di una mesh
          </p>
        </td>
      </tr>
      <tr>
        <td style="border-left-width: 1; border-top-style: solid; border-left-style: solid; border-top-width: 1; border-bottom-style: solid; border-right-style: solid; border-right-width: 1; border-bottom-width: 1; width: 50%" valign="top">
          <p style="margin-right: 1; margin-left: 1; margin-top: 1; margin-bottom: 1">
            
          </p>
        </td>
        <td style="border-left-width: 1; border-top-style: solid; border-left-style: solid; border-top-width: 1; border-bottom-style: solid; border-right-style: solid; border-right-width: 1; border-bottom-width: 1; width: 50%" valign="top">
          <p style="margin-right: 1; margin-left: 1; margin-top: 1; margin-bottom: 1">
            
          </p>
        </td>
      </tr>
    </table>
  </body>
</html>
</richcontent>
<attribute_layout NAME_WIDTH="64" VALUE_WIDTH="380"/>
<attribute NAME="Files" VALUE="object3d.h,object3d.cpp"/>
<attribute NAME="Classe base" VALUE="&lt;none&gt;"/>
<attribute NAME="Descrizione" VALUE="descrive una mesh  tramite strutture e classi"/>
<node CREATED="1352906221794" HGAP="108" ID="ID_776302123" MODIFIED="1352918451137" POSITION="right" TEXT="Struttura della classe" VSHIFT="-422">
<node CREATED="1352918488190" HGAP="46" ID="ID_637948617" MODIFIED="1352918503283" TEXT="propriet&#xe0;" VSHIFT="-107">
<node CREATED="1352918494102" HGAP="41" ID="ID_576012446" MODIFIED="1352918505872" TEXT="private" VSHIFT="-98">
<node COLOR="#00cccc" CREATED="1352907168355" HGAP="279" ID="ID_1361899889" MODIFIED="1352918582337" VSHIFT="193">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      <font size="3" color="#333300">std::vextor&lt;vertex&gt; local_vertex</font>
    </p>
  </body>
</html>
</richcontent>
<node CREATED="1352907201046" HGAP="60" ID="ID_777684837" LINK="vertex.mm" MODIFIED="1352918433488" TEXT="Mappa della classe vertex" VSHIFT="-170">
<cloud/>
</node>
<node CREATED="1352907257796" HGAP="102" ID="ID_1314024230" MODIFIED="1352918433488" TEXT="a cosa serve?" VSHIFT="6">
<icon BUILTIN="help"/>
<node CREATED="1352907271973" HGAP="66" ID="ID_201098174" MODIFIED="1352918433488" TEXT="Rappresenta i vertici della mesh in coordinate 3d (x,y,z)." VSHIFT="-84">
<icon BUILTIN="full-1"/>
</node>
<node CREATED="1352907302639" HGAP="76" ID="ID_62502006" MODIFIED="1352918433489" TEXT="ogni vertice &#xe8; rappresentato da tre valori float" VSHIFT="69">
<icon BUILTIN="full-2"/>
</node>
</node>
<node CREATED="1352907411869" HGAP="97" ID="ID_1838318056" MODIFIED="1352918433489" TEXT="perch&#xe8; utilizza un vector?" VSHIFT="117">
<icon BUILTIN="help"/>
<node CREATED="1352907430896" HGAP="65" ID="ID_1864755175" MODIFIED="1352918433489" TEXT="Per la trasportabilit&#xe0; del codice." VSHIFT="48">
<icon BUILTIN="xmag"/>
</node>
</node>
</node>
<node CREATED="1352907796448" HGAP="289" ID="ID_1772481571" MODIFIED="1352918586414" TEXT="std::vector&lt;line&gt; m_line" VSHIFT="-753">
<node CREATED="1352907829520" HGAP="204" ID="ID_943938634" MODIFIED="1352918433489" TEXT="a cosa serve?" VSHIFT="-56">
<icon BUILTIN="help"/>
<node CREATED="1352907848217" HGAP="41" ID="ID_201201936" MODIFIED="1352918433489" TEXT="rappresenta le linee della mesh" VSHIFT="-97">
<icon BUILTIN="full-1"/>
</node>
<node CREATED="1352907871173" HGAP="37" ID="ID_649393796" MODIFIED="1352918433489" TEXT="ogni linea contiene l&apos;indice dei vertici per formare una linea." VSHIFT="81">
<icon BUILTIN="full-2"/>
</node>
<node CREATED="1352907919056" HGAP="67" ID="ID_758978660" LINK="line.mm" MODIFIED="1352920240161" TEXT="Mappa della classe line." VSHIFT="92">
<cloud/>
</node>
</node>
</node>
</node>
</node>
</node>
</node>
</map>
