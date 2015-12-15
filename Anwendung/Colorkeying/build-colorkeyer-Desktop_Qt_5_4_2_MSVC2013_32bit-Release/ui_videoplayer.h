/********************************************************************************
** Form generated from reading UI file 'videoplayer.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIDEOPLAYER_H
#define UI_VIDEOPLAYER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>
#include "videowidget.h"

QT_BEGIN_NAMESPACE

class Ui_VideoPlayer
{
public:
    QWidget *centralWidget;
    VideoWidget *inputFrame;
    QPushButton *openVideoFileButton;
    QPushButton *playButton;
    VideoWidget *processedFrame;
    QSlider *HueMin;
    QSlider *SatMin;
    QSlider *ValueMin;
    QSlider *HueMax;
    QSlider *SatMax;
    QSlider *ValueMax;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *hueminlabel;
    QLabel *saturationminlabel;
    QLabel *valueminlabel;
    QLabel *huemaxlabel;
    QLabel *valuemaxlabel;
    QLabel *saturationmaxlabel;
    QSlider *pixelslider;
    QSlider *objectsslider;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *pixellabel;
    QLabel *objectslabel;
    VideoWidget *contoursFrame;
    QPushButton *yaxisbutton;
    QSlider *varianceslider;
    QLabel *label_8;
    QLabel *variancelabel;
    QCheckBox *centerscb;
    QCheckBox *exactcenterscb;
    QCheckBox *linescb;

    void setupUi(QMainWindow *VideoPlayer)
    {
        if (VideoPlayer->objectName().isEmpty())
            VideoPlayer->setObjectName(QStringLiteral("VideoPlayer"));
        VideoPlayer->resize(1354, 991);
        centralWidget = new QWidget(VideoPlayer);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        inputFrame = new VideoWidget(centralWidget);
        inputFrame->setObjectName(QStringLiteral("inputFrame"));
        inputFrame->setGeometry(QRect(20, 10, 641, 481));
        inputFrame->setFrameShape(QFrame::Box);
        inputFrame->setScaledContents(false);
        inputFrame->setAlignment(Qt::AlignCenter);
        openVideoFileButton = new QPushButton(centralWidget);
        openVideoFileButton->setObjectName(QStringLiteral("openVideoFileButton"));
        openVideoFileButton->setGeometry(QRect(240, 580, 101, 23));
        playButton = new QPushButton(centralWidget);
        playButton->setObjectName(QStringLiteral("playButton"));
        playButton->setEnabled(false);
        playButton->setGeometry(QRect(350, 580, 75, 23));
        processedFrame = new VideoWidget(centralWidget);
        processedFrame->setObjectName(QStringLiteral("processedFrame"));
        processedFrame->setGeometry(QRect(670, 10, 641, 481));
        processedFrame->setFrameShape(QFrame::Box);
        processedFrame->setAlignment(Qt::AlignCenter);
        HueMin = new QSlider(centralWidget);
        HueMin->setObjectName(QStringLiteral("HueMin"));
        HueMin->setGeometry(QRect(130, 870, 160, 19));
        HueMin->setMaximum(179);
        HueMin->setValue(30);
        HueMin->setOrientation(Qt::Horizontal);
        SatMin = new QSlider(centralWidget);
        SatMin->setObjectName(QStringLiteral("SatMin"));
        SatMin->setGeometry(QRect(130, 910, 160, 19));
        SatMin->setMaximum(255);
        SatMin->setValue(56);
        SatMin->setOrientation(Qt::Horizontal);
        ValueMin = new QSlider(centralWidget);
        ValueMin->setObjectName(QStringLiteral("ValueMin"));
        ValueMin->setGeometry(QRect(130, 950, 160, 19));
        ValueMin->setMaximum(255);
        ValueMin->setValue(112);
        ValueMin->setOrientation(Qt::Horizontal);
        HueMax = new QSlider(centralWidget);
        HueMax->setObjectName(QStringLiteral("HueMax"));
        HueMax->setGeometry(QRect(390, 870, 160, 19));
        HueMax->setMaximum(179);
        HueMax->setValue(73);
        HueMax->setOrientation(Qt::Horizontal);
        SatMax = new QSlider(centralWidget);
        SatMax->setObjectName(QStringLiteral("SatMax"));
        SatMax->setGeometry(QRect(390, 910, 160, 19));
        SatMax->setMaximum(255);
        SatMax->setValue(181);
        SatMax->setOrientation(Qt::Horizontal);
        ValueMax = new QSlider(centralWidget);
        ValueMax->setObjectName(QStringLiteral("ValueMax"));
        ValueMax->setGeometry(QRect(390, 950, 160, 19));
        ValueMax->setMaximum(255);
        ValueMax->setValue(171);
        ValueMax->setOrientation(Qt::Horizontal);
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(180, 840, 47, 13));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(440, 840, 47, 13));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(70, 870, 47, 13));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(70, 910, 61, 16));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(70, 950, 61, 16));
        hueminlabel = new QLabel(centralWidget);
        hueminlabel->setObjectName(QStringLiteral("hueminlabel"));
        hueminlabel->setGeometry(QRect(300, 870, 47, 13));
        saturationminlabel = new QLabel(centralWidget);
        saturationminlabel->setObjectName(QStringLiteral("saturationminlabel"));
        saturationminlabel->setGeometry(QRect(300, 910, 47, 13));
        valueminlabel = new QLabel(centralWidget);
        valueminlabel->setObjectName(QStringLiteral("valueminlabel"));
        valueminlabel->setGeometry(QRect(300, 950, 47, 13));
        huemaxlabel = new QLabel(centralWidget);
        huemaxlabel->setObjectName(QStringLiteral("huemaxlabel"));
        huemaxlabel->setGeometry(QRect(570, 870, 47, 13));
        valuemaxlabel = new QLabel(centralWidget);
        valuemaxlabel->setObjectName(QStringLiteral("valuemaxlabel"));
        valuemaxlabel->setGeometry(QRect(570, 950, 47, 13));
        saturationmaxlabel = new QLabel(centralWidget);
        saturationmaxlabel->setObjectName(QStringLiteral("saturationmaxlabel"));
        saturationmaxlabel->setGeometry(QRect(570, 910, 47, 13));
        pixelslider = new QSlider(centralWidget);
        pixelslider->setObjectName(QStringLiteral("pixelslider"));
        pixelslider->setGeometry(QRect(110, 730, 431, 20));
        pixelslider->setMinimum(500);
        pixelslider->setMaximum(10000);
        pixelslider->setValue(5000);
        pixelslider->setOrientation(Qt::Horizontal);
        objectsslider = new QSlider(centralWidget);
        objectsslider->setObjectName(QStringLiteral("objectsslider"));
        objectsslider->setGeometry(QRect(110, 780, 431, 20));
        objectsslider->setMinimum(1);
        objectsslider->setMaximum(10);
        objectsslider->setOrientation(Qt::Horizontal);
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(50, 730, 47, 13));
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(50, 780, 47, 13));
        pixellabel = new QLabel(centralWidget);
        pixellabel->setObjectName(QStringLiteral("pixellabel"));
        pixellabel->setGeometry(QRect(570, 730, 47, 13));
        objectslabel = new QLabel(centralWidget);
        objectslabel->setObjectName(QStringLiteral("objectslabel"));
        objectslabel->setGeometry(QRect(570, 780, 47, 13));
        contoursFrame = new VideoWidget(centralWidget);
        contoursFrame->setObjectName(QStringLiteral("contoursFrame"));
        contoursFrame->setGeometry(QRect(670, 500, 641, 481));
        contoursFrame->setFrameShape(QFrame::Box);
        contoursFrame->setScaledContents(false);
        contoursFrame->setAlignment(Qt::AlignCenter);
        yaxisbutton = new QPushButton(centralWidget);
        yaxisbutton->setObjectName(QStringLiteral("yaxisbutton"));
        yaxisbutton->setGeometry(QRect(280, 630, 101, 23));
        varianceslider = new QSlider(centralWidget);
        varianceslider->setObjectName(QStringLiteral("varianceslider"));
        varianceslider->setGeometry(QRect(190, 670, 291, 19));
        varianceslider->setMinimum(1);
        varianceslider->setMaximum(50);
        varianceslider->setOrientation(Qt::Horizontal);
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(90, 670, 91, 20));
        variancelabel = new QLabel(centralWidget);
        variancelabel->setObjectName(QStringLiteral("variancelabel"));
        variancelabel->setGeometry(QRect(490, 670, 47, 13));
        centerscb = new QCheckBox(centralWidget);
        centerscb->setObjectName(QStringLiteral("centerscb"));
        centerscb->setGeometry(QRect(520, 540, 70, 17));
        centerscb->setChecked(true);
        exactcenterscb = new QCheckBox(centralWidget);
        exactcenterscb->setObjectName(QStringLiteral("exactcenterscb"));
        exactcenterscb->setGeometry(QRect(520, 580, 91, 17));
        exactcenterscb->setChecked(true);
        linescb = new QCheckBox(centralWidget);
        linescb->setObjectName(QStringLiteral("linescb"));
        linescb->setGeometry(QRect(520, 620, 70, 17));
        linescb->setChecked(true);
        VideoPlayer->setCentralWidget(centralWidget);

        retranslateUi(VideoPlayer);

        QMetaObject::connectSlotsByName(VideoPlayer);
    } // setupUi

    void retranslateUi(QMainWindow *VideoPlayer)
    {
        VideoPlayer->setWindowTitle(QApplication::translate("VideoPlayer", "VideoPlayer", 0));
        inputFrame->setText(QString());
        openVideoFileButton->setText(QApplication::translate("VideoPlayer", "Start Camera", 0));
        playButton->setText(QApplication::translate("VideoPlayer", "Play", 0));
        processedFrame->setText(QString());
        label->setText(QApplication::translate("VideoPlayer", "Min", 0));
        label_2->setText(QApplication::translate("VideoPlayer", "Max", 0));
        label_3->setText(QApplication::translate("VideoPlayer", "Hue", 0));
        label_4->setText(QApplication::translate("VideoPlayer", "Saturation", 0));
        label_5->setText(QApplication::translate("VideoPlayer", "Value", 0));
        hueminlabel->setText(QApplication::translate("VideoPlayer", "TextLabel", 0));
        saturationminlabel->setText(QApplication::translate("VideoPlayer", "TextLabel", 0));
        valueminlabel->setText(QApplication::translate("VideoPlayer", "TextLabel", 0));
        huemaxlabel->setText(QApplication::translate("VideoPlayer", "TextLabel", 0));
        valuemaxlabel->setText(QApplication::translate("VideoPlayer", "TextLabel", 0));
        saturationmaxlabel->setText(QApplication::translate("VideoPlayer", "TextLabel", 0));
        label_6->setText(QApplication::translate("VideoPlayer", "# Pixels", 0));
        label_7->setText(QApplication::translate("VideoPlayer", "# Objects", 0));
        pixellabel->setText(QApplication::translate("VideoPlayer", "TextLabel", 0));
        objectslabel->setText(QApplication::translate("VideoPlayer", "TextLabel", 0));
        contoursFrame->setText(QString());
        yaxisbutton->setText(QApplication::translate("VideoPlayer", "Set y-Axis values", 0));
        label_8->setText(QApplication::translate("VideoPlayer", "variance in # px", 0));
        variancelabel->setText(QApplication::translate("VideoPlayer", "TextLabel", 0));
        centerscb->setText(QApplication::translate("VideoPlayer", "Centers", 0));
        exactcenterscb->setText(QApplication::translate("VideoPlayer", "Exact Centers", 0));
        linescb->setText(QApplication::translate("VideoPlayer", "Lines", 0));
    } // retranslateUi

};

namespace Ui {
    class VideoPlayer: public Ui_VideoPlayer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIDEOPLAYER_H
