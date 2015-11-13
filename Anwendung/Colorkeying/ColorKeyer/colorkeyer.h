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
private:
    cv::Mat maskColor(const cv::Mat&source);
    cv::Point ColorKeyer::centerOfMass(cv::Mat& image);
    std::vector<cv::Point> searchFrame(cv::Mat img);
    void findNeighbours(std::list<cv::Point> &neighbours, int x, int y, cv::Mat algoimg);
    bool isWhite(cv::Vec3b pointToCheck);
    double minH;
    double minS;
    double minV;
    double maxH;
    double maxS;
    double maxV;
};

#endif // COLORKEYER_H
