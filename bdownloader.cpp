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
    cancelDownload();
    ui->cButton->setEnabled(false);
}

void bDownloader::on_dButton_clicked()
{
    manager = new QNetworkAccessManager(this);

        QString fileName =  QUrl(ui->urlLine->text()).fileName();
       QString saveFilePath = QString(ui->dir->text() + "/" + fileName );



    file = new QFile;

    file->setFileName(saveFilePath);
    if(file->exists()){
        file->remove();
    }
    file->open(QIODevice::WriteOnly);

    ui->dButton->setEnabled(false);
    ui->cButton->setEnabled(true);
    ui->dirBut->setEnabled(false);
    ui->urlLine->setReadOnly(true);




    startRequest(ui->urlLine->text());


}

void bDownloader::startRequest(QUrl url){
    reply = manager->get(QNetworkRequest(url));

    connect(reply, SIGNAL(readyRead()), this, SLOT(httpReadyRead()));

    connect(reply, SIGNAL(downloadProgress(qint64, qint64)), this, SLOT(updateProg(qint64, qint64)));

    connect(reply, SIGNAL(finished()), this, SLOT(httpDownloadFinished()));
}

void bDownloader::httpReadyRead(){
    if (file)
           file->write(reply->readAll());
}

void bDownloader::httpDownloadFinished(){
    if(reply->error()){

    }else{
        if(file->open(QFile::Append)){
            file->write(reply->readAll());
            file->flush();
            file->close();
        }
    }
    ui->dButton->setEnabled(true);
    ui->cButton->setEnabled(false);
    ui->urlLine->setReadOnly(false);
    ui->dirBut->setEnabled(true);
    reply->deleteLater();
}

void bDownloader::updateProg(qint64 byteread, qint64 total){
    long amount = (byteread / total) * 100;
    ui->progressBar->setValue(total);
}

void bDownloader::cancelDownload(){
    reply->abort();

}
