<map version="0.9.0">
<!-- To view this file, download free mind mapping software FreeMind from http://freemind.sourceforge.net -->
<node CREATED="1352905264723" ID="ID_1219618491" MODIFIED="1352911326470">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      <b><font size="5" color="#3333ff">Look3D:</font><font size="5" color="#ff3333">&#160;</font><font size="5" color="#6633ff">Mesh animata</font></b>
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
            animatedmesh
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
            creazione di una mesh animata
          </p>
        </td>
      </tr>
      <tr>
        <td style="border-left-width: 1; border-top-style: solid; border-left-style: solid; border-top-width: 1; border-bottom-style: solid; border-right-style: solid; border-right-width: 1; border-bottom-width: 1; width: 50%" valign="top">
          <p style="margin-right: 1; margin-left: 1; margin-top: 1; margin-bottom: 1">
            
          </p>
        </td>
      </tr>
    </table>
  </body>
</html></richcontent>
<attribute_layout NAME_WIDTH="64" VALUE_WIDTH="380"/>
<attribute NAME="Files" VALUE="animaedmesh.h,animatedmesh.cpp"/>
<attribute NAME="Classe base" VALUE="object3d"/>
<attribute NAME="Descrizione" VALUE="descrive una mesh animata tramite strutture e classi idonee"/>
<node COLOR="#cc6600" CREATED="1352918063908" HGAP="45" ID="ID_399417510" MODIFIED="1353107916132" POSITION="right" TEXT="Struttura della classe" VSHIFT="-129">
<node CREATED="1352918122018" HGAP="121" ID="ID_502522302" MODIFIED="1353107922403" TEXT="propriet&#xe0;" VSHIFT="-91">
<node CREATED="1352918129156" HGAP="66" ID="ID_1625409031" MODIFIED="1352918602763" TEXT="private" VSHIFT="-74">
<node CREATED="1352909036567" HGAP="192" ID="ID_947244967" MODIFIED="1352921940292" TEXT="std::vector&lt;meshanimation&gt; _animation;" VSHIFT="-104">
<node CREATED="1352909115847" FOLDED="true" HGAP="45" ID="ID_51278760" MODIFIED="1353108034696" TEXT="A cosa serve?" VSHIFT="2">
<icon BUILTIN="help"/>
<node CREATED="1352909137053" HGAP="111" ID="ID_1987728536" MODIFIED="1352909159850" TEXT="A rappresentare una animazione" VSHIFT="-64">
<icon BUILTIN="full-1"/>
</node>
<node CREATED="1352909163107" HGAP="123" ID="ID_97799804" MODIFIED="1352909692958" TEXT="Per generare i frame dell&apos;animazione" VSHIFT="-5">
<icon BUILTIN="full-2"/>
</node>
</node>
</node>
<node CREATED="1352909803935" HGAP="204" ID="ID_585989003" MODIFIED="1352921937449" TEXT="bone * _rootbone;" VSHIFT="-37">
<node CREATED="1352909862982" FOLDED="true" HGAP="163" ID="ID_268559310" MODIFIED="1353108037773" TEXT="A cosa serve?" VSHIFT="-1">
<icon BUILTIN="help"/>
<node CREATED="1352909874511" HGAP="185" ID="ID_1563537129" MODIFIED="1352909892455" TEXT="A rappresentare le bone" VSHIFT="-65">
<icon BUILTIN="full-1"/>
</node>
<node CREATED="1352909897839" HGAP="188" ID="ID_510098188" MODIFIED="1352909917867" TEXT="Una bone &#xe8; una struttura per animare una mesh." VSHIFT="-10">
<icon BUILTIN="full-2"/>
</node>
<node CREATED="1352909926251" HGAP="187" ID="ID_1873739895" MODIFIED="1352909971083" TEXT="Una bone &#xe8; una struttura ad albero, con una radice e delle diramazioni per questo il campo &#xe8; puntato." VSHIFT="35">
<icon BUILTIN="full-3"/>
</node>
</node>
</node>
<node CREATED="1352909052515" HGAP="216" ID="ID_20628862" MODIFIED="1352921929960" TEXT="std::vector&lt;meshkeyframe&gt; _keyframe;" VSHIFT="76">
<node CREATED="1352909707715" FOLDED="true" HGAP="30" ID="ID_964956775" MODIFIED="1353108041844" TEXT="A cosa serve?" VSHIFT="3">
<icon BUILTIN="help"/>
<node CREATED="1352909718806" HGAP="106" ID="ID_1447281342" MODIFIED="1352918204664" TEXT="A contenere i keyframe della animazione" VSHIFT="-71">
<icon BUILTIN="full-1"/>
</node>
<node CREATED="1352910047463" HGAP="103" ID="ID_960371911" MODIFIED="1352918257766" TEXT="Un keyframe &#xe8; un frame chiave all&apos;interno di una animazione e serve a contenere informazioni sul tipo di animazione che un vertice o un gruppo di vertici devono compiere in un determinato intervallo di frame in una animazione" VSHIFT="-23">
<icon BUILTIN="full-2"/>
</node>
</node>
</node>
<node CREATED="1352924612418" HGAP="226" ID="ID_1191142756" MODIFIED="1352924618665" TEXT="meshframe *_firstframe;" VSHIFT="97">
<node CREATED="1352924624653" FOLDED="true" HGAP="93" ID="ID_456560131" MODIFIED="1353108049375" TEXT="A cosa serve?" VSHIFT="1">
<icon BUILTIN="help"/>
<node CREATED="1352924636625" HGAP="28" ID="ID_252793955" MODIFIED="1352924662089" TEXT="A contenere i frame generati dai keyframe" VSHIFT="-91">
<icon BUILTIN="full-1"/>
</node>
<node CREATED="1352924663900" HGAP="37" ID="ID_1935234924" MODIFIED="1352924693903" TEXT="A rendere una animazione piu semlice da gestire" VSHIFT="46">
<icon BUILTIN="full-2"/>
</node>
</node>
</node>
</node>
</node>
<node CREATED="1352924468280" FOLDED="true" HGAP="120" ID="ID_1509919998" MODIFIED="1380709412676" TEXT="metodi" VSHIFT="3">
<node CREATED="1352924540417" HGAP="133" ID="ID_994109953" MODIFIED="1352924548195" TEXT="pubblici" VSHIFT="-59"/>
</node>
<node CREATED="1352924474174" HGAP="118" ID="ID_27474928" MODIFIED="1353107938722" TEXT="riferimenti" VSHIFT="115">
<node CREATED="1352908889404" HGAP="79" ID="ID_1583724711" LINK="object3d2.mm" MODIFIED="1353107943594" TEXT="Mappa object3d" VSHIFT="-75">
<cloud/>
</node>
<node CREATED="1352910136583" HGAP="77" ID="ID_1561909835" LINK="Keyframe.mm" MODIFIED="1353107974454" TEXT="Mappa di un meshkeyframe" VSHIFT="-102">
<cloud/>
</node>
<node CREATED="1352924713323" HGAP="71" ID="ID_1566217184" LINK="Meshframe.mm" MODIFIED="1353107988187" TEXT="Mappa di un meshframe" VSHIFT="-103">
<cloud/>
</node>
<node CREATED="1352909814821" HGAP="76" ID="ID_1961803960" LINK="Bone.mm" MODIFIED="1353108061125" TEXT="Mappa di una bone" VSHIFT="1">
<cloud/>
</node>
<node CREATED="1352910230965" HGAP="65" ID="ID_1874752877" LINK="meshanimation.mm" MODIFIED="1353108063509" TEXT="Mappa meshanimation" VSHIFT="64">
<cloud/>
</node>
</node>
</node>
</node>
</map>
