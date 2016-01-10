#ifndef COLORKEYER_H
#define COLORKEYER_H

#include "videoprocessor.h"
#include "cvmattoqimage.h"
#include "asdf.h"
class ColorKeyer : public VideoProcessor
{
public:
    ColorKeyer();
    void startProcessing(const VideoFormat& format);
    cv::Mat process(const cv::Mat&source);
    void setThreshold(double hue,double sat,double val,double huem,double satm,double valm);
    void setSizeOfObject(unsigned int amountPixels);
    void setAmountOfObejects(unsigned int amountObjects);
    void setVariance(unsigned int variance);
    void setYValues();
    void setPaintCenters();
    void setPaintExactCenters();
    void setPaintLines();
    cv::Mat getCurrentContours();
    cv::Mat contoursret;
    void setasdfobject(asdf* asdfobj);

private:
    cv::Mat maskColor(const cv::Mat&source);
    double minH;
    double minS;
    double minV;
    double maxH;
    double maxS;
    double maxV;
    asdf* objectasdf;
    bool paintC;
    bool paintExact;
    bool paintLines;
    unsigned int amountPixels;
    unsigned int amountObjects;
    unsigned int variance;
    bool setval;
    std::vector<unsigned int> yValues;
    std::vector<cv::Point> sortCenters(std::vector<cv::Point> centers);
    std::vector<int> scaleValues(std::vector<cv::Point> centers);
    bool checkBorders(std::vector<cv::Point> centers);
    void setValidValues(std::vector<cv::Point> centers);
signals:
    void sendData(std::vector<cv::Point> sendCenters);
};

#endif // COLORKEYER_H
