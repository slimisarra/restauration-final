#ifndef DIALOG_H
#define DIALOG_H
#include <QDebug>
#include <QMainWindow>
#include "personnel.h"
#include "conge.h"
#include "departement.h"
#include <QWidget>
//#include <QSound>

#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();
private slots:
    void on_ajouterpersonnel_clicked();

    void on_ajouterconge_clicked();

    void on_modifierdepartement_clicked();

    void on_ajouterdepartement_clicked();

    void on_supprimerdepartement_clicked();

    void on_pushButton_supp_clicked();

    void on_modifperso_clicked();

    void on_modifierconge_clicked() ;

    void on_supprimerconge_clicked();

    void on_refresh1_clicked();
    void on_refresh2_clicked();
    void on_refresh3_clicked();
    void on_chercher_clicked();
    void on_chercherconge_clicked();
    void on_chercherdepart_clicked();
    void on_departement_currentTextChanged(const QString &arg1);



    void on_personnel1_clicked();

    void on_conge1_clicked();

    void on_pushButton_51_clicked();

    void on_departement1_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_personnel2_clicked();

    void on_conge2_clicked();

    void on_departement2_2_clicked();

    void on_pushButton_18_clicked();

    void on_pushButton_21_clicked();

    void on_pushButton_17_clicked();

    void on_pushButton_22_clicked();

    void on_pushButton_25_clicked();

    void on_pushButton_26_clicked();

    void on_pushButton_49_clicked();

    void on_pushButton_27_clicked();

    void on_pushButton_29_clicked();

    void on_pushButton_31_clicked();

    void on_pushButton_30_clicked();

    void on_pushButton_37_clicked();

    void on_pushButton_35_clicked();

    void on_pushButton_50_clicked();

    void on_pushButton_39_clicked();

    void on_pushButton_36_clicked();

    void on_pushButton_40_clicked();

    void on_pushButton_32_clicked();

    void on_pushButton_84_clicked();

    void on_pushButton_85_clicked();

    void on_pushButton_130_clicked();

    void on_pushButton_89_clicked();

    void on_pushButton_88_clicked();

    void on_pushButton_87_clicked();

    void on_pushButton_83_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_47_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_90_clicked();

    void on_pushButton_91_clicked();

    void on_pushButton_128_clicked();

    void on_pushButton_92_clicked();

    void on_pushButton_94_clicked();

    void on_pushButton_96_clicked();

    void on_pushButton_95_clicked();

    void on_pushButton_102_clicked();

    void on_pushButton_98_clicked();

    void on_pushButton_129_clicked();

    void on_pushButton_100_clicked();

    void on_pushButton_99_clicked();

    void on_pushButton_103_clicked();

    void on_pushButton_97_clicked();

    void on_pushButton_109_clicked();

    void on_pushButton_105_clicked();

    void on_pushButton_131_clicked();

    void on_pushButton_107_clicked();

    void on_pushButton_106_clicked();

    void on_pushButton_110_clicked();

    void on_pushButton_104_clicked();

    void on_pushButton_116_clicked();

    void on_pushButton_112_clicked();

    void on_pushButton_132_clicked();

    void on_pushButton_114_clicked();

    void on_pushButton_113_clicked();

    void on_pushButton_117_clicked();

    void on_pushButton_111_clicked();

    void on_pushButton_276_clicked();

    void on_pushButton_275_clicked();

    void on_pushButton_277_clicked();

    void on_pushButton_278_clicked();

    void on_pushButton_279_clicked();

    void on_pushButton_280_clicked();

    void on_pushButton_227_clicked();

    void on_pushButton_230_clicked();

    void on_pushButton_229_clicked();

    void on_pushButton_220_clicked();

    void on_pushButton_226_clicked();

    void on_pushButton_222_clicked();

    void on_pushButton_224_clicked();

    void on_pushButton_238_clicked();

    void on_pushButton_237_clicked();

    void on_pushButton_236_clicked();

    void on_pushButton_235_clicked();

    void on_pushButton_232_clicked();

    void on_pushButton_233_clicked();

    void on_pushButton_223_clicked();

    void on_pushButton_241_clicked();

    void on_pushButton_244_clicked();

    void on_pushButton_242_clicked();

    void on_pushButton_240_clicked();

    void on_pushButton_243_clicked();

    void on_pushButton_246_clicked();

    void on_pushButton_245_clicked();

    void on_pushButton_250_clicked();

    void on_pushButton_249_clicked();

    void on_pushButton_257_clicked();

    void on_pushButton_254_clicked();

    void on_pushButton_255_clicked();

    void on_pushButton_253_clicked();

    void on_pushButton_251_clicked();

    void on_pushButton_259_clicked();

    void on_pushButton_258_clicked();

    void on_pushButton_266_clicked();

    void on_pushButton_263_clicked();

    void on_pushButton_264_clicked();

    void on_pushButton_262_clicked();

    void on_pushButton_260_clicked();

    void on_pushButton_24_clicked();

    void on_pushButton_23_clicked();

    void on_pushButton_48_clicked();

    void on_pushButton_221_clicked();

    void makePlot();
    void on_pushButton_225_clicked();

    void sendMail();
    void mailSent(QString);

    void on_refresh_clicked();

private:
    personnel tmpp;
    conge tmpc;
    departement tmpd;
    //QSound *son;

    Ui::Dialog *ui;
};

#endif // DIALOG_H
