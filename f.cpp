#include "f.h"
#include "ui_f.h"
#include "equipement.h"
#include "maintenance.h"
//#include "mainwindow.h"
#include <QMessageBox>
#include <QString>
#include <QSqlQuery>
#include <QDebug>
#include <QVariant>
#include <QPdfWriter>
#include <QPainter>
#include <QPrinter>
#include <connexion.h>
#include <QDesktopServices>
#include <QUrl>
#include <QPrintDialog>
#include "statistique.h"
f::f(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::f)
{
    ui->setupUi(this);
    ui->tabletous->setModel(tmp.afficher());
    ui->tablemaintenance->setModel(tmp1.afficherm());
      ui->tablevendre->setModel(tmp2.afficherv());
      ui->comboBoxrefm->setModel(tmp1.listerrefm());
         ui->comboBoxlibm->setModel(tmp1.listerlibm());
         ui->comboBoxrefv->setModel(tmp2.listerrefv());
            ui->comboBoxlibv->setModel(tmp2.listerlibv());

            ui->stackedWidget->setCurrentIndex(0);




                  ui->comboBoxetat->addItem("maintenir");
                  ui->comboBoxetat->addItem("vendre");
                  ui->comboBoxetat->addItem("New");

                  ui->comboBoxag->addItem("3amsalah");
                  ui->comboBoxag->addItem("mr agent");
                  ui->comboBoxag->addItem("nouveau agent");

                  ui->comboBoxach->addItem("Societe Bois");
                  ui->comboBoxach->addItem("Renouvable Societe");
                  ui->comboBoxach->addItem("Mr Lauron");

                  ui->comboBoxmodetm->addItem("c bon maintenu");
                  ui->comboBoxmodetm->addItem("En attente!");

                  ui->comboBoxmodrefm->setModel(tmp1.listerrefm());
                  ui->comboBoxsupp->setModel(tmp2.listerrefv());

                  ui->famille->addItem("Electro");
                  ui->famille->addItem("Chambre");
                  ui->famille->addItem("Cuisine");


}

f::~f()
{
    delete ui;
}
QSqlQueryModel* equipement::afficher()
{
    QSqlQueryModel *model = new QSqlQueryModel;
        model->setQuery("SELECT * FROM equipement");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("Reference"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("Famille"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("libelle"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("Etat"));
        return model;
}

void f::on_ajoutertous_clicked()
{
    int verif=0;
    bool verif_ref=true;
    bool verif_libelle=true;
    bool verif_famille=true;
    bool verifHedhi2 = false;
    QString reftest=ui->reference->text();
    QString ref=ui->reference->text();
    QString fam=ui->famille->currentText();
    QString lib=ui->libelle->text();
    QString et=ui->comboBoxetat->currentText();
    QString numbers = "0123456789";
     bool verifHedhi = false;
           for(int i = 0; i < reftest.length(); i++){
               for(int j = 0; j < numbers.length(); j++){
                   if(reftest[i] == numbers[j]){
                       verifHedhi = true;
                   }
               }
               if(verifHedhi == false ){
                   verif_ref = false;
                   QMessageBox::information(nullptr, QObject::tr("Erreur"),
                               QObject::tr("Erreur reference invalide .\n"
                                           "Click Cancel to exit."), QMessageBox::Cancel);

                   break;
               }
           }

           QString alphab = "azertyuiopqsdfghjklmwxcvbnéàçAZERTYUIOPQSDFGHJKLMWXCVBN";
                   bool verifHedhi1 = false;
                   for(int i = 0; i < lib.length(); i++){
                       for(int j = 0; j < alphab.length(); j++){
                           if(lib[i] == alphab[j]){
                               verifHedhi1 = true;
                           }
                       }
                       if(verifHedhi1 == false ){
                           verif_libelle = false;
                           QMessageBox::information(nullptr, QObject::tr("Erreur"),
                                       QObject::tr("Erreur libelle invalide .\n"
                                                   "Click Cancel to exit."), QMessageBox::Cancel);

                           break;
                       }
                   }
                   for(int i = 0; i < fam.length(); i++){
                       for(int j = 0; j < alphab.length(); j++){
                           if(fam[i] == alphab[j]){
                               verifHedhi2 = true;
                           }
                       }
                       if(verifHedhi2 == false ){
                           verif_famille = false;
                           QMessageBox::information(nullptr, QObject::tr("Erreur"),
                                       QObject::tr("Erreur famille invalide .\n"
                                                   "Click Cancel to exit."), QMessageBox::Cancel);

                           break;
                       }
                   }

            if((ref == "") or (fam=="")or(lib=="")or (et==""))
            {
                verif =1 ;
               QMessageBox::warning(this,"  EQUIPEMENT ","CHAMP VIDE");


            }
          #define std ;


     QMessageBox msg;
     if(verif == 0){
     if((verif_ref == true)&&(verif_libelle== true) && (verif_famille==true)){
     equipement e(ref,fam,lib,et);

       bool test2=e.verifierId(ref);
       if(test2)
       {
           QMessageBox::critical(nullptr, QObject::tr("Ajouter un equipement"),
                       QObject::tr("déjà existant !.\n"
                                   "Click Ok to exit."), QMessageBox::Ok);


         }
     else {

                bool test=e.ajouter();
     if(test)
         {
          ui->tabletous->setModel(tmp.afficher());

              msg.setText("Ajouter avec succés");
               msg.exec();

           }
     else
         {
            msg.setText("Echec de l'ajout");
            msg.exec();
         }
}
}
}
}

void f::on_ajoutermaintenance_clicked()
{
    int verif=0;
    QString referencem=ui->comboBoxrefm->currentText();
    QString libellem=ui->comboBoxlibm->currentText();
    QString agent=ui->comboBoxag->currentText();
     int prix=ui->prix->text().toInt();
     QString duree=ui->duree->date().toString();

     if((prix == 0))
     {
         verif =1 ;
        QMessageBox::warning(this,"  EQUIPEMENT ","CHAMP VIDE");


     }
     maintenance m(referencem,libellem,agent,duree,prix);
     QMessageBox msg;
       if(verif == 0){
       bool test2=m.verifierId(referencem);
       if(test2)
       {
           QMessageBox::critical(nullptr, QObject::tr("Ajouter maintenance"),
                       QObject::tr("déjà existant !.\n"
                                   "Click Ok to exit."), QMessageBox::Ok);


         }
     else{
           bool testm=m.ajouterm();
     if(testm)
         {
           ui->tablemaintenance->setModel(tmp1.afficherm());
           msg.setText("Ajouter maintenance avec succés");
            msg.exec();

           }
     else
     {
         msg.setText("Echec de l'ajout maintenance");
         msg.exec();

      }
     }
}
}


void f::on_refresh_clicked()
{
      ui->tabletous->setModel(tmp.afficher());
      ui->tablemaintenance->setModel(tmp1.afficherm());
       ui->tablevendre->setModel(tmp2.afficherv());
      ui->comboBoxlibm->setModel(tmp1.listerlibm());
      ui->comboBoxrefm->setModel(tmp1.listerrefm());
      ui->comboBoxrefv->setModel(tmp2.listerrefv());
      ui->comboBoxlibv->setModel(tmp2.listerlibv());
      ui->comboBoxmodrefm->setModel(tmp1.listerrefm());
      ui->comboBoxsupp->setModel(tmp2.listerrefv());
}

void f::on_ajoutervendre_clicked()
{
    int verif=0;
    QString referencev=ui->comboBoxrefv->currentText();
    QString libellev=ui->comboBoxlibv->currentText();
    QString acheteur=ui->comboBoxach->currentText();
     int prix=ui->prix->text().toInt();
     if((prix == 0))
     {
         verif =1 ;
        QMessageBox::warning(this,"  EQUIPEMENT ","CHAMP VIDE");


     }

     vendre v(referencev,libellev,acheteur,prix);
     QMessageBox msg;
         if(verif == 0){
       bool test2=v.verifierId(referencev);
       if(test2)
       {
           QMessageBox::critical(nullptr, QObject::tr("Ajouter un equipement"),
                       QObject::tr("déjà existant !.\n"
                                   "Click Ok to exit."), QMessageBox::Ok);


         }
     else{
                bool testv=v.ajouterv();
     if(testv)
         {
           ui->tablevendre->setModel(tmp2.afficherv());
           msg.setText("Ajouter vendre avec succés");
            msg.exec();

           }
     else
     {
         msg.setText("Echec de l'ajout vendre");
         msg.exec();

      }


}
}
}
void f::on_modifer_clicked()
{
    QString  reference=ui->comboBoxmodrefm->currentText();
    QString etat=ui->comboBoxmodetm->currentText();
    QMessageBox msg;
    bool modif=tmp.modifierm(reference,etat);
    if(modif)
        {
           ui->tabletous->setModel(tmp.afficher());
          msg.setText("modifier avec succés");
           msg.exec();

          }
    else
    {
        msg.setText("Echec de modifier");
        msg.exec();

     }

}

void f::on_supprimer_clicked()
{
    QString  reference=ui->comboBoxsupp->currentText();

    QMessageBox msg;
    bool supp=tmp.supprimer(reference);
    if(supp)
        {
           ui->tabletous->setModel(tmp.afficher());
          msg.setText("Suppression avec succés");
           msg.exec();

          }
    else
    {
        msg.setText("Suppression echec");
        msg.exec();

     }
}


void f::on_chercher2_clicked()
{
    QString  lib = ui->cher->text();
    ui->tabletous->setModel(tmp.chercher(lib));


}


void f::on_facture_clicked()
{
//pour imprimer
    vendre v;
        QString text=v.apercu_pdf();
        ui->textEdit_imp->setText(text);

        QPrinter printer ;
        printer.setPrinterName("nom");
        QPrintDialog dialog (&printer,this);
        if(dialog.exec()==QDialog::Rejected) return ;
        ui->textEdit_imp->print(&printer);

}

void f::on_trier_clicked()
{
 ui->tablemaintenance->setModel(tmp1.trierprix());
}

void f::on_eq_clicked()
{
   ui->stackedWidget->setCurrentIndex(7);
}

void f::on_maintenir_7_clicked()
{
    ui->stackedWidget->setCurrentIndex(9);
}

void f::on_vendre_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void f::on_pushButton_221_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void f::on_pushButton_283_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void f::on_equip_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);
}

void f::on_pushButton_235_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}

void f::on_pushButton_233_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);
}

void f::on_pushButton_240_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}

void f::on_maintenir_clicked()
{
    ui->stackedWidget->setCurrentIndex(8);
}

void f::on_maintenir_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(8);
}

void f::on_pushButton_254_clicked()
{
    ui->stackedWidget->setCurrentIndex(8);
}

void f::on_maintenir_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(9);
}

void f::on_pushButton_263_clicked()
{
    ui->stackedWidget->setCurrentIndex(8);
}

void f::on_maintenir_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(9);
}

void f::on_pushButton_270_clicked()
{
    ui->stackedWidget->setCurrentIndex(8);
}

void f::on_maintenir_8_clicked()
{
    ui->stackedWidget->setCurrentIndex(9);
}

void f::on_vendre_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void f::on_equip_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);
}

void f::on_vendre_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void f::on_pushButton_246_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);
}

void f::on_equip_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);
}

void f::on_maintenir_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void f::on_pushButton_253_clicked()
{
    ui->stackedWidget->setCurrentIndex(9);
}

void f::on_pushButton_255_clicked()
{
    ui->stackedWidget->setCurrentIndex(9);
}

void f::on_equip_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);
}

void f::on_maintenir_6_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void f::on_pushButton_262_clicked()
{
    ui->stackedWidget->setCurrentIndex(9);
}

void f::on_pushButton_273_clicked()
{
    ui->stackedWidget->setCurrentIndex(10);
}

void f::on_pushButton_264_clicked()
{
    ui->stackedWidget->setCurrentIndex(10);
}

void f::on_equip_6_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);
}

void f::on_maintenir_9_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void f::on_pushButton_269_clicked()
{
    ui->stackedWidget->setCurrentIndex(9);
}

void f::on_equip_7_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);
}

void f::on_maintenir_10_clicked()
{
    ui->stackedWidget->setCurrentIndex(9);
}

void f::on_maintenir_11_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void f::on_pushButton_271_clicked()
{
    ui->stackedWidget->setCurrentIndex(10);
}

void f::on_pushButton_223_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void f::on_pushButton_272_clicked()
{
  ui->stackedWidget->setCurrentIndex(2);
}

void f::on_pushButton_282_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void f::on_equip_8_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);
}

void f::on_maintenir_12_clicked()
{
    ui->stackedWidget->setCurrentIndex(9);
}

void f::on_maintenir_13_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void f::on_pushButton_274_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void f::on_pushButton_275_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void f::on_maintenir_19_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void f::on_pushButton_18_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void f::on_maintenir_15_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void f::on_maintenir_17_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void f::on_pushButton_227_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void f::on_pushButton_229_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void f::on_pushButton_22_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void f::on_pushButton_285_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void f::on_pushButton_19_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void f::on_pushButton_17_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void f::on_pushButton_287_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void f::on_pushButton_288_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void f::on_pushButton_286_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void f::on_equip_11_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);
}

void f::on_equip_9_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);
}

void f::on_equip_10_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);
}

void f::on_maintenir_18_clicked()
{
    ui->stackedWidget->setCurrentIndex(9);
}

void f::on_maintenir_14_clicked()
{
    ui->stackedWidget->setCurrentIndex(9);
}

void f::on_maintenir_16_clicked()
{
    ui->stackedWidget->setCurrentIndex(9);
}

void f::on_pushButton_225_clicked()
{
    statistique S ;
        S.exec();

}

void f::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void f::on_pushButton_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}



void f::on_cher_clicked()
{
    QString  lib = ui->lib->text();
    ui->tabletous->setModel(tmp.chercher(lib));
}




void f::on_refreshm_clicked()
{

    ui->tablemaintenance->setModel(tmp1.afficherm());
    ui->comboBoxlibm->setModel(tmp1.listerlibm());
    ui->comboBoxrefm->setModel(tmp1.listerrefm());
    ui->comboBoxmodrefm->setModel(tmp1.listerrefm());

}

void f::on_refreshm_2_clicked()
{
    ui->tablemaintenance->setModel(tmp1.afficherm());
    ui->comboBoxlibm->setModel(tmp1.listerlibm());
    ui->comboBoxrefm->setModel(tmp1.listerrefm());
    ui->comboBoxmodrefm->setModel(tmp1.listerrefm());
}

void f::on_refreshv_clicked()
{
     ui->tablevendre->setModel(tmp2.afficherv());
    ui->comboBoxrefv->setModel(tmp2.listerrefv());
    ui->comboBoxlibv->setModel(tmp2.listerlibv());
    ui->comboBoxsupp->setModel(tmp2.listerrefv());
}

void f::on_refreshv_2_clicked()
{
    ui->tablevendre->setModel(tmp2.afficherv());
   ui->comboBoxrefv->setModel(tmp2.listerrefv());
   ui->comboBoxlibv->setModel(tmp2.listerlibv());
   ui->comboBoxsupp->setModel(tmp2.listerrefv());
}

void f::on_pushButton_230_clicked()
{
    statistique S ;
        S.exec();
}

void f::on_pushButton_232_clicked()
{

    statistique S ;
        S.exec();
}

void f::on_pushButton_228_clicked()
{

    statistique S ;
        S.exec();
}

void f::on_pushButton_231_clicked()
{

    statistique S ;
        S.exec();
}
