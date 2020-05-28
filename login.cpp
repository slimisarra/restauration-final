#include "login.h"


#include <QDebug>

#include <QString>
#include <QMessageBox>



login::login()

{



    nom="";

    cin="";



}



login::login(QString nom,QString cin)

{



  this->nom=nom;

  this->cin=cin;



}

QString login::get_nom(){return  nom;}

QString login::get_cin(){return cin;}





int login::verifierCompte(QString login,QString password)

{

    QSqlQuery query;

    QString login1,password1;

    if (login=="" || password=="")

        return  0;

    query.exec("SELECT NOM_EMPLOYE,MDP_EMPLOYE FROM EMPLOYE where NOM_EMPLOYE= '"+login+"' AND MDP_EMPLOYE= '"+password+"' ");

        query.last();

        login1=query.value("NOM_EMPLOYE").toString();

        password1=query.value("MDP_EMPLOYE").toString();

        if (login1==login && password1==password)

        {

            return 1;

        }

        else
        {
            QMessageBox::information(nullptr, QObject::tr("Erreur"),
                        QObject::tr("Erreur .\n"
                                    "Verifier le nom de l'utilisateur ou le mot de passe"), QMessageBox::Cancel);
            return 0;
}


}

