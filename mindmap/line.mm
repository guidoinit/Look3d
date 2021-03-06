<map version="0.9.0">
<!-- To view this file, download free mind mapping software FreeMind from http://freemind.sourceforge.net -->
<node CREATED="1352907958148" ID="ID_14439913" MODIFIED="1352907972901" TEXT="Classe line">
<node CREATED="1352916813645" HGAP="46" ID="ID_1066001338" MODIFIED="1352916825728" POSITION="right" TEXT="A cosa serve?" VSHIFT="-181">
<icon BUILTIN="help"/>
<node CREATED="1352916827054" HGAP="73" ID="ID_950680167" MODIFIED="1352916849125" TEXT="Rappresenta una linea attrvaerso l&apos;indice di due vertici" VSHIFT="-103">
<icon BUILTIN="full-1"/>
</node>
<node CREATED="1352916850604" HGAP="85" ID="ID_960055325" MODIFIED="1352916871332" TEXT="Disegna le linee degli oggetti" VSHIFT="-57">
<icon BUILTIN="full-2"/>
</node>
</node>
<node CREATED="1352916875437" HGAP="85" ID="ID_1392171740" MODIFIED="1352916884820" POSITION="right" TEXT="Struttura della classe" VSHIFT="-20">
<node CREATED="1352916885608" HGAP="82" ID="ID_1052744314" MODIFIED="1352917011112" TEXT="propriet&#xe0;" VSHIFT="-61">
<node CREATED="1352916906270" HGAP="51" ID="ID_1953941280" MODIFIED="1352917009758" TEXT="private" VSHIFT="-49">
<node CREATED="1352916944950" ID="ID_802044964" MODIFIED="1352916946935" TEXT="int m_vertice[2];">
<node CREATED="1352917014714" ID="ID_360611234" MODIFIED="1352917040165" TEXT="contiene gli indici dei vertici">
<icon BUILTIN="help"/>
</node>
</node>
<node CREATED="1352916955823" ID="ID_848761184" MODIFIED="1352916957547" TEXT="int m_iname;">
<node CREATED="1352917016380" ID="ID_1771470229" MODIFIED="1352917056966" TEXT="contiene il nome della linea per il picking">
<icon BUILTIN="help"/>
</node>
</node>
<node CREATED="1352916965790" ID="ID_57147846" MODIFIED="1352916967849" TEXT="bool m_bselected;">
<node CREATED="1352917017213" ID="ID_1620661839" MODIFIED="1352917069202" TEXT="selezione della linea">
<icon BUILTIN="help"/>
</node>
</node>
<node CREATED="1352916978100" ID="ID_1110391781" MODIFIED="1352916979682" TEXT="std::list&lt;int&gt; m_next;">
<node CREATED="1352917018182" ID="ID_1308411550" MODIFIED="1352917084914" TEXT="lista alle linee successive con stesso vertice">
<icon BUILTIN="help"/>
</node>
</node>
<node CREATED="1352916988474" ID="ID_594824462" MODIFIED="1352916990146" TEXT="std::list&lt;int&gt; m_prev;">
<node CREATED="1352917019120" ID="ID_1009750149" MODIFIED="1352917102978" TEXT="lista lineee precedenti con stesso vertice">
<icon BUILTIN="help"/>
</node>
</node>
</node>
</node>
<node CREATED="1352917109445" HGAP="97" ID="ID_444905538" MODIFIED="1352917124796" TEXT="metodi" VSHIFT="10">
<node CREATED="1352917113940" HGAP="77" ID="ID_837173170" MODIFIED="1352917121672" TEXT="pubblici" VSHIFT="37">
<node CREATED="1352917127770" ID="ID_1963519240" MODIFIED="1352917138975" TEXT="void clear_np();">
<node CREATED="1352917298075" ID="ID_437137651" MODIFIED="1352917343753" TEXT="">
<icon BUILTIN="help"/>
</node>
</node>
<node CREATED="1352917147041" ID="ID_938104112" MODIFIED="1352917148724" TEXT="void addnext(int);">
<node CREATED="1352917299538" ID="ID_920597284" MODIFIED="1352917343753" TEXT="">
<icon BUILTIN="help"/>
</node>
</node>
<node CREATED="1352917156414" ID="ID_350975690" MODIFIED="1352917158142" TEXT="void addprev(int);">
<node CREATED="1352917300281" ID="ID_305958556" MODIFIED="1352917343752" TEXT="">
<icon BUILTIN="help"/>
</node>
</node>
<node CREATED="1352917164599" ID="ID_701549051" MODIFIED="1352917167916" TEXT="int nextsize();">
<node CREATED="1352917301114" ID="ID_290436120" MODIFIED="1352917343752" TEXT="">
<icon BUILTIN="help"/>
</node>
</node>
<node CREATED="1352917173889" ID="ID_1030958380" MODIFIED="1352917176488" TEXT="int prevsize();">
<node CREATED="1352917301882" ID="ID_1395921051" MODIFIED="1352917343752" TEXT="">
<icon BUILTIN="help"/>
</node>
</node>
<node CREATED="1352917185609" ID="ID_1925634459" MODIFIED="1352917187067" TEXT="int getnext(int value);">
<node CREATED="1352917302511" ID="ID_786560563" MODIFIED="1352917343752" TEXT="">
<icon BUILTIN="help"/>
</node>
</node>
<node CREATED="1352917194269" ID="ID_241688781" MODIFIED="1352917195685" TEXT="int getprev(int value);">
<node CREATED="1352917303377" ID="ID_1046229353" MODIFIED="1352917343752" TEXT="">
<icon BUILTIN="help"/>
</node>
</node>
<node CREATED="1352917201614" ID="ID_510996205" MODIFIED="1352917204681" TEXT="void SetLine(int,int);">
<node CREATED="1352917304092" ID="ID_917345064" MODIFIED="1352917343752" TEXT="">
<icon BUILTIN="help"/>
</node>
</node>
<node CREATED="1352917212765" ID="ID_1718301862" MODIFIED="1352917214956" TEXT="void SetName(int);">
<node CREATED="1352917304755" ID="ID_897056401" MODIFIED="1352917343751" TEXT="">
<icon BUILTIN="help"/>
</node>
</node>
<node CREATED="1352917222167" ID="ID_1140212102" MODIFIED="1352917223555" TEXT="int GetName();">
<node CREATED="1352917305504" ID="ID_927634276" MODIFIED="1352917343751" TEXT="">
<icon BUILTIN="help"/>
</node>
</node>
<node CREATED="1352917229472" ID="ID_1017525175" MODIFIED="1352917230953" TEXT="int GetVertice(int);">
<node CREATED="1352917306374" ID="ID_27983108" MODIFIED="1352917343751" TEXT="">
<icon BUILTIN="help"/>
</node>
</node>
<node CREATED="1352917237913" ID="ID_863673158" MODIFIED="1352917239306" TEXT="void SetSelected(bool);">
<node CREATED="1352917307039" ID="ID_619031138" MODIFIED="1352917343751" TEXT="">
<icon BUILTIN="help"/>
</node>
</node>
<node CREATED="1352917250338" ID="ID_1153105314" MODIFIED="1352917251893" TEXT="bool selected();">
<node CREATED="1352917308157" ID="ID_482198637" MODIFIED="1352917343751" TEXT="">
<icon BUILTIN="help"/>
</node>
</node>
<node CREATED="1352917258486" ID="ID_983634816" MODIFIED="1352917260843" TEXT="void selected(bool value);">
<node CREATED="1352917309095" ID="ID_1489562857" MODIFIED="1352917343750" TEXT="">
<icon BUILTIN="help"/>
</node>
</node>
<node CREATED="1352917266800" ID="ID_869188419" MODIFIED="1352917268140" TEXT="bool IsSelected();">
<node CREATED="1352917309986" ID="ID_1450910764" MODIFIED="1352917309986" TEXT=""/>
</node>
<node CREATED="1352917279647" ID="ID_1265325786" MODIFIED="1352917281392" TEXT="void serialize(std::ifstream*  ar)">
<node CREATED="1352917311165" ID="ID_238432405" MODIFIED="1352917343750" TEXT="">
<icon BUILTIN="help"/>
</node>
</node>
<node CREATED="1352917288335" ID="ID_1917720839" MODIFIED="1352917290082" TEXT="void serialize(std::ofstream*  ar)">
<node CREATED="1352917312274" ID="ID_1517687898" MODIFIED="1352917343750" TEXT="">
<icon BUILTIN="help"/>
</node>
</node>
</node>
</node>
<node CREATED="1352915062438" HGAP="60" ID="ID_1745188390" LINK="vertex.mm" MODIFIED="1352915093779" TEXT="classe vertex" VSHIFT="96">
<cloud/>
</node>
</node>
<node CREATED="1352916668381" HGAP="202" ID="ID_122401076" MODIFIED="1352916679263" POSITION="left" TEXT="Classi che ne fanno uso" VSHIFT="106">
<node CREATED="1352916682821" HGAP="161" ID="ID_1043771206" LINK="object3d2.mm" MODIFIED="1352916721018" TEXT="object3d" VSHIFT="-123">
<cloud/>
</node>
<node CREATED="1352916722770" HGAP="148" ID="ID_588366811" LINK="animatedmesh2.mm" MODIFIED="1352916743321" TEXT="animatedmesh" VSHIFT="-42">
<cloud/>
</node>
</node>
</node>
</map>
