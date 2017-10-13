/*!CK:1066258320!*//*1383535463,178137879*/

if (self.CavalryLogger) { CavalryLogger.start_js(["0nHmY"]); }

__d("BlobFactory",["emptyFunction"],function(a,b,c,d,e,f){var g=b('emptyFunction'),h,i=a.BlobBuilder||a.WebKitBlobBuilder||a.MozBlobBuilder||a.MSBlobBuilder;if(a.Blob){var j;try{new a.Blob();j=true;}catch(k){j=false;}h={getBlob:function(l,m){l=l||[];m=m||{};if(j){return new a.Blob(l,m);}else{var n=new i();for(var o=0;o<l.length;o++)n.append(l[o]);return n.getBlob(m.type);}},isSupported:g.thatReturnsTrue};}else h={getBlob:function(){},isSupported:g.thatReturnsFalse};e.exports=h;});
__d("WebMessengerEditThreadDialog",["Event","Button","ContextualDialog","CSS","DOM","FileInput","FileInputUploader","Input","InputSelection","LayerFadeOnHide","LayerFadeOnShow","MercuryAPIArgsSource","MercuryLogMessageType","MercurySourceType","MercuryMessages","WebMessengerTemplates","MercuryThreads","URI","WebMessengerSubscriptionsHandler","csx","cx"],function(a,b,c,d,e,f){var g=b('Event'),h=b('Button'),i=b('ContextualDialog'),j=b('CSS'),k=b('DOM'),l=b('FileInput'),m=b('FileInputUploader'),n=b('Input'),o=b('InputSelection'),p=b('LayerFadeOnHide'),q=b('LayerFadeOnShow'),r=b('MercuryAPIArgsSource'),s=b('MercuryLogMessageType'),t=b('MercurySourceType'),u=b('MercuryMessages').get(),v=b('WebMessengerTemplates'),w=b('MercuryThreads').get(),x=b('URI'),y=b('WebMessengerSubscriptionsHandler'),z=b('csx'),aa=b('cx'),ba=':fb:web-messenger:read-view:header:edit-multichat';function ca(){"use strict";var da=v[ba].build();this._dialog=new i({position:'below',addedBehaviors:[p,q]},da.getRoot());this._saveButton=da.getNode('saveButton');this._cancelButton=da.getNode('cancelButton');this._pictureInput=da.getNode('newPicture');this._uploadButton=da.getNode('uploadButton');this._uploadingThrobber=da.getNode('uploadingThrobber');this._uploadedFileDetails=da.getNode('uploadedFileDetails');this._fileNameNode=da.getNode('fileName');this._cancelImageButton=da.getNode('cancelImage');this._threadID=null;var ea=da.getNode('newName');this._uploadedImage=null;if(!this._pictureInput){var fa=k.scry(da.getRoot(),"._8-9")[0];this._pictureInput=k.create('input',{accept:'image/*',type:'file',className:"_n",name:'attachment[]',tabindex:2});new l(fa,this._uploadButton,this._pictureInput);}this._uploader=new m(this._pictureInput);this._uploader.setURI(x('/ajax/mercury/upload.php').setSubdomain('upload').toString());y.addSubscriptions(this._uploader.subscribe('success',this._onFileUploadSuccess.bind(this)),g.listen(this._pictureInput,'change',this._onFileUploadChange.bind(this)),g.listen(this._cancelImageButton,'click',this._resetImageUpload.bind(this)));g.listen(this._saveButton,'click',function(){this.save(n.getValue(ea));this._dialog.hide();}.bind(this));g.listen(this._cancelButton,'click',function(){this._dialog.hide();}.bind(this));this._dialog.subscribe('show',function(){var ga=w.getThreadMetaNow(this._threadID);n.setValue(ea,ga.name);this._resetImageUpload();}.bind(this));this._dialog.subscribe('aftershow',function(){o.set(ea,0,n.getValue(ea).length);}.bind(this));}ca.prototype.toggleShown=function(da,ea){"use strict";if(!this._dialog.isShown()){this._dialog.setContext(da);this._threadID=ea;this._uploadedImage=null;this._dialog.show();}else this._dialog.hide();};ca.prototype.save=function(da){"use strict";var ea=null,fa=w.getThreadMetaNow(this._threadID);if(fa)ea=fa.name;if((da||ea)&&(da!=ea))u.sendMessage(u.constructLogMessageObject(t.CHAT_WEB,this._threadID,s.THREAD_NAME,{name:da}),null,r.WEBMESSENGER);if(this._uploadedImage)u.sendMessage(u.constructLogMessageObject(t.CHAT_WEB,this._threadID,s.THREAD_IMAGE,{image:this._uploadedImage}));};ca.prototype._onFileUploadChange=function(event){"use strict";var da=n.getValue(event.getTarget());if(da){h.setEnabled(this._saveButton,false);j.hide(this._uploadButton);j.hide(this._uploadedFileDetails);j.show(this._uploadingThrobber);this._uploader.send();}};ca.prototype._onFileUploadSuccess=function(da,ea){"use strict";var fa=ea.response.getPayload();this._uploadedImage=fa.metadata[0];k.setContent(this._fileNameNode,this._uploadedImage.filename);j.hide(this._uploadingThrobber);j.hide(this._uploadButton);j.show(this._uploadedFileDetails);h.setEnabled(this._saveButton,true);};ca.prototype._resetImageUpload=function(){"use strict";this._uploadedImage=null;j.hide(this._uploadingThrobber);j.hide(this._uploadedFileDetails);j.show(this._uploadButton);};e.exports=ca;});
__d("MercuryDataSourceHelper",["MercuryPayloadSource","MercuryServerRequests","MercuryThreadMetadataRawRenderer","MercuryThreadMetadataRenderer","WebMessengerConstants"],function(a,b,c,d,e,f){var g=b('MercuryPayloadSource'),h=b('MercuryServerRequests').get(),i=b('MercuryThreadMetadataRawRenderer'),j=b('MercuryThreadMetadataRenderer').get(),k=b('WebMessengerConstants'),l={updateMercuryOnFetchComplete:function(m){m.subscribe('fetchComplete',function(n,o){var p={participants:[],threads:[],payload_source:g.SERVER_SEARCH};o.response.getPayload().entries.forEach(function(q){if(q.type==k.THREAD_TYPE){p.threads=p.threads.concat(q.mercury_thread);p.participants=p.participants.concat(q.participants_to_render);}});if(p.threads.length){h.handleUpdate(p);o.response.getPayload().entries.forEach(function(q){if(q.mercury_thread)q.text=j.renderThreadNameAndParticipantList(q.mercury_thread.thread_id,q.participants_to_render,q.mercury_thread.participants.length,{last_separator_uses_and:false,names_renderer:i.renderShortNames});});}});}};e.exports=l;});
__d("clamp",[],function(a,b,c,d,e,f){function g(h,i,j){return Math.max(h,Math.min(j,i));}e.exports=g;});
__d("ProgressBar",["CSS","DOM","Style","csx","cx","emptyFunction","requestAnimationFrame","removeFromArray","arrayContains"],function(a,b,c,d,e,f){var g=b('CSS'),h=b('DOM'),i=b('Style'),j=b('csx'),k=b('cx'),l=b('emptyFunction'),m=b('requestAnimationFrame'),n=b('removeFromArray'),o=b('arrayContains'),p=[];function q(t,u,v){"use strict";this._root=t;this._min=u||0;this._max=v||100;this._meter=h.find(t,"div._5e4k");this._meter2=h.scry(t,"div._5e2g")[0];this._initialPosition=0;this._position=0;this._initialVelocity=0;this._velocity=0;this._acceleration=0;this.useAcceleration=true;this._targetPosition=0;this._targetTime=0;this._startTime=null;this._onComplete=l;}q.prototype.getRoot=function(){"use strict";return this._root;};q.prototype.setPosition=function(t){"use strict";t=this._normalizePosition(t);this._initialPosition=t;this._position=t;this._updateMeter();this.stop();return this;};q.prototype.changeLabel=function(t){"use strict";var u=h.scry(this._root,"span._5e2h");u.forEach(function(v){h.setContent(v,t);});return this;};q.prototype.setCompleteHandler=function(t){"use strict";this._onComplete=t||l;return this;};q.prototype.setTarget=function(t,u){"use strict";this._stopAnimating();this._clearOnCompleteTimeout();this._targetPosition=t;var v=this._normalizePosition(t);this._targetTime=u;this._initialVelocity=this._velocity;this._initialPosition=this._position;if(this.useAcceleration){this._acceleration=2*(v-this._initialPosition-this._initialVelocity*u)/(u*u);}else{this._acceleration=0;this._velocity=this._initialVelocity=(v-this._initialPosition)/u;}if(this._position>=v){this._onComplete();}else this._start();return this;};q.prototype.setNoAcceleration=function(t){"use strict";this.useAcceleration=!t;return this;};q.prototype._clearOnCompleteTimeout=function(){"use strict";a.clearTimeout(this._onCompleteTimeout);};q.prototype.stop=function(){"use strict";this._clearOnCompleteTimeout();this._velocity=0;this._initialVelocity=0;this._acceleration=0;this._stopAnimating();return this;};q.prototype._start=function(){"use strict";this._startTime=Date.now();this._onCompleteTimeout=a.setTimeout(function(){this.setPosition(this._targetPosition);this._onComplete();}.bind(this),this._targetTime);this._startAnimating();return this;};q.prototype._loop=function(){"use strict";var t=Date.now()-this._startTime;this._position=(.5*this._acceleration*t*t)+(this._initialVelocity*t)+this._initialPosition;var u=this._velocity;this._velocity=this._acceleration*t+this._initialVelocity;var v=u<0!==this._velocity<0;if(this._position>this._normalizePosition(this._targetPosition)||v){this.setPosition(this._targetPosition);this._onComplete();}else this._updateMeter();};q.prototype._updateMeter=function(){"use strict";var t=Math.min(Math.max(this._position,0),1);g.conditionClass(this._meter,"_5e2d",t<=0);g.conditionClass(this._meter,"_5e4j",t>=1);t=t*100+'%';i.set(this._meter,'width',t);if(this._meter2){i.set(this._meter2,'left',t);i.set(this._meter2,'width',t);}};q.prototype._normalizePosition=function(t){"use strict";return Math.min(Math.max((t-this._min)/(this._max-this._min),0),1);};q.prototype._startAnimating=function(){"use strict";if(!o(p,this)){p.push(this);if(p.length===1)m(q.prototype._requestAnimationFrameCallback);}};q.prototype._stopAnimating=function(){"use strict";n(p,this);};q.prototype._requestAnimationFrameCallback=function(){"use strict";p.forEach(function(t){t._loop();});if(p.length)m(q.prototype._requestAnimationFrameCallback);};function r(t,u){t.setPosition(u);}function s(t,u,v){t.setTarget(u,v);}e.exports=q;e.exports.setTarget=s;e.exports.setPosition=r;});
__d("FreeformTokenizerBehavior",["Input","Keys","Event","function-extensions"],function(a,b,c,d,e,f){var g=b('Input'),h=b('Keys'),i=b('Event');b('function-extensions');function j(k,l){var m=l.tokenize_on_blur!==false,n=l.tokenize_on_paste!==false,o=l.matcher&&new RegExp(l.matcher,'i'),p=l.paste_split&&new RegExp(l.paste_split),q=l.select_on_comma!==false,r=l.never_submit===true;function s(event){var t=g.getValue(k.getInput()).trim();if(p&&event&&event.type=='paste'){t=t.split(p);}else t=[t];var u=false;for(var v=0;v<t.length;v++){var w=t[v].trim();if(w&&(!o||o.test(w))){var x={uid:w,text:w,freeform:true};k.addToken(k.createToken(x));u=true;}}if(event&&u){k.getTypeahead().getCore().afterSelect();event.kill();}}k.subscribe('keydown',function(t,u){var event=u.event,v=i.getKeyCode(event);if((q&&v==h.COMMA)||v==h.RETURN){var w=k.getTypeahead().getView();if(w.getSelection()){w.select();event.kill();}else s(event);}if(v==h.RETURN&&r)event.kill();});k.subscribe('paste',function(t,u){if(n)s.bind(null,u.event).defer(20);});k.subscribe('blur',function(t,u){if(m)s();k.getTypeahead().getCore().reset();});}e.exports=j;});