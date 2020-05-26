#include "connexion.h"
#include <QDebug>

connexion::connexion()
{

}
bool connexion::ouvrircnx()
{
    db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("Source_projet2A");
    db.setUserName("sarra");
    db.setPassword("sarra");
    if(db.open())
        return true;

        return false;
}
void connexion::fermercnx()
{
    db.close();
}
