<map version="0.9.0">
<!-- To view this file, download free mind mapping software FreeMind from http://freemind.sourceforge.net -->
<node CREATED="1352900963453" ID="ID_594889695" MODIFIED="1352903282450" TEXT="Look3D">
<attribute_layout NAME_WIDTH="64" VALUE_WIDTH="266"/>
<attribute NAME="Programma" VALUE="Look3D"/>
<attribute NAME="Tipo" VALUE="Programma di modellazione grafica tridimensionale"/>
<attribute NAME="Autore" VALUE="Guido Agostini"/>
<node CREATED="1352901837543" HGAP="94" ID="ID_34547110" MODIFIED="1352903236810" POSITION="right" TEXT="Descrizione" VSHIFT="-200">
<icon BUILTIN="help"/>
<node CREATED="1352901885765" HGAP="37" ID="ID_363604647" MODIFIED="1352902680691" TEXT="Look3D &#xe8; una applicazione libera creata con la licenza GPL v. 3 e succ." VSHIFT="-96">
<icon BUILTIN="idea"/>
<node CREATED="1352901956480" HGAP="59" ID="ID_812717323" MODIFIED="1352902686909" TEXT="Cosa comporta?" VSHIFT="-71">
<icon BUILTIN="help"/>
<node CREATED="1352901980475" HGAP="68" ID="ID_1439192288" MODIFIED="1352902228957" TEXT="Libert&#xe0; di eseguire il programma, per qualsiasi scopo (libert&#xe0; 0)." VSHIFT="-93">
<icon BUILTIN="full-0"/>
</node>
<node CREATED="1352901991066" HGAP="55" ID="ID_610914441" MODIFIED="1352902236450" TEXT="Libert&#xe0; di studiare come funziona il programma e adattarlo alle proprie necessit&#xe0; (libert&#xe0; 1). L&apos;accesso al codice sorgente ne &#xe8; un prerequisito." VSHIFT="-39">
<icon BUILTIN="full-1"/>
</node>
<node CREATED="1352901995840" HGAP="64" ID="ID_775968846" MODIFIED="1352902240082" TEXT="Libert&#xe0; di ridistribuire copie in modo da aiutare il prossimo (libert&#xe0; 2)." VSHIFT="72">
<icon BUILTIN="full-2"/>
</node>
<node CREATED="1352902004052" HGAP="61" ID="ID_1578058299" MODIFIED="1352902242381" TEXT="Libert&#xe0; di migliorare il programma e distribuirne pubblicamente i miglioramenti, in modo tale che tutta la comunit&#xe0; ne tragga beneficio (libert&#xe0; 3). L&apos;accesso al codice sorgente ne &#xe8; un prerequisito." VSHIFT="111">
<icon BUILTIN="full-3"/>
</node>
</node>
<node CREATED="1352908409098" ID="ID_1577340035" LINK="www.gnu.it" MODIFIED="1352908522162" TEXT="Sito gnu.it"/>
</node>
<node CREATED="1352902271693" HGAP="38" ID="ID_530136007" MODIFIED="1352902304268" TEXT="L&apos;autore &#xe8; Guido Agostini" VSHIFT="55">
<icon BUILTIN="help"/>
<node CREATED="1352902306505" HGAP="27" ID="ID_780531924" MODIFIED="1352902319732" TEXT="Chi &#xe8;?" VSHIFT="-67">
<icon BUILTIN="help"/>
<node CREATED="1352902324870" HGAP="59" ID="ID_1417949557" MODIFIED="1352902358974" TEXT="E&apos; un&apos;appassionato di informatica..." VSHIFT="-85">
<icon BUILTIN="yes"/>
<icon BUILTIN="button_ok"/>
</node>
</node>
</node>
</node>
<node CREATED="1352902461928" HGAP="179" ID="ID_222038548" MODIFIED="1352908627361" POSITION="left" TEXT="Struttura dell&apos;applicazione" VSHIFT="-381">
<icon BUILTIN="messagebox_warning"/>
<node CREATED="1352902546692" HGAP="135" ID="ID_1105935130" MODIFIED="1352904190184" TEXT="Rappresentare una mesh" VSHIFT="-343">
<node CREATED="1352902589430" HGAP="143" ID="ID_1539345389" MODIFIED="1352906188513" TEXT="Classe object3d (rappresenta una mesh statica) senza animazioni." VSHIFT="-171">
<attribute_layout NAME_WIDTH="134" VALUE_WIDTH="134"/>
<attribute NAME="std::vector&lt;vertex&gt;" VALUE="local_vertex"/>
<attribute NAME="std::vector&lt;line&gt;" VALUE="m_line"/>
<attribute NAME="std::vector&lt;polygon&gt;" VALUE="m_poly"/>
<attribute NAME="std::vector&lt;polygon3&gt;" VALUE="m_poly3"/>
<node CREATED="1352906757608" HGAP="273" ID="ID_1390520806" LINK="object3d2.mm" MODIFIED="1352906932567" TEXT="Mappa della classe" VSHIFT="-41">
<cloud/>
</node>
</node>
<node CREATED="1352904190184" HGAP="102" ID="ID_1340572789" MODIFIED="1352906152192" TEXT="Classe animatedmesh (rappresnta una mesh dinamica con animazioni), deriva dalla classe object3d." VSHIFT="-128">
<arrowlink DESTINATION="ID_1340572789" ENDARROW="Default" ENDINCLINATION="0;0;" ID="Arrow_ID_397076576" STARTARROW="None" STARTINCLINATION="0;0;"/>
<attribute_layout NAME_WIDTH="63" VALUE_WIDTH="106"/>
<attribute NAME="file .h" VALUE="animatedmesh.h"/>
<attribute NAME="file .cpp" VALUE="animatedmesh.cpp"/>
<attribute NAME="classe base" VALUE="object3d"/>
<node CREATED="1352906845255" HGAP="121" ID="ID_42868467" LINK="animatedmesh2.mm" MODIFIED="1352906906758" TEXT="Mappa della classe" VSHIFT="-30">
<cloud/>
</node>
</node>
</node>
<node CREATED="1352907053554" HGAP="379" ID="ID_1987885132" MODIFIED="1352907062834" TEXT="La classe scena" VSHIFT="-6">
<node CREATED="1352907066059" HGAP="631" ID="ID_1901625739" LINK="scena.mm" MODIFIED="1352907141422" TEXT="Mappa della classe" VSHIFT="1">
<cloud/>
</node>
</node>
</node>
</node>
</map>
