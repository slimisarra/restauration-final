--------------------------------------------------------
--  Fichier cr�� - jeudi-mai-28-2020   
--------------------------------------------------------
--------------------------------------------------------
--  DDL for Sequence EQUIPEMENT_SEQ
--------------------------------------------------------

   CREATE SEQUENCE  "SARRA"."EQUIPEMENT_SEQ"  MINVALUE 1 MAXVALUE 999999999999999999999999999 INCREMENT BY 1 START WITH 1 CACHE 20 NOORDER  NOCYCLE ;
--------------------------------------------------------
--  DDL for Table BONF
--------------------------------------------------------

  CREATE TABLE "SARRA"."BONF" 
   (	"PIC" VARCHAR2(20 BYTE), 
	"CODEF" VARCHAR2(20 BYTE), 
	"DATEBONF" VARCHAR2(20 BYTE), 
	"CODEP" VARCHAR2(20 BYTE), 
	"LIBELLE" VARCHAR2(50 BYTE), 
	"QTPROD" VARCHAR2(20 BYTE)
   ) PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Table BONI
--------------------------------------------------------

  CREATE TABLE "SARRA"."BONI" 
   (	"PIC" VARCHAR2(20 BYTE), 
	"DATEBONI" VARCHAR2(20 BYTE), 
	"CODEP" VARCHAR2(20 BYTE), 
	"LIBELLE" VARCHAR2(50 BYTE), 
	"QTPROD" VARCHAR2(20 BYTE)
   ) PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Table CONGE
--------------------------------------------------------

  CREATE TABLE "SARRA"."CONGE" 
   (	"REF" NUMBER, 
	"ID_P" VARCHAR2(20 BYTE), 
	"DATEDEBUT" VARCHAR2(20 BYTE), 
	"DATEFIN" VARCHAR2(20 BYTE)
   ) PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Table DEPARTEMENT
--------------------------------------------------------

  CREATE TABLE "SARRA"."DEPARTEMENT" 
   (	"NUM" VARCHAR2(20 BYTE), 
	"NOM_D" VARCHAR2(20 BYTE)
   ) PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Table EMPLOYE
--------------------------------------------------------

  CREATE TABLE "SARRA"."EMPLOYE" 
   (	"NOM_EMPLOYE" VARCHAR2(20 BYTE), 
	"MDP_EMPLOYE" VARCHAR2(20 BYTE)
   ) PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Table EQUIPEMENT
--------------------------------------------------------

  CREATE TABLE "SARRA"."EQUIPEMENT" 
   (	"REFERENCE" VARCHAR2(20 BYTE), 
	"FAMILLE" VARCHAR2(20 BYTE), 
	"LIBELLE" VARCHAR2(20 BYTE), 
	"ETAT" VARCHAR2(20 BYTE)
   ) PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Table ETUDIANT
--------------------------------------------------------

  CREATE TABLE "SARRA"."ETUDIANT" 
   (	"NOM" VARCHAR2(20 BYTE), 
	"ID" NUMBER, 
	"PRENOM" VARCHAR2(20 BYTE)
   ) PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Table FOURN
--------------------------------------------------------

  CREATE TABLE "SARRA"."FOURN" 
   (	"CODE" VARCHAR2(20 BYTE), 
	"ADR" VARCHAR2(100 BYTE), 
	"TEL" VARCHAR2(20 BYTE), 
	"REG" VARCHAR2(50 BYTE), 
	"FAX" VARCHAR2(20 BYTE), 
	"MAIL" VARCHAR2(100 BYTE), 
	"DAILLIV" VARCHAR2(30 BYTE), 
	"MODEPI" VARCHAR2(30 BYTE)
   ) PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Table MAINTENANCE
--------------------------------------------------------

  CREATE TABLE "SARRA"."MAINTENANCE" 
   (	"REFERENCEM" VARCHAR2(20 BYTE), 
	"LIBELLEM" VARCHAR2(20 BYTE), 
	"AGENT" VARCHAR2(20 BYTE), 
	"PRIX" NUMBER(*,0), 
	"DUREE" VARCHAR2(20 BYTE)
   ) PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Table MENUS
--------------------------------------------------------

  CREATE TABLE "SARRA"."MENUS" 
   (	"CODE" VARCHAR2(20 BYTE), 
	"NATURE" VARCHAR2(20 BYTE), 
	"DATEMENU" VARCHAR2(20 BYTE), 
	"QTPROD" VARCHAR2(20 BYTE), 
	"LIBELLE" VARCHAR2(20 BYTE)
   ) PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Table NOMEN
--------------------------------------------------------

  CREATE TABLE "SARRA"."NOMEN" 
   (	"CODE" NUMBER, 
	"CODECOMP" NUMBER, 
	"COEF" NUMBER, 
	"DATEN" VARCHAR2(20 BYTE)
   ) PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Table PERSONNEL
--------------------------------------------------------

  CREATE TABLE "SARRA"."PERSONNEL" 
   (	"DEPARTEMENT" VARCHAR2(20 BYTE), 
	"NOM" VARCHAR2(20 BYTE), 
	"PRENOM" VARCHAR2(20 BYTE), 
	"SALAIRE" NUMBER(*,0), 
	"DATENAISS" VARCHAR2(20 BYTE), 
	"ID" NUMBER, 
	"DATEEMB" VARCHAR2(20 BYTE)
   ) PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Table PRODUIT
--------------------------------------------------------

  CREATE TABLE "SARRA"."PRODUIT" 
   (	"CODE" VARCHAR2(20 BYTE), 
	"LIBELLE" VARCHAR2(50 BYTE), 
	"DATEPROD" VARCHAR2(20 BYTE), 
	"PRIX" NUMBER, 
	"QT" NUMBER, 
	"CATG" VARCHAR2(50 BYTE), 
	"FAMIL" VARCHAR2(50 BYTE)
   ) PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Table VENDRE
--------------------------------------------------------

  CREATE TABLE "SARRA"."VENDRE" 
   (	"REFERENCEV" VARCHAR2(20 BYTE), 
	"LIBELLEV" VARCHAR2(20 BYTE), 
	"ACHETEUR" VARCHAR2(20 BYTE), 
	"PRIX" NUMBER(*,0)
   ) PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT)
  TABLESPACE "SYSTEM" ;
REM INSERTING into SARRA.BONF
SET DEFINE OFF;
Insert into SARRA.BONF (PIC,CODEF,DATEBONF,CODEP,LIBELLE,QTPROD) values ('df','458','mer. janv. 1 2020','525','df','d');
Insert into SARRA.BONF (PIC,CODEF,DATEBONF,CODEP,LIBELLE,QTPROD) values ('526','1234','sam. janv. 1 2000','7452','dlf','kdf');
Insert into SARRA.BONF (PIC,CODEF,DATEBONF,CODEP,LIBELLE,QTPROD) values ('526','1234','sam. janv. 1 2000','7452','dks','25');
Insert into SARRA.BONF (PIC,CODEF,DATEBONF,CODEP,LIBELLE,QTPROD) values ('745','1234','sam. janv. 1 2000','7452','lfds','15');
Insert into SARRA.BONF (PIC,CODEF,DATEBONF,CODEP,LIBELLE,QTPROD) values ('147','1234','sam. janv. 1 2000','7452','df','df');
Insert into SARRA.BONF (PIC,CODEF,DATEBONF,CODEP,LIBELLE,QTPROD) values ('745','1234','sam. janv. 1 2000','7452','dsd','4');
Insert into SARRA.BONF (PIC,CODEF,DATEBONF,CODEP,LIBELLE,QTPROD) values ('745','1234','sam. janv. 1 2000','5963','ldfk','4');
Insert into SARRA.BONF (PIC,CODEF,DATEBONF,CODEP,LIBELLE,QTPROD) values ('745','1234','sam. janv. 1 2000','5963','d','4');
Insert into SARRA.BONF (PIC,CODEF,DATEBONF,CODEP,LIBELLE,QTPROD) values ('748','785','sam. janv. 1 2000','751','uah','4');
Insert into SARRA.BONF (PIC,CODEF,DATEBONF,CODEP,LIBELLE,QTPROD) values ('748','785','sam. janv. 1 2000','855','lkcs','k;x');
Insert into SARRA.BONF (PIC,CODEF,DATEBONF,CODEP,LIBELLE,QTPROD) values ('748','785','sam. janv. 1 2000','7452','565','45');
Insert into SARRA.BONF (PIC,CODEF,DATEBONF,CODEP,LIBELLE,QTPROD) values ('748','785','sam. janv. 1 2000','5963','l,dfsdk','ld');
REM INSERTING into SARRA.BONI
SET DEFINE OFF;
Insert into SARRA.BONI (PIC,DATEBONI,CODEP,LIBELLE,QTPROD) values ('896','sam. janv. 1 2000','7452','jqs','sk');
Insert into SARRA.BONI (PIC,DATEBONI,CODEP,LIBELLE,QTPROD) values ('896','sam. janv. 1 2000','7452','jndj','zjd');
Insert into SARRA.BONI (PIC,DATEBONI,CODEP,LIBELLE,QTPROD) values ('896','sam. janv. 1 2000','855','ss','r');
Insert into SARRA.BONI (PIC,DATEBONI,CODEP,LIBELLE,QTPROD) values ('8454','sam. janv. 1 2000','855','fd','rkdf');
Insert into SARRA.BONI (PIC,DATEBONI,CODEP,LIBELLE,QTPROD) values ('845','sam. janv. 1 2000','855','fd','rkdf');
Insert into SARRA.BONI (PIC,DATEBONI,CODEP,LIBELLE,QTPROD) values (null,'sam. janv. 1 2000',null,null,null);
REM INSERTING into SARRA.CONGE
SET DEFINE OFF;
Insert into SARRA.CONGE (REF,ID_P,DATEDEBUT,DATEFIN) values ('100','10','lun. janv. 3 2000','mar. janv. 4 2000');
Insert into SARRA.CONGE (REF,ID_P,DATEDEBUT,DATEFIN) values ('5','4','sam. janv. 1 2000','sam. janv. 1 2000');
Insert into SARRA.CONGE (REF,ID_P,DATEDEBUT,DATEFIN) values ('5','4','sam. janv. 1 2000','sam. janv. 1 2000');
Insert into SARRA.CONGE (REF,ID_P,DATEDEBUT,DATEFIN) values ('1','10','sam. janv. 1 2000','sam. janv. 1 2000');
Insert into SARRA.CONGE (REF,ID_P,DATEDEBUT,DATEFIN) values ('70','4','sam. janv. 1 2000','sam. janv. 1 2000');
Insert into SARRA.CONGE (REF,ID_P,DATEDEBUT,DATEFIN) values ('88','10','mar. janv. 4 2000','jeu. janv. 6 2000');
REM INSERTING into SARRA.DEPARTEMENT
SET DEFINE OFF;
Insert into SARRA.DEPARTEMENT (NUM,NOM_D) values ('3','m');
Insert into SARRA.DEPARTEMENT (NUM,NOM_D) values ('8','j');
Insert into SARRA.DEPARTEMENT (NUM,NOM_D) values ('15','l');
Insert into SARRA.DEPARTEMENT (NUM,NOM_D) values ('2','salem');
REM INSERTING into SARRA.EMPLOYE
SET DEFINE OFF;
Insert into SARRA.EMPLOYE (NOM_EMPLOYE,MDP_EMPLOYE) values ('arwa','0000');
Insert into SARRA.EMPLOYE (NOM_EMPLOYE,MDP_EMPLOYE) values ('farah','1111');
Insert into SARRA.EMPLOYE (NOM_EMPLOYE,MDP_EMPLOYE) values ('sarra','2222');
Insert into SARRA.EMPLOYE (NOM_EMPLOYE,MDP_EMPLOYE) values ('iheb','3333');
Insert into SARRA.EMPLOYE (NOM_EMPLOYE,MDP_EMPLOYE) values ('aziz','4444');
REM INSERTING into SARRA.EQUIPEMENT
SET DEFINE OFF;
Insert into SARRA.EQUIPEMENT (REFERENCE,FAMILLE,LIBELLE,ETAT) values ('3','Chambre','lit','maintenir');
Insert into SARRA.EQUIPEMENT (REFERENCE,FAMILLE,LIBELLE,ETAT) values ('1','Electro','clima','c bon maintenu');
Insert into SARRA.EQUIPEMENT (REFERENCE,FAMILLE,LIBELLE,ETAT) values ('12','Electro','soso','maintenir');
Insert into SARRA.EQUIPEMENT (REFERENCE,FAMILLE,LIBELLE,ETAT) values ('2','Cuisine','gaz','maintenir');
Insert into SARRA.EQUIPEMENT (REFERENCE,FAMILLE,LIBELLE,ETAT) values ('55','Electro','g','maintenir');
Insert into SARRA.EQUIPEMENT (REFERENCE,FAMILLE,LIBELLE,ETAT) values ('123','Electro','gg','c bon maintenu');
Insert into SARRA.EQUIPEMENT (REFERENCE,FAMILLE,LIBELLE,ETAT) values ('1244','Chambre','ff','maintenir');
Insert into SARRA.EQUIPEMENT (REFERENCE,FAMILLE,LIBELLE,ETAT) values ('55','Electro','lala','maintenir');
Insert into SARRA.EQUIPEMENT (REFERENCE,FAMILLE,LIBELLE,ETAT) values ('181dd','Chambre','fifi','maintenir');
Insert into SARRA.EQUIPEMENT (REFERENCE,FAMILLE,LIBELLE,ETAT) values ('99999','Cuisine','frigo','vendre');
Insert into SARRA.EQUIPEMENT (REFERENCE,FAMILLE,LIBELLE,ETAT) values ('7','Electro','vv','c bon maintenu');
Insert into SARRA.EQUIPEMENT (REFERENCE,FAMILLE,LIBELLE,ETAT) values ('6','Electro','mm','maintenir');
Insert into SARRA.EQUIPEMENT (REFERENCE,FAMILLE,LIBELLE,ETAT) values (null,'Electro','mm','maintenir');
Insert into SARRA.EQUIPEMENT (REFERENCE,FAMILLE,LIBELLE,ETAT) values ('4','Electro','ff','vendre');
REM INSERTING into SARRA.ETUDIANT
SET DEFINE OFF;
Insert into SARRA.ETUDIANT (NOM,ID,PRENOM) values ('bejaoui','142','lamia');
Insert into SARRA.ETUDIANT (NOM,ID,PRENOM) values ('lefi','1234','lamia');
Insert into SARRA.ETUDIANT (NOM,ID,PRENOM) values ('beja','111','amen');
Insert into SARRA.ETUDIANT (NOM,ID,PRENOM) values ('bejaoui','11','loulou');
REM INSERTING into SARRA.FOURN
SET DEFINE OFF;
Insert into SARRA.FOURN (CODE,ADR,TEL,REG,FAX,MAIL,DAILLIV,MODEPI) values ('52',null,null,'Tunis',null,null,null,'Cheque');
Insert into SARRA.FOURN (CODE,ADR,TEL,REG,FAX,MAIL,DAILLIV,MODEPI) values ('458',null,null,'Tunis',null,null,null,'Cheque');
Insert into SARRA.FOURN (CODE,ADR,TEL,REG,FAX,MAIL,DAILLIV,MODEPI) values ('785','hammalif','52512546','Nabeul','71586947','brahim.ferjeni','2 jours','traite');
Insert into SARRA.FOURN (CODE,ADR,TEL,REG,FAX,MAIL,DAILLIV,MODEPI) values ('lerf','fd','df','Tunis','d',null,null,'Cheque');
Insert into SARRA.FOURN (CODE,ADR,TEL,REG,FAX,MAIL,DAILLIV,MODEPI) values ('5214','kdf','lksc','Tunis',null,null,null,'Cheque');
REM INSERTING into SARRA.MAINTENANCE
SET DEFINE OFF;
Insert into SARRA.MAINTENANCE (REFERENCEM,LIBELLEM,AGENT,PRIX,DUREE) values ('3','lit','3amsalah','2','mer. avr. 1 2020');
Insert into SARRA.MAINTENANCE (REFERENCEM,LIBELLEM,AGENT,PRIX,DUREE) values ('3','lit','3amsalah','500','ven. mai 1 2020');
Insert into SARRA.MAINTENANCE (REFERENCEM,LIBELLEM,AGENT,PRIX,DUREE) values ('12','soso','3amsalah','44','sam. juil. 1 2000');
Insert into SARRA.MAINTENANCE (REFERENCEM,LIBELLEM,AGENT,PRIX,DUREE) values ('3','lit','3amsalah','800','mar. mai 2 2000');
Insert into SARRA.MAINTENANCE (REFERENCEM,LIBELLEM,AGENT,PRIX,DUREE) values ('2','lit','3amsalah','888','sam. janv. 1 2000');
Insert into SARRA.MAINTENANCE (REFERENCEM,LIBELLEM,AGENT,PRIX,DUREE) values ('3','lit','3amsalah','0','sam. janv. 1 2000');
Insert into SARRA.MAINTENANCE (REFERENCEM,LIBELLEM,AGENT,PRIX,DUREE) values ('3','lit','3amsalah','100','sam. janv. 1 2000');
Insert into SARRA.MAINTENANCE (REFERENCEM,LIBELLEM,AGENT,PRIX,DUREE) values ('3','lit','3amsalah','150','dim. mars 1 2020');
Insert into SARRA.MAINTENANCE (REFERENCEM,LIBELLEM,AGENT,PRIX,DUREE) values ('7','vv','3amsalah','55','sam. janv. 1 2000');
Insert into SARRA.MAINTENANCE (REFERENCEM,LIBELLEM,AGENT,PRIX,DUREE) values ('6','lit','3amsalah','200','sam. janv. 1 2000');
REM INSERTING into SARRA.MENUS
SET DEFINE OFF;
Insert into SARRA.MENUS (CODE,NATURE,DATEMENU,QTPROD,LIBELLE) values ('785','Déj','sam. janv. 1 2000','5','569');
Insert into SARRA.MENUS (CODE,NATURE,DATEMENU,QTPROD,LIBELLE) values ('55','Petit Déj','lun. janv. 7 2008','5','ld;fdl');
Insert into SARRA.MENUS (CODE,NATURE,DATEMENU,QTPROD,LIBELLE) values ('159','Déj','1','1','ammouna');
Insert into SARRA.MENUS (CODE,NATURE,DATEMENU,QTPROD,LIBELLE) values ('25','Déj','mer. janv. 1 2020',null,null);
Insert into SARRA.MENUS (CODE,NATURE,DATEMENU,QTPROD,LIBELLE) values ('785','Déj','sam. janv. 1 2000','kk','45');
Insert into SARRA.MENUS (CODE,NATURE,DATEMENU,QTPROD,LIBELLE) values ('7452','Déj','ven. nov. 6 2020','fv','fgv');
Insert into SARRA.MENUS (CODE,NATURE,DATEMENU,QTPROD,LIBELLE) values ('624','Déj','sam. janv. 1 2000','45','TOMATO');
Insert into SARRA.MENUS (CODE,NATURE,DATEMENU,QTPROD,LIBELLE) values ('55','Petit Déj','lun. janv. 7 2008','5','ld;fdl');
Insert into SARRA.MENUS (CODE,NATURE,DATEMENU,QTPROD,LIBELLE) values ('444','Déj','sam. janv. 1 2000','4','kjfds');
Insert into SARRA.MENUS (CODE,NATURE,DATEMENU,QTPROD,LIBELLE) values ('7452','Déj','jeu. janv. 13 2000','55','mldf');
Insert into SARRA.MENUS (CODE,NATURE,DATEMENU,QTPROD,LIBELLE) values ('7452','Déj','jeu. janv. 13 2000','4','vd');
Insert into SARRA.MENUS (CODE,NATURE,DATEMENU,QTPROD,LIBELLE) values ('525','Dinner','mer. janv. 5 2000','kl','5');
REM INSERTING into SARRA.NOMEN
SET DEFINE OFF;
Insert into SARRA.NOMEN (CODE,CODECOMP,COEF,DATEN) values ('852','52','2','dim. avr. 1 2001');
REM INSERTING into SARRA.PERSONNEL
SET DEFINE OFF;
Insert into SARRA.PERSONNEL (DEPARTEMENT,NOM,PRENOM,SALAIRE,DATENAISS,ID,DATEEMB) values ('8','s','d','10','sam. janv. 1 2000','4','sam. janv. 1 2000');
Insert into SARRA.PERSONNEL (DEPARTEMENT,NOM,PRENOM,SALAIRE,DATENAISS,ID,DATEEMB) values ('8','nl','hjk','10','sam. janv. 1 2000','10000','sam. janv. 1 2000');
Insert into SARRA.PERSONNEL (DEPARTEMENT,NOM,PRENOM,SALAIRE,DATENAISS,ID,DATEEMB) values ('3','fl','gh','70','sam. janv. 1 2000','1','sam. janv. 1 2000');
Insert into SARRA.PERSONNEL (DEPARTEMENT,NOM,PRENOM,SALAIRE,DATENAISS,ID,DATEEMB) values ('8','k','k','10','sam. janv. 1 2000','4','sam. janv. 1 2000');
Insert into SARRA.PERSONNEL (DEPARTEMENT,NOM,PRENOM,SALAIRE,DATENAISS,ID,DATEEMB) values ('4','da','fg','10','sam. janv. 1 2000','7','sam. janv. 1 2000');
Insert into SARRA.PERSONNEL (DEPARTEMENT,NOM,PRENOM,SALAIRE,DATENAISS,ID,DATEEMB) values ('3','jk','il','10','sam. janv. 1 2000','5','sam. janv. 1 2000');
Insert into SARRA.PERSONNEL (DEPARTEMENT,NOM,PRENOM,SALAIRE,DATENAISS,ID,DATEEMB) values ('3','njl','n,','45','sam. janv. 1 2000','8','sam. janv. 1 2000');
Insert into SARRA.PERSONNEL (DEPARTEMENT,NOM,PRENOM,SALAIRE,DATENAISS,ID,DATEEMB) values ('3','dh','kl','100','mar. janv. 4 2000','10','sam. janv. 1 2000');
Insert into SARRA.PERSONNEL (DEPARTEMENT,NOM,PRENOM,SALAIRE,DATENAISS,ID,DATEEMB) values ('3','j','lm','40','mar. janv. 11 2000','4','sam. janv. 1 2000');
Insert into SARRA.PERSONNEL (DEPARTEMENT,NOM,PRENOM,SALAIRE,DATENAISS,ID,DATEEMB) values ('8',null,null,'0','sam. janv. 1 2000',null,'sam. janv. 1 2000');
Insert into SARRA.PERSONNEL (DEPARTEMENT,NOM,PRENOM,SALAIRE,DATENAISS,ID,DATEEMB) values (null,'a','s','10','sam. janv. 1 2000',null,'sam. janv. 1 2000');
Insert into SARRA.PERSONNEL (DEPARTEMENT,NOM,PRENOM,SALAIRE,DATENAISS,ID,DATEEMB) values (null,'x','c','1000','sam. janv. 1 2000','7','sam. janv. 1 2000');
REM INSERTING into SARRA.PRODUIT
SET DEFINE OFF;
Insert into SARRA.PRODUIT (CODE,LIBELLE,DATEPROD,PRIX,QT,CATG,FAMIL) values ('444','j,ds','sam. janv. 1 2000','4','6','Matiére premiére','Légumes');
Insert into SARRA.PRODUIT (CODE,LIBELLE,DATEPROD,PRIX,QT,CATG,FAMIL) values ('525','gff','sam. janv. 1 2000','4','4','Matiére premiére','Légumes');
Insert into SARRA.PRODUIT (CODE,LIBELLE,DATEPROD,PRIX,QT,CATG,FAMIL) values ('11','jdncdjx','sam. janv. 1 2000','4','25','Matiére premiére','Légumes');
Insert into SARRA.PRODUIT (CODE,LIBELLE,DATEPROD,PRIX,QT,CATG,FAMIL) values ('55','dfd','sam. janv. 1 2000','0','50','Matiére premiére','Légumes');
Insert into SARRA.PRODUIT (CODE,LIBELLE,DATEPROD,PRIX,QT,CATG,FAMIL) values ('7452','POTATO','sam. janv. 1 2000','5','44','Produit fini','Légumes');
Insert into SARRA.PRODUIT (CODE,LIBELLE,DATEPROD,PRIX,QT,CATG,FAMIL) values ('5963','ldf','sam. janv. 1 2000','7','2','Produit fini','Légumes');
REM INSERTING into SARRA.VENDRE
SET DEFINE OFF;
Insert into SARRA.VENDRE (REFERENCEV,LIBELLEV,ACHETEUR,PRIX) values ('8','machina','Societe Bois','0');
Insert into SARRA.VENDRE (REFERENCEV,LIBELLEV,ACHETEUR,PRIX) values ('8','machina','Societe Bois','0');
Insert into SARRA.VENDRE (REFERENCEV,LIBELLEV,ACHETEUR,PRIX) values ('5','armoir','Societe Bois','500');
Insert into SARRA.VENDRE (REFERENCEV,LIBELLEV,ACHETEUR,PRIX) values ('8','machina','Renouvable Societe','500');
Insert into SARRA.VENDRE (REFERENCEV,LIBELLEV,ACHETEUR,PRIX) values ('8','machina','Societe Bois','0');
Insert into SARRA.VENDRE (REFERENCEV,LIBELLEV,ACHETEUR,PRIX) values ('8','machina','Societe Bois','0');
Insert into SARRA.VENDRE (REFERENCEV,LIBELLEV,ACHETEUR,PRIX) values ('8','machina','Societe Bois','0');
Insert into SARRA.VENDRE (REFERENCEV,LIBELLEV,ACHETEUR,PRIX) values ('8','machina','Societe Bois','0');
Insert into SARRA.VENDRE (REFERENCEV,LIBELLEV,ACHETEUR,PRIX) values ('8','machina','Societe Bois','0');
Insert into SARRA.VENDRE (REFERENCEV,LIBELLEV,ACHETEUR,PRIX) values ('8','machina','Societe Bois','0');
Insert into SARRA.VENDRE (REFERENCEV,LIBELLEV,ACHETEUR,PRIX) values ('99999','frigo','Societe Bois','200');
--------------------------------------------------------
--  DDL for Index ETUDIANT_PK
--------------------------------------------------------

  CREATE UNIQUE INDEX "SARRA"."ETUDIANT_PK" ON "SARRA"."ETUDIANT" ("ID") 
  PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  Constraints for Table ETUDIANT
--------------------------------------------------------

  ALTER TABLE "SARRA"."ETUDIANT" ADD CONSTRAINT "ETUDIANT_PK" PRIMARY KEY ("ID")
  USING INDEX PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT)
  TABLESPACE "SYSTEM"  ENABLE;
 
  ALTER TABLE "SARRA"."ETUDIANT" MODIFY ("ID" NOT NULL ENABLE);
--------------------------------------------------------
--  Constraints for Table FOURN
--------------------------------------------------------

  ALTER TABLE "SARRA"."FOURN" MODIFY ("CODE" NOT NULL ENABLE);
--------------------------------------------------------
--  Constraints for Table NOMEN
--------------------------------------------------------

  ALTER TABLE "SARRA"."NOMEN" MODIFY ("CODE" NOT NULL ENABLE);
 
  ALTER TABLE "SARRA"."NOMEN" MODIFY ("CODECOMP" NOT NULL ENABLE);
--------------------------------------------------------
--  Constraints for Table MENUS
--------------------------------------------------------

  ALTER TABLE "SARRA"."MENUS" MODIFY ("NATURE" NOT NULL ENABLE);
 
  ALTER TABLE "SARRA"."MENUS" MODIFY ("DATEMENU" NOT NULL ENABLE);
