#include "bdownloader.h"
#include "ui_bdownloader.h"
#include <QFileDialog>
#include <QDebug>


static QString s;
static QString g;

bDownloader::bDownloader(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::bDownloader)
{
    ui->setupUi(this);
    ui->dir->setReadOnly(true);
    ui->dir->setFrame(false);

}

bDownloader::~bDownloader()
{
    delete ui;

}

void bDownloader::on_dirBut_clicked()
{
    s = QFileDialog::getExistingDirectory();
    ui->dir->setText(s);
    if(!s.isEmpty() && !g.isEmpty()){
        ui->dButton->setEnabled(true);
    }else if(s.isEmpty() || g.isEmpty()){
        ui->dButton->setEnabled(false);
    }
}

void bDownloader::on_urlLine_textChanged(const QString &arg1)
{
     g=arg1;
     if(!s.isEmpty() && !g.isEmpty()){
         ui->dButton->setEnabled(true);
     }else if(s.isEmpty() || g.isEmpty()){
         ui->dButton->setEnabled(false);
     }

}

void bDownloader::on_cButton_clicked()
{
}

void bDownloader::on_dButton_clicked()
{
    manager = new QNetworkAccessManager(this);

    url = ui->urlLine->text();

    QFileInfo fileInfo(url.path());
    QString name = fileInfo.fileName();

    ui->dButton->setEnabled(false);





}

void bDownloader::startRequest(QUrl url){
    reply = manager->get(QNetworkRequest(url));

    connect(reply, SIGNAL(readyRead()), this, SLOT(httpReadyRead()));
}

void bDownloader::httpReadyRead(){

}
