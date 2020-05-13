#include "menu.h"
#include "ui_menu.h"
#include "produit.h"
#include "nomen.h"
#include "menus.h"
#include "bonf.h"
#include "boni.h"
#include "qcustomplot.h"
#include "fourn.h"
#include <QMessageBox>
#include <QTableWidget>
#include <QTableView>
#include <QPixmap>
#include <QComboBox>
#include <QPrinter>
#include <QPrintDialog>

#include <QDate>
menu::menu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::menu)
{

ui->setupUi(this);




}
menu::~menu()
{
    delete ui;
}

void menu::on_ajouterproduit_clicked()
{
    bool verif_code,verif_libelle,verif_prix,verif_qt;
   verif_code=true;
   verif_libelle=true;
   verif_qt=true;
   verif_prix=true;
   bool verifHedhi2 = false;
   bool verifHedhi3 = false;

   QString code = ui->lineEdit_code->text();
        QString numbers = "0123456789";
          bool verifHedhi = false;
          for(int i = 0; i < code.length(); i++){
              for(int j = 0; j < numbers.length(); j++){
                  if(code[i] == numbers[j]){
                      verifHedhi = true;
                  }
              }
              if(verifHedhi == false ){
                  verif_code = false;
                  QMessageBox::information(nullptr, QObject::tr("Erreur"),
                              QObject::tr("Erreur code invalide .\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);

                  break;
              }
          }
           QString libelle= ui->lineEdit_lib->text();
          QString alphab = "azertyuiopqsdfghjklmwxcvbnéàçAZERTYUIOPQSDFGHJKLMWXCVBN";
            bool verifHedhi1 = false;
            for(int i = 0; i < libelle.length(); i++){
                for(int j = 0; j < alphab.length(); j++){
                    if(libelle[i] == alphab[j]){
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
            QString dateprod=ui->dateEdit->date().toString();

            QString prixprodtest = ui->lineEdit_prix->text();
           int prix = ui->lineEdit_prix->text().toInt();


       for(int i = 0; i < prixprodtest.length(); i++){
           for(int j = 0; j < numbers.length(); j++){
               if(prixprodtest[i] == numbers[j]){
                   verifHedhi2 = true;
               }
           }
           if(verifHedhi2 == false ){
               verif_prix = false;
               QMessageBox::information(nullptr, QObject::tr("Erreur"),
                           QObject::tr("Erreur prix invalide .\n"
                                       "Click Cancel to exit."), QMessageBox::Cancel);

               break;
           }
       }
       QString qtprodtest = ui->lineEdit_qt->text();
       int qt = ui->lineEdit_qt->text().toInt();
       for(int i = 0; i < qtprodtest.length(); i++){
           for(int j = 0; j < numbers.length(); j++){
               if(qtprodtest[i] == numbers[j]){
                   verifHedhi3 = true;
               }
           }
           if(verifHedhi3 == false ){
               verif_qt = false;
               QMessageBox::information(nullptr, QObject::tr("Erreur"),
                           QObject::tr("Erreur qyantités invalide .\n"
                                       "Click Cancel to exit."), QMessageBox::Cancel);

               break;
           }
       }
       QString catg= ui->comboBox_2->currentText();
       QString famil= ui->comboBox->currentText();
        if((verif_code == true)&&(verif_qt== true) && (verif_prix==true)&&(verif_libelle)){
            produit  p(code,libelle,dateprod,prix,qt,catg,famil);
                bool test=p.ajouter();
    if(test)
  {
        ui->lineEdit_code->clear();
               ui->lineEdit_lib->clear();
               ui->lineEdit_prix->clear();
               ui->lineEdit_qt->clear();
ui->tableViewarwa_2->setModel(tmpp.afficher());//refresh
  QMessageBox::information(nullptr, QObject::tr("Ajouter un produit"),
                    QObject::tr("Produit ajouté.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

  }
    else
        QMessageBox::critical(nullptr, QObject::tr("Modifier un produit"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);


}
}




void menu::on_ajouternomen_clicked()
{
    bool verif_code,verif_coef,verif_codecomp;
   verif_code=true;
   verif_codecomp=true;
   verif_coef=true;

       QString codeprodtest = ui->lineEdit_68->text();
    int code = ui->lineEdit_68->text().toInt();
    QString numbers = "0123456789";
      bool verifHedhi = false;
      for(int i = 0; i < codeprodtest.length(); i++){
          for(int j = 0; j < numbers.length(); j++){
              if(codeprodtest[i] == numbers[j]){
                  verifHedhi = true;
              }
          }
          if(verifHedhi == false ){
              verif_code = false;
              QMessageBox::information(nullptr, QObject::tr("Erreur"),
                          QObject::tr("Erreur code invalide .\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);

              break;
          }
      }

        int codecomp = ui->lineEdit_2->text().toInt();
        if (codecomp ==0){
                      verif_codecomp = false;
                      QMessageBox::information(nullptr, QObject::tr("Erreur"),
                                  QObject::tr("Erreur code compossante invalide .\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);
                  }
        int coef = ui->lineEdit_70->text().toInt();
        if (coef ==0){
                      verif_coef = false;
                      QMessageBox::information(nullptr, QObject::tr("Erreur"),
                                  QObject::tr("Erreur coeffision invalide .\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);
                  }


      if((verif_code == true)&&(verif_codecomp== true) && (verif_coef==true)){
      nomen n(code,codecomp,coef);
      bool test=n.ajouter();
      if(test)
    {

          ui->lineEdit_68->clear();
                 ui->lineEdit_2->clear();
                 ui->lineEdit_70->clear();
    QMessageBox::information(nullptr, QObject::tr("Ajouter une nomenclature"),
                      QObject::tr("Nomenclature ajouté.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);

    }
      else
          QMessageBox::critical(nullptr, QObject::tr("Ajouter une nomenclature"),
                      QObject::tr("Erreur !.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);
}
}


void menu::on_pushButton_supp_clicked()
{

    bool verif_code=true;

    QString code = ui->lineEdit_12->text();
    QString numbers = "0123456789";
      bool verifHedhi = false;
      for(int i = 0; i < code.length(); i++){
          for(int j = 0; j < numbers.length(); j++){
              if(code[i] == numbers[j]){
                  verifHedhi = true;
              }
          }
          if(verifHedhi == false ){
              verif_code = false;
              QMessageBox::information(nullptr, QObject::tr("Erreur"),
                          QObject::tr("Erreur code invalide .\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);

              break;
          }
      }
    if(verif_code == true){
    bool test=tmpp.supprimer(code);
    if(test)
    {
        ui->lineEdit_12->clear();
        ui->tableViewarwa->setModel(tmpp.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer un produit"),
                    QObject::tr("Produit supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un produit"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
}



void menu::on_modifprod_clicked()
{
    bool verif_code,verif_libelle,verif_prix,verif_qt;
   verif_code=true;
   verif_libelle=true;
   verif_qt=true;
   verif_prix=true;
   bool verifHedhi2 = false;
   bool verifHedhi3 = false;
        QString code = ui->lineEdit_code_2->text();

        QString numbers = "0123456789";
          bool verifHedhi = false;
          for(int i = 0; i < code.length(); i++){
              for(int j = 0; j < numbers.length(); j++){
                  if(code[i] == numbers[j]){
                      verifHedhi = true;
                  }
              }
              if(verifHedhi == false ){
                  verif_code = false;
                  QMessageBox::information(nullptr, QObject::tr("Erreur"),
                              QObject::tr("Erreur code invalide .\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);

                  break;
              }
          }
          QString libelle= ui->lineEdit_lib_2->text();
          QString alphab = "azertyuiopqsdfghjklmwxcvbnéàçAZERTYUIOPQSDFGHJKLMWXCVBN";
            bool verifHedhi1 = false;
            for(int i = 0; i < libelle.length(); i++){
                for(int j = 0; j < alphab.length(); j++){
                    if(libelle[i] == alphab[j]){
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
     QString dateprod=ui->dateEdit_2->date().toString();
        QString prixprodtest = ui->lineEdit_prix_11->text();
       int prix = ui->lineEdit_prix_11->text().toInt();

       for(int i = 0; i < prixprodtest.length(); i++){
           for(int j = 0; j < numbers.length(); j++){
               if(prixprodtest[i] == numbers[j]){
                   verifHedhi2 = true;
               }
           }
           if(verifHedhi2 == false ){
               verif_prix = false;
               QMessageBox::information(nullptr, QObject::tr("Erreur"),
                           QObject::tr("Erreur prix invalide .\n"
                                       "Click Cancel to exit."), QMessageBox::Cancel);

               break;
           }
       }
       QString qtprodtest = ui->lineEdit_qt_5->text();
       int qt = ui->lineEdit_qt_5->text().toInt();
       for(int i = 0; i < qtprodtest.length(); i++){
           for(int j = 0; j < numbers.length(); j++){
               if(qtprodtest[i] == numbers[j]){
                   verifHedhi3 = true;
               }
           }
           if(verifHedhi3 == false ){
               verif_qt = false;
               QMessageBox::information(nullptr, QObject::tr("Erreur"),
                           QObject::tr("Erreur qyantités invalide .\n"
                                       "Click Cancel to exit."), QMessageBox::Cancel);

               break;
           }
       }
        QString catg= ui->comboBox_5->currentText();
        QString famil= ui->comboBox_3->currentText();
        if((verif_code == true)&&(verif_qt== true) && (verif_prix==true)&&(verif_libelle)){
    produit p(code,libelle,dateprod,prix,qt,catg,famil);
    bool test = tmpp.modifier(code,libelle,dateprod,prix,qt,catg,famil);
    if(test)
  {
        ui->lineEdit_code_2->clear();
               ui->lineEdit_lib_2->clear();
               ui->lineEdit_qt_5->clear();
               ui->lineEdit_prix_11->clear();
ui->tableViewarwa->setModel(tmpp.afficher());//refresh
  QMessageBox::information(nullptr, QObject::tr("Modifier un produit"),
                    QObject::tr("Produit modifié.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

  }
    else
        QMessageBox::critical(nullptr, QObject::tr("Modifier un produit"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);


}
}


void menu::on_ajoutermenu_clicked()
{
    bool verif_code=true;
    bool verif_qtprod=true;
    QString code = ui->comboBox_16->currentText();

    QString numbers = "0123456789";
      bool verifHedhi = false;
      for(int i = 0; i < code.length(); i++){
          for(int j = 0; j < numbers.length(); j++){
              if(code[i] == numbers[j]){
                  verifHedhi = true;
              }
          }
          if(verifHedhi == false ){
              verif_code = false;
              QMessageBox::information(nullptr, QObject::tr("Erreur"),
                          QObject::tr("Erreur code invalide .\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);

              break;
          }
      }

            QString nature = ui->comboBox_17->currentText();
            QString datemenu=ui->dateEdit_3->date().toString();

            QString qtprod = ui->lineEdit_7->text();

              bool verifHedhi1 = false;
              for(int i = 0; i < qtprod.length(); i++){
                  for(int j = 0; j < numbers.length(); j++){
                      if(qtprod[i] == numbers[j]){
                          verifHedhi1 = true;
                      }
                  }
                  if(verifHedhi1 == false ){
                      bool verif_qtprod = false;
                      QMessageBox::information(nullptr, QObject::tr("Erreur"),
                                  QObject::tr("Erreur qt produit invalide .\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);

                      break;
                  }
              }
            QString libelle= ui->lineEdit_6->text();
if((verif_code == true)&&(verif_qtprod== true) ){
      menus  mn(code,nature,datemenu,qtprod,libelle);
          bool test=mn.ajouter();
          if(test)
        {
              ui->comboBox_16->clear();
              ui->lineEdit_7->clear();
              ui->lineEdit_6->clear();

     ui->tableView_4->setModel(tmpmn.afficher2(datemenu));//refresh
    ui->tableView->setModel(tmpmn.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Ajouter un menu"),
                          QObject::tr("Menu ajouté.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);

        }
          else
              QMessageBox::critical(nullptr, QObject::tr("Menu un menu"),
                          QObject::tr("Erreur !.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);


    }}





void menu::on_pushButton_suppmenu_clicked()
{
    QString nature = ui->comboBox_28->currentText();
    QString datemenu=ui->dateEdit_5->date().toString();
    bool test=tmpmn.supprimer(datemenu,nature);
    if(test)
    {

        ui->tableView->setModel(tmpmn.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer un menu"),
                    QObject::tr("Produit supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un menu"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);


}


void menu::on_pushButton_clicked()
{
    QString code = ui->comboBox_18->currentText();
    QString nature = ui->comboBox_27->currentText();
    QString datemenu=ui->dateEdit_6->date().toString();
    QString qtprod = ui->lineEdit_9->text();
    QString libelle= ui->lineEdit_10->text();

    menus  mn(code,nature,datemenu,qtprod,libelle);
        bool test=mn.modifier(code,nature,datemenu,qtprod,libelle);
    if(test)
  {
        ui->comboBox_18->clear();
               ui->lineEdit_9->clear();
               ui->lineEdit_10->clear();

 ui->tableView->setModel(tmpmn.afficher());//refresh
 ui->tableView_4->setModel(tmpmn.afficher2(datemenu));//refresh
  QMessageBox::information(nullptr, QObject::tr("Modifier un produit"),
                    QObject::tr("Produit modifié.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

  }
    else
        QMessageBox::critical(nullptr, QObject::tr("Modifier un produit"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);



}


void menu::on_refresh_clicked()
{
 ui->tableView->setModel(tmpmn.afficher());//refresh
}


void menu::on_refajout_clicked()
{
    ui->comboBox_16->setModel(tmpp.listerprod());

}

void menu::on_refmodif_clicked()
{
 ui->comboBox_18->setModel(tmpp.listerprod());
}





void menu::on_pushButton_20_clicked()
{
  ui->tableViewarwa->setModel(tmpp.tridesc());//refresh
}



void menu::on_ajouterbonf_clicked()
{

              QString pic = ui->lineEdit_30->text();
              QString codef = ui->comboBox_23->currentText();
              QString datebonf=ui->dateEdit_12->date().toString();
               QString codep = ui->comboBox_8->currentText();
              QString libelle= ui->lineEdit_20->text();
                QString qtprod = ui->lineEdit_21->text();


          bonf  bf(pic,codef,datebonf,codep,libelle,qtprod);
              bool test=bf.ajouterbonf();
              if(test)
            {
                  ui->comboBox_8->clear();
                  ui->lineEdit_20->clear();
                  ui->lineEdit_21->clear();

         ui->tableView_9->setModel(tmpbf.afficher2(pic));//refresh
        ui->tableView_3->setModel(tmpbf.afficher());//refresh
            QMessageBox::information(nullptr, QObject::tr("Ajouter un bon fournisseur"),
                              QObject::tr("Bon  ajouté.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);

            }
              else
                  QMessageBox::critical(nullptr, QObject::tr("Ajouter un bon fournisseur"),
                              QObject::tr("Erreur !.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);





}







void menu::on_ajoutermenu_6_clicked()
{
    QString pic = ui->lineEdit_63->text();
    QString datebonf=ui->dateEdit_26->date().toString();
     QString codep = ui->comboBox_4->currentText();
    QString libelle= ui->lineEdit_61->text();
      QString qtprod = ui->lineEdit_62->text();


boni  bi(pic,datebonf,codep,libelle,qtprod);
    bool test=bi.ajouter();
    if(test)
  {
        ui->comboBox_8->clear();
        ui->lineEdit_20->clear();
        ui->lineEdit_21->clear();

ui->tableView_17->setModel(tmpbi.afficher2(pic));//refresh
ui->tableView_7->setModel(tmpbi.afficher());//refresh
  QMessageBox::information(nullptr, QObject::tr("Ajouter un bon intérne"),
                    QObject::tr("Bon  ajouté.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

  }
    else
        QMessageBox::critical(nullptr, QObject::tr("Ajouter un bon intérne"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void menu::on_refprod_6_clicked()
{
 ui->comboBox_8->setModel(tmpp.listerprod());
}

void menu::on_refprod_11_clicked()
{
 ui->comboBox_4->setModel(tmpp.listerprod());
}

void menu::on_refprod_2_clicked()
{
    ui->tableView_3->setModel(tmpbf.afficher());//refresh
}

void menu::on_refprod_10_clicked()
{
   ui->tableView_7->setModel(tmpbi.afficher());//refresh
}

void menu::on_suppboni_clicked()
{
QString pic = ui->lineEdit_70->text();

    bool test=tmpbi.supprimer(pic);
    if(test)
    {

        ui->tableView_7->setModel(tmpbi.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer un bon"),
                    QObject::tr("Bon supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un bon"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}

void menu::on_suppbonf_clicked()
{
    QString pic = ui->lineEdit_32->text();

        bool test=tmpbf.supprimer(pic);
        if(test)
        {

            ui->tableView_3->setModel(tmpbf.afficher());//refresh
            QMessageBox::information(nullptr, QObject::tr("Supprimer un bon"),
                        QObject::tr("Bon supprimé.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

        }
        else
            QMessageBox::critical(nullptr, QObject::tr("Supprimer un bon"),
                        QObject::tr("Erreur !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
}
void menu::on_pushButton_6_clicked()
{
    //pour imprimer
        bonf bf;
            QString text=bf.apercu_pdf();
            ui->imprimbf->setText(text);

            QPrinter printer ;
            printer.setPrinterName("nom");
            QPrintDialog dialog (&printer,this);
            if(dialog.exec()==QDialog::Rejected) return ;
            ui->imprimbf->print(&printer);

}


void menu::on_pushButton_33_clicked()
{
    QString pic = ui->lineEdit_63->text();
    QString dateboni=ui->dateEdit_26->date().toString();
     QString codep = ui->comboBox_4->currentText();
    QString libelle= ui->lineEdit_61->text();
      QString qtprod = ui->lineEdit_62->text();
    boni  bi(pic,dateboni,codep,libelle,qtprod);
        bool test=bi.modifier(pic,dateboni,codep,libelle,qtprod);
    if(test)
  {
        ui->comboBox_4->clear();
               ui->lineEdit_61->clear();
               ui->lineEdit_62->clear();

 ui->tableView_7->setModel(tmpbi.afficher());//refresh
 ui->tableView_17->setModel(tmpbi.afficher2(pic));//refresh
  QMessageBox::information(nullptr, QObject::tr("Modifier un bon"),
                    QObject::tr("Bon modifié.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

  }
    else
        QMessageBox::critical(nullptr, QObject::tr("Modifier un bon"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}

void menu::on_refprod_12_clicked()
{
    ui->comboBox_7->setModel(tmpp.listerprod());

}

void menu::on_refprod_7_clicked()
{
    ui->comboBox_20->setModel(tmpp.listerprod());

}

void menu::on_modifbonf_clicked()
{
    QString pic = ui->lineEdit_31->text();
    QString codef = ui->comboBox_9->currentText();

    QString datebonf=ui->dateEdit_9->date().toString();
     QString codep = ui->comboBox_20->currentText();
    QString libelle= ui->lineEdit_22->text();
      QString qtprod = ui->lineEdit_23->text();
    bonf  bf(pic,codef,datebonf,codep,libelle,qtprod);
        bool test=bf.modifier(pic,codef,datebonf,codep,libelle,qtprod);
    if(test)
  {
        ui->comboBox_20->clear();
               ui->lineEdit_22->clear();
               ui->lineEdit_23->clear();

 ui->tableView_3->setModel(tmpbf.afficher());//refresh
 ui->tableView_9->setModel(tmpbf.afficher2(pic));//refresh
  QMessageBox::information(nullptr, QObject::tr("Modifier un bon"),
                    QObject::tr("Bon modifié.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

  }
    else
        QMessageBox::critical(nullptr, QObject::tr("Modifier un bon"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void menu::on_refprod_18_clicked()
{
    ui->comboBox_23->setModel(tmpf.listerfourn());

}

void menu::on_refprod_13_clicked()
{
     ui->comboBox_9->setModel(tmpf.listerfourn());
}

void menu::on_ajouterfourn_clicked()
{
    QString code = ui->lineEdit_18->text();
    QString adr = ui->lineEdit_72->text();
     QString tel = ui->lineEdit_73->text();
    QString reg=ui->comboBox_25->currentText();
    QString fax= ui->lineEdit_76->text();
      QString mail = ui->lineEdit_77->text();
      QString dailliv = ui->lineEdit_78->text();
      QString modepi = ui->comboBox_29->currentText();


fourn  f(code,adr,tel,reg,fax,mail,dailliv,modepi);
    bool test=f.ajouter();
    if(test)
  {
        ui->lineEdit_18->clear();
        ui->lineEdit_72->clear();
        ui->lineEdit_73->clear();
        ui->lineEdit_76->clear();
        ui->lineEdit_77->clear();
        ui->lineEdit_78->clear();


ui->tableViewarwa_2->setModel(tmpf.afficher());//refresh
  QMessageBox::information(nullptr, QObject::tr("Ajouter un  fournisseur"),
                    QObject::tr("Fournisseur  ajouté.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

  }
    else
        QMessageBox::critical(nullptr, QObject::tr("Ajouter un bon fournisseur"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);





}

void menu::on_modifprod_2_clicked()
{
    QString code = ui->lineEdit_17->text();
    QString adr = ui->lineEdit_54->text();
     QString tel = ui->lineEdit_26->text();
    QString reg=ui->comboBox_12->currentText();
    QString fax= ui->lineEdit_25->text();
      QString mail = ui->lineEdit_75->text();
      QString dailliv = ui->lineEdit_74->text();
      QString modepi = ui->comboBox_15->currentText();
      fourn  f(code,adr,tel,reg,fax,mail,dailliv,modepi);
          bool test=f.modifier(code,adr,tel,reg,fax,mail,dailliv,modepi);
          if(test)
        {
              ui->lineEdit_17->clear();
              ui->lineEdit_54->clear();
              ui->lineEdit_26->clear();
              ui->lineEdit_25->clear();
              ui->lineEdit_75->clear();
              ui->lineEdit_74->clear();

 ui->tableViewarwa_2->setModel(tmpf.afficher());//refresh
  QMessageBox::information(nullptr, QObject::tr("Modifier un fournisseur"),
                    QObject::tr("Fournisseur modifié.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

  }
    else
        QMessageBox::critical(nullptr, QObject::tr("Modifier un fournisseur"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void menu::on_pushButton_supp_2_clicked()
{
    QString code = ui->lineEdit_27->text();

        bool test=tmpf.supprimer(code);
        if(test)
        {
            ui->lineEdit_66->clear();
            ui->tableViewarwa_2->setModel(tmpf.afficher());//refresh
            QMessageBox::information(nullptr, QObject::tr("Supprimer un fournisseur"),
                        QObject::tr("Fournisseur supprimé.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

        }
        else
            QMessageBox::critical(nullptr, QObject::tr("Supprimer un fournisseur"),
                        QObject::tr("Erreur !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
}


void menu::on_refprod_4_clicked()
{
    ui->tableViewarwa_2->setModel(tmpf.afficher());//refresh

}

void menu::on_pushButton_23_clicked()
{
    ui->tableView->setModel(tmpmn.tridesc());//refresh

}

void menu::on_chercherprod_clicked()
{
    QString code = ui->lineEdit_28->text();

    ui->tableView_11->setModel(tmpp.rechercher(code));//refr
}

void menu::on_chercherfourn_clicked()
{
    QString code = ui->lineEdit_29->text();

    ui->tableView_12->setModel(tmpf.rechercher(code));//refr
}

void menu::on_cherchermenu_clicked()
{

    QString datemenu=ui->dateEdit_4->date().toString();
    ui->tableView_2->setModel(tmpmn.rechercher(datemenu));//refr
}



void menu::on_pushButton_9_clicked()
{
    QString pic = ui->lineEdit_15->text();


    ui->tableView_16->setModel(tmpbi.rechercher(pic));//refr
}

void menu::on_pushButton_10_clicked()
{
    QString pic = ui->lineEdit_8->text();


    ui->tableView_8->setModel(tmpbf.rechercher(pic));//refr
}




//void menu::on_imprim_clicked()
//{


    //QPrinter printer;
   // printer.setPrinterName("desiered printer name");
    //QPrintDialog dialog(&printer,this);
    //if(dialog.exec() == QDialog::Rejected) return;
    //ui->textEdit->print(&printer);
//}


void menu::on_pushButton_292_clicked()
{

    ui->stackedWidget->setCurrentIndex(13);
}

void menu::on_pushButton_221_clicked()
{
    ui->stackedWidget->setCurrentIndex(13);

}

void menu::on_pushButton_293_clicked()
{
    ui->stackedWidget->setCurrentIndex(13);

}

void menu::on_pushButton_286_clicked()
{
    ui->stackedWidget->setCurrentIndex(13);

}

void menu::on_pushButton_305_clicked()
{
    ui->stackedWidget->setCurrentIndex(13);

}

void menu::on_pushButton_306_clicked()
{
    ui->stackedWidget->setCurrentIndex(13);

}

void menu::on_pushButton_240_clicked()
{
    ui->stackedWidget->setCurrentIndex(15);

}

void menu::on_pushButton_255_clicked()
{
    ui->stackedWidget->setCurrentIndex(16);

}

void menu::on_pushButton_233_clicked()
{
    ui->stackedWidget->setCurrentIndex(13);

}

void menu::on_pushButton_223_clicked()
{
    ui->stackedWidget->setCurrentIndex(14);

}

void menu::on_pushButton_217_clicked()
{
    ui->stackedWidget->setCurrentIndex(12);

}

void menu::on_pushButton_495_clicked()
{
    ui->stackedWidget->setCurrentIndex(13);

}

void menu::on_pushButton_220_clicked()
{
    ui->stackedWidget->setCurrentIndex(15);

}

void menu::on_pushButton_224_clicked()
{
    ui->stackedWidget->setCurrentIndex(16);

}


void menu::on_pushButton_219_clicked()
{
    ui->stackedWidget->setCurrentIndex(14);

}

void menu::on_pushButton_229_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);

}

void menu::on_pushButton_235_clicked()
{
    ui->stackedWidget->setCurrentIndex(15);

}

void menu::on_pushButton_232_clicked()
{
    ui->stackedWidget->setCurrentIndex(16);

}

void menu::on_pushButton_243_clicked()
{
    ui->stackedWidget->setCurrentIndex(16);

}

void menu::on_pushButton_234_clicked()
{
    ui->stackedWidget->setCurrentIndex(12);

}

void menu::on_pushButton_295_clicked()
{
    ui->stackedWidget->setCurrentIndex(9);

}

void menu::on_pushButton_296_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);

}

void menu::on_pushButton_298_clicked()
{
    ui->stackedWidget->setCurrentIndex(20);

}

void menu::on_pushButton_297_clicked()
{
    ui->stackedWidget->setCurrentIndex(26);

}

void menu::on_pushButton_294_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);

}

void menu::on_pushButton_213_clicked()
{
    ui->stackedWidget->setCurrentIndex(15);

}


void menu::on_pushButton_212_clicked()
{
    ui->stackedWidget->setCurrentIndex(16);

}


void menu::on_pushButton_215_clicked()
{
    ui->stackedWidget->setCurrentIndex(13);

}


void menu::on_pushButton_216_clicked()
{
    ui->stackedWidget->setCurrentIndex(14);

}

void menu::on_pushButton_289_clicked()
{
    ui->stackedWidget->setCurrentIndex(9);

}

void menu::on_pushButton_287_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);

}


void menu::on_pushButton_290_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);

}

void menu::on_pushButton_291_clicked()
{
    ui->stackedWidget->setCurrentIndex(20);

}

void menu::on_pushButton_288_clicked()
{
    ui->stackedWidget->setCurrentIndex(26);

}

void menu::on_pushButton_222_clicked()
{
    ui->stackedWidget->setCurrentIndex(12);

}

void menu::on_pushButton_283_clicked()
{
    ui->stackedWidget->setCurrentIndex(9);

}

void menu::on_pushButton_281_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);

}

void menu::on_pushButton_284_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);

}

void menu::on_pushButton_285_clicked()
{
    ui->stackedWidget->setCurrentIndex(20);

}


void menu::on_pushButton_282_clicked()
{
    ui->stackedWidget->setCurrentIndex(26);

}

void menu::on_pushButton_246_clicked()
{
    ui->stackedWidget->setCurrentIndex(13);

}

void menu::on_pushButton_245_clicked()
{
    ui->stackedWidget->setCurrentIndex(14);

}

void menu::on_pushButton_247_clicked()
{
    ui->stackedWidget->setCurrentIndex(12);

}

void menu::on_pushButton_241_clicked()
{
    ui->stackedWidget->setCurrentIndex(9);

}

void menu::on_pushButton_244_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);

}

void menu::on_pushButton_248_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);

}

void menu::on_pushButton_256_clicked()
{
    ui->stackedWidget->setCurrentIndex(20);

}

void menu::on_pushButton_265_clicked()
{
    ui->stackedWidget->setCurrentIndex(26);

}

void menu::on_pushButton_254_clicked()
{
    ui->stackedWidget->setCurrentIndex(15);

}

void menu::on_pushButton_253_clicked()
{
    ui->stackedWidget->setCurrentIndex(13);

}

void menu::on_pushButton_251_clicked()
{
    ui->stackedWidget->setCurrentIndex(14);

}

void menu::on_pushButton_252_clicked()
{
    ui->stackedWidget->setCurrentIndex(12);

}

void menu::on_pushButton_502_clicked()
{
    ui->stackedWidget->setCurrentIndex(9);

}

void menu::on_pushButton_501_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);

}

void menu::on_pushButton_504_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);

}

void menu::on_pushButton_505_clicked()
{
    ui->stackedWidget->setCurrentIndex(20);

}

void menu::on_pushButton_503_clicked()
{
    ui->stackedWidget->setCurrentIndex(26);

}

void menu::on_pushButton_542_clicked()
{
    ui->stackedWidget->setCurrentIndex(20);

}

void menu::on_pushButton_499_clicked()
{
    ui->stackedWidget->setCurrentIndex(20);

}

void menu::on_pushButton_263_clicked()
{
    ui->stackedWidget->setCurrentIndex(17);

}

void menu::on_pushButton_264_clicked()
{
    ui->stackedWidget->setCurrentIndex(19);

}

void menu::on_pushButton_262_clicked()
{
    ui->stackedWidget->setCurrentIndex(20);

}

void menu::on_pushButton_260_clicked()
{
    ui->stackedWidget->setCurrentIndex(21);

}

void menu::on_pushButton_261_clicked()
{
    ui->stackedWidget->setCurrentIndex(22);

}

void menu::on_pushButton_497_clicked()
{
    ui->stackedWidget->setCurrentIndex(9);

}


void menu::on_pushButton_498_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);

}

void menu::on_pushButton_494_clicked()
{
    ui->stackedWidget->setCurrentIndex(26);

}

void menu::on_pushButton_507_clicked()
{
    ui->stackedWidget->setCurrentIndex(13);

}

void menu::on_pushButton_509_clicked()
{
    ui->stackedWidget->setCurrentIndex(9);

}

void menu::on_pushButton_510_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);

}

void menu::on_pushButton_512_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);

}

void menu::on_pushButton_530_clicked()
{
    ui->stackedWidget->setCurrentIndex(20);

}


void menu::on_pushButton_511_clicked()
{
    ui->stackedWidget->setCurrentIndex(26);

}

void menu::on_pushButton_514_clicked()
{
    ui->stackedWidget->setCurrentIndex(17);

}

void menu::on_pushButton_517_clicked()
{
    ui->stackedWidget->setCurrentIndex(19);

}

void menu::on_pushButton_513_clicked()
{
    ui->stackedWidget->setCurrentIndex(20);

}

void menu::on_pushButton_516_clicked()
{
    ui->stackedWidget->setCurrentIndex(21);

}

void menu::on_pushButton_515_clicked()
{
    ui->stackedWidget->setCurrentIndex(22);

}

void menu::on_pushButton_524_clicked()
{
    ui->stackedWidget->setCurrentIndex(13);

}

void menu::on_pushButton_519_clicked()
{
    ui->stackedWidget->setCurrentIndex(9);

}

void menu::on_pushButton_523_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);

}

void menu::on_pushButton_520_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);

}

void menu::on_pushButton_543_clicked()
{
    ui->stackedWidget->setCurrentIndex(20);

}

void menu::on_pushButton_521_clicked()
{
    ui->stackedWidget->setCurrentIndex(26);

}

void menu::on_pushButton_525_clicked()
{
    ui->stackedWidget->setCurrentIndex(17);

}

void menu::on_pushButton_527_clicked()
{
    ui->stackedWidget->setCurrentIndex(19);

}

void menu::on_pushButton_528_clicked()
{
    ui->stackedWidget->setCurrentIndex(20);

}

void menu::on_pushButton_526_clicked()
{
    ui->stackedWidget->setCurrentIndex(21);

}

void menu::on_pushButton_529_clicked()
{
    ui->stackedWidget->setCurrentIndex(22);

}

void menu::on_pushButton_532_clicked()
{
    ui->stackedWidget->setCurrentIndex(13);

}

void menu::on_pushButton_531_clicked()
{
    ui->stackedWidget->setCurrentIndex(9);

}

void menu::on_pushButton_536_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);

}

void menu::on_pushButton_537_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);

}

void menu::on_pushButton_544_clicked()
{
    ui->stackedWidget->setCurrentIndex(20);

}

void menu::on_pushButton_539_clicked()
{
    ui->stackedWidget->setCurrentIndex(26);

}

void menu::on_pushButton_541_clicked()
{
    ui->stackedWidget->setCurrentIndex(17);

}

void menu::on_pushButton_533_clicked()
{
    ui->stackedWidget->setCurrentIndex(19);

}

void menu::on_pushButton_535_clicked()
{
    ui->stackedWidget->setCurrentIndex(20);

}

void menu::on_pushButton_538_clicked()
{
    ui->stackedWidget->setCurrentIndex(21);

}

void menu::on_pushButton_534_clicked()
{
    ui->stackedWidget->setCurrentIndex(22);

}

void menu::on_pushButton_551_clicked()
{
    ui->stackedWidget->setCurrentIndex(13);

}

void menu::on_pushButton_556_clicked()
{
    ui->stackedWidget->setCurrentIndex(9);

}

void menu::on_pushButton_548_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);

}

void menu::on_pushButton_554_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);

}

void menu::on_pushButton_545_clicked()
{
    ui->stackedWidget->setCurrentIndex(20);

}

void menu::on_pushButton_558_clicked()
{
    ui->stackedWidget->setCurrentIndex(26);

}

void menu::on_pushButton_555_clicked()
{
    ui->stackedWidget->setCurrentIndex(17);

}



void menu::on_pushButton_557_clicked()
{
    ui->stackedWidget->setCurrentIndex(19);

}

void menu::on_pushButton_552_clicked()
{
    ui->stackedWidget->setCurrentIndex(20);

}

void menu::on_pushButton_549_clicked()
{
    ui->stackedWidget->setCurrentIndex(21);

}

void menu::on_pushButton_553_clicked()
{
    ui->stackedWidget->setCurrentIndex(22);

}

void menu::on_pushButton_578_clicked()
{
    ui->stackedWidget->setCurrentIndex(13);

}

void menu::on_pushButton_571_clicked()
{
    ui->stackedWidget->setCurrentIndex(9);

}

void menu::on_pushButton_580_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);

}

void menu::on_pushButton_572_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);

}

void menu::on_pushButton_573_clicked()
{
    ui->stackedWidget->setCurrentIndex(20);

}

void menu::on_pushButton_576_clicked()
{
    ui->stackedWidget->setCurrentIndex(21);

}

void menu::on_pushButton_579_clicked()
{
    ui->stackedWidget->setCurrentIndex(24);

}

void menu::on_pushButton_575_clicked()
{
    ui->stackedWidget->setCurrentIndex(25);

}

void menu::on_pushButton_574_clicked()
{
    ui->stackedWidget->setCurrentIndex(26);

}

void menu::on_pushButton_577_clicked()
{
    ui->stackedWidget->setCurrentIndex(27);

}

void menu::on_pushButton_581_clicked()
{
    ui->stackedWidget->setCurrentIndex(28);

}

void menu::on_pushButton_1208_clicked()
{
    ui->stackedWidget->setCurrentIndex(24);

}

void menu::on_pushButton_1210_clicked()
{
    ui->stackedWidget->setCurrentIndex(25);

}

void menu::on_pushButton_1206_clicked()
{
    ui->stackedWidget->setCurrentIndex(26);

}

void menu::on_pushButton_1204_clicked()
{
    ui->stackedWidget->setCurrentIndex(27);

}

void menu::on_pushButton_1207_clicked()
{
    ui->stackedWidget->setCurrentIndex(28);

}

void menu::on_pushButton_1213_clicked()
{
    ui->stackedWidget->setCurrentIndex(13);

}

void menu::on_pushButton_1211_clicked()
{
    ui->stackedWidget->setCurrentIndex(9);

}

void menu::on_pushButton_1203_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);

}

void menu::on_pushButton_1212_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);

}

void menu::on_pushButton_1209_clicked()
{
    ui->stackedWidget->setCurrentIndex(20);

}

void menu::on_pushButton_583_clicked()
{
    ui->stackedWidget->setCurrentIndex(26);

}

void menu::on_pushButton_1219_clicked()
{
    ui->stackedWidget->setCurrentIndex(24);

}

void menu::on_pushButton_1221_clicked()
{
    ui->stackedWidget->setCurrentIndex(25);

}

void menu::on_pushButton_1217_clicked()
{
    ui->stackedWidget->setCurrentIndex(26);

}

void menu::on_pushButton_1215_clicked()
{
    ui->stackedWidget->setCurrentIndex(27);

}

void menu::on_pushButton_1218_clicked()
{
    ui->stackedWidget->setCurrentIndex(28);

}

void menu::on_pushButton_1224_clicked()
{
    ui->stackedWidget->setCurrentIndex(13);

}

void menu::on_pushButton_1222_clicked()
{
    ui->stackedWidget->setCurrentIndex(9);

}

void menu::on_pushButton_1214_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);

}

void menu::on_pushButton_1223_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);

}

void menu::on_pushButton_1220_clicked()
{
    ui->stackedWidget->setCurrentIndex(20);

}

void menu::on_pushButton_584_clicked()
{
    ui->stackedWidget->setCurrentIndex(26);

}

void menu::on_pushButton_1241_clicked()
{
    ui->stackedWidget->setCurrentIndex(24);

}

void menu::on_pushButton_1243_clicked()
{
    ui->stackedWidget->setCurrentIndex(25);

}

void menu::on_pushButton_1239_clicked()
{
    ui->stackedWidget->setCurrentIndex(26);

}

void menu::on_pushButton_1237_clicked()
{
    ui->stackedWidget->setCurrentIndex(27);

}

void menu::on_pushButton_1240_clicked()
{
    ui->stackedWidget->setCurrentIndex(28);

}

void menu::on_pushButton_1246_clicked()
{
    ui->stackedWidget->setCurrentIndex(13);

}

void menu::on_pushButton_1244_clicked()
{
    ui->stackedWidget->setCurrentIndex(9);

}

void menu::on_pushButton_1236_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);

}

void menu::on_pushButton_1245_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);

}

void menu::on_pushButton_1242_clicked()
{
    ui->stackedWidget->setCurrentIndex(20);

}

void menu::on_pushButton_585_clicked()
{
    ui->stackedWidget->setCurrentIndex(26);

}

void menu::on_pushButton_1230_clicked()
{
    ui->stackedWidget->setCurrentIndex(24);

}

void menu::on_pushButton_1232_clicked()
{
    ui->stackedWidget->setCurrentIndex(25);

}

void menu::on_pushButton_1228_clicked()
{
    ui->stackedWidget->setCurrentIndex(26);

}

void menu::on_pushButton_1226_clicked()
{
    ui->stackedWidget->setCurrentIndex(27);

}

void menu::on_pushButton_1229_clicked()
{
    ui->stackedWidget->setCurrentIndex(28);

}

void menu::on_pushButton_1235_clicked()
{
    ui->stackedWidget->setCurrentIndex(13);

}

void menu::on_pushButton_1233_clicked()
{
    ui->stackedWidget->setCurrentIndex(9);

}

void menu::on_pushButton_1225_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);

}

void menu::on_pushButton_1234_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);

}

void menu::on_pushButton_1231_clicked()
{
    ui->stackedWidget->setCurrentIndex(20);

}

void menu::on_pushButton_586_clicked()
{
    ui->stackedWidget->setCurrentIndex(26);

}

void menu::on_pushButton_479_clicked()
{
    ui->stackedWidget->setCurrentIndex(13);

}

void menu::on_pushButton_481_clicked()
{
    ui->stackedWidget->setCurrentIndex(9);

}

void menu::on_pushButton_477_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);

}

void menu::on_pushButton_487_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);

}

void menu::on_pushButton_478_clicked()
{
    ui->stackedWidget->setCurrentIndex(20);

}

void menu::on_pushButton_476_clicked()
{
    ui->stackedWidget->setCurrentIndex(26);

}

void menu::on_pushButton_485_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);

}

void menu::on_pushButton_482_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);

}

void menu::on_pushButton_484_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);

}

void menu::on_pushButton_486_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);

}

void menu::on_pushButton_483_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);

}

void menu::on_pushButton_18_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);

}

void menu::on_pushButton_19_clicked()
{
    ui->tableView_7->setModel(tmpbi.tridesc());//refresh

}

void menu::on_pushButton_21_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);

}

void menu::on_pushButton_17_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);

}

void menu::on_pushButton_22_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);

}

void menu::on_pushButton_16_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);

}

void menu::on_pushButton_470_clicked()
{
    ui->stackedWidget->setCurrentIndex(13);

}

void menu::on_pushButton_471_clicked()
{
    ui->stackedWidget->setCurrentIndex(9);

}

void menu::on_pushButton_474_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);

}

void menu::on_pushButton_496_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);

}

void menu::on_pushButton_472_clicked()
{
    ui->stackedWidget->setCurrentIndex(20);

}

void menu::on_pushButton_473_clicked()
{
    ui->stackedWidget->setCurrentIndex(26);

}

void menu::on_pushButton_27_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);

}

void menu::on_pushButton_29_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);

}

void menu::on_pushButton_31_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);

}

void menu::on_pushButton_30_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);

}

void menu::on_pushButton_28_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);

}

void menu::on_pushButton_463_clicked()
{
    ui->stackedWidget->setCurrentIndex(13);

}

void menu::on_pushButton_464_clicked()
{
    ui->stackedWidget->setCurrentIndex(9);

}

void menu::on_pushButton_465_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);

}

void menu::on_pushButton_506_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);

}

void menu::on_pushButton_466_clicked()
{
    ui->stackedWidget->setCurrentIndex(20);

}

void menu::on_pushButton_467_clicked()
{
    ui->stackedWidget->setCurrentIndex(26);

}

void menu::on_pushButton_39_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);

}

void menu::on_pushButton_36_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);

}

void menu::on_pushButton_40_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);

}

void menu::on_pushButton_32_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);

}

void menu::on_pushButton_38_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);

}

void menu::on_pushButton_456_clicked()
{
    ui->stackedWidget->setCurrentIndex(13);

}

void menu::on_pushButton_459_clicked()
{
    ui->stackedWidget->setCurrentIndex(9);

}

void menu::on_pushButton_508_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);

}

void menu::on_pushButton_455_clicked()
{
    ui->stackedWidget->setCurrentIndex(20);

}

void menu::on_pushButton_454_clicked()
{
    ui->stackedWidget->setCurrentIndex(26);

}

void menu::on_pushButton_89_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);

}

void menu::on_pushButton_88_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);

}

void menu::on_pushButton_87_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);

}

void menu::on_pushButton_83_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);

}

void menu::on_pushButton_86_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);

}

void menu::on_pushButton_452_clicked()
{
    ui->stackedWidget->setCurrentIndex(13);

}

void menu::on_pushButton_450_clicked()
{
    ui->stackedWidget->setCurrentIndex(9);

}

void menu::on_pushButton_451_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);

}

void menu::on_pushButton_522_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);

}

void menu::on_pushButton_447_clicked()
{
    ui->stackedWidget->setCurrentIndex(20);

}

void menu::on_pushButton_449_clicked()
{
    ui->stackedWidget->setCurrentIndex(26);

}

void menu::on_pushButton_442_clicked()
{
    ui->stackedWidget->setCurrentIndex(13);

}

void menu::on_pushButton_443_clicked()
{
    ui->stackedWidget->setCurrentIndex(9);

}



void menu::on_pushButton_448_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);

}

void menu::on_pushButton_439_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);

}

void menu::on_pushButton_440_clicked()
{
    ui->stackedWidget->setCurrentIndex(20);

}

void menu::on_pushButton_441_clicked()
{
    ui->stackedWidget->setCurrentIndex(26);

}

void menu::on_pushButton_92_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);

}

void menu::on_pushButton_427_clicked()
{
    ui->stackedWidget->setCurrentIndex(13);
}

void menu::on_pushButton_444_clicked()
{
    ui->stackedWidget->setCurrentIndex(9);

}

void menu::on_pushButton_430_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);

}

void menu::on_pushButton_428_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);

}

void menu::on_pushButton_431_clicked()
{
    ui->stackedWidget->setCurrentIndex(20);

}

void menu::on_pushButton_432_clicked()
{
    ui->stackedWidget->setCurrentIndex(26);

}

void menu::on_pushButton_107_clicked()
{
    ui->stackedWidget->setCurrentIndex(11);

}

void menu::on_pushButton_106_clicked()
{
    ui->stackedWidget->setCurrentIndex(10);

}

void menu::on_pushButton_110_clicked()
{
    ui->stackedWidget->setCurrentIndex(9);

}

void menu::on_pushButton_104_clicked()
{
    ui->stackedWidget->setCurrentIndex(8);

}

void menu::on_pushButton_108_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);

}

void menu::on_pushButton_423_clicked()
{
    ui->stackedWidget->setCurrentIndex(13);

}

void menu::on_pushButton_458_clicked()
{
    ui->stackedWidget->setCurrentIndex(9);

}

void menu::on_pushButton_425_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);

}

void menu::on_pushButton_424_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);

}

void menu::on_pushButton_420_clicked()
{
    ui->stackedWidget->setCurrentIndex(20);

}

void menu::on_pushButton_422_clicked()
{
    ui->stackedWidget->setCurrentIndex(26);

}

void menu::on_pushButton_114_clicked()
{
    ui->stackedWidget->setCurrentIndex(11);

}

void menu::on_pushButton_113_clicked()
{
    ui->stackedWidget->setCurrentIndex(10);

}

void menu::on_pushButton_117_clicked()
{
    ui->stackedWidget->setCurrentIndex(9);

}

void menu::on_pushButton_111_clicked()
{
    ui->stackedWidget->setCurrentIndex(8);

}

void menu::on_pushButton_115_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);

}

void menu::on_pushButton_124_clicked()
{
    ui->stackedWidget->setCurrentIndex(11);

}

void menu::on_pushButton_123_clicked()
{
    ui->stackedWidget->setCurrentIndex(10);

}

void menu::on_pushButton_125_clicked()
{    ui->stackedWidget->setCurrentIndex(9);


}

void menu::on_pushButton_127_clicked()
{
    ui->stackedWidget->setCurrentIndex(8);

}

void menu::on_pushButton_122_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);

}

void menu::on_pushButton_412_clicked()
{
    ui->stackedWidget->setCurrentIndex(13);

}

void menu::on_pushButton_460_clicked()
{
    ui->stackedWidget->setCurrentIndex(9);

}

void menu::on_pushButton_411_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);

}

void menu::on_pushButton_409_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);

}

void menu::on_pushButton_414_clicked()
{
    ui->stackedWidget->setCurrentIndex(20);

}

void menu::on_pushButton_410_clicked()
{
    ui->stackedWidget->setCurrentIndex(26);

}

void menu::on_pushButton_403_clicked()
{
    ui->stackedWidget->setCurrentIndex(11);

}

void menu::on_pushButton_407_clicked()
{
    ui->stackedWidget->setCurrentIndex(10);

}

void menu::on_pushButton_404_clicked()
{
    ui->stackedWidget->setCurrentIndex(9);

}

void menu::on_pushButton_405_clicked()
{
    ui->stackedWidget->setCurrentIndex(8);

}

void menu::on_pushButton_406_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);

}

void menu::on_pushButton_400_clicked()
{
    ui->stackedWidget->setCurrentIndex(13);

}

void menu::on_pushButton_462_clicked()
{
    ui->stackedWidget->setCurrentIndex(9);

}

void menu::on_pushButton_401_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);

}

void menu::on_pushButton_399_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);

}

void menu::on_pushButton_397_clicked()
{
    ui->stackedWidget->setCurrentIndex(20);

}

void menu::on_pushButton_402_clicked()
{
    ui->stackedWidget->setCurrentIndex(26);

}

void menu::on_pushButton_302_clicked()
{
    ui->stackedWidget->setCurrentIndex(13);

}

void menu::on_pushButton_468_clicked()
{
    ui->stackedWidget->setCurrentIndex(9);

}

void menu::on_pushButton_303_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);

}

void menu::on_pushButton_301_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);

}

void menu::on_pushButton_300_clicked()
{
    ui->stackedWidget->setCurrentIndex(20);

}

void menu::on_pushButton_299_clicked()
{
    ui->stackedWidget->setCurrentIndex(26);

}

void menu::on_pushButton_226_clicked()
{
    ui->stackedWidget->setCurrentIndex(11);

}

void menu::on_pushButton_228_clicked()
{
    ui->stackedWidget->setCurrentIndex(10);

}

void menu::on_pushButton_227_clicked()
{
    ui->stackedWidget->setCurrentIndex(9);

}

void menu::on_pushButton_225_clicked()
{
    ui->stackedWidget->setCurrentIndex(8);

}



void menu::on_pushButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);

}

void menu::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);

}

void menu::on_pushButton999_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);

}

void menu::on_pushButton999_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);

}

void menu::on_pushButton999_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);

}

void menu::on_pushButton999_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);

}

void menu::on_pushButton_4_clicked()
{

    ui->tableViewarwa_2->setModel(tmpf.tridesc());//refresh

}

void menu::on_pushButton_34_clicked()
{
    ui->tableView_3->setModel(tmpbf.tridesc());//refresh

}

void menu::on_pushButton_26_clicked()
{
    QString code = ui->lineEdit_8->text();

    ui->tableView_8->setModel(tmpbf.rechercher(code));//refr
}

void menu::on_pushButton_24_clicked()
{
    QString code = ui->lineEdit_15->text();

    ui->tableView_16->setModel(tmpbi.rechercher(code));//refr
}

void menu::on_pushButton_436_clicked()
{
    ui->stackedWidget->setCurrentIndex(13);

}

void menu::on_pushButton_446_clicked()
{
    ui->stackedWidget->setCurrentIndex(9);

}

void menu::on_pushButton_437_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);

}

void menu::on_pushButton_433_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);

}

void menu::on_pushButton_434_clicked()
{
    ui->stackedWidget->setCurrentIndex(20);

}

void menu::on_pushButton_435_clicked()
{
    ui->stackedWidget->setCurrentIndex(26);

}

void menu::on_pushButton_100_clicked()
{
    ui->stackedWidget->setCurrentIndex(11);

}

void menu::on_pushButton_99_clicked()
{
    ui->stackedWidget->setCurrentIndex(10);

}

void menu::on_pushButton_103_clicked()
{
    ui->stackedWidget->setCurrentIndex(9);

}

void menu::on_pushButton_97_clicked()
{
    ui->stackedWidget->setCurrentIndex(8);

}

void menu::on_pushButton_101_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);

}

void menu::on_refprod_clicked()
{
    ui->tableViewarwa->setModel(tmpp.afficher());//refresh

}


void menu::on_pushButton_5_clicked()
{

          //pour imprimer
              boni bi;
                  QString text=bi.apercu_pdf();
                  ui->imprimbi->setText(text);

                  QPrinter printer ;
                  printer.setPrinterName("nom");
                  QPrintDialog dialog (&printer,this);
                  if(dialog.exec()==QDialog::Rejected) return ;
                  ui->imprimbi->print(&printer);
}

void menu::on_pushButton_268_clicked()
{
    ui->stackedWidget->setCurrentIndex(18);

}

void menu::on_pushButton_271_clicked()
{
    ui->stackedWidget->setCurrentIndex(23);

}

void menu::on_pushButton_272_clicked()
{
    ui->stackedWidget->setCurrentIndex(23);

}

void menu::on_pushButton_275_clicked()
{
    ui->stackedWidget->setCurrentIndex(23);

}

void menu::on_pushButton_276_clicked()
{
    ui->stackedWidget->setCurrentIndex(23);

}

void menu::on_pushButton_540_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);

}

void menu::on_pushButton_489_clicked()
{
    ui->stackedWidget->setCurrentIndex(13);

}

void menu::on_pushButton_491_clicked()
{
    ui->stackedWidget->setCurrentIndex(9);

}

void menu::on_pushButton_492_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);

}

void menu::on_pushButton_493_clicked()
{
    ui->stackedWidget->setCurrentIndex(20);

}

void menu::on_pushButton_488_clicked()
{
    ui->stackedWidget->setCurrentIndex(26);

}

void menu::on_pushButton_270_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);

}

void menu::on_pushButton_273_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);

}

void menu::on_pushButton_269_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);

}

void menu::on_pushButton_267_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);

}

void menu::on_pushButton_274_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);

}

void menu::on_pushButton_277_clicked()
{
    ui->stackedWidget->setCurrentIndex(23);

}

void menu::on_pushButton_278_clicked()
{
    ui->stackedWidget->setCurrentIndex(18);

}

void menu::on_pushButton_279_clicked()
{
    ui->stackedWidget->setCurrentIndex(18);

}

void menu::on_pushButton_280_clicked()
{
    ui->stackedWidget->setCurrentIndex(18);

}

void menu::on_pushButton_304_clicked()
{
    ui->stackedWidget->setCurrentIndex(18);

}

void menu::on_pushButton_307_clicked()
{
    ui->stackedWidget->setCurrentIndex(18);

}

void menu::on_pushButton_566_clicked()
{
    ui->stackedWidget->setCurrentIndex(17);

}

void menu::on_pushButton_568_clicked()
{
    ui->stackedWidget->setCurrentIndex(19);

}

void menu::on_pushButton_563_clicked()
{
    ui->stackedWidget->setCurrentIndex(20);

}

void menu::on_pushButton_560_clicked()
{
    ui->stackedWidget->setCurrentIndex(21);

}

void menu::on_pushButton_564_clicked()
{
    ui->stackedWidget->setCurrentIndex(22);

}

void menu::on_pushButton_562_clicked()
{
    ui->stackedWidget->setCurrentIndex(13);

}

void menu::on_pushButton_567_clicked()
{
    ui->stackedWidget->setCurrentIndex(9);

}

void menu::on_pushButton_559_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);

}

void menu::on_pushButton_565_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);

}

void menu::on_pushButton_546_clicked()
{
    ui->stackedWidget->setCurrentIndex(20);

}

void menu::on_pushButton_569_clicked()
{
    ui->stackedWidget->setCurrentIndex(26);

}

void menu::on_refprod_14_clicked()
{
    ui->rupture->setModel(tmpp.afficher3());//refresh

}
