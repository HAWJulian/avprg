/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
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
    QComboBox *comboMidiInputBox;
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
    QLabel *label_7;
    QFrame *line;
    QCustomPlot *plot;
    QSlider *rateSlider;
    QLabel *label_9;
    QSlider *posSlider;
    QLabel *label_10;
    QSlider *posSlider_3;
    QLabel *label_11;
    QSlider *posSlider_4;
    QFrame *line_2;
    QLabel *label_12;
    QComboBox *comboBox;
    QComboBox *comboBox_2;
    QFrame *line_3;
    QLabel *label_13;
    QFrame *line_4;
    QLabel *label_14;
    QSlider *gainSlider;
    QLabel *label_2;
    QLabel *label_5;
    QPushButton *openWAVButton;
    QLabel *labelAttack;
    QLabel *labelHold;
    QLabel *labelRelease;
    QLabel *GainLabel;
    QLabel *GainLabel_2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setWindowModality(Qt::NonModal);
        MainWindow->setEnabled(true);
        MainWindow->resize(740, 789);
        MainWindow->setAutoFillBackground(false);
        MainWindow->setStyleSheet(QStringLiteral(""));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        comboMidiInputBox = new QComboBox(centralWidget);
        comboMidiInputBox->setObjectName(QStringLiteral("comboMidiInputBox"));
        comboMidiInputBox->setGeometry(QRect(80, 20, 261, 22));
        filtertypeCombobox = new QComboBox(centralWidget);
        filtertypeCombobox->setObjectName(QStringLiteral("filtertypeCombobox"));
        filtertypeCombobox->setGeometry(QRect(330, 610, 69, 22));
        frequencySlider = new QSlider(centralWidget);
        frequencySlider->setObjectName(QStringLiteral("frequencySlider"));
        frequencySlider->setGeometry(QRect(280, 650, 231, 22));
        frequencySlider->setMaximum(100);
        frequencySlider->setValue(0);
        frequencySlider->setOrientation(Qt::Horizontal);
        frequencyLabel = new QLabel(centralWidget);
        frequencyLabel->setObjectName(QStringLiteral("frequencyLabel"));
        frequencyLabel->setGeometry(QRect(530, 650, 31, 16));
        qSlider = new QSlider(centralWidget);
        qSlider->setObjectName(QStringLiteral("qSlider"));
        qSlider->setGeometry(QRect(280, 700, 231, 22));
        qSlider->setMinimum(1);
        qSlider->setMaximum(25);
        qSlider->setPageStep(1);
        qSlider->setValue(1);
        qSlider->setOrientation(Qt::Horizontal);
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(530, 700, 46, 13));
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
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(20, 20, 61, 16));
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
        rateSlider->setGeometry(QRect(20, 520, 491, 51));
        rateSlider->setMinimum(20);
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
        label_10->setGeometry(QRect(180, 430, 61, 16));
        QFont font1;
        font1.setPointSize(8);
        label_10->setFont(font1);
        posSlider_3 = new QSlider(centralWidget);
        posSlider_3->setObjectName(QStringLiteral("posSlider_3"));
        posSlider_3->setGeometry(QRect(310, 430, 151, 21));
        posSlider_3->setMinimum(0);
        posSlider_3->setMaximum(10000);
        posSlider_3->setSingleStep(1);
        posSlider_3->setValue(0);
        posSlider_3->setSliderPosition(0);
        posSlider_3->setOrientation(Qt::Horizontal);
        posSlider_3->setInvertedAppearance(false);
        label_11 = new QLabel(centralWidget);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(470, 430, 61, 16));
        label_11->setFont(font1);
        posSlider_4 = new QSlider(centralWidget);
        posSlider_4->setObjectName(QStringLiteral("posSlider_4"));
        posSlider_4->setGeometry(QRect(20, 430, 151, 21));
        posSlider_4->setMinimum(0);
        posSlider_4->setMaximum(10000);
        posSlider_4->setSingleStep(1);
        posSlider_4->setValue(0);
        posSlider_4->setSliderPosition(0);
        posSlider_4->setOrientation(Qt::Horizontal);
        posSlider_4->setInvertedAppearance(false);
        line_2 = new QFrame(centralWidget);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setGeometry(QRect(0, 460, 751, 16));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        label_12 = new QLabel(centralWidget);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(10, 470, 151, 41));
        label_12->setFont(font);
        comboBox = new QComboBox(centralWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(550, 370, 171, 22));
        comboBox_2 = new QComboBox(centralWidget);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));
        comboBox_2->setGeometry(QRect(550, 530, 171, 22));
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
        gainSlider = new QSlider(centralWidget);
        gainSlider->setObjectName(QStringLiteral("gainSlider"));
        gainSlider->setGeometry(QRect(280, 750, 231, 22));
        gainSlider->setMinimum(-100);
        gainSlider->setMaximum(20);
        gainSlider->setPageStep(1);
        gainSlider->setValue(0);
        gainSlider->setOrientation(Qt::Horizontal);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(530, 750, 46, 13));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(570, 650, 21, 16));
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
        GainLabel = new QLabel(centralWidget);
        GainLabel->setObjectName(QStringLiteral("GainLabel"));
        GainLabel->setGeometry(QRect(530, 760, 31, 16));
        GainLabel_2 = new QLabel(centralWidget);
        GainLabel_2->setObjectName(QStringLiteral("GainLabel_2"));
        GainLabel_2->setGeometry(QRect(560, 760, 31, 16));
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        filtertypeCombobox->clear();
        filtertypeCombobox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Peak", 0)
         << QApplication::translate("MainWindow", "Bandpass", 0)
         << QApplication::translate("MainWindow", "Lowpass", 0)
         << QApplication::translate("MainWindow", "Highpass", 0)
         << QApplication::translate("MainWindow", "Lowshelf", 0)
         << QApplication::translate("MainWindow", "Highshelf", 0)
        );
        frequencyLabel->setText(QApplication::translate("MainWindow", "frequencyLabel", 0));
        label->setText(QApplication::translate("MainWindow", "Q", 0));
        label_3->setText(QApplication::translate("MainWindow", "Attack", 0));
        label_4->setText(QApplication::translate("MainWindow", "Hold", 0));
        label_6->setText(QApplication::translate("MainWindow", "Release", 0));
        label_7->setText(QApplication::translate("MainWindow", "Midi Input", 0));
        label_9->setText(QApplication::translate("MainWindow", "Position", 0));
        label_10->setText(QApplication::translate("MainWindow", "Randomize", 0));
        label_11->setText(QApplication::translate("MainWindow", "Reverse", 0));
        label_12->setText(QApplication::translate("MainWindow", "Rate", 0));
#ifndef QT_NO_TOOLTIP
        comboBox_2->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p><br/></p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        label_13->setText(QApplication::translate("MainWindow", "Grain: Gain-Envelope", 0));
        label_14->setText(QApplication::translate("MainWindow", "Filter:", 0));
        label_2->setText(QApplication::translate("MainWindow", "Gain", 0));
        label_5->setText(QApplication::translate("MainWindow", "Hz", 0));
        openWAVButton->setText(QApplication::translate("MainWindow", "Open WAV", 0));
        labelAttack->setText(QString());
        labelHold->setText(QString());
        labelRelease->setText(QString());
        GainLabel->setText(QApplication::translate("MainWindow", "gain", 0));
        GainLabel_2->setText(QApplication::translate("MainWindow", "dB", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
