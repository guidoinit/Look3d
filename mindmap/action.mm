<map version="0.9.0">
<!-- To view this file, download free mind mapping software FreeMind from http://freemind.sourceforge.net -->
<node CREATED="1352925323139" ID="ID_1550713714" MODIFIED="1352925332158" TEXT="action">
<node CREATED="1352925441391" HGAP="52" ID="ID_388002370" MODIFIED="1352925477952" POSITION="right" TEXT="Struttura della classe" VSHIFT="-92">
<node CREATED="1352925451156" HGAP="36" ID="ID_888088123" MODIFIED="1352925887979" TEXT="propriet&#xe0;" VSHIFT="-27">
<node CREATED="1352925456274" HGAP="39" ID="ID_1927128597" MODIFIED="1352925798888" TEXT="private" VSHIFT="-111">
<node CREATED="1352925460668" HGAP="22" ID="ID_1688031261" MODIFIED="1352925792291" TEXT="int m_nObject;" VSHIFT="-2">
<node CREATED="1352925463901" HGAP="60" ID="ID_1704195516" MODIFIED="1352925489366" TEXT="identifica un oggetto" VSHIFT="1">
<icon BUILTIN="help"/>
</node>
</node>
<node CREATED="1352925496526" ID="ID_106856705" MODIFIED="1352925505696" TEXT="int m_nframe;">
<node CREATED="1352925625172" ID="ID_1897234866" MODIFIED="1352925776845" TEXT="numero del frame">
<icon BUILTIN="help"/>
</node>
</node>
<node CREATED="1352925505909" ID="ID_866857460" MODIFIED="1352925514456" TEXT="float m_rangolo[3];">
<node CREATED="1352925627123" ID="ID_1516705571" MODIFIED="1352925776845" TEXT="valori della azione da compiere nella rotazione">
<icon BUILTIN="help"/>
</node>
</node>
<node CREATED="1352925514673" ID="ID_1937572740" MODIFIED="1352925525650" TEXT="float m_fsposta[3];">
<node CREATED="1352925627970" ID="ID_1332973299" MODIFIED="1352925776846" TEXT="valori della azione da compiere nella traslazione">
<icon BUILTIN="help"/>
</node>
</node>
<node CREATED="1352925613906" ID="ID_178729636" MODIFIED="1352925615713" TEXT="float m_fscala[3];">
<node CREATED="1352925628914" ID="ID_934321410" MODIFIED="1352925776846" TEXT="valori della azione da compiere nella scalatura">
<icon BUILTIN="help"/>
</node>
</node>
<node CREATED="1352925525881" ID="ID_476095820" MODIFIED="1352925536896" TEXT="vertex m_vsposta;">
<node CREATED="1352925629678" ID="ID_1541559169" MODIFIED="1352925776846" TEXT="">
<icon BUILTIN="help"/>
</node>
</node>
<node CREATED="1352925537150" ID="ID_1949046131" MODIFIED="1352925554085" TEXT="int m_nAction;">
<node CREATED="1352925630447" ID="ID_1076634500" MODIFIED="1352925776846" TEXT="identifica l&apos;azione">
<icon BUILTIN="help"/>
</node>
</node>
<node CREATED="1352925555013" ID="ID_1333263985" MODIFIED="1352925563615" TEXT="bool dirx,diry,dirz;">
<node CREATED="1352925631202" ID="ID_386263075" MODIFIED="1352925776846" TEXT="direzione dell&apos;azione">
<icon BUILTIN="help"/>
</node>
</node>
<node CREATED="1352925564062" ID="ID_1685924026" MODIFIED="1352925572934" TEXT="bool m_bhide;">
<node CREATED="1352925631931" ID="ID_455001087" MODIFIED="1352925776846" TEXT="azione di hide o di non visualizzazione">
<icon BUILTIN="help"/>
</node>
</node>
<node CREATED="1352925573160" ID="ID_1554610234" MODIFIED="1352925582084" TEXT="bool m_bkeyframe;">
<node CREATED="1352925632655" ID="ID_733178787" MODIFIED="1352925776846" TEXT="??">
<icon BUILTIN="help"/>
</node>
</node>
<node CREATED="1352925582394" ID="ID_1017066842" MODIFIED="1352925590747" TEXT="int q;">
<node CREATED="1352925633335" HGAP="88" ID="ID_1491109747" MODIFIED="1352925780798" TEXT="??" VSHIFT="2">
<icon BUILTIN="help"/>
</node>
</node>
<node CREATED="1352925591024" ID="ID_1185038177" MODIFIED="1352925599938" TEXT="float fq;">
<node CREATED="1352925634003" HGAP="75" ID="ID_506932302" MODIFIED="1352925783206" TEXT="??" VSHIFT="1">
<icon BUILTIN="help"/>
</node>
</node>
</node>
<node CREATED="1352925491196" ID="ID_1738695191" MODIFIED="1352925491196" TEXT=""/>
</node>
<node CREATED="1352925831820" HGAP="59" ID="ID_1365839438" MODIFIED="1352925885533" TEXT="metodi" VSHIFT="206">
<node CREATED="1352925836375" HGAP="19" ID="ID_1239476" MODIFIED="1352925882888" TEXT="pubblici" VSHIFT="-131">
<node CREATED="1352925846091" HGAP="19" ID="ID_767438291" MODIFIED="1352926201457" TEXT="void SetAction(int , vertex,float [],float [] );" VSHIFT="-5">
<node CREATED="1352925863053" ID="ID_1225111911" MODIFIED="1352925874337" TEXT="imposta il tipo di azione da compiere">
<icon BUILTIN="help"/>
</node>
</node>
<node CREATED="1352925891756" ID="ID_933008277" MODIFIED="1352925902561" TEXT="vertex GetVertex();">
<node CREATED="1352925903017" ID="ID_1287760860" MODIFIED="1352925929890" TEXT="ritorna il vertice dell&apos;azione">
<icon BUILTIN="help"/>
</node>
</node>
<node CREATED="1352925932660" ID="ID_541564195" MODIFIED="1352926195057" TEXT="float* GetAngoli();">
<node CREATED="1352925946986" ID="ID_1035009941" MODIFIED="1352925966431" TEXT="ritorna i valori per l&apos;azione di rotazione">
<icon BUILTIN="help"/>
</node>
</node>
<node CREATED="1352925969992" ID="ID_539814455" MODIFIED="1352926013334" TEXT="float* GetScale();">
<node CREATED="1352925986420" ID="ID_1622452269" MODIFIED="1352926000420" TEXT="ritorna i valori dell&apos;azione di scalatura">
<icon BUILTIN="help"/>
</node>
</node>
<node CREATED="1352926014602" ID="ID_74945832" MODIFIED="1352926015845" TEXT="void SetActionSposta(vertex );">
<node CREATED="1352926178603" ID="ID_568178513" MODIFIED="1352926178603" TEXT=""/>
</node>
<node CREATED="1352926024232" ID="ID_1962220826" MODIFIED="1352926025395" TEXT="void SetActionSposta(float[] );">
<node CREATED="1352926180147" ID="ID_749738271" MODIFIED="1352926180147" TEXT=""/>
</node>
<node CREATED="1352926033561" ID="ID_683664665" MODIFIED="1352926034751" TEXT=" void SetActionRuota(float[] ); ">
<node CREATED="1352926180911" ID="ID_252168263" MODIFIED="1352926180911" TEXT=""/>
</node>
<node CREATED="1352926035248" ID="ID_536290943" MODIFIED="1352926054270" TEXT="void SetActionHide(bool);">
<node CREATED="1352926181614" ID="ID_1896073532" MODIFIED="1352926181614" TEXT=""/>
</node>
<node CREATED="1352926042753" ID="ID_1515668562" MODIFIED="1352926046004" TEXT="void SetActionScala(float []); ">
<node CREATED="1352926182303" ID="ID_626583607" MODIFIED="1352926182303" TEXT=""/>
</node>
<node CREATED="1352926056764" ID="ID_1827816815" MODIFIED="1352926080792" TEXT="int GetSpostaDir();">
<node CREATED="1352926182922" ID="ID_1051108083" MODIFIED="1352926182922" TEXT=""/>
</node>
<node CREATED="1352926065002" ID="ID_1204136798" MODIFIED="1352926067026" TEXT="int GetAction(); ">
<node CREATED="1352926183634" ID="ID_982394376" MODIFIED="1352926183634" TEXT=""/>
</node>
<node CREATED="1352926082837" ID="ID_835831127" MODIFIED="1352926092005" TEXT="int GetSpostaVal();">
<node CREATED="1352926184280" ID="ID_660492017" MODIFIED="1352926184280" TEXT=""/>
</node>
<node CREATED="1352926092313" ID="ID_219143231" MODIFIED="1352926100762" TEXT="float GetScaleVal();">
<node CREATED="1352926184826" ID="ID_1300388144" MODIFIED="1352926184826" TEXT=""/>
</node>
<node CREATED="1352926101037" ID="ID_16870056" MODIFIED="1352926109573" TEXT="void KeyFrame();">
<node CREATED="1352926185350" ID="ID_1663564042" MODIFIED="1352926185350" TEXT=""/>
</node>
<node CREATED="1352926109924" ID="ID_501974154" MODIFIED="1352926119888" TEXT=" bool IsKey();">
<node CREATED="1352926186289" ID="ID_127197885" MODIFIED="1352926186289" TEXT="">
<node CREATED="1352926186923" ID="ID_1934211465" MODIFIED="1352926186923" TEXT=""/>
</node>
</node>
<node CREATED="1352926130281" ID="ID_160519601" MODIFIED="1352926131759" TEXT="int SetSposta(char dir, int q);">
<node CREATED="1352926188459" ID="ID_1087276953" MODIFIED="1352926188459" TEXT=""/>
</node>
<node CREATED="1352926140947" ID="ID_511480325" MODIFIED="1352926142037" TEXT="int SetScale(char dir, float q);">
<node CREATED="1352926189119" ID="ID_1874321794" MODIFIED="1352926189119" TEXT=""/>
</node>
<node CREATED="1352926151591" ID="ID_324589814" MODIFIED="1352926152658" TEXT="int SetRotate(char dir, float q);">
<node CREATED="1352926190425" ID="ID_1060683721" MODIFIED="1352926190425" TEXT=""/>
</node>
<node CREATED="1352926160267" ID="ID_750836441" MODIFIED="1352926161405" TEXT="bool GetHide();">
<node CREATED="1352926191274" ID="ID_1660783583" MODIFIED="1352926191274" TEXT=""/>
</node>
</node>
</node>
</node>
</node>
</map>
