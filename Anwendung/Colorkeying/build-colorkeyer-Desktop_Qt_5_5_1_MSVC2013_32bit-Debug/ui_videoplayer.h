/********************************************************************************
** Form generated from reading UI file 'videoplayer.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIDEOPLAYER_H
#define UI_VIDEOPLAYER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
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

    void setupUi(QMainWindow *VideoPlayer)
    {
        if (VideoPlayer->objectName().isEmpty())
            VideoPlayer->setObjectName(QStringLiteral("VideoPlayer"));
        VideoPlayer->resize(864, 618);
        centralWidget = new QWidget(VideoPlayer);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        inputFrame = new VideoWidget(centralWidget);
        inputFrame->setObjectName(QStringLiteral("inputFrame"));
        inputFrame->setGeometry(QRect(40, 30, 331, 221));
        inputFrame->setFrameShape(QFrame::Box);
        inputFrame->setScaledContents(false);
        inputFrame->setAlignment(Qt::AlignCenter);
        openVideoFileButton = new QPushButton(centralWidget);
        openVideoFileButton->setObjectName(QStringLiteral("openVideoFileButton"));
        openVideoFileButton->setGeometry(QRect(40, 270, 101, 23));
        playButton = new QPushButton(centralWidget);
        playButton->setObjectName(QStringLiteral("playButton"));
        playButton->setGeometry(QRect(280, 270, 75, 23));
        processedFrame = new VideoWidget(centralWidget);
        processedFrame->setObjectName(QStringLiteral("processedFrame"));
        processedFrame->setGeometry(QRect(480, 30, 341, 221));
        processedFrame->setFrameShape(QFrame::Box);
        processedFrame->setAlignment(Qt::AlignCenter);
        HueMin = new QSlider(centralWidget);
        HueMin->setObjectName(QStringLiteral("HueMin"));
        HueMin->setGeometry(QRect(210, 460, 160, 19));
        HueMin->setMaximum(179);
        HueMin->setValue(40);
        HueMin->setOrientation(Qt::Horizontal);
        SatMin = new QSlider(centralWidget);
        SatMin->setObjectName(QStringLiteral("SatMin"));
        SatMin->setGeometry(QRect(210, 500, 160, 19));
        SatMin->setMaximum(255);
        SatMin->setValue(100);
        SatMin->setOrientation(Qt::Horizontal);
        ValueMin = new QSlider(centralWidget);
        ValueMin->setObjectName(QStringLiteral("ValueMin"));
        ValueMin->setGeometry(QRect(210, 540, 160, 19));
        ValueMin->setMaximum(255);
        ValueMin->setValue(50);
        ValueMin->setOrientation(Qt::Horizontal);
        HueMax = new QSlider(centralWidget);
        HueMax->setObjectName(QStringLiteral("HueMax"));
        HueMax->setGeometry(QRect(470, 460, 160, 19));
        HueMax->setMaximum(179);
        HueMax->setValue(80);
        HueMax->setOrientation(Qt::Horizontal);
        SatMax = new QSlider(centralWidget);
        SatMax->setObjectName(QStringLiteral("SatMax"));
        SatMax->setGeometry(QRect(470, 500, 160, 19));
        SatMax->setMaximum(255);
        SatMax->setValue(255);
        SatMax->setOrientation(Qt::Horizontal);
        ValueMax = new QSlider(centralWidget);
        ValueMax->setObjectName(QStringLiteral("ValueMax"));
        ValueMax->setGeometry(QRect(470, 540, 160, 19));
        ValueMax->setMaximum(255);
        ValueMax->setValue(255);
        ValueMax->setOrientation(Qt::Horizontal);
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(260, 430, 47, 13));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(520, 430, 47, 13));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(150, 460, 47, 13));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(150, 500, 61, 16));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(150, 540, 61, 16));
        hueminlabel = new QLabel(centralWidget);
        hueminlabel->setObjectName(QStringLiteral("hueminlabel"));
        hueminlabel->setGeometry(QRect(380, 460, 47, 13));
        saturationminlabel = new QLabel(centralWidget);
        saturationminlabel->setObjectName(QStringLiteral("saturationminlabel"));
        saturationminlabel->setGeometry(QRect(380, 500, 47, 13));
        valueminlabel = new QLabel(centralWidget);
        valueminlabel->setObjectName(QStringLiteral("valueminlabel"));
        valueminlabel->setGeometry(QRect(380, 540, 47, 13));
        huemaxlabel = new QLabel(centralWidget);
        huemaxlabel->setObjectName(QStringLiteral("huemaxlabel"));
        huemaxlabel->setGeometry(QRect(650, 460, 47, 13));
        valuemaxlabel = new QLabel(centralWidget);
        valuemaxlabel->setObjectName(QStringLiteral("valuemaxlabel"));
        valuemaxlabel->setGeometry(QRect(650, 540, 47, 13));
        saturationmaxlabel = new QLabel(centralWidget);
        saturationmaxlabel->setObjectName(QStringLiteral("saturationmaxlabel"));
        saturationmaxlabel->setGeometry(QRect(650, 500, 47, 13));
        VideoPlayer->setCentralWidget(centralWidget);

        retranslateUi(VideoPlayer);

        QMetaObject::connectSlotsByName(VideoPlayer);
    } // setupUi

    void retranslateUi(QMainWindow *VideoPlayer)
    {
        VideoPlayer->setWindowTitle(QApplication::translate("VideoPlayer", "VideoPlayer", 0));
        inputFrame->setText(QString());
        openVideoFileButton->setText(QApplication::translate("VideoPlayer", "Open Video File...", 0));
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
    } // retranslateUi

};

namespace Ui {
    class VideoPlayer: public Ui_VideoPlayer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIDEOPLAYER_H
