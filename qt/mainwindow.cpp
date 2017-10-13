#define GLEW_STATIC
#include <GL/glew.h>

#include "insertobject.h"
#include "ui_mainwindow.h"
#include "scene/sceneinclude.h"

#include "newproject.h"
#include "newsphere.h"
#include "aboutdialog.h"

#include "loadpackage.h"
#include "ui_loadpackage.h"
#include "newpackage.h"
#include "ui_newpackage.h"
#include "fastinsert.h"


#include "mainwindow.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->toolBarHome->setVisible(false);
    ui->toolBarObject->setVisible(false);
    ui->toolBarTools->setVisible(false);



    //crea il documento principale dell'applicazione
    QMessageBox qm;

    qm.setWindowTitle(tr("Look3D:(Cannot create main document)"));
    qm.setText(tr("Exit"));
    if(!createmaindocument())
        if(qm.exec()==QDialog::Accepted)
            this->close();

    //mp_opengl=new OpenGL;

    ui->mainwidget->pscene->SetInsert(false);





    ui->mainwidget->pscene->setdocument(m_maindocument);
    ui->mainwidget->pscene->SetMode(SCENE::normal);
    ui->mainwidget->pscene->SetDocument(SCENE::solid);
    //ui->mainwidget->pscene->setMainWindow(ui);

    //md_about= new AboutDialog(this);
    m_fastinsert=NULL;// new fastinsert();

    m_numobject=0;

    m_insertobject= new insertObject(this);

    m_insertobject->setscene(ui->mainwidget->pscene);

    m_insertobject->connectobjects(ui);

    maintreemodel= new QStandardItemModel();

    m_insertobject->setdata(maintreemodel,ui);

    m_insertobject->initMainDock(maintreemodel,ui);

    glewInit();



}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionAbout_triggered()
{


   md_about->exec();




}

void MainWindow::on_actionSphere_2_triggered()
{
    /*
    md_newsphere= new newSphere(this);



    if(md_newsphere->exec()== QDialog::Accepted)
    {
        //insert the sphereUV created
        sphereuv ns;

        int *u,*v,vu,vv;
        float *r,vr;

        u=&vu;
        v=&vv;
        r=&vr;

        md_newsphere->getuvr(u,v,r);

        ns.SetUV(vu,vv);
        ns.setRadius(vr);

        ns.create(m_numobject++);

        string subn(20,' ');
        /*
        example:
        std::string str(100, ' ');
        sprintf(&str[0], "%s %s", "Hello", "World");

        *//*
        sprintf(&subn[0],"%d-%d-%0.00f",vu,vv,vr);

        ns.setName("sphere",subn);


        getdocument()->getmainscenedoc()->addObjectSphere(ns);

    }
    updateMainDock();
    */
}

void MainWindow::on_actionProject_triggered()
{
    NewProject *np= new NewProject(this);



    np->showNormal();
}

void MainWindow::on_actionExit_triggered()
{
    this->hide();
}

void MainWindow::on_actionNew_project_triggered()
{
    NewProject *np= new NewProject(this);



    np->showNormal();
}

void MainWindow::on_actionActionHome_triggered()
{
    ui->toolBarObject->setVisible(false);
    ui->toolBarTools->setVisible(false);
    ui->toolBarHome->setVisible(true);

}

void MainWindow::on_actionObjects_triggered()
{
    ui->toolBarHome->setVisible(false);

    ui->toolBarTools->setVisible(false);

    ui->toolBarObject->setVisible(true);



}

void MainWindow::on_actionspheredlg_triggered()
{
    on_actionSphere_2_triggered();
}

void MainWindow::on_actionOpen_project_triggered()
{
    QFileDialog *pdlg= new QFileDialog(this,Qt::Window);

    //QIcon iconmain(":images/main.png");

    pdlg->setWindowTitle(tr("Open Look 3D Project..."));
    //pdlg->setWindowIcon(iconmain);
    pdlg->show();
}

void MainWindow::on_actionSaveproject_triggered()
{
    QFileDialog *pdlg= new QFileDialog(this,Qt::Window);

    //QIcon iconmain(":images/main.png");

    pdlg->setWindowTitle(tr("Save Look 3D Project..."));
   // pdlg->setWindowIcon(iconmain);
    pdlg->show();

}

void MainWindow::on_actionSaveprojectas_triggered()
{
    QFileDialog *pdlg= new QFileDialog(this,Qt::Window);

    //QIcon iconmain(":images/main.png");

    pdlg->setWindowTitle(tr("Save Look 3D project as..."));
    //pdlg->setWindowIcon(iconmain);
    pdlg->show();

}

void MainWindow::updateMainDock()
{


    m_insertobject->updateMainDock(maintreemodel,ui);

    //delete maintreemodel;
    /*maintreemodel= new QStandardItemModel();

    maintreemodel->setObjectName(tr("Main scene"));

    maintreemodel->clear();

    QStandardItem *rootNode = maintreemodel->invisibleRootItem();

    //defining a couple of items

    QStandardItem *sceneitem = new QStandardItem("Main scene");

    sceneitem->setEditable(false);

    QStandardItem *objectitem = new QStandardItem("Objects");

    objectitem->setEditable(false);
    //load objects

    vector<object3d> appobject=getdocument()->getmainscenedoc()->getvectorobject();
    //to-do
    vector<object3d>::iterator oit;
    int io=0;
    for(oit=appobject.begin(); oit != appobject.end(); oit++ )
    {
        QString name=QString("object%1(").arg(io);

        QString nameo=oit.base()->getname().c_str();
        nameo.append("-");
        nameo.append(oit.base()->getsubname().c_str());
        nameo.append(")");
        name.append(nameo);

        //name.fromStdString(getdocument()->getmainscenedoc()->getObject(io)->name);

        QStandardItem *objectlabel = new QStandardItem(name);
        QVariant odata(QVariant::Int,&io);



        objectlabel->setData(odata);


        objectlabel->setEditable(false);

        objectitem->appendRow(objectlabel);

        io++;
    }

    sceneitem->appendRow(objectitem);

    QStandardItem *ligthitem = new QStandardItem("Lights");

    ligthitem->setEditable(false);

    /*to-do
    for(int io=0; io < mp_opengl->pscene->GetSizeLigth(); io++ )
    {
        QString name=QString("ligth(%d)").arg(io);
        QStandardItem *ligthlabel = new QStandardItem(name);

        ligthitem->appendRow(ligthlabel);

    }


    sceneitem->appendRow(ligthitem);



    QStandardItem *cameraitem = new QStandardItem("Camera");
    /*to-do
    for(int io=0; io < mp_opengl->pscene->GetSizeTelecamera(); io++ )
    {
        QString name=QString("camera(%d)").arg(io);;

        QStandardItem *cameralabel = new QStandardItem(name);

        cameraitem->appendRow(cameralabel);

    }
    */
    /*
    cameraitem->setEditable(false);

    sceneitem->appendRow(cameraitem);


    QStandardItem *materialitem = new QStandardItem("Material");

    materialitem->setEditable(false);
    //to-do
    /*for(int io=0; io < mp_opengl->pscene->m_telecamera.size(); io++ )
    {
        QString name;
        name.append("camera(%d)",io);
        QStandardItem *cameralabel = new QStandardItem(name);

        cameraitem->appendRow(cameralabel);

    }
    */
    /*
    sceneitem->appendRow(materialitem);

    QStandardItem *textureitem = new QStandardItem("Textures");

    textureitem->setEditable(false);

    sceneitem->appendRow(textureitem);

    QStandardItem *animationitem = new QStandardItem("Animations");


    animationitem->setEditable(false);

    QStandardItem *animationitemobject = new QStandardItem("Objects");

    animationitemobject->setEditable(false);

    //to-do

    QStandardItem *animationitemscene = new QStandardItem("Scene");

    animationitemscene->setEditable(false);
    /*to-do
    for(int io=0; io < mp_opengl->pscene->GetSizeAnimation(); io++ )
    {
        QString name=QString("anim(%d)").arg(io);;

        QStandardItem *animlabel = new QStandardItem(name);

        animationitemscene->appendRow(animlabel);

    }

    */
    /*
    animationitem->appendRow(animationitemscene);

    animationitem->appendRow(animationitemobject);

    sceneitem->appendRow(animationitem);

    rootNode->appendRow(sceneitem);

    //maintreemodel->setVerticalHeaderLabels(tr("Main scene"));

    ui->treeViewMain->setModel(maintreemodel);
*/
}

void MainWindow::on_actionExportproject_triggered()
{

}

void MainWindow::on_actionTools_triggered()
{
    ui->toolBarObject->setVisible(false);

    ui->toolBarHome->setVisible(false);

    ui->toolBarTools->setVisible(true);
}

void MainWindow::on_viewnew_clicked()
{
    //newview *nv = new newview;

    //nv->show();


}

void MainWindow::viewfullscreen()
{
    if(!ui->actionTfullscreen->isChecked())
    {
        ui->actionTfullscreen->setChecked(false);
        this->showNormal();

    }
    else
    {
        ui->actionTfullscreen->setChecked(true);
        this->showFullScreen();
    }

}

void MainWindow::on_actionTfullscreen_triggered()
{
    viewfullscreen();
}
document * MainWindow::getdocument()
{
    //restituisce il documento principale

    return (m_maindocument);
}
bool MainWindow::createmaindocument()
{
    m_maindocument= new document();

    Q_ASSERT(m_maindocument!=NULL);

    return true;
}


void MainWindow::on_actionFast_insert_triggered()
{
    // create the fastinsert dialog and show it


    ui->mainwidget->pscene->SetMode(SCENE::fastinsert);

    //ui->swElements->setCurrentIndex(6);

    //mp_opengl->stop_timer();
    /*
    if(m_fastinsert==NULL)
        m_fastinsert= new fastinsert();

    m_fastinsert->starttimer();
    if(m_fastinsert->exec()==QDialog::Accepted)
    {

        object3d nobj;
        nobj=m_fastinsert->getobject();
        m_maindocument->getmainscenedoc()->addObject(nobj);
    }

    m_fastinsert->stoptimer();

    //mp_opengl->start_timer();

    delete(m_fastinsert);
    m_fastinsert=NULL;
    */
    updateMainDock();

}

void MainWindow::on_actionPackage_triggered()
{
    loadpackage lp;

    lp.exec();
}

void MainWindow::on_actionPackage_2_triggered()
{
    newpackage np;

    np.exec();
}

void MainWindow::on_view3d_clicked()
{

}

void MainWindow::on_viewtop_clicked()
{

}

void MainWindow::on_viewbottom_clicked()
{

}

void MainWindow::on_viewsolid_clicked()
{
    ui->viewsolid->setChecked(true);
    ui->viewbox->setChecked(false);
    ui->viewwireframe->setChecked(false);
    ui->viewcolor->setChecked(false);
    ui->viewtexture->setChecked(false);

    ui->mainwidget->pscene->SetDocument(SCENE::solid);

}

void MainWindow::on_viewwireframe_clicked()
{
    ui->viewsolid->setChecked(false);
    ui->viewbox->setChecked(false);
    ui->viewwireframe->setChecked(true);
    ui->viewcolor->setChecked(false);
    ui->viewtexture->setChecked(false);

    ui->mainwidget->pscene->SetDocument(SCENE::wireframe);
}

void MainWindow::on_viewcolor_clicked()
{
    ui->viewsolid->setChecked(false);
    ui->viewbox->setChecked(false);
    ui->viewwireframe->setChecked(false);
    ui->viewcolor->setChecked(true);
    ui->viewtexture->setChecked(false);

     ui->mainwidget->pscene->SetDocument(SCENE::color);
}

void MainWindow::on_viewtexture_clicked()
{
    ui->viewsolid->setChecked(false);
    ui->viewbox->setChecked(false);
    ui->viewwireframe->setChecked(false);
    ui->viewcolor->setChecked(false);
    ui->viewtexture->setChecked(true);

    ui->mainwidget->pscene->SetDocument(SCENE::mtexture);
}

void MainWindow::on_treeViewMain_clicked(const QModelIndex &index)
{
    QString name,parent;//=index.model()->objectName();
    QStandardItem *item = maintreemodel->itemFromIndex(index);
    name=item->text();
    if(item->parent()!=0)
        parent=item->parent()->text();
    else
        parent="Null";
    int cindex=0;
    if(parent=="Main scene")
    {
        /*to-do da fare altri elementi per la selezione principale
        if(name=="Objects")
            cindex=1;
        if(name=="Groups")
            cindex=2;
        if(name=="Lights")
            cindex=3;
        if(name=="Textures")
            cindex=5;
        if(name=="Telecamera")
            cindex=4;
        */


    }

    if(parent=="Objects" && item->parent()->parent()->text()=="Main scene")
    {
        //to-do inserire codice per visualizzare propriettà dell'oggetto
        QVariant ov=item->data();
        int nobject=ov.toInt();
        m_insertobject->loadObject(nobject);

        ui->mainwidget->pscene->UnselectAllObjects();
        ui->mainwidget->pscene->SelectObjectDocument(nobject);
        cindex=1;


    }
    if(parent=="Groups" && item->parent()->parent()->text()=="Main scene")
    {
        QVariant ov=item->data();
        int ngroup=ov.toInt();
        ui->mainwidget->pscene->getdocument()->getmainscenedoc()->unselectobject();

        m_insertobject->loadGroup(ngroup);
        cindex=2;

    }
    if(parent=="Lights" && item->parent()->parent()->text()=="Main scene")
    {
        QVariant ov=item->data();
        int nlight=ov.toInt();
        ui->mainwidget->pscene->getdocument()->getmainscenedoc()->unselectobject();
        m_insertobject->loadlight(nlight);
        cindex=3;

    }

    if(parent=="Telecamera" && item->parent()->parent()->text()=="Main scene")
    {
        QVariant ov=item->data();
        int ntel=ov.toInt();
        ui->mainwidget->pscene->getdocument()->getmainscenedoc()->unselectobject();

        m_insertobject->loadcamera(ntel);

        cindex=4;


    }
    if(parent=="Textures" && item->parent()->parent()->text()=="Main scene")
    {
        //to-do

        cindex=5;
    }

    //ui->swElements->setCurrentIndex(cindex);


}

void MainWindow::on_mode3d_clicked()
{
    ui->modeedit->setChecked(false);
    ui->modeanimation->setChecked(false);
    ui->modeconsolle->setChecked(false);
    ui->modepaint->setChecked(false);
    ui->modetexture->setChecked(false);
    ui->mode3d->setChecked(true);

    ui->mainwidget->pscene->SetMode(SCENE::normal);

}

void MainWindow::on_modeedit_clicked()
{
    ui->modeedit->setChecked(true);
    ui->modeanimation->setChecked(false);
    ui->modeconsolle->setChecked(false);
    ui->modepaint->setChecked(false);
    ui->modetexture->setChecked(false);
    ui->mode3d->setChecked(false);

    ui->mainwidget->pscene->SetMode(SCENE::edit);
    //int nobj=ui->mainwidget->pscene->getdocument()->getmainscenedoc()->getObjectSelected();

    //if(nobj>=0)
    //    ui->mainwidget->pscene->getdocument()->getmainscenedoc()->getObject(nobj)->makeindex();


    //ui->swElements->setCurrentIndex(7);


}

void MainWindow::on_modeanimation_clicked()
{
    ui->modeedit->setChecked(false);
    ui->modeanimation->setChecked(true);
    ui->modeconsolle->setChecked(false);
    ui->modepaint->setChecked(false);
    ui->modetexture->setChecked(false);
    ui->mode3d->setChecked(false);

    ui->mainwidget->pscene->SetMode(SCENE::animation);

    //ui->swElements->setCurrentIndex(8);

}

void MainWindow::on_tbinsertsphere_clicked()
{
   /* sphereuv ns;

    ns.SetUV(32,32);
    ns.setRadius(10.0F);
    ns.setName("sphere","32-32-10");

    ns.create();

    getdocument()->getmainscenedoc()->addObjectSphere(ns);
*/
    updateMainDock();

}
