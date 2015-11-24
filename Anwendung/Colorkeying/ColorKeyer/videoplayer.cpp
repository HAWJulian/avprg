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
    connect(videoThread, SIGNAL(sendContoursImage(const QImage&)), ui->contoursFrame, SLOT(setImage(const QImage&)));
    callSliderchange();
    setAllLabels();
    colorKeyer->setAmountOfObejects(ui->objectsslider->value());
    colorKeyer->setSizeOfObject(ui->pixelslider->value());
    colorKeyer->setVariance(ui->varianceslider->value());
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
//alle werte als min & max werte setzen zur threshold berechnung
void VideoPlayer::callSliderchange()
{
    colorKeyer->setThreshold(ui->HueMin->value(), ui->SatMin->value(), ui->ValueMin->value(), ui->HueMax->value(), ui->SatMax->value(), ui->ValueMax->value());
    //qDebug() << ui->HueMin->value() << ui->SatMin->value() << ui->ValueMin->value() << ui->HueMax->value() << ui->SatMax->value() << ui->ValueMax->value();
}
//alle labels setzen auf skalierten wert + einheit
void VideoPlayer::setAllLabels()
{
    ui->hueminlabel->setText(QString::number((int)ui->HueMin->value()*2) + "°");
    ui->saturationminlabel->setText(QString::number((int)round(ui->SatMin->value()/2.55)) + "%");
    ui->valueminlabel->setText(QString::number((int)round(ui->ValueMin->value()/2.55)) + "%");
    ui->huemaxlabel->setText(QString::number((int)ui->HueMax->value()*2) + "°");
    ui->saturationmaxlabel->setText(QString::number((int)round(ui->SatMax->value()/2.55)) + "%");
    ui->valuemaxlabel->setText(QString::number((int)round(ui->ValueMax->value()/2.55))+ "%");
    ui->objectslabel->setText(QString::number((int)ui->objectsslider->value()));
    ui->pixellabel->setText(QString::number((int)ui->pixelslider->value()));
    ui->variancelabel->setText(QString::number((int)ui->varianceslider->value()));
}

void VideoPlayer::on_HueMin_valueChanged(int value)
{
    callSliderchange();
    ui->hueminlabel->setText(QString::number(value*2)+"°");
}

void VideoPlayer::on_HueMax_valueChanged(int value)
{
    callSliderchange();
    ui->huemaxlabel->setText(QString::number(value*2)+"°");
}

void VideoPlayer::on_SatMin_valueChanged(int value)
{
    callSliderchange();
    ui->saturationminlabel->setText(QString::number((int)round(value/2.55)) + "%");
}

void VideoPlayer::on_SatMax_valueChanged(int value)
{
    callSliderchange();
    ui->saturationmaxlabel->setText(QString::number((int)round(value/2.55))+ "%");
}

void VideoPlayer::on_ValueMin_valueChanged(int value)
{
    callSliderchange();
    ui->valueminlabel->setText(QString::number((int)round(value/2.55))+ "%");
}

void VideoPlayer::on_ValueMax_valueChanged(int value)
{
    callSliderchange();
    ui->valuemaxlabel->setText(QString::number((int)round(value/2.55))+"%");
}

void VideoPlayer::on_pixelslider_valueChanged(int value)
{
    colorKeyer->setSizeOfObject(value);
    ui->pixellabel->setText(QString::number(value));
}

void VideoPlayer::on_objectsslider_valueChanged(int value)
{
    colorKeyer->setAmountOfObejects(value);
    ui->objectslabel->setText(QString::number(value));
}

void VideoPlayer::on_varianceslider_valueChanged(int value)
{
    colorKeyer->setVariance(value);
    ui->variancelabel->setText(QString::number(value));
}

void VideoPlayer::on_yaxisbutton_clicked()
{
    colorKeyer->setYValues();
}

void VideoPlayer::on_centerscb_clicked()
{
    colorKeyer->setPaintCenters();
}

void VideoPlayer::on_exactcenterscb_clicked()
{
    colorKeyer->setPaintExactCenters();
}

void VideoPlayer::on_linescb_clicked()
{
    colorKeyer->setPaintLines();
}
