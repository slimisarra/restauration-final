#include "s.h"
#include "prog.h"
#include <QApplication>
#include "connexion.h"
#include <QMessageBox>
#include <QtDebug>
#include <QWidget>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    prog w;
    connexion c;
    QMessageBox msgBox;

    if(c.ouvrircnx())
    {

     msgBox.setText("connexion avec succes.");
     msgBox.exec();
   w.show();
     }
    else
    {
        msgBox.setText("Echec.");
        msgBox.exec(); }
    return a.exec();
}
