<map version="0.9.0">
<!-- To view this file, download free mind mapping software FreeMind from http://freemind.sourceforge.net -->
<node CREATED="1352909980611" ID="ID_1947950172" MODIFIED="1352909990030" TEXT="Bone">
<node CREATED="1352913728555" HGAP="268" ID="ID_1515236887" MODIFIED="1352922246383" POSITION="right" TEXT="A cosa serve?" VSHIFT="209">
<icon BUILTIN="help"/>
<node CREATED="1352913743347" HGAP="65" ID="ID_937460295" MODIFIED="1352913763498" TEXT="Rappresenta una bone" VSHIFT="-100">
<icon BUILTIN="full-1"/>
</node>
<node CREATED="1352913748851" HGAP="78" ID="ID_1356964785" MODIFIED="1352913779219" TEXT="DIsegna una bone" VSHIFT="-77">
<icon BUILTIN="full-2"/>
</node>
</node>
<node CREATED="1352913786369" HGAP="96" ID="ID_1923168957" MODIFIED="1352913819329" POSITION="right" TEXT="Struttura della classe" VSHIFT="-59">
<node CREATED="1352922080571" HGAP="68" ID="ID_779393595" MODIFIED="1352922242079" TEXT="propriet&#xe0;" VSHIFT="79">
<node CREATED="1352922086633" HGAP="51" ID="ID_409025905" MODIFIED="1352922118683" TEXT="private" VSHIFT="-137">
<node CREATED="1352913847813" ID="ID_1675597279" MODIFIED="1352922119528" TEXT="join * _first;">
<node CREATED="1352913934464" ID="ID_855467015" MODIFIED="1352913976571" TEXT="rappresenta la prima join">
<icon BUILTIN="help"/>
</node>
</node>
<node CREATED="1352913849175" ID="ID_1410880394" MODIFIED="1352913905316" TEXT="join * _second;">
<node CREATED="1352913935465" ID="ID_61595057" MODIFIED="1352913985694" TEXT="rappresenta la seconda join">
<icon BUILTIN="help"/>
</node>
</node>
<node CREATED="1352913850161" ID="ID_1596435993" MODIFIED="1352913913144" TEXT="list&lt;bone*&gt; _next;">
<node CREATED="1352913936473" ID="ID_1676727735" MODIFIED="1352914005582" TEXT="rappresentta le bone successiva">
<icon BUILTIN="help"/>
</node>
</node>
<node CREATED="1352913851030" ID="ID_679678559" MODIFIED="1352913922955" TEXT="bbox * _box;">
<node CREATED="1352913939464" ID="ID_1818448167" MODIFIED="1352914031131" TEXT="rappresenta una box per lo schinning dei vertici">
<icon BUILTIN="help"/>
</node>
</node>
<node CREATED="1352913851930" ID="ID_867998584" MODIFIED="1352913931824" TEXT="int _id;">
<node CREATED="1352913940517" ID="ID_1518692839" MODIFIED="1352914043198" TEXT="rappresenta la bone">
<icon BUILTIN="help"/>
</node>
</node>
</node>
</node>
<node CREATED="1352913801021" HGAP="112" ID="ID_1905293195" MODIFIED="1352922197388" TEXT="Metodi " VSHIFT="-191">
<node CREATED="1352913823050" HGAP="57" ID="ID_696661338" MODIFIED="1352914529031" TEXT="pubblici" VSHIFT="-39">
<node CREATED="1352914121763" ID="ID_314583085" MODIFIED="1352914141133" TEXT="void addnext(bone *,int);">
<node CREATED="1352914260170" ID="ID_995743148" MODIFIED="1352914379807" TEXT="aggiunge una bone">
<icon BUILTIN="help"/>
</node>
</node>
<node CREATED="1352914122881" ID="ID_288577191" MODIFIED="1352914148804" TEXT="void setbox(bbox *); ">
<node CREATED="1352914261322" ID="ID_1607918362" MODIFIED="1352914389220" TEXT="imposta il box della bone">
<icon BUILTIN="help"/>
</node>
</node>
<node CREATED="1352914123894" ID="ID_1925075479" MODIFIED="1352914156388" TEXT=" void setid(int);">
<node CREATED="1352914262265" ID="ID_243394579" MODIFIED="1352914399140" TEXT="imposta lidentificativo">
<icon BUILTIN="help"/>
</node>
</node>
<node CREATED="1352914124766" ID="ID_1988285740" MODIFIED="1352914165960" TEXT="void setid(bone *,int id); ">
<node CREATED="1352914263182" ID="ID_1091298492" MODIFIED="1352914422134" TEXT="imposta l&apos;identificativo ad una bone nell&apos;albero">
<icon BUILTIN="help"/>
</node>
</node>
<node CREATED="1352914125540" ID="ID_869537094" MODIFIED="1352914175382" TEXT="void draw(bone*,object3d*,object3d*);">
<node CREATED="1352914264033" ID="ID_602728581" MODIFIED="1352914438932" TEXT="disegna la bone e tutte le bone successive">
<icon BUILTIN="help"/>
</node>
</node>
<node CREATED="1352914126257" ID="ID_742773115" MODIFIED="1352914183873" TEXT="void draw_select();">
<node CREATED="1352914264762" ID="ID_1295345677" MODIFIED="1352914452747" TEXT="disegna per la selezione o picking">
<icon BUILTIN="help"/>
</node>
</node>
<node CREATED="1352914126925" ID="ID_1799416613" MODIFIED="1352914190615" TEXT="bool find(bone *,int);">
<node CREATED="1352914265574" ID="ID_50787103" MODIFIED="1352914469317" TEXT="cerca una bone sottostante">
<icon BUILTIN="help"/>
</node>
</node>
<node CREATED="1352914127622" ID="ID_1190989932" MODIFIED="1352914198902" TEXT="bone * get(bone *,int id); ">
<node CREATED="1352914267250" ID="ID_1352850825" MODIFIED="1352914486767" TEXT="ritorna una bone sottostante in base all&apos;identificativo">
<icon BUILTIN="help"/>
</node>
</node>
</node>
<node CREATED="1352914220879" HGAP="60" ID="ID_801055676" MODIFIED="1352914523458" TEXT="costruttori" VSHIFT="-43">
<node CREATED="1352914235669" ID="ID_712415978" MODIFIED="1352914332495" TEXT="bone();">
<node CREATED="1352914255851" ID="ID_223405762" MODIFIED="1352914341761" TEXT="costruttore standard">
<icon BUILTIN="help"/>
</node>
</node>
<node CREATED="1352914246659" ID="ID_1243455270" MODIFIED="1352914318302" TEXT="bone(join*,join*);">
<node CREATED="1352914247988" ID="ID_1815595959" MODIFIED="1352914355531" TEXT="con due join">
<icon BUILTIN="help"/>
</node>
</node>
<node CREATED="1352914252217" ID="ID_1069030319" MODIFIED="1352914327952" TEXT="bone(join*,join*,int);">
<node CREATED="1352914258133" ID="ID_1574785772" MODIFIED="1352914367918" TEXT="con due join e l&apos;idenificativo">
<icon BUILTIN="help"/>
</node>
</node>
</node>
</node>
<node CREATED="1352922103941" HGAP="152" ID="ID_585158101" MODIFIED="1352922165268" TEXT="riferimenti" VSHIFT="-87">
<node CREATED="1352914052759" HGAP="181" ID="ID_1506407944" LINK="Join.mm" MODIFIED="1352922169088" TEXT="classe join" VSHIFT="11">
<cloud/>
</node>
<node CREATED="1352915062438" HGAP="175" ID="ID_1745188390" LINK="vertex.mm" MODIFIED="1352922171751" TEXT="classe vertex" VSHIFT="30">
<cloud/>
</node>
</node>
</node>
<node CREATED="1352917460882" HGAP="114" ID="ID_185652490" MODIFIED="1352922217524" POSITION="left" TEXT="Classi che la utilizzano" VSHIFT="-168">
<node CREATED="1352917475786" HGAP="82" ID="ID_1957798381" LINK="animatedmesh2.mm" MODIFIED="1352922599070" TEXT="animatedmesh" VSHIFT="-104">
<cloud/>
</node>
</node>
</node>
</map>
