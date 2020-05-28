#ifndef LOGIN_H
#define LOGIN_H


#include <QString>

#include <QSqlQuery>

#include <QSqlQueryModel>



class login

{

public:

    login();

    login(QString,QString);



        QString get_cin();

        QString get_nom();

        int verifierCompte(QString,QString);

private:

    QString nom , cin ;





};



#endif // LOGIN_H
