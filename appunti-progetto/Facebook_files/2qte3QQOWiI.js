/*!CK:3807606671!*//*1383062890,178158909*/

if (self.CavalryLogger) { CavalryLogger.start_js(["97Zhe"]); }

__d("legacy:nux-wizard-page",["NUXWizard"],function(a,b,c,d){a.NUXWizard=b('NUXWizard');},3);
__d("PrivacyLiteNUXController",["AsyncRequest","CSS","Event","LayerSlowlyFadeOnShow","Locale","ModalMask","PageTransitions","Parent","PrivacyLiteFlyout","Toggler","$","copyProperties","cx"],function(a,b,c,d,e,f){var g=b('AsyncRequest'),h=b('CSS'),i=b('Event'),j=b('LayerSlowlyFadeOnShow'),k=b('Locale'),l=b('ModalMask'),m=b('PageTransitions'),n=b('Parent'),o=b('PrivacyLiteFlyout'),p=b('Toggler'),q=b('$'),r=b('copyProperties'),s=b('cx'),t="_3oye",u="_1luv",v=[],w={bootload:function(){},init:function(y){if(!w.initialized)r(this,{dialog:y.dialog,sectionID:y.sectionID,subsectionID:y.subsectionID,initialized:true,tourStarted:false});if(y.showOnExpand){w._attachFlyoutListener();}else w._detachFlyoutListener();},startTourFromAnywhere:function(){w._startTour(false);},startTourFromMegaphone:function(){w._startTour(true);},_startTour:function(y){if(w.tourStarted)return;w.tourStarted=true;w._detachFlyoutListener();new g('/ajax/privacy/privacy_lite/log_nux_imp').setData({from_megaphone:y}).send();l.show();h.conditionClass(w.dialog.getRoot(),t,y);if(!y)w._maskListener=i.listen(q('modalMaskOverlay'),'click',w._cleanup);p.setSticky(true);setTimeout(w._showFlyout);m.registerHandler(function(){w._cleanup();o.setFlyoutVisible(false);},10);},_showFlyout:function(){o.loadBodyFromMegaphone();o.setFlyoutVisible(true);w._initDialog();x('load',w._showTour);},_showTour:function(){o.showSection(w.sectionID);x('expanded',function(y,z){if(z===w.sectionID)w.dialog.setContext(q(w.subsectionID)).setOffsetY(20).show();});x(['collapse','hide'],w._cleanup);},_initDialog:function(){var y=w.dialog.getRoot(),z=w.dialog.getContent();h.addClass(y,"_1luy");h.conditionClass(y,"_3qz8",k.isRTL());h.addClass(z,"_1luz");w.dialog.enableBehavior(j);i.listen(y,'click',function(event){if(n.byClass(event.getTarget(),u))w._cleanup();});},_attachFlyoutListener:function(){if(!w.flyoutSubscription)if(o.isFlyoutVisible()){w.startTourFromAnywhere();}else w.flyoutSubscription=o.subscribe('show',w.startTourFromAnywhere);},_detachFlyoutListener:function(){if(w.flyoutSubscription){w.flyoutSubscription.unsubscribe();w.flyoutSubscription=null;}},_cleanup:function(){if(!w.tourStarted)return;w.tourStarted=false;p.setSticky(false);l.hide();w.dialog.hide();while(v.length)v.pop().unsubscribe();if(w._maskListener){w._maskListener.remove();w._maskListener=null;}}};function x(y,z){v.push(o.subscribe(y,z));}e.exports=w;});