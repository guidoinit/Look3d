/*!CK:1647571626!*//*1383661135,178158627*/

if (self.CavalryLogger) { CavalryLogger.start_js(["q1bAu"]); }

__d("ComposerXEmptyAttachment",["ComposerXAttachment"],function(a,b,c,d,e,f){var g=b('ComposerXAttachment');for(var h in g)if(g.hasOwnProperty(h))j[h]=g[h];var i=g===null?null:g.prototype;j.prototype=Object.create(i);j.prototype.constructor=j;j.__superConstructor__=g;function j(k,l){"use strict";g.call(this);this._root=k;if(l)this.attachmentClassName=l;}j.prototype.getRoot=function(){"use strict";return this._root;};e.exports=j;});
__d("BanzaiNectarSimple",["Banzai"],function(a,b,c,d,e,f){var g=b('Banzai');function h(j){return {log:function(k,l,m){var n={e:l,a:m};g.post('nectar_simple:'+k,n,j);}};}var i=h();i.create=h;e.exports=i;});
__d("HubsTypeaheadView",["Arbiter","AsyncRequest","ContextualTypeaheadView","CSS","DOM","Event","$","copyProperties","tx"],function(a,b,c,d,e,f){var g=b('Arbiter'),h=b('AsyncRequest'),i=b('ContextualTypeaheadView'),j=b('CSS'),k=b('DOM'),l=b('Event'),m=b('$'),n=b('copyProperties'),o=b('tx');for(var p in i)if(i.hasOwnProperty(p))r[p]=i[p];var q=i===null?null:i.prototype;r.prototype=Object.create(q);r.prototype.constructor=r;r.__superConstructor__=i;function r(s,t){"use strict";i.call(this,s,t);if(t.allowDedupe)this.subscribe('select',this.selectDuplicates.bind(this));}r.prototype.hide=function(){"use strict";return this.canHide?q.hide.call(this):null;};r.prototype.reset=function(){"use strict";return this.canHide?q.reset.call(this):null;};r.prototype._createFreeFormNode=function(s){"use strict";var t=s;if(this.showCreatePrompt){t=o._("Aggiungi \"{partial_name}\"",{partial_name:s});}else if(this.showAltCreatePrompt)t=o._("Crea \"{partial_name}\"",{partial_name:s});return {text:t,orig_text:s,type:'addnew calltoaction',uid:'0'};};r.prototype.render=function(s,t,u){"use strict";var v=[],w=Math.max(1,Math.floor(t.length/10));for(var x=w;x<t.length;x++)if(!!t[x].already_added){v.push(t[x]);t.splice(x,1);x--;}t=t.concat(v);if(this.alwaysRender&&s!=='')if(this.allowFreeformEntry){t.push(this._createFreeFormNode(s));}else{var y=s.toLowerCase().trim(),z=false;for(var aa=0;aa<t.length;aa++)if(y==t[aa].text.toLowerCase().trim()){z=true;break;}if(!z)t.push(this._createFreeFormNode(s));}var ba=t.length;for(var ca=0;ca<t.length;ca++)if(t[ca].uid==false)ba--;if(this.allowDedupe&&ba>1)t.push({text:"Contrassegna risultati duplicati",type:'dupelink calltoaction'});return q.render.call(this,s,t,u);};r.prototype.selectDuplicates=function(s,t){"use strict";if(!t.selected.type.match('dupelink'))return;var u=[];for(var v=0;v<this.results.length;v++){if(this.results[v].uid==false)continue;u.push(this.results[v].uid);}var w=g.subscribe('typeahead/'+this.collectionID+'/confirmDupes',function(x,y){var z=this.results.map(function(ca){return ca.uid;});for(var aa=0;aa<y.dupe_ids.length;aa++){var ba=z.indexOf(y.dupe_ids[aa]);j.hide(this.items[ba]);}this.hasHiddenDupes=y.dupe_ids.length>0;}.bind(this));g.subscribe('typeahead/'+this.collectionID+'/finishDupes',function(x,y){g.unsubscribe(w);this.canHide=true;this.hasHiddenDupes&&j.hide(k.find(this.content,'.dupelink'));this.hasHiddenDupes=false;}.bind(this));this.canHide=false;new h('/ajax/typeahead/quality/duplicates').setData({ids:u,surface:m('collections_surface').value,collection_id:this.collectionID}).send();};r.initFreeformBoxes=function(){"use strict";var s=k.scry(document,'div.fbAddFormDialog')[0];if(!s)return;var t=k.find(s,'form');l.listen(t,'submit',function(){k.scry(t,'div.fbFreeformInput').forEach(function(u){if(k.find(u,'input.inputtext').value)j.addClass(u.firstChild,'selected');});});};n(r.prototype,{canHide:true,hasHiddenDupes:false});e.exports=r;});
__d("MultiInferenceMegaphone",["AsyncRequest","CSS","DOM","DOMClone","Event","csx","cx","$"],function(a,b,c,d,e,f){var g=b('AsyncRequest'),h=b('CSS'),i=b('DOM'),j=b('DOMClone'),k=b('Event'),l=b('csx'),m=b('cx'),n=b('$'),o={init:function(p,q,r,s){this._checkedImage=r;this._disableBlock=s;p.forEach(function(t){k.listen(t,'click',function(u){var v=u.target,w=i.scry(v,"^._52bq").pop();if(w||h.hasClass(v,"_52bq"))return;this._setChecked(t);this._disableMP();var x=q[t.id];if(x)new g(x).setMethod('POST').setStatusElement('typeahead_load_indicator').send();}.bind(this));}.bind(this));},initTypeahead:function(p,q,r,s,t){this._typeaheadBlock=p;this._typeaheadInput=i.scry(p,'input[name="'+t+'"]').pop();k.listen(p,'click',function(u){this._setTypeaheadFocus();}.bind(this));q.subscribe('select',function(u,v){var w=v.selected;if(!w||!(w.uid||w.text))return;this._setChecked(this._typeaheadBlock);this._disableMP();var x={};if(w.uid)x[s]=w.uid;if(w.text)x[t]=w.text;new g(r).setMethod('POST').setData(x).setStatusElement('typeahead_load_indicator').send();}.bind(this));},_disableMP:function(){var p=n('nf_megaphone_school_add_content');if(p)i.appendContent(p,this._disableBlock);},_setTypeaheadFocus:function(){if(!this._typeaheadInput)return;this._typeaheadInput.focus();},_setChecked:function(p){if(!p)return;var q=i.scry(p,"._51w4").pop();if(q)i.replace(q,j.deepClone(this._checkedImage));}};e.exports=o;});
__d("ProfileQuestionsForm",["BanzaiNectarSimple","CSS","DOM","Form","cx","csx","tidyEvent"],function(a,b,c,d,e,f){var g=b('BanzaiNectarSimple'),h=b('CSS'),i=b('DOM'),j=b('Form'),k=b('cx'),l=b('csx'),m=b('tidyEvent'),n={POPULATED:"_5daa"},o={FOOTER:"._59q7"},p=false;function q(r,s,t,u,v){"use strict";this.$ProfileQuestionsForm0=r;this.$ProfileQuestionsForm1=s;this.$ProfileQuestionsForm2=t;this.$ProfileQuestionsForm3=u.logData||{};this.$ProfileQuestionsForm4=i.find(this.$ProfileQuestionsForm0,'input[name="action"]');this.$ProfileQuestionsForm5=v?v:i.find(this.$ProfileQuestionsForm0,o.FOOTER);m([this.$ProfileQuestionsForm1.subscribe('populated',this.$ProfileQuestionsForm6.bind(this))]);}q.prototype.$ProfileQuestionsForm7=function(){"use strict";if(p)return;g.log('socrates_impressions','question_interact',this.$ProfileQuestionsForm3);p=true;};q.prototype.$ProfileQuestionsForm6=function(event,r){"use strict";r&&this.$ProfileQuestionsForm7();h.conditionClass(this.$ProfileQuestionsForm5,n.POPULATED,r);};q.prototype.$ProfileQuestionsForm8=function(){"use strict";i.appendContent(this.$ProfileQuestionsForm0,this.$ProfileQuestionsForm2);j.bootstrap(this.$ProfileQuestionsForm0);};q.prototype.$ProfileQuestionsForm9=function(r){"use strict";this.$ProfileQuestionsForm4.value=r;};e.exports=q;});
__d("ProfileQuestionFormatSinglePage",["ArbiterMixin","CSS","DOM","Event","Parent","cx","mixin","tidyEvent"],function(a,b,c,d,e,f){var g=b('ArbiterMixin'),h=b('CSS'),i=b('DOM'),j=b('Event'),k=b('Parent'),l=b('cx'),m=b('mixin'),n=b('tidyEvent'),o={ITEM:"_59qe",ITEM_SELECTED:"_59qc"},p=m(g);for(var q in p)if(p.hasOwnProperty(q))s[q]=p[q];var r=p===null?null:p.prototype;s.prototype=Object.create(r);s.prototype.constructor=s;s.__superConstructor__=p;function s(t,u,v,w){"use strict";this.$ProfileQuestionFormatSinglePage0=t;this.$ProfileQuestionFormatSinglePage1=u;this.$ProfileQuestionFormatSinglePage2=v;this.$ProfileQuestionFormatSinglePage3=w;this.$ProfileQuestionFormatSinglePage4=i.find(this.$ProfileQuestionFormatSinglePage2,'input[name="page_id"]');n([j.listen(this.$ProfileQuestionFormatSinglePage2,'click',this.$ProfileQuestionFormatSinglePage5.bind(this)),this.$ProfileQuestionFormatSinglePage3.subscribe('select',this.$ProfileQuestionFormatSinglePage6.bind(this)),this.$ProfileQuestionFormatSinglePage3.subscribe('unselect',this.$ProfileQuestionFormatSinglePage7.bind(this,null))]);}s.prototype.$ProfileQuestionFormatSinglePage6=function(t,u){"use strict";var v=(u&&u.selected);v&&v.uid&&this.$ProfileQuestionFormatSinglePage7(parseInt(v.uid,10));};s.prototype.$ProfileQuestionFormatSinglePage5=function(event){"use strict";var t=k.byClass(event.getTarget(),o.ITEM);if(!t)return;var u=this.$ProfileQuestionFormatSinglePage1[t.id];if(this.$ProfileQuestionFormatSinglePage4.value==u)u=null;if(this.$ProfileQuestionFormatSinglePage3.getCore().getHiddenValue())this.$ProfileQuestionFormatSinglePage3.getCore().reset();this.$ProfileQuestionFormatSinglePage7(u);};s.prototype.$ProfileQuestionFormatSinglePage7=function(t){"use strict";this.$ProfileQuestionFormatSinglePage4.value=t;for(var u=0;u<this.$ProfileQuestionFormatSinglePage0.length;u++){var v=this.$ProfileQuestionFormatSinglePage0[u];this.$ProfileQuestionFormatSinglePage9(v,this.$ProfileQuestionFormatSinglePage1[v.id]==t);}this.inform('populated',!!t);};s.prototype.$ProfileQuestionFormatSinglePage9=function(t,u){"use strict";h.conditionClass(t,o.ITEM_SELECTED,u);};e.exports=s;});
__d("TimelineAboutUnitAddCityDialog",["AsyncRequest","Button","CSS","DOMQuery","Event"],function(a,b,c,d,e,f){var g=b('AsyncRequest'),h=b('Button'),i=b('CSS'),j=b('DOMQuery'),k=b('Event');function l(m,n,o,p,q,r){"use strict";this._dialog=n;var s=n.getRoot();this._icon=m;this._typeahead=o;this._radioCities=j.scry(s,'input[type="radio"]');this._textOther=j.find(s,'.textOther');this._buttonSave=j.scry(s,'button[name="save"]')[0];this._buttonClose=j.scry(s,'a.layerCancel')[0];this._form=j.scry(s,'form[name="city_form"]')[0];this._ref=q;this._uri=r;if(this._radioCities.length>0){this._radioCityOther=j.find(s,'.radioCityOther');this._typeahead.subscribe('select',this._enableSaveButtonTypeahead.bind(this));this._typeahead.subscribe('unselect',this._disableSaveButtonTypeahead.bind(this));for(var t=0;t<this._radioCities.length-1;t++)k.listen(this._radioCities[t],'click',this._enableSaveButton.bind(this));k.listen(this._radioCityOther,'click',this._saveButtonCityOther.bind(this));}else{this._typeahead.subscribe('select',this._enableSaveButton.bind(this));this._typeahead.subscribe('unselect',this._disableSaveButton.bind(this));}k.listen(m,'click',this._onIconClick.bind(this));if(this._radioCityOther){k.listen(this._textOther,'focus',this._selectRadioOther.bind(this));k.listen(this._radioCityOther,'click',this._focusTextOther.bind(this));}if(p)n.show();k.listen(this._buttonClose,'click',this._onClose.bind(this));k.listen(this._form,'submit',this._onSubmit.bind(this));}l.prototype._onSubmit=function(){"use strict";var m=false;if(this._radioCities.length===0){if(this._typeahead.getCore().getHiddenValue()!=='')m=true;}else{for(var n=0;n<this._radioCities.length-1;n++)if(this._radioCities[n].checked){m=true;break;}if(this._radioCityOther.checked)if(this._typeahead.getCore().getHiddenValue()!==''){m=true;}else m=false;}if(m){i.hide(this._icon);}else this._onClose();};l.prototype._onIconClick=function(m){"use strict";new g().setURI(this._uri).setData({log:'icon_clicked',ref:this._ref}).setMethod('POST').send();m.prevent();this._dialog.show();};l.prototype._onClose=function(){"use strict";new g().setURI(this._uri).setData({log:'close_clicked',ref:this._ref}).setMethod('POST').send();};l.prototype._focusTextOther=function(){"use strict";this._textOther.focus();};l.prototype._selectRadioOther=function(){"use strict";this._radioCityOther.checked=true;if(this._typeahead.getCore().getHiddenValue()!==''){h.setEnabled(this._buttonSave,true);}else h.setEnabled(this._buttonSave,false);};l.prototype._enableSaveButton=function(){"use strict";h.setEnabled(this._buttonSave,true);};l.prototype._disableSaveButton=function(){"use strict";h.setEnabled(this._buttonSave,false);};l.prototype._enableSaveButtonTypeahead=function(){"use strict";if(this._radioCityOther.checked)h.setEnabled(this._buttonSave,true);};l.prototype._disableSaveButtonTypeahead=function(){"use strict";if(this._radioCityOther.checked)h.setEnabled(this._buttonSave,false);};l.prototype._saveButtonCityOther=function(){"use strict";if(this._typeahead.getCore().getHiddenValue()!==''){h.setEnabled(this._buttonSave,true);}else h.setEnabled(this._buttonSave,false);};e.exports=l;});
__d("TimelineStickyHeaderComposerX",["Arbiter","Bootloader","ComposerXController","CSS","DOMQuery","Event","Parent","Run","TimelineComposerUtilities","TimelineContentLoader","TimelineStickyHeader","Vector","csx","cx"],function(a,b,c,d,e,f){var g=b('Arbiter'),h=b('Bootloader'),i=b('ComposerXController'),j=b('CSS'),k=b('DOMQuery'),l=b('Event'),m=b('Parent'),n=b('Run'),o=b('TimelineComposerUtilities'),p=b('TimelineContentLoader'),q=b('TimelineStickyHeader'),r=b('Vector'),s=b('csx'),t=b('cx');function u(w){return w&&w.getContext&&m.byClass(w.getContext(),"_2wp");}function v(w){"use strict";this._composerRoot=w;this._tokens=[o.listenToSetEstimatedDate(this._composerRoot,p.capsuleForCurrentSection),o.listenToPublish(this._composerRoot,this._close.bind(this)),g.subscribe('PhotoSnowlift.OPEN',this._close.bind(this)),g.subscribe('TimelineMLE/mleFlyoutShown',function(x,y){if(u(y)===this._composerRoot)i.reset(this._composerRoot);}.bind(this)),g.subscribe('composer/initializedAttachment',function(x,y){if(y.composerRoot===this._composerRoot){this._registerClickToDismiss();if(!y.isInitial)this._closeMLE();}else this._close();}.bind(this)),g.subscribe(q.ADJUST_WIDTH,this._toggleNarrowMode.bind(this))];this._clickCancelToken=o.listenToCancel(this._composerRoot,this._close.bind(this));n.onLeave(function(){while(this._tokens.length)this._tokens.pop().unsubscribe();this._clearClickDismissToken();if(this._clickCancelToken){this._clickCancelToken.remove();this._clickCancelToken=null;}}.bind(this));}v.prototype._toggleNarrowMode=function(event,w){"use strict";h.loadModules(['Tooltip'],function(x){var y=r.getElementDimensions(w).x>400,z=k.scry(this._composerRoot,"._9lb");j.conditionClass(this._composerRoot,"_2wq",y);for(var aa=0;aa<z.length;aa++){var ba=z[aa],ca=k.getText(ba);if(y){x.set(ba,ca);}else x.remove(ba);}}.bind(this));return false;};v.prototype._registerClickToDismiss=function(){"use strict";var w=j.hasClass(k.find(this._composerRoot,"._yq"),"_519b");if(!w){this._clearClickDismissToken();return;}this._clickDismissToken=l.listen(document.body,'click',function(x){var y=m.byClass(x.getTarget(),"_2wp");if(!y){this._close();this._clearClickDismissToken();}}.bind(this));};v.prototype._clearClickDismissToken=function(){"use strict";if(this._clickDismissToken){this._clickDismissToken.remove();this._clickDismissToken=null;}};v.prototype._close=function(){"use strict";this._clearClickDismissToken();this._closeMLE();i.reset(this._composerRoot);};v.prototype._closeMLE=function(){"use strict";h.loadModules(['TimelineMLE'],function(w){var x=w.getFlyout();if(u(x)===this._composerRoot)w.hideFlyout();}.bind(this));};e.exports=v;});
__d("TimelineProfileQuestionsUnit",["CSS","Event","Parent","tidyEvent"],function(a,b,c,d,e,f){var g=b('CSS'),h=b('Event'),i=b('Parent'),j=b('tidyEvent'),k=null,l={COLLAPSED:'collapsedUnit',UNIT:'fbTimelineUnit'};function m(n,o,p,q){"use strict";this.$TimelineProfileQuestionsUnit0=n;this.$TimelineProfileQuestionsUnit1=o;this.$TimelineProfileQuestionsUnit2=p;this.$TimelineProfileQuestionsUnit3=q;this.$TimelineProfileQuestionsUnit4();k&&k.$TimelineProfileQuestionsUnit5();k=this;}m.prototype.$TimelineProfileQuestionsUnit5=function(){"use strict";this.$TimelineProfileQuestionsUnit6&&this.$TimelineProfileQuestionsUnit6.remove();this.$TimelineProfileQuestionsUnit6=null;};m.prototype.$TimelineProfileQuestionsUnit4=function(){"use strict";if(this.$TimelineProfileQuestionsUnit3.isCollapsed)return;this.$TimelineProfileQuestionsUnit6=h.listen(this.$TimelineProfileQuestionsUnit1,'click',this.$TimelineProfileQuestionsUnit7.bind(this));j(this.$TimelineProfileQuestionsUnit6);};m.prototype.$TimelineProfileQuestionsUnit7=function(){"use strict";if(!this.$TimelineProfileQuestionsUnit2)return;var n=i.byClass(this.$TimelineProfileQuestionsUnit0,l.UNIT);g.toggle(this.$TimelineProfileQuestionsUnit2);var o=!g.shown(this.$TimelineProfileQuestionsUnit2);g.conditionClass(n,l.COLLAPSED,o);};m.updateElements=function(n,o){"use strict";if(!k)return;k.$TimelineProfileQuestionsUnit5();k.$TimelineProfileQuestionsUnit1=n;k.$TimelineProfileQuestionsUnit2=o;k.$TimelineProfileQuestionsUnit4();};e.exports=m;});
__d("TypeaheadRequireSelection",["Event","copyProperties"],function(a,b,c,d,e,f){var g=b('Event'),h=b('copyProperties');function i(j){"use strict";this._typeahead=j;}i.prototype.enable=function(){"use strict";var j=this._typeahead.getCore(),k=j.getElement().form;function l(){!j.getHiddenValue()&&j.reset();}l();this._subscription=j.subscribe('blur',l);if(k)this._eventListener=g.listen(k,'submit',l);};i.prototype.disable=function(){"use strict";this._typeahead.getCore().unsubscribe(this._subscription);this._subscription=null;if(this._eventListener){this._eventListener.remove();this._eventListener=null;}};h(i.prototype,{_subscription:null,_eventListener:null});e.exports=i;});
__d("legacy:RequireSelectionTypeaheadBehavior",["TypeaheadRequireSelection"],function(a,b,c,d){var e=b('TypeaheadRequireSelection');if(!a.TypeaheadBehaviors)a.TypeaheadBehaviors={};a.TypeaheadBehaviors.requireSelection=function(f){f.enableBehavior(e);};},3);
__d("TypeaheadSetPhotoOnSelect",["function-extensions","CSS","DOM","Event","copyProperties"],function(a,b,c,d,e,f){b('function-extensions');var g=b('CSS'),h=b('DOM'),i=b('Event'),j=b('copyProperties');function k(l){"use strict";this._typeahead=l;}k.prototype.enable=function(){"use strict";var l=h.scry(this._typeahead.getElement(),'.photo')[0];if(l){if(!h.isNodeOfType(l,'img')){var m=h.create('img',{className:l.className});h.replace(l,m);l=m;}var n=g.hide.curry(l),o=g.show.curry(l);this._eventListener=i.listen(l,{load:o,error:n,abort:n});this._subscription=this._typeahead.subscribe('select',function(p,q){var r=q.selected.photo||this._typeahead.view.fallbackPhoto;r?l.setAttribute('src',r):n();}.bind(this));}};k.prototype.disable=function(){"use strict";this._eventListener.remove();this._eventListener=null;this._typeahead.unsubscribe(this._subscription);this._subscription=null;};j(k.prototype,{_eventListener:null,_subscription:null});e.exports=k;});
__d("legacy:SetPhotoOnSelectTypeaheadBehavior",["TypeaheadSetPhotoOnSelect"],function(a,b,c,d){var e=b('TypeaheadSetPhotoOnSelect');if(!a.TypeaheadBehaviors)a.TypeaheadBehaviors={};a.TypeaheadBehaviors.setPhotoOnSelect=function(f){f.enableBehavior(e);};},3);
__d("TypeaheadShowResultsOnFocus",["Event","Keys","copyProperties"],function(a,b,c,d,e,f){var g=b('Event'),h=b('Keys'),i=b('copyProperties');function j(k){"use strict";this._typeahead=k;}j.prototype.enable=function(){"use strict";var k=this._typeahead.getCore(),l=this._typeahead.getData();k.resetOnKeyup=false;this._subscription=this._typeahead.subscribe('bootstrap',function(m,n){this.firstFetch(n,k,l);}.bind(this));this._keyUpListener=g.listen(k.getElement(),'keyup',function(event){if(g.getKeyCode(event)==h.BACKSPACE||g.getKeyCode(event)==h.DELETE)this.respond(k,l);}.bind(this));this._focusListener=g.listen(k.getElement(),'focus',function(event){this.respond(k,l);}.bind(this));};j.prototype.disable=function(){"use strict";this._typeahead.unsubscribe(this._subscription);this._subscription=null;this._keyUpListener.remove();this._keyUpListener=null;this._focusListener.remove();this._focusListener=null;};j.prototype.firstFetch=function(k,l,m){"use strict";!k.bootstrapping&&this.respond(l,m);};j.prototype.respond=function(k,l){"use strict";if(!k.getValue()){var m=this.getUidsFromData(l);k.setValue('');var n=l.buildUids(' ',m);l.respond('',n);}};j.prototype.getUidsFromData=function(k){"use strict";var l=k.getAllEntries(),m=[];for(var n in l)m.push({uid:l[n].uid,index:l[n].index});m.sort(function(o,p){return o.index-p.index;});return m.map(function(o){return o.uid;});};i(j.prototype,{_subscription:null,_keyUpListener:null,_focusListener:null});e.exports=j;});
__d("TypeaheadShowBootstrapOnFocus",["TypeaheadShowResultsOnFocus"],function(a,b,c,d,e,f){var g=b('TypeaheadShowResultsOnFocus'),h=3;for(var i in g)if(g.hasOwnProperty(i))k[i]=g[i];var j=g===null?null:g.prototype;k.prototype=Object.create(j);k.prototype.constructor=k;k.__superConstructor__=g;function k(l){"use strict";g.call(this,l);this._uids=[];}k.prototype.firstFetch=function(l,m,n){"use strict";if(!l.bootstrapping){this._uids=this.getUidsFromData(n);this.respond(m,n);}};k.prototype.respond=function(l,m){"use strict";if(!l.getValue()){l.setValue('');var n=m.buildUids(' ',this._uids);m.respond('',n);}};k.prototype.getUidsFromData=function(l){"use strict";var m=l.getAllEntries(),n=[];for(var o in m)if(m[o].bootstrapped)n.push({uid:m[o].uid,index:m[o].index});n.sort(function(p,q){return p.index-q.index;});n=n.slice(0,h);return n.map(function(p){return p.uid;});};e.exports=k;});