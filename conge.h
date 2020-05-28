#ifndef CONGE_H
#define CONGE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QWidget>
class conge
{
private:
     int ref ;
     QString datedebut , datefin ,id_p;


public:
   conge();
   conge(int,QString,QString,QString);

      int get_ref();
      int get_id_p();
      void setref(int);
      void setid_p(QString);

    bool ajouterconge();
    QSqlQueryModel * afficherconge();
      QSqlQueryModel * afficher2(QString);
    bool supprimerconge(QString);
     QSqlQueryModel* affecterperso();
      QSqlQueryModel * chercherconge(QString id_p);

    bool modifierconge(int,QString,QString,QString);

    bool verifierRef(int ref);
};

#endif // CONGE_H
