#ifndef BDOWNLOADER_H
#define BDOWNLOADER_H

#include <QMainWindow>
#include <QObject>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <QFile>
#include <QStringList>

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


private:
    Ui::bDownloader *ui;

};

#endif // BDOWNLOADER_H
