#ifndef COLORKEYER_H
#define COLORKEYER_H

#include "videoprocessor.h"

class ColorKeyer : public VideoProcessor
{
public:
    ColorKeyer();
    void startProcessing(const VideoFormat& format);
    cv::Mat process(const cv::Mat&source);
    void setThreshold(double hue,double sat,double val,double huem,double satm,double valm);
    void setSizeOfObject(unsigned int amountPixels);
    void setAmountOfObejects(unsigned int amountObjects);
private:
    cv::Mat maskColor(const cv::Mat&source);
    double minH;
    double minS;
    double minV;
    double maxH;
    double maxS;
    double maxV;
    unsigned int amountPixels;
    unsigned int amountObjects;
};

#endif // COLORKEYER_H