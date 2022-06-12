#include "OpenAccount.h"
#include "ui_OpenAccount.h"
#include "Menu.h"
#include <QMessageBox>


void OpenAccount::setData(QString title,QString button_name,QString name2,bool acc_status){
    setWindowTitle(title);
    ui->ao_push->setText(button_name);
    ui->ao_back->setText(name2);
    ui->ao_acc_no->setReadOnly(acc_status);
}

void OpenAccount::setAccountNumber(){
    ui->ao_acc_no->setText(QString::number(OpenAccount::getAccountNumber()));
    ui->ao_acc_no->setReadOnly(true);
}

void OpenAccount::setoff(){
    ui->ao_type->setDisabled(true);
    ui->ao_name->setReadOnly(true);
    ui->ao_dob->setReadOnly(true);
    ui->ao_gender->setDisabled(true);
    ui->ao_mobno->setReadOnly(true);
    ui->ao_nationality->setReadOnly(true);
    ui->ao_address->setReadOnly(true);
    ui->ao_fname->setReadOnly(true);
}

void OpenAccount::seton(){
    ui->ao_name->setReadOnly(false);
    ui->ao_dob->setReadOnly(false);
    ui->ao_gender->setDisabled(false);
    ui->ao_mobno->setReadOnly(false);
    ui->ao_nationality->setReadOnly(false);
    ui->ao_address->setReadOnly(false);
    ui->ao_fname->setReadOnly(false);
}

OpenAccount::OpenAccount(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::OpenAccount)
{
    ui->setupUi(this);
    ui->ao_male->setChecked(true);
    ui->ao_mobno->setInputMask("9999999999");
    ui->ao_mobno->clear();
    ui->ao_mobno->setMaxLength(10);
}

OpenAccount::~OpenAccount()
{
    delete ui;
}

//Load Data To dialog Box

void OpenAccount::loadData(QString acc_no){
    OpenAccount::Connect();
    QSqlQuery query;
    query.prepare("Select [Account Number],[Account Type],[Name],[Date of Birth],[Gender],[Mobile No],[Nationality],[Address],"
                  "[Father Name] FROM account WHERE [Account Number]='"+acc_no+"'");
    query.exec();
    while(query.next()){
        ui->ao_acc_no->setText(query.value(0).toString());
        ui->ao_type->setCurrentText(query.value(1).toString());
        ui->ao_name->setText(query.value(2).toString());
        ui->ao_dob->setDate(query.value(3).toDate());
        if(query.value(4).toString()=="Male"){
            ui->ao_male->setChecked(true);
        }
        else{
            ui->ao_female->setChecked(true);
        }
        ui->ao_mobno->setText(query.value(5).toString());
        ui->ao_nationality->setText(query.value(6).toString());
        ui->ao_address->setText(query.value(7).toString());
        ui->ao_fname->setText(query.value(8).toString());
    }
    OpenAccount::seton();
    OpenAccount::Disconnect();
}

//Check Account No

bool OpenAccount::checkAccountNumber(int acc_no){
    OpenAccount::Connect();
    QSqlQuery query;
    query.prepare("SELECT * FROM account WHERE [Account Number]='"+QString::number(acc_no)+"'");
    query.exec();
    while(query.next()){
        OpenAccount::Disconnect();
        return false;
    }
    OpenAccount::Disconnect();
    return true;
}

//Get Account No

int OpenAccount::getAccountNumber(){
    int acc_no=0;
    OpenAccount::Connect();
    QSqlQuery query;
    query.prepare("SELECT max([Account Number]) FROM account");
    query.exec();
    while(query.next()){
        acc_no=query.value(0).toInt();
    }
    return  acc_no+1;
}
//Get Rate

double OpenAccount::getRate(QString type){
    OpenAccount::Connect();
    QSqlQuery query;
    double rate;
    query.prepare("SELECT * FROM ratelist WHERE [Account Type]='"+type+"'");
    query.exec();
    while(query.next()){
        rate=query.value(1).toDouble();
    }
    OpenAccount::Disconnect();
    return rate;
}

//Clear Data

void OpenAccount::clearData(){
    ui->ao_acc_no->clear();
    ui->ao_type->setCurrentIndex(0);
    ui->ao_name->clear();
    ui->ao_dob->clear();
    ui->ao_male->setChecked(true);
    ui->ao_mobno->clear();
    ui->ao_nationality->clear();
    ui->ao_address->clear();
    ui->ao_fname->clear();
//    ui->ao_gfname->clear();
}

//Account Open Back Button

void OpenAccount::on_ao_back_clicked()
{
    if(ui->ao_back->text()=="Close"){
        close();
    }
    else{
        Menu *win=new Menu;
        this->hide();
        win->show();
    }
}

//Account Open Check Null

bool OpenAccount::isNullData(){
    if(ui->ao_acc_no->text()==NULL || ui->ao_name->text()==NULL || ui->ao_mobno->text()==NULL || ui->ao_nationality->text()==NULL || ui->ao_address->text()==NULL || ui->ao_fname->text()==NULL){
        return true;
    }
    return false;
}

//DataBase Connection

bool OpenAccount::Connect(){
    mydb=QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName(pathToDatabase);
    if(mydb.open()){
        return true;
    }
    else{
        return false;
    }
}

//DataBase Disconnect

void OpenAccount::Disconnect(){
    mydb.close();
    mydb.removeDatabase(QSqlDatabase::defaultConnection);
}

SavingAccount OpenAccount::getUpdateData(){
    SavingAccount acc;
    acc.saving.setaccount_no(ui->ao_acc_no->text());
    acc.saving.setaccount_type(ui->ao_type->currentText());
    acc.name.setname(ui->ao_name->text());
    acc.info.birth.setdate(ui->ao_dob->date());
    if(ui->ao_male->isChecked()){
        acc.info.setgender("Male");
    }
    else{
        acc.info.setgender("Female");
    }
    acc.info.setmobileno(ui->ao_mobno->text());
    acc.info.setnationality(ui->ao_nationality->text());
    acc.info.setaddress(ui->ao_address->text());
    acc.father.setname(ui->ao_fname->text());
//    acc.grandfather.setname(ui->ao_gfname->text());
    return acc;
}

//Update Data

bool OpenAccount::updateData(SavingAccount k){
    OpenAccount::Connect();
    QSqlQuery query;
    query.prepare("UPDATE account SET [Name]=:name,[Date of Birth]=:dob,[Gender]=:gender,[Mobile No]=:mob,[Nationality]=:nationality,[Address]=:address,"
                  "[Father Name]=:fname WHERE [Account Number]='"+k.saving.getaccount_no()+"'");
    query.bindValue(":name",k.name.getname());
    query.bindValue(":dob",k.info.birth.getdate());
    query.bindValue(":gender",k.info.getgender());
    query.bindValue(":mob",k.info.getmobileno());
    query.bindValue(":nationality",k.info.getnationality());
    query.bindValue(":address",k.info.getaddress());
    query.bindValue(":fname",k.father.getname());
//    query.bindValue(":gfname",k.grandfather.getname());
    if(query.exec()){
        OpenAccount::Disconnect();
        return true;
    }
    OpenAccount::Disconnect();
    return false;
}

//Get Saving Account Data

SavingAccount OpenAccount::getSavingData(){
    SavingAccount acc;
    acc.saving.setaccount_no(ui->ao_acc_no->text());
    acc.saving.setaccount_type(ui->ao_type->currentText());
    acc.name.setname(ui->ao_name->text());
    acc.info.birth.setdate(ui->ao_dob->date());
    if(ui->ao_male->isChecked()){
        acc.info.setgender("Male");
    }
    else{
        acc.info.setgender("Female");
    }
    acc.info.setmobileno(ui->ao_mobno->text());
    acc.info.setnationality(ui->ao_nationality->text());
    acc.info.setaddress(ui->ao_address->text());
    acc.father.setname(ui->ao_fname->text());
//    acc.grandfather.setname(ui->ao_gfname->text());
    acc.saving.setstatus(true);
    acc.account_created.setdate(QDate::currentDate());
    acc.setrate(OpenAccount::getRate("Saving"));
    acc.saving.setbalance("0");
    return acc;
}

//Get Current Account Data

CurrentAccount OpenAccount::getCurrentData(){
    CurrentAccount acc;
    acc.current.setaccount_no(ui->ao_acc_no->text());
    acc.current.setaccount_type(ui->ao_type->currentText());
    acc.name.setname(ui->ao_name->text());
    acc.info.birth.setdate(ui->ao_dob->date());
    if(ui->ao_male->isChecked()){
        acc.info.setgender("Male");
    }
    else{
        acc.info.setgender("Female");
    }
    acc.info.setmobileno(ui->ao_mobno->text());
    acc.info.setnationality(ui->ao_nationality->text());
    acc.info.setaddress(ui->ao_address->text());
    acc.father.setname(ui->ao_fname->text());
//    acc.grandfather.setname(ui->ao_gfname->text());
    acc.current.setstatus(true);
    acc.account_created.setdate(QDate::currentDate());
    acc.current.setbalance("0");
    return acc;
}

//Saving Account Data to Database

void OpenAccount::sendToSavingAccountDb(SavingAccount k){
    OpenAccount::Connect();
    QSqlQuery query;
    query.prepare("INSERT INTO account ([Account Number],[Account Type],[Name],[Date of Birth],[Gender],[Mobile Number],"
                  "[Nationality],[Address],[Father Name],[Status],[Account Created],[Rate],[Balance],[Account Created Time])"
                  "VALUES(:acc_no,:type,:name,:dob,:gender,:mob_no,:nationality,:address,:fname,:status,:acc_created,:rate,:blnc,:time)");
    query.bindValue(":acc_no",k.saving.getaccount_no());
    query.bindValue(":type",k.saving.getaccount_type());
    query.bindValue(":name",k.name.getname());
    query.bindValue(":dob",k.info.birth.getdate());
    query.bindValue(":gender",k.info.getgender());
    query.bindValue(":mob_no",k.info.getmobileno());
    query.bindValue(":nationality",k.info.getnationality());
    query.bindValue(":address",k.info.getaddress());
    query.bindValue(":fname",k.father.getname());
//    query.bindValue(":gfname",k.grandfather.getname());
    query.bindValue(":status",k.saving.getstatus());
    query.bindValue(":acc_created",k.account_created.getdate());
    query.bindValue(":rate",k.getrate());
    query.bindValue(":blnc",k.saving.getbalance());
    query.bindValue(":time",QTime::currentTime());
    if(query.exec()){
        QMessageBox::information(this,"Account","Account Was Created Successfully");
        OpenAccount::clearData();
        return;
    }
    QMessageBox::warning(this,"Account",query.lastError().text());
    return;
}

//Current Account To Database

void OpenAccount::sendToCurrentAccountDb(CurrentAccount k){
    OpenAccount::Connect();
    QSqlQuery query;
    query.prepare("INSERT INTO account ([Account Number],[Account Type],[Name],[Date of Birth],[Gender],[Mobile Number],"
                  "[Nationality],[Address],[Father Name],[Status],[Account Created],[Rate],[Balance],[Account Created Time])"
                  "VALUES(:acc_no,:type,:name,:dob,:gender,:mob_no,:nationality,:address,:fname,:status,:acc_created,:rate,:blnc,:time)");
    query.bindValue(":acc_no",k.current.getaccount_no());
    query.bindValue(":type",k.current.getaccount_type());
    query.bindValue(":name",k.name.getname());
    query.bindValue(":dob",k.info.birth.getdate());
    query.bindValue(":gender",k.info.getgender());
    query.bindValue(":mob_no",k.info.getmobileno());
    query.bindValue(":nationality",k.info.getnationality());
    query.bindValue(":address",k.info.getaddress());
    query.bindValue(":fname",k.father.getname());
//    query.bindValue(":gfname",k.grandfather.getname());
    query.bindValue(":status",k.current.getstatus());
    query.bindValue(":acc_created",k.account_created.getdate());
    query.bindValue(":blnc",k.current.getbalance());
    query.bindValue(":time",QTime::currentTime());
    if(query.exec()){
        QMessageBox::information(this,"Account","Account Was Created Successfully");
        OpenAccount::clearData();
        return;
    }
    QMessageBox::warning(this,"Account",query.lastError().text());
    return;
}


void OpenAccount::on_ao_push_clicked()
{
    if(ui->ao_push->text()=="Create Account"){
        if(OpenAccount::isNullData()){
            QMessageBox::warning(this,"Account","Please Enter All The Information!!");
        }
        else{
            if(ui->ao_type->currentText()=="Saving"){
                SavingAccount k=OpenAccount::getSavingData();
                OpenAccount::sendToSavingAccountDb(k);
            }
            else{
                CurrentAccount k=OpenAccount::getCurrentData();
                OpenAccount::sendToCurrentAccountDb(k);
            }
            OpenAccount::setAccountNumber();
        }
    }
    else{
        if(OpenAccount::isNullData()){
            QMessageBox::warning(this,"Account","Please Enter All The Information!!");
        }
        else{
            SavingAccount k=OpenAccount::getUpdateData();
            if(OpenAccount::updateData(k)){
                QMessageBox::information(this,"Account","Account Updated!!");
                OpenAccount::clearData();
                OpenAccount::setoff();
            }
        }
    }
}

void OpenAccount::on_ao_acc_no_returnPressed()
{

//    if(obj.checkacc_no(ui->ao_acc_no->text())){
//        OpenAccount::load_data(ui->ao_acc_no->text());
//    }
//    else{
        QMessageBox::warning(this,"Account","No Account Found!!");
//    }
}


