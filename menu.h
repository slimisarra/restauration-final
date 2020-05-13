#ifndef MENU_H
#define MENU_H

#include <QMainWindow>
#include "produit.h"
#include "nomen.h"
#include "menus.h"
#include "bonf.h"
#include "boni.h"
#include "fourn.h"
#include "qcustomplot.h"

namespace Ui {
class menu;
}

class menu : public QMainWindow
{
    Q_OBJECT

public:
    explicit menu(QWidget *parent = nullptr);
    ~menu();

private slots:


    void on_ajouterproduit_clicked();

    void on_ajouternomen_clicked();

    void on_pushButton_supp_clicked();

    void on_modifprod_clicked();

    void on_ajoutermenu_clicked();



    void on_pushButton_suppmenu_clicked();


    void on_pushButton_clicked();

    void on_lineEdit_code_returnPressed();

    void on_lineEdit_code_textChanged(const QString &arg1);

    void on_pushButton_20_clicked();

    void on_refresh_clicked();

    void on_refprod_clicked();

    void on_refajout_clicked();

    void on_refmodif_clicked();



    void on_refmodifprod_clicked();

    void on_pushButton_21_clicked();

    void on_refprod_13_clicked();


    void on_ajouterbonf_clicked();


    void on_refprod_6_clicked();

    void on_ajoutermenu_6_clicked();

    void on_refprod_11_clicked();

    void on_refprod_2_clicked();

    void on_refprod_10_clicked();

    void on_suppboni_clicked();

    void on_suppbonf_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_33_clicked();

    void on_refprod_12_clicked();

    void on_refprod_7_clicked();

    void on_modifbonf_clicked();

    void on_refprod_18_clicked();

    void on_ajouterfourn_clicked();

    void on_modifprod_2_clicked();

    void on_pushButton_supp_2_clicked();

    void on_refprod_4_clicked();

    void on_pushButton_23_clicked();

    void on_chercherprod_clicked();

    void on_chercherfourn_clicked();

    void on_cherchermenu_clicked();

    void on_lineEdit_15_textChanged(const QString &arg1);

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void makeplot();
    void on_actionprint_triggered();

    void on_actionprint_2_triggered();

    void on_imprim_clicked();

    void on_tableView_9_activated(const QModelIndex &index);

    void on_pushButton_240_clicked();

    void on_pushButton_255_clicked();

    void on_pushButton_223_clicked();

    void on_pushButton_221_clicked();

    void on_pushButton_217_clicked();

    void on_pushButton_226_clicked();

    void on_pushButton_407_clicked();

    void on_pushButton_125_clicked();

    void on_pushButton_111_clicked();

    void on_pushButton_108_clicked();

    void on_pushButton_92_clicked();

    void on_pushButton_89_clicked();

    void on_pushButton_36_clicked();

    void on_pushButton_31_clicked();

    void on_pushButton_22_clicked();

    void on_pushButton_483_clicked();

    void on_pushButton_263_clicked();

    void on_pushButton_517_clicked();

    void on_pushButton_528_clicked();

    void on_pushButton_538_clicked();

    void on_pushButton_553_clicked();

    void on_pushButton_579_clicked();

    void on_pushButton_1210_clicked();

    void on_pushButton_1217_clicked();

    void on_pushButton_1237_clicked();

    void on_pushButton_1229_clicked();

    void on_pushButton_supp_5_clicked();

    void on_cherchermenu_4_clicked();

    void on_pushButton_83_clicked();

    void on_pushButton_30_clicked();

    void on_pushButton_462_clicked();

    void on_pushButton_1216_clicked();

    void on_pushButton_522_clicked();

    void on_pushButton_292_clicked();

    void on_pushButton_413_clicked();

    void on_pushButton_444_clicked();

    void on_pushButton_293_clicked();

    void on_pushButton_286_clicked();

    void on_pushButton_305_clicked();

    void on_pushButton_306_clicked();

    void on_pushButton_233_clicked();

    void on_pushButton_495_clicked();

    void on_pushButton_220_clicked();

    void on_pushButton_224_clicked();

    void on_pushButton_216_clicked();

    void on_pushButton_219_clicked();

    void on_pushButton_229_clicked();

    void on_pushButton_235_clicked();

    void on_pushButton_232_clicked();

    void on_pushButton_243_clicked();

    void on_pushButton_234_clicked();

    void on_pushButton_295_clicked();

    void on_pushButton_296_clicked();

    void on_pushButton_298_clicked();

    void on_pushButton_297_clicked();

    void on_pushButton_294_clicked();

    void on_pushButton_213_clicked();

    void on_pushButton_212_clicked();

    void on_pushButton_215_clicked();

    void on_pushButton_289_clicked();

    void on_pushButton_287_clicked();

    void on_pushButton_290_clicked();

    void on_pushButton_291_clicked();

    void on_pushButton_288_clicked();

    void on_pushButton_222_clicked();

    void on_pushButton_283_clicked();

    void on_pushButton_281_clicked();

    void on_pushButton_284_clicked();

    void on_pushButton_285_clicked();

    void on_pushButton_282_clicked();

    void on_pushButton_246_clicked();

    void on_pushButton_245_clicked();

    void on_pushButton_247_clicked();

    void on_pushButton_241_clicked();

    void on_pushButton_244_clicked();

    void on_pushButton_248_clicked();

    void on_pushButton_256_clicked();

    void on_pushButton_265_clicked();

    void on_pushButton_254_clicked();

    void on_pushButton_253_clicked();

    void on_pushButton_251_clicked();

    void on_pushButton_252_clicked();

    void on_pushButton_502_clicked();

    void on_pushButton_501_clicked();

    void on_pushButton_504_clicked();

    void on_pushButton_505_clicked();

    void on_pushButton_503_clicked();

    void on_pushButton_542_clicked();

    void on_pushButton_499_clicked();

    void on_pushButton_264_clicked();

    void on_pushButton_262_clicked();

    void on_pushButton_260_clicked();

    void on_pushButton_261_clicked();

    void on_pushButton_497_clicked();

    void on_pushButton_498_clicked();

    void on_pushButton_494_clicked();

    void on_pushButton_507_clicked();

    void on_pushButton_509_clicked();

    void on_pushButton_510_clicked();

    void on_pushButton_512_clicked();

    void on_pushButton_530_clicked();

    void on_pushButton_511_clicked();

    void on_pushButton_514_clicked();

    void on_pushButton_513_clicked();

    void on_pushButton_516_clicked();

    void on_pushButton_515_clicked();

    void on_pushButton_524_clicked();

    void on_pushButton_519_clicked();

    void on_pushButton_523_clicked();

    void on_pushButton_520_clicked();

    void on_pushButton_543_clicked();

    void on_pushButton_521_clicked();

    void on_pushButton_525_clicked();

    void on_pushButton_527_clicked();

    void on_pushButton_526_clicked();

    void on_pushButton_529_clicked();

    void on_pushButton_532_clicked();

    void on_pushButton_531_clicked();

    void on_pushButton_536_clicked();

    void on_pushButton_537_clicked();

    void on_pushButton_544_clicked();

    void on_pushButton_539_clicked();

    void on_pushButton_541_clicked();

    void on_pushButton_533_clicked();

    void on_pushButton_535_clicked();

    void on_pushButton_534_clicked();

    void on_pushButton_551_clicked();

    void on_pushButton_556_clicked();

    void on_pushButton_548_clicked();

    void on_pushButton_554_clicked();

    void on_pushButton_545_clicked();

    void on_pushButton_558_clicked();

    void on_pushButton_555_clicked();

    void on_pushButton_557_objectNameChanged(const QString &objectName);

    void on_pushButton_557_clicked();

    void on_pushButton_552_clicked();

    void on_pushButton_549_clicked();

    void on_pushButton_578_clicked();

    void on_pushButton_571_clicked();

    void on_pushButton_580_clicked();

    void on_pushButton_572_clicked();

    void on_pushButton_573_clicked();

    void on_pushButton_576_clicked();

    void on_pushButton_575_clicked();

    void on_pushButton_574_clicked();

    void on_pushButton_577_clicked();

    void on_pushButton_581_clicked();

    void on_pushButton_1208_clicked();

    void on_pushButton_1206_clicked();

    void on_pushButton_1204_clicked();

    void on_pushButton_1207_clicked();

    void on_pushButton_1213_clicked();

    void on_pushButton_1211_clicked();

    void on_pushButton_1203_clicked();

    void on_pushButton_1212_clicked();

    void on_pushButton_1209_clicked();

    void on_pushButton_583_clicked();

    void on_pushButton_1219_clicked();

    void on_pushButton_1221_clicked();

    void on_pushButton_1215_clicked();

    void on_pushButton_1218_clicked();

    void on_pushButton_1224_clicked();

    void on_pushButton_1222_clicked();

    void on_pushButton_1214_clicked();

    void on_pushButton_1223_clicked();

    void on_pushButton_1220_clicked();

    void on_pushButton_584_clicked();

    void on_pushButton_1241_clicked();

    void on_pushButton_1243_clicked();

    void on_pushButton_1239_clicked();

    void on_pushButton_1240_clicked();

    void on_pushButton_1246_clicked();

    void on_pushButton_1244_clicked();

    void on_pushButton_1236_clicked();

    void on_pushButton_1245_clicked();

    void on_pushButton_1242_clicked();

    void on_pushButton_585_clicked();

    void on_pushButton_1230_clicked();

    void on_pushButton_1232_clicked();

    void on_pushButton_1228_clicked();

    void on_pushButton_1226_clicked();

    void on_pushButton_1235_clicked();

    void on_pushButton_1233_clicked();

    void on_pushButton_1225_clicked();

    void on_pushButton_1234_clicked();

    void on_pushButton_1231_clicked();

    void on_pushButton_586_clicked();

    void on_pushButton_479_clicked();

    void on_pushButton_481_clicked();

    void on_pushButton_477_clicked();

    void on_pushButton_487_clicked();

    void on_pushButton_478_clicked();

    void on_pushButton_476_clicked();

    void on_pushButton_485_clicked();

    void on_pushButton_482_clicked();

    void on_pushButton_484_clicked();

    void on_pushButton_486_clicked();

    void on_pushButton_18_clicked();

    void on_pushButton_19_clicked();

    void on_pushButton_17_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_470_clicked();

    void on_pushButton_471_clicked();

    void on_pushButton_474_clicked();

    void on_pushButton_496_clicked();

    void on_pushButton_472_clicked();

    void on_pushButton_473_clicked();

    void on_pushButton_27_clicked();

    void on_pushButton_29_clicked();

    void on_pushButton_28_clicked();

    void on_pushButton_463_clicked();

    void on_pushButton_464_clicked();

    void on_pushButton_465_clicked();

    void on_pushButton_506_clicked();

    void on_pushButton_466_clicked();

    void on_pushButton_467_clicked();

    void on_pushButton_39_clicked();

    void on_pushButton_40_clicked();

    void on_pushButton_32_clicked();

    void on_pushButton_38_clicked();

    void on_pushButton_456_clicked();

    void on_pushButton_459_clicked();

    void on_pushButton_508_clicked();

    void on_pushButton_455_clicked();

    void on_pushButton_454_clicked();

    void on_pushButton_88_clicked();

    void on_pushButton_87_clicked();

    void on_pushButton_86_clicked();

    void on_pushButton_452_clicked();

    void on_pushButton_450_clicked();

    void on_pushButton_451_clicked();

    void on_pushButton_447_clicked();

    void on_pushButton_449_clicked();

    void on_pushButton_442_clicked();

    void on_pushButton_443_clicked();

    void on_pushButton_448_clicked();

    void on_pushButton_439_clicked();

    void on_pushButton_440_clicked();

    void on_pushButton_441_clicked();

    void on_pushButton_427_clicked();

    void on_pushButton_430_clicked();

    void on_pushButton_428_clicked();

    void on_pushButton_431_clicked();

    void on_pushButton_432_clicked();

    void on_pushButton_107_clicked();

    void on_pushButton_106_clicked();

    void on_pushButton_110_clicked();

    void on_pushButton_104_clicked();

    void on_pushButton_423_clicked();

    void on_pushButton_458_clicked();

    void on_pushButton_425_clicked();

    void on_pushButton_424_clicked();

    void on_pushButton_420_clicked();

    void on_pushButton_422_clicked();

    void on_pushButton_114_clicked();

    void on_pushButton_113_clicked();

    void on_pushButton_117_clicked();

    void on_pushButton_115_clicked();

    void on_pushButton_124_clicked();

    void on_pushButton_123_clicked();

    void on_pushButton_127_clicked();

    void on_pushButton_122_clicked();

    void on_pushButton_412_clicked();

    void on_pushButton_460_clicked();

    void on_pushButton_411_clicked();

    void on_pushButton_409_clicked();

    void on_pushButton_414_clicked();

    void on_pushButton_410_clicked();

    void on_pushButton_403_clicked();

    void on_pushButton_404_clicked();

    void on_pushButton_405_clicked();

    void on_pushButton_406_clicked();

    void on_pushButton_400_clicked();

    void on_pushButton_401_clicked();

    void on_pushButton_399_clicked();

    void on_pushButton_397_clicked();

    void on_pushButton_402_clicked();

    void on_pushButton_302_clicked();

    void on_pushButton_468_clicked();

    void on_pushButton_303_clicked();

    void on_pushButton_301_clicked();

    void on_pushButton_300_clicked();

    void on_pushButton_299_clicked();

    void on_pushButton_228_clicked();

    void on_pushButton_227_clicked();

    void on_pushButton_225_clicked();

    void on_pushButton_25_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton999_clicked();

    void on_pushButton999_2_clicked();

    void on_pushButton999_3_clicked();

    void on_pushButton999_4_clicked();

    void on_pushButton_34_clicked();

    void on_tableViewarwa_activated(const QModelIndex &index);

    void on_pushButton_26_clicked();

    void on_pushButton_24_clicked();

    void on_pushButton_436_clicked();

    void on_pushButton_446_clicked();

    void on_pushButton_437_clicked();

    void on_pushButton_433_clicked();

    void on_pushButton_434_clicked();

    void on_pushButton_435_clicked();

    void on_pushButton_100_clicked();

    void on_pushButton_99_clicked();

    void on_pushButton_103_clicked();

    void on_pushButton_97_clicked();

    void on_pushButton_101_clicked();

    void on_pushButton_268_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_271_clicked();

    void on_pushButton_272_clicked();

    void on_pushButton_275_clicked();

    void on_pushButton_276_clicked();

    void on_pushButton_540_clicked();

    void on_pushButton_489_clicked();

    void on_pushButton_491_clicked();

    void on_pushButton_492_clicked();

    void on_pushButton_493_clicked();

    void on_pushButton_488_clicked();

    void on_pushButton_270_clicked();

    void on_pushButton_273_clicked();

    void on_pushButton_269_clicked();

    void on_pushButton_267_clicked();

    void on_pushButton_274_clicked();

    void on_pushButton_277_clicked();

    void on_pushButton_278_clicked();

    void on_pushButton_279_clicked();

    void on_pushButton_280_clicked();

    void on_pushButton_304_clicked();

    void on_pushButton_307_clicked();

    void on_pushButton_566_clicked();

    void on_pushButton_568_clicked();

    void on_pushButton_563_clicked();

    void on_pushButton_560_clicked();

    void on_pushButton_564_clicked();

    void on_pushButton_562_clicked();

    void on_pushButton_567_clicked();

    void on_pushButton_559_clicked();

    void on_pushButton_565_clicked();

    void on_pushButton_546_clicked();

    void on_pushButton_569_clicked();

    void on_refprod_14_clicked();

private:
    Ui::menu *ui;
    produit tmpp;
    nomen tmpn;
    menus tmpmn;
    bonf tmpbf;
    boni tmpbi;
    fourn tmpf;
};

#endif // MENU_H
