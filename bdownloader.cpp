#include "bdownloader.h"
#include "ui_bdownloader.h"
#include <QFileDialog>

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
    QUrl url = QUrl::fromUserInput(ui->urlLine->text());
    QFileInfo info(url.path());
    QString name = info.fileName();


}
