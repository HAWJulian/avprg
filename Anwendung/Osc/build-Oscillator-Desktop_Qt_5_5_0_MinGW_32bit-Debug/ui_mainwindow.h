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
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>
#include "qcustomplot/qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QComboBox *comboMidiInputBox;
    QComboBox *waveformCombobox;
    QSlider *frequencySlider;
    QLabel *frequencyLabel;
    QSlider *gainSlider;
    QLabel *label;
    QDial *dialAttack;
    QDial *dialDecay;
    QDial *dialSustain;
    QDial *dialRelease;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *labelAttack;
    QLabel *labelDecay;
    QLabel *labelSustain;
    QLabel *labelRelease;
    QLabel *label_7;
    QFrame *line;
    QCustomPlot *plot;
    QSlider *rateSlider;
    QLabel *label_8;
    QLabel *label_9;
    QSlider *posSlider;

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
        comboMidiInputBox = new QComboBox(centralWidget);
        comboMidiInputBox->setObjectName(QStringLiteral("comboMidiInputBox"));
        comboMidiInputBox->setGeometry(QRect(80, 20, 261, 22));
        waveformCombobox = new QComboBox(centralWidget);
        waveformCombobox->setObjectName(QStringLiteral("waveformCombobox"));
        waveformCombobox->setGeometry(QRect(350, 630, 69, 22));
        frequencySlider = new QSlider(centralWidget);
        frequencySlider->setObjectName(QStringLiteral("frequencySlider"));
        frequencySlider->setGeometry(QRect(430, 630, 211, 22));
        frequencySlider->setValue(50);
        frequencySlider->setOrientation(Qt::Horizontal);
        frequencyLabel = new QLabel(centralWidget);
        frequencyLabel->setObjectName(QStringLiteral("frequencyLabel"));
        frequencyLabel->setGeometry(QRect(660, 630, 47, 13));
        gainSlider = new QSlider(centralWidget);
        gainSlider->setObjectName(QStringLiteral("gainSlider"));
        gainSlider->setGeometry(QRect(430, 690, 211, 22));
        gainSlider->setMinimum(-100);
        gainSlider->setMaximum(0);
        gainSlider->setValue(0);
        gainSlider->setOrientation(Qt::Horizontal);
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(350, 690, 46, 13));
        dialAttack = new QDial(centralWidget);
        dialAttack->setObjectName(QStringLiteral("dialAttack"));
        dialAttack->setGeometry(QRect(20, 640, 50, 64));
        dialAttack->setValue(20);
        dialDecay = new QDial(centralWidget);
        dialDecay->setObjectName(QStringLiteral("dialDecay"));
        dialDecay->setGeometry(QRect(100, 640, 50, 64));
        dialDecay->setValue(35);
        dialSustain = new QDial(centralWidget);
        dialSustain->setObjectName(QStringLiteral("dialSustain"));
        dialSustain->setGeometry(QRect(180, 640, 50, 64));
        dialSustain->setValue(90);
        dialRelease = new QDial(centralWidget);
        dialRelease->setObjectName(QStringLiteral("dialRelease"));
        dialRelease->setGeometry(QRect(250, 640, 50, 64));
        dialRelease->setValue(50);
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(30, 630, 46, 13));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(110, 630, 46, 13));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(190, 630, 46, 13));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(260, 630, 46, 13));
        labelAttack = new QLabel(centralWidget);
        labelAttack->setObjectName(QStringLiteral("labelAttack"));
        labelAttack->setGeometry(QRect(20, 710, 46, 13));
        labelAttack->setFrameShape(QFrame::Box);
        labelDecay = new QLabel(centralWidget);
        labelDecay->setObjectName(QStringLiteral("labelDecay"));
        labelDecay->setGeometry(QRect(100, 710, 46, 13));
        labelDecay->setFrameShape(QFrame::Box);
        labelSustain = new QLabel(centralWidget);
        labelSustain->setObjectName(QStringLiteral("labelSustain"));
        labelSustain->setGeometry(QRect(180, 710, 46, 13));
        labelSustain->setFrameShape(QFrame::Box);
        labelRelease = new QLabel(centralWidget);
        labelRelease->setObjectName(QStringLiteral("labelRelease"));
        labelRelease->setGeometry(QRect(250, 710, 46, 13));
        labelRelease->setFrameShape(QFrame::Box);
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
        plot->setGeometry(QRect(0, 60, 741, 241));
        plot->setCursor(QCursor(Qt::IBeamCursor));
        rateSlider = new QSlider(centralWidget);
        rateSlider->setObjectName(QStringLiteral("rateSlider"));
        rateSlider->setGeometry(QRect(20, 440, 491, 51));
        rateSlider->setMinimum(20);
        rateSlider->setMaximum(1000);
        rateSlider->setValue(1000);
        rateSlider->setOrientation(Qt::Horizontal);
        rateSlider->setInvertedAppearance(true);
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(20, 420, 47, 13));
        QFont font;
        font.setPointSize(10);
        label_8->setFont(font);
        label_9 = new QLabel(centralWidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(20, 330, 61, 16));
        label_9->setFont(font);
        posSlider = new QSlider(centralWidget);
        posSlider->setObjectName(QStringLiteral("posSlider"));
        posSlider->setGeometry(QRect(20, 350, 491, 51));
        posSlider->setMinimum(0);
        posSlider->setMaximum(10000);
        posSlider->setSingleStep(1);
        posSlider->setValue(0);
        posSlider->setSliderPosition(0);
        posSlider->setOrientation(Qt::Horizontal);
        posSlider->setInvertedAppearance(false);
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);
        QObject::connect(dialAttack, SIGNAL(valueChanged(int)), labelAttack, SLOT(setNum(int)));
        QObject::connect(dialDecay, SIGNAL(valueChanged(int)), labelDecay, SLOT(setNum(int)));
        QObject::connect(dialSustain, SIGNAL(valueChanged(int)), labelSustain, SLOT(setNum(int)));
        QObject::connect(dialRelease, SIGNAL(valueChanged(int)), labelRelease, SLOT(setNum(int)));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        waveformCombobox->clear();
        waveformCombobox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Sinus", 0)
         << QApplication::translate("MainWindow", "Dreieck", 0)
         << QApplication::translate("MainWindow", "Rechteck", 0)
         << QApplication::translate("MainWindow", "S\303\244gezahn", 0)
         << QApplication::translate("MainWindow", "Rauschen", 0)
        );
        frequencyLabel->setText(QApplication::translate("MainWindow", "frequencyLabel", 0));
        label->setText(QApplication::translate("MainWindow", "Gain:", 0));
        label_3->setText(QApplication::translate("MainWindow", "Attack", 0));
        label_4->setText(QApplication::translate("MainWindow", "Decay", 0));
        label_5->setText(QApplication::translate("MainWindow", "Sustain", 0));
        label_6->setText(QApplication::translate("MainWindow", "Release", 0));
        labelAttack->setText(QString());
        labelDecay->setText(QString());
        labelSustain->setText(QString());
        labelRelease->setText(QString());
        label_7->setText(QApplication::translate("MainWindow", "Midi Input", 0));
        label_8->setText(QApplication::translate("MainWindow", "Rate", 0));
        label_9->setText(QApplication::translate("MainWindow", "x-Position", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
