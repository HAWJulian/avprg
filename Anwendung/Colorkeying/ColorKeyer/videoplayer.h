#ifndef VIDEOPLAYER_H
#define VIDEOPLAYER_H

#include <QMainWindow>
#include <QImage>
#include "videoengine.h"
#include "colorkeyer.h"
#include "asdf.h"
namespace Ui {
class VideoPlayer;
}

class VideoPlayer : public QMainWindow
{
    Q_OBJECT

public:
    explicit VideoPlayer(QWidget *parent = 0);
    ~VideoPlayer();
    void verbinden(asdf* x);
private slots:
    void on_playButton_clicked();

    void on_openVideoFileButton_clicked();

    void on_HueMin_valueChanged(int value);

    void on_HueMax_valueChanged(int value);

    void on_SatMin_valueChanged(int value);

    void on_SatMax_valueChanged(int value);

    void on_ValueMin_valueChanged(int value);

    void on_ValueMax_valueChanged(int value);

    void on_pixelslider_valueChanged(int value);

    void on_objectsslider_valueChanged(int value);

    void on_varianceslider_valueChanged(int value);

    void on_yaxisbutton_clicked();

    void on_centerscb_clicked();

    void on_exactcenterscb_clicked();

    void on_linescb_clicked();

private:
    Ui::VideoPlayer *ui;
    VideoEngine *videoThread;
    ColorKeyer* colorKeyer;
    void callSliderchange();
    void setAllLabels();
};

#endif // VIDEOPLAYER_H
