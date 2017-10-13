<map version="0.9.0">
<!-- To view this file, download free mind mapping software FreeMind from http://freemind.sourceforge.net -->
<node CREATED="1352910159430" ID="ID_1331945662" MODIFIED="1352911125745">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Keyframe classe meshkeyframe
    </p>
  </body>
</html></richcontent>
<node CREATED="1352911549952" HGAP="389" ID="ID_1107996883" MODIFIED="1352921327979" POSITION="right" TEXT="A cosa serve?" VSHIFT="-183">
<icon BUILTIN="help"/>
<node CREATED="1352911563227" HGAP="77" ID="ID_46040777" MODIFIED="1352922735994" TEXT="A rappresentare un frame chiave" VSHIFT="-8">
<icon BUILTIN="full-1"/>
</node>
<node CREATED="1352911584182" HGAP="77" ID="ID_145912057" MODIFIED="1352922754939" TEXT="A contenere le informazioni di un keyframe" VSHIFT="-2">
<icon BUILTIN="full-2"/>
</node>
<node CREATED="1352911616221" HGAP="79" ID="ID_579097377" MODIFIED="1352922758923" TEXT="Ad animaze una mesh attraverso la manipolazione dei suoi vertici" VSHIFT="5">
<icon BUILTIN="full-3"/>
</node>
</node>
<node CREATED="1352911663333" HGAP="375" ID="ID_1471702430" MODIFIED="1352916445128" POSITION="right" TEXT="Struttura della classe" VSHIFT="1">
<node CREATED="1352921386086" HGAP="161" ID="ID_1782413953" MODIFIED="1352921418268" TEXT="propriet&#xe0;" VSHIFT="-210">
<node CREATED="1352921399917" HGAP="73" ID="ID_1340119853" MODIFIED="1352921411373" TEXT="private" VSHIFT="-143">
<node CREATED="1352911686303" HGAP="172" ID="ID_1694030637" MODIFIED="1352913269588" TEXT="int _start;" VSHIFT="-55">
<node CREATED="1352912284180" HGAP="36" ID="ID_427841479" MODIFIED="1352912893214" TEXT="frame iniziale" VSHIFT="3">
<icon BUILTIN="help"/>
</node>
</node>
<node CREATED="1352913273832" HGAP="170" ID="ID_241465342" MODIFIED="1352913353050" TEXT="KEYFRAMEMESH::KeyFrameType _type;" VSHIFT="-29">
<node CREATED="1352913330943" HGAP="22" ID="ID_1530391429" MODIFIED="1352921540230" TEXT="definisce il tipo di keyframe" VSHIFT="2">
<icon BUILTIN="help"/>
</node>
</node>
<node CREATED="1352911714402" HGAP="173" ID="ID_285176578" MODIFIED="1352912198766" TEXT="int _end;" VSHIFT="-10">
<node CREATED="1352912301120" ID="ID_215601804" MODIFIED="1352912307688" TEXT="frame finale">
<icon BUILTIN="help"/>
</node>
</node>
<node CREATED="1352911769571" HGAP="172" ID="ID_879564961" MODIFIED="1352912195399" TEXT="int _nframe;" VSHIFT="39">
<node CREATED="1352912342205" HGAP="18" ID="ID_1088320167" MODIFIED="1352912895214" TEXT="numero di frame" VSHIFT="2">
<icon BUILTIN="help"/>
</node>
</node>
<node CREATED="1352911781492" HGAP="158" ID="ID_1475786813" MODIFIED="1352912338523" TEXT="int _idanimation;" VSHIFT="51">
<node CREATED="1352912314486" HGAP="15" ID="ID_1623410896" MODIFIED="1352912898237" TEXT="animazione a cui fare riferimento" VSHIFT="2">
<icon BUILTIN="help"/>
</node>
</node>
<node CREATED="1352912038612" HGAP="62" ID="ID_1275945251" MODIFIED="1352921450861" TEXT="movimento" VSHIFT="51">
<node CREATED="1352911793074" ID="ID_11624984" MODIFIED="1352911795112" TEXT="locx_vertex * _locx;">
<node CREATED="1352912357174" ID="ID_467264890" MODIFIED="1352913188851" TEXT=" movimento in x (locale)">
<icon BUILTIN="help"/>
</node>
</node>
<node CREATED="1352911803522" ID="ID_122920472" MODIFIED="1352911806175" TEXT="locy_vertex * _locy;">
<node CREATED="1352912359110" ID="ID_1459385315" MODIFIED="1352913191121" TEXT="movimento in y(locale)">
<icon BUILTIN="help"/>
</node>
</node>
<node CREATED="1352911812497" ID="ID_1374658550" MODIFIED="1352911815207" TEXT="locz_vertex * _locz;">
<node CREATED="1352912364115" ID="ID_1510077395" MODIFIED="1352913192569" TEXT="movimento in z(locale)">
<icon BUILTIN="help"/>
</node>
</node>
<node CREATED="1352911821867" ID="ID_695509115" MODIFIED="1352911823933" TEXT="locx_vertex * _dlocx;">
<node CREATED="1352912365924" ID="ID_275308391" MODIFIED="1352913212535" TEXT="movimento in x(relativo)">
<icon BUILTIN="help"/>
</node>
</node>
<node CREATED="1352911831003" ID="ID_303396963" MODIFIED="1352911833379" TEXT="locy_vertex * _dlocy;">
<node CREATED="1352912366862" ID="ID_1938409736" MODIFIED="1352913214631" TEXT="movimento in y(relativo)">
<icon BUILTIN="help"/>
</node>
</node>
<node CREATED="1352911840753" ID="ID_1374444110" MODIFIED="1352911860544" TEXT="locz_vertex * _dlocz;">
<node CREATED="1352912367640" ID="ID_405784580" MODIFIED="1352913216710" TEXT="movimento in z(relativo)">
<icon BUILTIN="help"/>
</node>
</node>
</node>
<node CREATED="1352912059446" HGAP="76" ID="ID_399477080" MODIFIED="1352921457054" TEXT="rotazione" VSHIFT="1">
<node CREATED="1352911953984" ID="ID_712729885" MODIFIED="1352911956208" TEXT="locx_vertex * _rlocx;">
<node CREATED="1352912368838" ID="ID_1334015554" MODIFIED="1352913194819" TEXT="rotazione in x(locale)">
<icon BUILTIN="help"/>
</node>
</node>
<node CREATED="1352911965706" ID="ID_1108045614" MODIFIED="1352911967614" TEXT="locy_vertex * _rlocy;">
<node CREATED="1352912369541" ID="ID_1797835743" MODIFIED="1352913196670" TEXT="rotazione in y(locale)">
<icon BUILTIN="help"/>
</node>
</node>
<node CREATED="1352911974857" ID="ID_1192558698" MODIFIED="1352911989719" TEXT="locz_vertex * _rlocz;">
<node CREATED="1352912370298" ID="ID_420229891" MODIFIED="1352913198663" TEXT="rotazione in z(locale)">
<icon BUILTIN="help"/>
</node>
</node>
<node CREATED="1352911994145" ID="ID_1761797271" MODIFIED="1352911996849" TEXT="locx_vertex * _rdlocx;">
<node CREATED="1352912371817" ID="ID_1373290607" MODIFIED="1352913218222" TEXT="rotazione in x(relativo)">
<icon BUILTIN="help"/>
</node>
</node>
<node CREATED="1352912008616" ID="ID_240912975" MODIFIED="1352912011057" TEXT="locy_vertex * _rdlocy;">
<node CREATED="1352912372756" ID="ID_410756269" MODIFIED="1352913219715" TEXT="rotazione in y(relativo)">
<icon BUILTIN="help"/>
</node>
</node>
<node CREATED="1352912020840" ID="ID_874207935" MODIFIED="1352912023831" TEXT="locz_vertex * _rdlocz;">
<node CREATED="1352912373598" ID="ID_1620244975" MODIFIED="1352913221355" TEXT="rotazione in z(relativo)">
<icon BUILTIN="help"/>
</node>
</node>
</node>
<node CREATED="1352912065644" HGAP="73" ID="ID_1099464553" MODIFIED="1352921459140" TEXT="scalatura" VSHIFT="-9">
<node CREATED="1352911889343" ID="ID_836650453" MODIFIED="1352911892169" TEXT="locx_vertex * _slocx;">
<node CREATED="1352912377091" ID="ID_1985311292" MODIFIED="1352913200479" TEXT="scala in x(locale)">
<icon BUILTIN="help"/>
</node>
</node>
<node CREATED="1352911902445" ID="ID_1112721929" MODIFIED="1352911904814" TEXT="locy_vertex * _slocy;">
<node CREATED="1352912380272" ID="ID_674441623" MODIFIED="1352913201764" TEXT="scala in y(locale)">
<icon BUILTIN="help"/>
</node>
</node>
<node CREATED="1352911912647" ID="ID_1260351946" MODIFIED="1352911915001" TEXT="locz_vertex * _slocz;">
<node CREATED="1352912381595" ID="ID_1000063369" MODIFIED="1352913203662" TEXT="scala in z(locale)">
<icon BUILTIN="help"/>
</node>
</node>
<node CREATED="1352911923302" ID="ID_820026637" MODIFIED="1352911925231" TEXT="locx_vertex * _sdlocx;">
<node CREATED="1352912382603" ID="ID_125226625" MODIFIED="1352913222604" TEXT="scala in x(relativo)">
<icon BUILTIN="help"/>
</node>
</node>
<node CREATED="1352911933010" ID="ID_559675838" MODIFIED="1352911934763" TEXT="locy_vertex * _sdlocy;">
<node CREATED="1352912383490" ID="ID_615536135" MODIFIED="1352913223940" TEXT="scala in y(relativo)">
<icon BUILTIN="help"/>
</node>
</node>
<node CREATED="1352911943314" ID="ID_96196675" MODIFIED="1352911945745" TEXT="locz_vertex * _sdlocz;">
<node CREATED="1352912384171" ID="ID_1347103762" MODIFIED="1352913225526" TEXT="scala in z(relativo)">
<icon BUILTIN="help"/>
</node>
</node>
</node>
</node>
<node CREATED="1352921431272" HGAP="158" ID="ID_1789658093" MODIFIED="1352921504613" TEXT="riferimenti" VSHIFT="-156">
<node CREATED="1352921473783" ID="ID_681081100" LINK="baseframe_vertex.mm" MODIFIED="1352926734313" TEXT="baseframe_vertex">
<cloud/>
<node CREATED="1352912600254" HGAP="121" ID="ID_1639319055" LINK="locx_vertex.mm" MODIFIED="1352921616415" TEXT="classe locx_vertex" VSHIFT="3">
<cloud/>
</node>
<node CREATED="1352912619213" HGAP="131" ID="ID_694436325" LINK="locy_vertex.mm" MODIFIED="1352921627271" TEXT="classe locy_vertex" VSHIFT="39">
<cloud/>
</node>
<node CREATED="1352912628914" HGAP="122" ID="ID_1399235942" LINK="locz_vertex.mm" MODIFIED="1352921629838" TEXT="classe locz_vertex" VSHIFT="37">
<cloud/>
</node>
</node>
</node>
</node>
</node>
<node CREATED="1352912959073" HGAP="381" ID="ID_1236336181" MODIFIED="1352916426448" POSITION="right" TEXT="Metodi della classe" VSHIFT="163">
<node CREATED="1352912986018" FOLDED="true" HGAP="177" ID="ID_1672978620" MODIFIED="1352926731100" TEXT="pubblici" VSHIFT="-134">
<node CREATED="1352913007951" HGAP="50" ID="ID_863075125" MODIFIED="1352913012075" TEXT="" VSHIFT="-144"/>
</node>
<node CREATED="1352912993150" HGAP="177" ID="ID_1158386278" MODIFIED="1352913019286" TEXT="privati" VSHIFT="5"/>
<node CREATED="1352913000712" HGAP="180" ID="ID_1578111661" MODIFIED="1352913030956" TEXT="protetti" VSHIFT="103"/>
</node>
<node CREATED="1352913048219" HGAP="147" ID="ID_1201236809" MODIFIED="1352922668218" POSITION="left" TEXT="enumeratori" VSHIFT="-65">
<node CREATED="1352913061061" HGAP="125" ID="ID_444850929" MODIFIED="1352913255569" TEXT="KEYFRAMEMESH::KeyFrameType" VSHIFT="-56">
<node CREATED="1352913092144" HGAP="64" ID="ID_893610939" MODIFIED="1352913169147" VSHIFT="-69">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      valori
    </p>
    <table style="border-left-width: 0; border-top-style: solid; border-left-style: solid; border-top-width: 0; border-bottom-style: solid; border-right-style: solid; border-right-width: 0; border-bottom-width: 0; width: 80%" border="0">
      <tr>
        <td style="border-left-width: 1; border-top-style: solid; border-left-style: solid; border-top-width: 1; border-bottom-style: solid; border-right-style: solid; border-right-width: 1; border-bottom-width: 1; width: 50%" valign="top">
          <font color="#800080">kf_movelocal=1</font><font color="#000000">, </font>

          <pre style="margin-right: 0px; margin-left: 0px; text-indent: 0px; margin-top: 0px; margin-bottom: 0px"><font color="#800080">kf_moverelative</font><font color="#000000">=</font><font color="#000080">2</font><font color="#000000">,</font></pre>
          <pre style="margin-right: 0px; margin-left: 0px; text-indent: 0px; margin-top: 0px; margin-bottom: 0px"><font color="#800080">kf_scalelocal</font><font color="#000000">=</font><font color="#000080">3</font><font color="#000000">,</font></pre>
          <pre style="margin-right: 0px; margin-left: 0px; text-indent: 0px; margin-top: 0px; margin-bottom: 0px"><font color="#800080">kf_scalerelative</font><font color="#000000">=</font><font color="#000080">4</font><font color="#000000">,</font></pre>
          <pre style="margin-right: 0px; margin-left: 0px; text-indent: 0px; margin-top: 0px; margin-bottom: 0px"><font color="#800080">kf_rotatelocal</font><font color="#000000">=</font><font color="#000080">5</font><font color="#000000">,</font></pre>
          <pre style="margin-right: 0px; margin-left: 0px; text-indent: 0px; margin-top: 0px; margin-bottom: 0px"><font color="#800080">kf_rotaterelative</font><font color="#000000">=</font><font color="#000080">6</font></pre>
        </td>
        <td style="border-left-width: 1; border-top-style: solid; border-left-style: solid; border-top-width: 1; border-bottom-style: solid; border-right-style: solid; border-right-width: 1; border-bottom-width: 1; width: 50%" valign="top">
          <p style="margin-right: 1; margin-left: 1; margin-top: 1; margin-bottom: 1">
            
          </p>
        </td>
      </tr>
    </table>
  </body>
</html></richcontent>
</node>
</node>
</node>
</node>
</map>
