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
#include <QtWidgets/QScrollBar>
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
    QPushButton *note_8;
    QPushButton *note_12;
    QPushButton *note_10;
    QPushButton *note_7;
    QPushButton *note_11;
    QPushButton *note_4;
    QPushButton *note_6;
    QPushButton *note_1;
    QPushButton *note_3;
    QPushButton *note_5;
    QPushButton *note_9;
    QLabel *label_2;
    QPushButton *note_2;
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
    QScrollBar *horizontalScrollBar;
    QSlider *rateSlider;
    QLabel *label_8;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(748, 772);
        MainWindow->setAutoFillBackground(false);
        MainWindow->setStyleSheet(QStringLiteral(""));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        comboMidiInputBox = new QComboBox(centralWidget);
        comboMidiInputBox->setObjectName(QStringLiteral("comboMidiInputBox"));
        comboMidiInputBox->setGeometry(QRect(80, 20, 261, 22));
        waveformCombobox = new QComboBox(centralWidget);
        waveformCombobox->setObjectName(QStringLiteral("waveformCombobox"));
        waveformCombobox->setGeometry(QRect(30, 430, 69, 22));
        frequencySlider = new QSlider(centralWidget);
        frequencySlider->setObjectName(QStringLiteral("frequencySlider"));
        frequencySlider->setGeometry(QRect(110, 430, 211, 22));
        frequencySlider->setValue(50);
        frequencySlider->setOrientation(Qt::Horizontal);
        frequencyLabel = new QLabel(centralWidget);
        frequencyLabel->setObjectName(QStringLiteral("frequencyLabel"));
        frequencyLabel->setGeometry(QRect(340, 430, 47, 13));
        gainSlider = new QSlider(centralWidget);
        gainSlider->setObjectName(QStringLiteral("gainSlider"));
        gainSlider->setGeometry(QRect(110, 490, 211, 22));
        gainSlider->setMinimum(-100);
        gainSlider->setMaximum(0);
        gainSlider->setValue(0);
        gainSlider->setOrientation(Qt::Horizontal);
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 490, 46, 13));
        note_8 = new QPushButton(centralWidget);
        note_8->setObjectName(QStringLiteral("note_8"));
        note_8->setGeometry(QRect(260, 560, 16, 23));
        note_8->setCheckable(true);
        note_12 = new QPushButton(centralWidget);
        note_12->setObjectName(QStringLiteral("note_12"));
        note_12->setGeometry(QRect(340, 560, 16, 23));
        note_12->setCheckable(true);
        note_10 = new QPushButton(centralWidget);
        note_10->setObjectName(QStringLiteral("note_10"));
        note_10->setGeometry(QRect(300, 560, 16, 23));
        note_10->setCheckable(true);
        note_7 = new QPushButton(centralWidget);
        note_7->setObjectName(QStringLiteral("note_7"));
        note_7->setGeometry(QRect(240, 560, 16, 23));
        note_7->setCheckable(true);
        note_11 = new QPushButton(centralWidget);
        note_11->setObjectName(QStringLiteral("note_11"));
        note_11->setGeometry(QRect(320, 560, 16, 23));
        note_11->setCheckable(true);
        note_4 = new QPushButton(centralWidget);
        note_4->setObjectName(QStringLiteral("note_4"));
        note_4->setGeometry(QRect(180, 560, 16, 23));
        note_4->setCheckable(true);
        note_6 = new QPushButton(centralWidget);
        note_6->setObjectName(QStringLiteral("note_6"));
        note_6->setGeometry(QRect(220, 560, 16, 23));
        note_6->setCheckable(true);
        note_1 = new QPushButton(centralWidget);
        note_1->setObjectName(QStringLiteral("note_1"));
        note_1->setGeometry(QRect(120, 560, 16, 23));
        note_1->setCheckable(true);
        note_3 = new QPushButton(centralWidget);
        note_3->setObjectName(QStringLiteral("note_3"));
        note_3->setGeometry(QRect(160, 560, 16, 23));
        note_3->setCheckable(true);
        note_5 = new QPushButton(centralWidget);
        note_5->setObjectName(QStringLiteral("note_5"));
        note_5->setGeometry(QRect(200, 560, 16, 23));
        note_5->setCheckable(true);
        note_9 = new QPushButton(centralWidget);
        note_9->setObjectName(QStringLiteral("note_9"));
        note_9->setGeometry(QRect(280, 560, 16, 23));
        note_9->setCheckable(true);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(30, 560, 46, 13));
        note_2 = new QPushButton(centralWidget);
        note_2->setObjectName(QStringLiteral("note_2"));
        note_2->setGeometry(QRect(140, 560, 16, 23));
        note_2->setCheckable(true);
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
        plot->setCursor(QCursor(Qt::CrossCursor));
        horizontalScrollBar = new QScrollBar(centralWidget);
        horizontalScrollBar->setObjectName(QStringLiteral("horizontalScrollBar"));
        horizontalScrollBar->setGeometry(QRect(0, 300, 741, 17));
        horizontalScrollBar->setOrientation(Qt::Horizontal);
        rateSlider = new QSlider(centralWidget);
        rateSlider->setObjectName(QStringLiteral("rateSlider"));
        rateSlider->setGeometry(QRect(20, 330, 131, 51));
        rateSlider->setMinimum(20);
        rateSlider->setMaximum(1000);
        rateSlider->setValue(1000);
        rateSlider->setOrientation(Qt::Horizontal);
        rateSlider->setInvertedAppearance(true);
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(170, 350, 47, 13));
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
        note_8->setText(QString());
        note_12->setText(QString());
        note_10->setText(QString());
        note_7->setText(QString());
        note_11->setText(QString());
        note_4->setText(QString());
        note_6->setText(QString());
        note_1->setText(QString());
        note_3->setText(QString());
        note_5->setText(QString());
        note_9->setText(QString());
        label_2->setText(QApplication::translate("MainWindow", "Notes", 0));
        note_2->setText(QString());
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
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
