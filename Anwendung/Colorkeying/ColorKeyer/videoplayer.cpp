#include <QFileDialog>
#include "videoplayer.h"
#include "ui_videoplayer.h"

VideoPlayer::VideoPlayer(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::VideoPlayer)
    , videoThread(new VideoEngine)
    , colorKeyer(new ColorKeyer())
{
    ui->setupUi(this);
    videoThread->setProcessor(colorKeyer);
    connect(videoThread, SIGNAL(sendInputImage(const QImage&)), ui->inputFrame, SLOT(setImage(const QImage&)));
    connect(videoThread, SIGNAL(sendProcessedImage(const QImage&)), ui->processedFrame , SLOT(setImage(const QImage&)));
    callSliderchange();
}

VideoPlayer::~VideoPlayer()
{
    delete videoThread;
    delete colorKeyer;
    delete ui;
}


void VideoPlayer::on_playButton_clicked()
{
    videoThread->start();
}


void VideoPlayer::on_openVideoFileButton_clicked()
{
    // Kamera
    videoThread->openCamera();
    videoThread->start();
    return;

    QString fileName = QFileDialog::getOpenFileName(this, tr("Open Movie"),QDir::homePath());

    if (!fileName.isEmpty()) {
        videoThread->openFile(fileName);
     }

}
void VideoPlayer::callSliderchange()
{
    colorKeyer->setThreshold(ui->HueMin->value(), ui->SatMin->value(), ui->ValueMin->value(), ui->HueMax->value(), ui->SatMax->value(), ui->ValueMax->value());
    //qDebug() << ui->HueMin->value() << ui->SatMin->value() << ui->ValueMin->value() << ui->HueMax->value() << ui->SatMax->value() << ui->ValueMax->value();
}

void VideoPlayer::on_HueMin_valueChanged(int value)
{
    callSliderchange();
}

void VideoPlayer::on_HueMax_valueChanged(int value)
{
    callSliderchange();
}

void VideoPlayer::on_SatMin_valueChanged(int value)
{
    callSliderchange();
}

void VideoPlayer::on_SatMax_valueChanged(int value)
{
    callSliderchange();
}

void VideoPlayer::on_ValueMin_valueChanged(int value)
{
    callSliderchange();
}

void VideoPlayer::on_ValueMax_valueChanged(int value)
{
    callSliderchange();
}
