#include "dialog.h"
#include "ui_dialog.h"
#include "personnel.h"
#include "conge.h"
#include "departement.h"
#include "smtp.h"
#include <QMessageBox>
#include <QTableWidget>
#include <QTableView>
#include <QPixmap>
#include <QComboBox>
#include <QString>
#include <QDebug>
#include <QVariant>
#include<QLineEdit>
#include <QDate>
#include "statistique.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{

  ui->setupUi(this);
  ui->tableView_2->setModel(tmpp.afficher());
  ui->tableViewconge->setModel(tmpc.afficherconge());
  ui->tableViewdepartement->setModel(tmpd.afficherdepartement());


}

Dialog::~Dialog()
{
    delete ui;
}




void Dialog::on_ajouterpersonnel_clicked()
{
    bool verif_id,verif_depart,verif_nom,verif_prenom,verif_salaire;
   verif_id=true;
   verif_depart=true;
   verif_nom=true;
   verif_prenom=true;
   verif_salaire=true;
  // bool test2 = false;
   bool test3 = false;
   bool test4 = false ;
   bool test5 = false;

   QString id= ui->id->text();
    bool test1 = false;
   QString alphab = "azertyuiopqsdfghjklmwxcvbnéàçAZERTYUIOPQSDFGHJKLMWXCVBN0123456789";
     for(int i = 0; i < id.length(); i++){
         for(int j = 0; j < alphab.length(); j++){
             if((id[i] == alphab[j])&&(id!="")){
                 test1 = true;
             }
         }
         if(test1 == false ){
             verif_id = false;
             QMessageBox::information(nullptr, QObject::tr("Erreur"),
                         QObject::tr("Erreur id invalide .\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);

             break;
         }
     }





       QString departement = ui->departement->currentText();

        QString datenaiss = ui->datenaiss->date().toString();
        QString dateemb = ui->dateemb->date().toString();

        QString numbers = "0123456789";
         QString salairpersotest = ui->salaire->text();
         int salaire = ui->salaire->text().toInt();
           for(int i = 0; i < salairpersotest.length(); i++){
               for(int j = 0; j < numbers.length(); j++){
                   if(salairpersotest[i] == numbers[j]){
                       test3 = true;
                   }
               }
               if(test3 == false ){
                   verif_salaire = false;
                   QMessageBox::information(nullptr, QObject::tr("Erreur"),
                               QObject::tr("Erreur salaire invalide .\n"
                                           "Click Cancel to exit."), QMessageBox::Cancel);

                   break;
               }
           }

           QString nom= ui->nom->text();
           QString alphab1 = "azertyuiopqsdfghjklmwxcvbnéàçAZERTYUIOPQSDFGHJKLMWXCVBN";
             for(int i = 0; i < nom.length(); i++){
                 for(int j = 0; j < alphab1.length(); j++){
                     if(nom[i] == alphab1[j]){
                         test4 = true;
                     }
                 }
                 if(test4 == false ){
                     verif_nom = false;
                     QMessageBox::information(nullptr, QObject::tr("Erreur"),
                                 QObject::tr("Erreur nom invalide .\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);

                     break;
                 }
             }
        QString prenom= ui->prenom->text();
          for(int i = 0; i < prenom.length(); i++){
              for(int j = 0; j < alphab1.length(); j++){
                  if(prenom[i] == alphab1[j]){
                      test5 = true;
                  }
              }
              if(test5 == false ){
                  verif_prenom = false;
                  QMessageBox::information(nullptr, QObject::tr("Erreur"),
                              QObject::tr("Erreur prenom invalide .\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);

                  break;
              }
          }

if((verif_id == true)&&(verif_depart== true) && (verif_salaire==true) && (verif_nom==true) &&(verif_prenom==true)){
  personnel p( departement, nom, prenom , salaire , datenaiss , id, dateemb );
  bool test2=p.verifierId(id);
  if(test2)
  {
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un personnel"),
                  QObject::tr("déjà existant !.\n"
                              "Click Ok to exit."), QMessageBox::Ok);


    }
else{
      bool test=p.ajouter();
      if(test)
    {
                 ui->id->clear();
                 ui->departement->clear();
                 ui->salaire->clear();
                 ui->nom->clear();
                  ui->prenom->clear();
    ui->tableView_2->setModel(tmpp.afficher());//refresh
      ui->departement->setModel(tmpp.affecter());

    QMessageBox::information(nullptr, QObject::tr("Ajouter un produit"),
                      QObject::tr("Personnel ajouté.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);

    }
      else
          QMessageBox::critical(nullptr, QObject::tr("Ajouter un personnel"),
                      QObject::tr("Erreur !.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);



}
}

}


void Dialog::on_modifperso_clicked()
{
    bool verif_id,verif_depart,verif_nom,verif_prenom,verif_salaire;
   verif_id=true;
   verif_depart=true;
   verif_nom=true;
   verif_prenom=true;
   verif_salaire=true;
   //bool test2 = false;
   bool test3 = false;
   bool test4 = false ;
   bool test5 = false;

   QString numbers = "0123456789";
   QString id= ui->id->text();
    bool test1 = false;
   QString alphab = "azertyuiopqsdfghjklmwxcvbnéàçAZERTYUIOPQSDFGHJKLMWXCVBN0123456789";
     for(int i = 0; i < id.length(); i++){
         for(int j = 0; j < alphab.length(); j++){
             if(id[i] == alphab[j]){
                 test1 = true;
             }
         }
         if(test1 == false ){
             verif_id = false;
             QMessageBox::information(nullptr, QObject::tr("Erreur"),
                         QObject::tr("Erreur id invalide .\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);

             break;
         }
     }



          QString departement = ui->departement2->currentText();

           QString datenaiss = ui->datenaiss2->date().toString();
           QString dateemb = ui->dateemb2->date().toString();


         QString salairpersotest = ui->salaire2->text();
         int salaire = ui->salaire2->text().toInt();
           for(int i = 0; i < salairpersotest.length(); i++){
               for(int j = 0; j < numbers.length(); j++){
                   if(salairpersotest[i] == numbers[j]){
                       test3 = true;
                   }
               }
               if(test3 == false ){
                   verif_salaire = false;
                   QMessageBox::information(nullptr, QObject::tr("Erreur"),
                               QObject::tr("Erreur salaire invalide .\n"
                                           "Click Cancel to exit."), QMessageBox::Cancel);

                   break;
               }
           }

           QString nom= ui->nom2->text();
           QString alphab1 = "azertyuiopqsdfghjklmwxcvbnéàçAZERTYUIOPQSDFGHJKLMWXCVBN";
             for(int i = 0; i < nom.length(); i++){
                 for(int j = 0; j < alphab1.length(); j++){
                     if(nom[i] == alphab1[j]){
                         test4 = true;
                     }
                 }
                 if(test4 == false ){
                     verif_nom = false;
                     QMessageBox::information(nullptr, QObject::tr("Erreur"),
                                 QObject::tr("Erreur nom invalide .\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);

                     break;
                 }
             }
        QString prenom= ui->prenom2->text();
          for(int i = 0; i < prenom.length(); i++){
              for(int j = 0; j < alphab1.length(); j++){
                  if(prenom[i] == alphab1[j]){
                      test5 = true;
                  }
              }
              if(test5 == false ){
                  verif_prenom = false;
                  QMessageBox::information(nullptr, QObject::tr("Erreur"),
                              QObject::tr("Erreur prenom invalide .\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);

                  break;
              }
          }

if((verif_id == true)&&(verif_depart== true) && (verif_salaire==true) && (verif_nom==true) &&(verif_prenom==true)){
 personnel p( departement, nom, prenom , salaire , datenaiss , id ,dateemb);
 bool test = tmpp.modifier( departement, nom, prenom , salaire , datenaiss, id, dateemb);
    if(test)
  {
        ui->id2->clear();
        ui->departement2->clear();
        ui->salaire2->clear();
        ui->nom2->clear();
         ui->prenom2->clear();
 ui->tableView_2->setModel(tmpp.afficher());//refresh
  QMessageBox::information(nullptr, QObject::tr("Modifier un personnel"),
                    QObject::tr("personnel modifié.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

  }
    else
        QMessageBox::critical(nullptr, QObject::tr("Modifier un personnel"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);


}
}

void Dialog::on_pushButton_supp_clicked()
{
    bool verif_id , test1=true;
   verif_id=true;
    QString id = ui->id3->text();
            QString alphab = "azertyuiopqsdfghjklmwxcvbnéàçAZERTYUIOPQSDFGHJKLMWXCVBN0123456789";
              for(int i = 0; i < id.length(); i++){
                  for(int j = 0; j < alphab.length(); j++){
                      if(id[i] == alphab[j]){
                          test1 = true;
                      }
                  }
                  if(test1 == false ){
                      verif_id = false;
                      QMessageBox::information(nullptr, QObject::tr("Erreur"),
                                  QObject::tr("Erreur id invalide .\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);

                      break;
                  }
              }
    bool test=tmpp.supprimer(id);
    if(test)
    {ui->tableView_2->setModel(tmpp.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer un personnel"),
                    QObject::tr("Personnel supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un personnel"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}


 void Dialog::on_ajouterconge_clicked()
 {
     bool verif_ref,verif_idp;
    verif_ref=true;
    verif_idp=true;
    //bool test2 = false;
    bool test1 = false;
    QString alphab = "azertyuiopqsdfghjklmwxcvbnéàçAZERTYUIOPQSDFGHJKLMWXCVBN0123456789";

           QString reftest = ui->ref->text();
           int ref= ui->ref->text().toInt();
            QString numbers = "0123456789";
             for(int i = 0; i < reftest.length(); i++){
                 for(int j = 0; j < numbers.length(); j++){
                     if(reftest[i] == numbers[j]){
                         test1 = true;
                     }
                 }
                 if(test1 == false ){
                     verif_ref = false;
                     QMessageBox::information(nullptr, QObject::tr("Erreur"),
                                 QObject::tr("Erreur reference invalide .\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);

                     break;
                 }
             }

             QString id_p= ui->id_p->currentText();
             QString datedebut = ui->datedebut->date().toString();
               QString datefin = ui->datefin->date().toString();



 if(verif_ref== true){
   conge c (ref , id_p , datedebut , datefin);
    bool test2=c.verifierRef(ref);
   if(test2)
   {
       QMessageBox::critical(nullptr, QObject::tr("Ajouter un conge"),
                   QObject::tr("déjà existant !.\n"
                               "Click Ok to exit."), QMessageBox::Ok);


     }
 else{
       bool test=c.ajouterconge();
       if(test)
     {
                  ui->ref->clear();
                  ui->id_p->clear();

     ui->tableViewconge->setModel(tmpc.afficherconge());//refresh
     QMessageBox::information(nullptr, QObject::tr("Ajouter un conge"),
                       QObject::tr("conge ajouté.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);

     }
       else
           QMessageBox::critical(nullptr, QObject::tr("Ajouter un conge"),
                       QObject::tr("Erreur !.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);



 }
}
 }


 void Dialog::on_modifierconge_clicked()
 {
     bool verif_ref,verif_idp;
    verif_ref=true;
    verif_idp=true;
    bool test1 = false;
   // bool test2 = false;
    QString alphab = "azertyuiopqsdfghjklmwxcvbnéàçAZERTYUIOPQSDFGHJKLMWXCVBN0123456789";
         QString refcongetest = ui->ref2->text();
         int ref = ui->ref2->text().toInt();
         QString numbers = "0123456789";
           for(int i = 0; i < refcongetest.length(); i++){
               for(int j = 0; j < numbers.length(); j++){
                   if(refcongetest[i] == numbers[j]){
                       test1 = true;
                   }
               }
               if(test1 == false ){
                   verif_ref = false;
                   QMessageBox::information(nullptr, QObject::tr("Erreur"),
                               QObject::tr("Erreur reference invalide .\n"
                                           "Click Cancel to exit."), QMessageBox::Cancel);

                   break;
               }
           }

            QString id_p= ui->id_p_2->currentText();






             QString datedebut = ui->datenaiss2->date().toString();
             QString datefin = ui->dateemb2->date().toString();




 if(verif_ref== true){
  conge c (ref , id_p , datedebut , datefin);
      bool test=c.modifierconge(ref,id_p, datedebut , datefin);
      if(test)
    {
                 ui->ref2->clear();
                 ui->id_p_2->clear();

    ui->tableViewconge->setModel(tmpc.afficherconge());//refresh
    QMessageBox::information(nullptr, QObject::tr("Modifier un conge"),
                      QObject::tr("conge modifié.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);

    }
      else
          QMessageBox::critical(nullptr, QObject::tr("Modifier un conge"),
                      QObject::tr("Erreur !.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);



}

}


 void Dialog::on_supprimerconge_clicked()
 {

     QString id_p = ui->id_p_3->currentText();

     bool test=tmpc.supprimerconge(id_p);
     if(test)
     {ui->tableViewconge->setModel(tmpc.afficherconge());//refresh
         QMessageBox::information(nullptr, QObject::tr("Supprimer un conge"),
                     QObject::tr("conge supprimé.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);

     }
     else
         QMessageBox::critical(nullptr, QObject::tr("Supprimer un conge"),
                     QObject::tr("Erreur !.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);

 }



 void Dialog::on_ajouterdepartement_clicked()
 {
     bool verif_num,verif_nomd;
    verif_num=true;
    verif_nomd=true;
    bool test2 = false;
    bool test1 = false;
    QString numtest = ui->num->text();
           QString num = ui->num->text();
           QString numbers = "0123456789";
             for(int i = 0; i < numtest.length(); i++){
                 for(int j = 0; j < numbers.length(); j++){
                     if(numtest[i] == numbers[j]){
                         test1 = true;
                     }
                 }
                 if(test1 == false ){
                     verif_num = false;
                     QMessageBox::information(nullptr, QObject::tr("Erreur"),
                                 QObject::tr("Erreur id invalide .\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);

                     break;
                 }
             }
             QString nom_d= ui->nomd->text();
             QString alphab = "azertyuiopqsdfghjklmwxcvbnéàçAZERTYUIOPQSDFGHJKLMWXCVBN";
               for(int i = 0; i < nom_d.length(); i++){
                   for(int j = 0; j < alphab.length(); j++){
                       if(nom_d[i] == alphab[j]){
                           test2 = true;
                       }
                   }
                   if(test2 == false ){
                       verif_nomd = false;
                       QMessageBox::information(nullptr, QObject::tr("Erreur"),
                                   QObject::tr("Erreur nom invalide .\n"
                                               "Click Cancel to exit."), QMessageBox::Cancel);

                       break;
                   }
               }




 if((verif_num == true)&&(verif_nomd== true)){
   departement d (num , nom_d);
   bool test2=d.verifierNum(num);
   if(test2)
   {
       QMessageBox::critical(nullptr, QObject::tr("Ajouter un departement"),
                   QObject::tr("déjà existant !.\n"
                               "Click Ok to exit."), QMessageBox::Ok);


     }
 else{
       bool test=d.ajouterdepartement();
       if(test)
     {
                  ui->num->clear();
                  ui->nomd->clear();

     ui->tableViewdepartement->setModel(tmpd.afficherdepartement());//refresh
     QMessageBox::information(nullptr, QObject::tr("Ajouter un departement"),
                       QObject::tr("departement ajouté.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);

     }
       else
           QMessageBox::critical(nullptr, QObject::tr("Ajouter un departement"),
                       QObject::tr("Erreur !.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);



 }
}
 }


 void Dialog::on_modifierdepartement_clicked()
 {
     //int nb;
     bool verif_num,verif_nomd;
    verif_num=true;
    verif_nomd=true;
    bool test2 = false;
    bool test1 = false;
    QString numtest = ui->num1->text();
           QString num = ui->num1->text();
           QString numbers = "0123456789";
             for(int i = 0; i < numtest.length(); i++){
                 for(int j = 0; j < numbers.length(); j++){
                     if(numtest[i] == numbers[j]){
                         test1 = true;
                     }
                 }
                 if(test1 == false ){
                     verif_num = false;
                     QMessageBox::information(nullptr, QObject::tr("Erreur"),
                                 QObject::tr("Erreur id invalide .\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);

                     break;
                 }
             }
             QString nom_d= ui->nomd1->text();
             QString alphab = "azertyuiopqsdfghjklmwxcvbnéàçAZERTYUIOPQSDFGHJKLMWXCVBN";
               for(int i = 0; i < nom_d.length(); i++){
                   for(int j = 0; j < alphab.length(); j++){
                       if(nom_d[i] == alphab[j]){
                           test2 = true;
                       }
                   }
                   if(test2 == false ){
                       verif_nomd = false;
                       QMessageBox::information(nullptr, QObject::tr("Erreur"),
                                   QObject::tr("Erreur nom invalide .\n"
                                               "Click Cancel to exit."), QMessageBox::Cancel);

                       break;
                   }
               }




 if((verif_num == true)&&(verif_nomd== true)){
   departement d (num , nom_d);
   qDebug()<<"a"<<num<<nom_d;
       bool test=d.modifierdepartement(num,nom_d);
        qDebug()<<"b"<<num<<nom_d;
       if(test)
     {
                  ui->num1->clear();
                  ui->nomd1->clear();

     ui->tableViewdepartement->setModel(tmpd.afficherdepartement());//refresh
     QMessageBox::information(nullptr, QObject::tr("modifier un departement"),
                       QObject::tr("departement modifié.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);

     }
       else
           QMessageBox::critical(nullptr, QObject::tr("Ajouter un departement"),
                       QObject::tr("Erreur !.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);



 }

}


 void Dialog::on_supprimerdepartement_clicked()
 {
     bool verif_num;
    verif_num=true;
    bool test1 = false;
    QString numtest = ui->num2->text();
           QString num = ui->num2->text();
           QString numbers = "0123456789";
             for(int i = 0; i < numtest.length(); i++){
                 for(int j = 0; j < numbers.length(); j++){
                     if(numtest[i] == numbers[j]){
                         test1 = true;
                     }
                 }
                 if(test1 == false ){
                     verif_num = false;
                     QMessageBox::information(nullptr, QObject::tr("Erreur"),
                                 QObject::tr("Erreur id invalide .\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);

                     break;
                 }
             }
     bool test=tmpd.supprimerdepartement(num);
     if(test)
     {ui->tableViewdepartement->setModel(tmpd.afficherdepartement());//refresh
         QMessageBox::information(nullptr, QObject::tr("Supprimer un departement"),
                     QObject::tr("département supprimé.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);

     }
     else
         QMessageBox::critical(nullptr, QObject::tr("Supprimer un departement"),
                     QObject::tr("Erreur !.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);

 }

void Dialog::on_refresh1_clicked()
{
    ui->tableView_2->setModel(tmpp.afficher());//refresh

    ui->tableViewconge->setModel(tmpc.afficherconge());
    ui->tableViewdepartement->setModel(tmpd.afficherdepartement());//refresh
    ui->id_p_3->setModel(tmpc.affecterperso());
    ui->chercher_c->setModel(tmpc.affecterperso());
    ui->id_p->setModel(tmpc.affecterperso());
     ui->id_p_2->setModel(tmpc.affecterperso());
    ui->departement->setModel(tmpp.affecter());
    ui->departement2->setModel(tmpp.affecter());
}
void Dialog::on_refresh2_clicked()
{
    ui->tableView_2->setModel(tmpp.afficher());//refresh

    ui->tableViewconge->setModel(tmpc.afficherconge());
    ui->tableViewdepartement->setModel(tmpd.afficherdepartement());//refresh
    ui->id_p_3->setModel(tmpc.affecterperso());
    ui->chercher_c->setModel(tmpc.affecterperso());
    ui->id_p->setModel(tmpc.affecterperso());
     ui->id_p_2->setModel(tmpc.affecterperso());
    ui->departement->setModel(tmpp.affecter());
    ui->departement2->setModel(tmpp.affecter());
}
void Dialog::on_refresh3_clicked()
{
    ui->tableView_2->setModel(tmpp.afficher());//refresh

    ui->tableViewconge->setModel(tmpc.afficherconge());
    ui->tableViewdepartement->setModel(tmpd.afficherdepartement());//refresh
    ui->id_p_3->setModel(tmpc.affecterperso());
    ui->chercher_c->setModel(tmpc.affecterperso());
    ui->id_p->setModel(tmpc.affecterperso());
     ui->id_p_2->setModel(tmpc.affecterperso());
    ui->departement->setModel(tmpp.affecter());
    ui->departement2->setModel(tmpp.affecter());
}

void Dialog::on_chercher_clicked()
{
    QString  id=ui->chercher_2->text();
    ui->tableView_2->setModel(tmpp.chercher(id));


}
void Dialog::on_chercherconge_clicked()
{
    QString  id_p=ui->chercher_c->currentText();
    ui->tableViewconge->setModel(tmpc.chercherconge(id_p));


}

void Dialog::on_chercherdepart_clicked()
{
    QString  num=ui->chercherd->text();
    ui->tableViewdepartement->setModel(tmpd.chercherdepart(num));


}



void Dialog::on_departement_currentTextChanged(const QString &arg1)
{

}




void Dialog::sendMail()
{
    Smtp* smtp = new Smtp(ui->uname->text(), ui->paswd->text(), ui->server->text(), ui->port->text().toUShort());
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));


    smtp->sendMail(ui->uname->text(), ui->rcpt->text() , ui->subject->text(),ui->msg->toPlainText());
}

void Dialog::mailSent(QString status)
{
    if(status == "Message sent")
        QMessageBox::warning( nullptr, tr( "Qt Simple SMTP client" ), tr( "Message sent!\n\n" ) );
}




void Dialog::on_personnel1_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void Dialog::on_conge1_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void Dialog::on_departement1_clicked()
{
    ui->stackedWidget->setCurrentIndex(12);
}


void Dialog::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void Dialog::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void Dialog::on_pushButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void Dialog::on_pushButton_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void Dialog::on_personnel2_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void Dialog::on_conge2_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void Dialog::on_departement2_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(12);
}


void Dialog::on_pushButton_18_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void Dialog::on_pushButton_21_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}


void Dialog::on_pushButton_17_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}


void Dialog::on_pushButton_22_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void Dialog::on_pushButton_25_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void Dialog::on_pushButton_26_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}


void Dialog::on_pushButton_49_clicked()
{
    ui->stackedWidget->setCurrentIndex(12);
}

void Dialog::on_pushButton_27_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void Dialog::on_pushButton_29_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void Dialog::on_pushButton_31_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}


void Dialog::on_pushButton_30_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void Dialog::on_pushButton_37_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void Dialog::on_pushButton_35_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void Dialog::on_pushButton_50_clicked()
{
    ui->stackedWidget->setCurrentIndex(12);
}

void Dialog::on_pushButton_39_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void Dialog::on_pushButton_36_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void Dialog::on_pushButton_40_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void Dialog::on_pushButton_32_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void Dialog::on_pushButton_84_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void Dialog::on_pushButton_85_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void Dialog::on_pushButton_130_clicked()
{
    ui->stackedWidget->setCurrentIndex(12);
}

void Dialog::on_pushButton_89_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void Dialog::on_pushButton_88_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void Dialog::on_pushButton_87_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void Dialog::on_pushButton_83_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void Dialog::on_pushButton_14_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void Dialog::on_pushButton_9_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void Dialog::on_pushButton_47_clicked()
{
    ui->stackedWidget->setCurrentIndex(12);
}

void Dialog::on_pushButton_13_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}

void Dialog::on_pushButton_10_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);
}

void Dialog::on_pushButton_12_clicked()
{
    ui->stackedWidget->setCurrentIndex(8);
}

void Dialog::on_pushButton_11_clicked()
{
    ui->stackedWidget->setCurrentIndex(9);
}

void Dialog::on_pushButton_90_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void Dialog::on_pushButton_91_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void Dialog::on_pushButton_128_clicked()
{
    ui->stackedWidget->setCurrentIndex(12);
}

void Dialog::on_pushButton_92_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}

void Dialog::on_pushButton_94_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);
}

void Dialog::on_pushButton_96_clicked()
{
    ui->stackedWidget->setCurrentIndex(9);
}

void Dialog::on_pushButton_95_clicked()
{
    ui->stackedWidget->setCurrentIndex(8);
}

void Dialog::on_pushButton_102_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void Dialog::on_pushButton_98_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void Dialog::on_pushButton_129_clicked()
{
    ui->stackedWidget->setCurrentIndex(12);
}

void Dialog::on_pushButton_100_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}

void Dialog::on_pushButton_99_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);
}

void Dialog::on_pushButton_103_clicked()
{
    ui->stackedWidget->setCurrentIndex(9);
}

void Dialog::on_pushButton_97_clicked()
{
    ui->stackedWidget->setCurrentIndex(8);
}

void Dialog::on_pushButton_109_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void Dialog::on_pushButton_105_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void Dialog::on_pushButton_131_clicked()
{
    ui->stackedWidget->setCurrentIndex(12);
}

void Dialog::on_pushButton_107_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}

void Dialog::on_pushButton_106_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);
}

void Dialog::on_pushButton_110_clicked()
{
    ui->stackedWidget->setCurrentIndex(9);
}

void Dialog::on_pushButton_104_clicked()
{
    ui->stackedWidget->setCurrentIndex(8);
}

void Dialog::on_pushButton_116_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void Dialog::on_pushButton_112_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void Dialog::on_pushButton_132_clicked()
{
    ui->stackedWidget->setCurrentIndex(12);
}

void Dialog::on_pushButton_114_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}

void Dialog::on_pushButton_113_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);
}

void Dialog::on_pushButton_117_clicked()
{
    ui->stackedWidget->setCurrentIndex(9);
}

void Dialog::on_pushButton_111_clicked()
{
    ui->stackedWidget->setCurrentIndex(8);
}

void Dialog::on_pushButton_276_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void Dialog::on_pushButton_275_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void Dialog::on_pushButton_277_clicked()
{
    ui->stackedWidget->setCurrentIndex(12);
}

void Dialog::on_pushButton_278_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void Dialog::on_pushButton_279_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void Dialog::on_pushButton_280_clicked()
{
    ui->stackedWidget->setCurrentIndex(12);
}

void Dialog::on_pushButton_227_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void Dialog::on_pushButton_230_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void Dialog::on_pushButton_229_clicked()
{
    ui->stackedWidget->setCurrentIndex(12);
}

void Dialog::on_pushButton_220_clicked()
{
    ui->stackedWidget->setCurrentIndex(13);
}

void Dialog::on_pushButton_226_clicked()
{
    ui->stackedWidget->setCurrentIndex(14);
}

void Dialog::on_pushButton_222_clicked()
{
    ui->stackedWidget->setCurrentIndex(15);
}

void Dialog::on_pushButton_224_clicked()
{
    ui->stackedWidget->setCurrentIndex(16);
}

void Dialog::on_pushButton_238_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void Dialog::on_pushButton_237_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void Dialog::on_pushButton_236_clicked()
{
    ui->stackedWidget->setCurrentIndex(12);
}

void Dialog::on_pushButton_235_clicked()
{
    ui->stackedWidget->setCurrentIndex(13);
}

void Dialog::on_pushButton_232_clicked()
{
    ui->stackedWidget->setCurrentIndex(14);
}

void Dialog::on_pushButton_233_clicked()
{
    ui->stackedWidget->setCurrentIndex(16);
}

void Dialog::on_pushButton_223_clicked()
{
    ui->stackedWidget->setCurrentIndex(15);
}

void Dialog::on_pushButton_241_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void Dialog::on_pushButton_244_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void Dialog::on_pushButton_242_clicked()
{
    ui->stackedWidget->setCurrentIndex(12);
}

void Dialog::on_pushButton_240_clicked()
{
    ui->stackedWidget->setCurrentIndex(13);
}

void Dialog::on_pushButton_243_clicked()
{
    ui->stackedWidget->setCurrentIndex(14);
}

void Dialog::on_pushButton_246_clicked()
{
    ui->stackedWidget->setCurrentIndex(16);
}

void Dialog::on_pushButton_245_clicked()
{
    ui->stackedWidget->setCurrentIndex(15);
}

void Dialog::on_pushButton_250_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void Dialog::on_pushButton_249_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void Dialog::on_pushButton_257_clicked()
{
    ui->stackedWidget->setCurrentIndex(12);
}

void Dialog::on_pushButton_254_clicked()
{
    ui->stackedWidget->setCurrentIndex(13);
}

void Dialog::on_pushButton_255_clicked()
{
    ui->stackedWidget->setCurrentIndex(14);
}

void Dialog::on_pushButton_253_clicked()
{
    ui->stackedWidget->setCurrentIndex(16);
}

void Dialog::on_pushButton_251_clicked()
{
    ui->stackedWidget->setCurrentIndex(15);
}

void Dialog::on_pushButton_259_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void Dialog::on_pushButton_258_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void Dialog::on_pushButton_266_clicked()
{
    ui->stackedWidget->setCurrentIndex(12);
}

void Dialog::on_pushButton_263_clicked()
{
    ui->stackedWidget->setCurrentIndex(13);
}

void Dialog::on_pushButton_264_clicked()
{
    ui->stackedWidget->setCurrentIndex(14);
}

void Dialog::on_pushButton_262_clicked()
{
    ui->stackedWidget->setCurrentIndex(16);
}

void Dialog::on_pushButton_260_clicked()
{
    ui->stackedWidget->setCurrentIndex(15);
}

void Dialog::on_pushButton_24_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void Dialog::on_pushButton_23_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void Dialog::on_pushButton_48_clicked()
{
    ui->stackedWidget->setCurrentIndex(12);
}

void Dialog::on_pushButton_221_clicked()
{
     ui->stackedWidget->setCurrentIndex(11);
}

void Dialog::on_pushButton_225_clicked()
{
    statistique S ;
            S.exec();
}


