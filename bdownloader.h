#ifndef BDOWNLOADER_H
#define BDOWNLOADER_H

#include <QMainWindow>
#include <QObject>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <QUrl>
#include <QDateTime>
#include <QFile>
#include <QDebug>
#include <QProgressDialog>
#include <QString>

namespace Ui {
class bDownloader;
}

class bDownloader : public QMainWindow
{
    Q_OBJECT

public:
    explicit bDownloader(QWidget *parent = nullptr);
    ~bDownloader();



private slots:
    void on_dirBut_clicked();

    void on_urlLine_textChanged(const QString &arg1);

    void on_cButton_clicked();

    void on_dButton_clicked();

    void startRequest(QUrl url);

    void httpReadyRead();

private:
    Ui::bDownloader *ui;
    QNetworkAccessManager *manager;
    QUrl url;
    QNetworkReply *reply;
    QProgressDialog *progress;
    QFile *file;
    qint64 size;

};

#endif // BDOWNLOADER_H
