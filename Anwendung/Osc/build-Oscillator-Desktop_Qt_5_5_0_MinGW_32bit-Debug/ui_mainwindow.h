/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDial>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>
#include "qcustomplot/qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QComboBox *filtertypeCombobox;
    QSlider *frequencySlider;
    QLabel *frequencyLabel;
    QSlider *qSlider;
    QLabel *label;
    QDial *dialAttack;
    QDial *dialHold;
    QDial *dialRelease;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_6;
    QFrame *line;
    QCustomPlot *plot;
    QSlider *rateSlider;
    QLabel *label_9;
    QSlider *posSlider;
    QLabel *label_10;
    QSlider *spreadSlider;
    QLabel *label_11;
    QSlider *posRandSlider;
    QFrame *line_2;
    QLabel *label_12;
    QFrame *line_3;
    QLabel *label_13;
    QFrame *line_4;
    QLabel *label_14;
    QLabel *label_5;
    QPushButton *openWAVButton;
    QLabel *labelAttack;
    QLabel *labelHold;
    QLabel *labelRelease;
    QLabel *label_15;
    QSlider *volumeSlider;
    QSlider *volRandSlider;
    QLabel *label_16;
    QLabel *label_2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setWindowModality(Qt::NonModal);
        MainWindow->setEnabled(true);
        MainWindow->resize(740, 772);
        MainWindow->setAutoFillBackground(false);
        MainWindow->setStyleSheet(QStringLiteral(""));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        filtertypeCombobox = new QComboBox(centralWidget);
        filtertypeCombobox->setObjectName(QStringLiteral("filtertypeCombobox"));
        filtertypeCombobox->setGeometry(QRect(330, 610, 69, 22));
        frequencySlider = new QSlider(centralWidget);
        frequencySlider->setObjectName(QStringLiteral("frequencySlider"));
        frequencySlider->setGeometry(QRect(280, 650, 361, 22));
        frequencySlider->setMaximum(100);
        frequencySlider->setValue(100);
        frequencySlider->setOrientation(Qt::Horizontal);
        frequencyLabel = new QLabel(centralWidget);
        frequencyLabel->setObjectName(QStringLiteral("frequencyLabel"));
        frequencyLabel->setGeometry(QRect(660, 650, 31, 16));
        qSlider = new QSlider(centralWidget);
        qSlider->setObjectName(QStringLiteral("qSlider"));
        qSlider->setGeometry(QRect(280, 700, 361, 22));
        qSlider->setMinimum(1);
        qSlider->setMaximum(25);
        qSlider->setPageStep(1);
        qSlider->setValue(1);
        qSlider->setOrientation(Qt::Horizontal);
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(660, 700, 46, 13));
        dialAttack = new QDial(centralWidget);
        dialAttack->setObjectName(QStringLiteral("dialAttack"));
        dialAttack->setGeometry(QRect(30, 670, 50, 64));
        dialAttack->setMaximum(100);
        dialAttack->setValue(20);
        dialHold = new QDial(centralWidget);
        dialHold->setObjectName(QStringLiteral("dialHold"));
        dialHold->setGeometry(QRect(100, 670, 50, 64));
        dialHold->setMaximum(100);
        dialHold->setValue(35);
        dialRelease = new QDial(centralWidget);
        dialRelease->setObjectName(QStringLiteral("dialRelease"));
        dialRelease->setGeometry(QRect(170, 670, 50, 64));
        dialRelease->setMaximum(100);
        dialRelease->setValue(50);
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(30, 660, 46, 13));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(100, 660, 46, 13));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(170, 660, 46, 13));
        line = new QFrame(centralWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(0, 50, 751, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        plot = new QCustomPlot(centralWidget);
        plot->setObjectName(QStringLiteral("plot"));
        plot->setEnabled(true);
        plot->setGeometry(QRect(0, 60, 741, 251));
        plot->setCursor(QCursor(Qt::IBeamCursor));
        rateSlider = new QSlider(centralWidget);
        rateSlider->setObjectName(QStringLiteral("rateSlider"));
        rateSlider->setGeometry(QRect(20, 520, 671, 51));
        rateSlider->setMinimum(10);
        rateSlider->setMaximum(1000);
        rateSlider->setValue(1000);
        rateSlider->setOrientation(Qt::Horizontal);
        rateSlider->setInvertedAppearance(true);
        label_9 = new QLabel(centralWidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(10, 310, 151, 41));
        QFont font;
        font.setPointSize(12);
        font.setBold(false);
        font.setWeight(50);
        label_9->setFont(font);
        posSlider = new QSlider(centralWidget);
        posSlider->setObjectName(QStringLiteral("posSlider"));
        posSlider->setGeometry(QRect(20, 360, 491, 51));
        posSlider->setMinimum(0);
        posSlider->setMaximum(10000);
        posSlider->setSingleStep(1);
        posSlider->setValue(0);
        posSlider->setSliderPosition(0);
        posSlider->setOrientation(Qt::Horizontal);
        posSlider->setInvertedAppearance(false);
        label_10 = new QLabel(centralWidget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(540, 340, 131, 16));
        QFont font1;
        font1.setPointSize(8);
        label_10->setFont(font1);
        spreadSlider = new QSlider(centralWidget);
        spreadSlider->setObjectName(QStringLiteral("spreadSlider"));
        spreadSlider->setGeometry(QRect(20, 430, 181, 21));
        spreadSlider->setMinimum(0);
        spreadSlider->setMaximum(100);
        spreadSlider->setSingleStep(1);
        spreadSlider->setValue(0);
        spreadSlider->setSliderPosition(0);
        spreadSlider->setOrientation(Qt::Horizontal);
        spreadSlider->setInvertedAppearance(false);
        label_11 = new QLabel(centralWidget);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(210, 430, 61, 16));
        label_11->setFont(font1);
        posRandSlider = new QSlider(centralWidget);
        posRandSlider->setObjectName(QStringLiteral("posRandSlider"));
        posRandSlider->setGeometry(QRect(540, 370, 181, 21));
        posRandSlider->setMinimum(0);
        posRandSlider->setMaximum(100);
        posRandSlider->setSingleStep(1);
        posRandSlider->setValue(0);
        posRandSlider->setSliderPosition(0);
        posRandSlider->setOrientation(Qt::Horizontal);
        posRandSlider->setInvertedAppearance(false);
        line_2 = new QFrame(centralWidget);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setGeometry(QRect(0, 460, 751, 16));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        label_12 = new QLabel(centralWidget);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(10, 470, 151, 41));
        label_12->setFont(font);
        line_3 = new QFrame(centralWidget);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setGeometry(QRect(0, 590, 751, 16));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);
        label_13 = new QLabel(centralWidget);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(10, 600, 151, 41));
        label_13->setFont(font);
        line_4 = new QFrame(centralWidget);
        line_4->setObjectName(QStringLiteral("line_4"));
        line_4->setGeometry(QRect(260, 600, 16, 191));
        line_4->setFrameShape(QFrame::VLine);
        line_4->setFrameShadow(QFrame::Sunken);
        label_14 = new QLabel(centralWidget);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(280, 600, 41, 41));
        label_14->setFont(font);
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(700, 650, 21, 16));
        openWAVButton = new QPushButton(centralWidget);
        openWAVButton->setObjectName(QStringLiteral("openWAVButton"));
        openWAVButton->setGeometry(QRect(600, 20, 121, 23));
        labelAttack = new QLabel(centralWidget);
        labelAttack->setObjectName(QStringLiteral("labelAttack"));
        labelAttack->setGeometry(QRect(30, 730, 46, 13));
        labelAttack->setFrameShape(QFrame::Box);
        labelHold = new QLabel(centralWidget);
        labelHold->setObjectName(QStringLiteral("labelHold"));
        labelHold->setGeometry(QRect(100, 730, 46, 13));
        labelHold->setFrameShape(QFrame::Box);
        labelRelease = new QLabel(centralWidget);
        labelRelease->setObjectName(QStringLiteral("labelRelease"));
        labelRelease->setGeometry(QRect(170, 730, 46, 13));
        labelRelease->setFrameShape(QFrame::Box);
        label_15 = new QLabel(centralWidget);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(480, 430, 41, 16));
        label_15->setFont(font1);
        volumeSlider = new QSlider(centralWidget);
        volumeSlider->setObjectName(QStringLiteral("volumeSlider"));
        volumeSlider->setGeometry(QRect(300, 430, 171, 21));
        volumeSlider->setMinimum(0);
        volumeSlider->setMaximum(100);
        volumeSlider->setSingleStep(1);
        volumeSlider->setValue(100);
        volumeSlider->setSliderPosition(100);
        volumeSlider->setOrientation(Qt::Horizontal);
        volumeSlider->setInvertedAppearance(false);
        volRandSlider = new QSlider(centralWidget);
        volRandSlider->setObjectName(QStringLiteral("volRandSlider"));
        volRandSlider->setGeometry(QRect(540, 430, 181, 21));
        volRandSlider->setMinimum(0);
        volRandSlider->setMaximum(10000);
        volRandSlider->setSingleStep(1);
        volRandSlider->setValue(0);
        volRandSlider->setSliderPosition(0);
        volRandSlider->setOrientation(Qt::Horizontal);
        volRandSlider->setInvertedAppearance(false);
        label_16 = new QLabel(centralWidget);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(540, 410, 121, 16));
        label_16->setFont(font1);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 10, 441, 31));
        QFont font2;
        font2.setPointSize(22);
        label_2->setFont(font2);
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        filtertypeCombobox->clear();
        filtertypeCombobox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Bandpass", 0)
         << QApplication::translate("MainWindow", "Lowpass", 0)
         << QApplication::translate("MainWindow", "Highpass", 0)
        );
        filtertypeCombobox->setCurrentText(QApplication::translate("MainWindow", "Lowpass", 0));
        frequencyLabel->setText(QApplication::translate("MainWindow", "frequencyLabel", 0));
        label->setText(QApplication::translate("MainWindow", "Q", 0));
        label_3->setText(QApplication::translate("MainWindow", "Attack", 0));
        label_4->setText(QApplication::translate("MainWindow", "Hold", 0));
        label_6->setText(QApplication::translate("MainWindow", "Release", 0));
        label_9->setText(QApplication::translate("MainWindow", "Position", 0));
        label_10->setText(QApplication::translate("MainWindow", "Position Randomize", 0));
        label_11->setText(QApplication::translate("MainWindow", "Spread", 0));
        label_12->setText(QApplication::translate("MainWindow", "Rate", 0));
        label_13->setText(QApplication::translate("MainWindow", "Gain-Envelope", 0));
        label_14->setText(QApplication::translate("MainWindow", "Filter:", 0));
        label_5->setText(QApplication::translate("MainWindow", "Hz", 0));
        openWAVButton->setText(QApplication::translate("MainWindow", "Open WAV", 0));
        labelAttack->setText(QString());
        labelHold->setText(QString());
        labelRelease->setText(QString());
        label_15->setText(QApplication::translate("MainWindow", "Volume", 0));
        label_16->setText(QApplication::translate("MainWindow", "Volume Randomize", 0));
        label_2->setText(QApplication::translate("MainWindow", "Granular Synthesizer", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
