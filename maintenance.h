#ifndef MAINTENANCE_H
#define MAINTENANCE_H
#include <QString>
#include <QSqlQueryModel>

class maintenance
{
 private:
    QString referencem;
    int prix;
    QString agent;
    QString duree;
    QString libellem;
public:
    maintenance();
    maintenance(QString,QString, QString, QString, int);
    QString getreferencem();
    QString getlibellem();
    QString getagent();
    QString getduree();
    int getprix();
    // A implementer les gets et les sets
     bool ajouterm();
    QSqlQueryModel* afficherm();
    QSqlQueryModel* listerlibm();
    QSqlQueryModel* listerrefm();
    QSqlQueryModel * trierprix();
    QSqlQueryModel * trierduree();
    bool verifierId(QString);
};

#endif // MAINTENANCE_H
