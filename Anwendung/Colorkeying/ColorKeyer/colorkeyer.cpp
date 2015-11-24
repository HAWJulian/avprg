#include "colorkeyer.h"
using namespace cv;

// Referenzfarbe
// ACHTUNG, die Reihenfolge ist BGR!
// ToDo: dies von aussen einstellbar machen
//const Vec3b REFERENCE_COLOR(54, 39, 97);	// BGR

// Schwellwert
// ToDo: dies von aussen einstellbar machen
const int THRESHOLD = 40;

ColorKeyer::ColorKeyer()
{
    setval = false;
    yValues = {};
    paintC = true;
    paintExact = true;
    paintLines = true;
}
void ColorKeyer::setPaintCenters()
{
    paintC = !paintC;
}
void ColorKeyer::setPaintExactCenters()
{
    paintExact = !paintExact;
}
void ColorKeyer::setPaintLines()
{
    paintLines = !paintLines;
}

void ColorKeyer::setThreshold(double hue,double sat,double val,double huem,double satm,double valm)
{
    minH = hue;
    minS = sat;
    minV = val;
    maxH = huem;
    maxS = satm;
    maxV = valm;
}
//setzt die groesse eines objektes, das erkannt werden soll, in anzahl der pixel
void ColorKeyer::setSizeOfObject(unsigned int amountPixels)
{
    this->amountPixels = amountPixels;
}
//setzt die anzahl der objekte, die erkannt werden sollen
void ColorKeyer::setAmountOfObejects(unsigned int amountObjects)
{
    this->amountObjects = amountObjects;
}
//setzt variance, die ein objekt in y richtung haben darf (in beide richtungen)
void ColorKeyer::setVariance(unsigned int variance)
{
    this->variance = variance;
}
void ColorKeyer::setYValues()
{
    setval = true;
}

void ColorKeyer::startProcessing(const VideoFormat& format){
    // Höhe: format.frameHeight()
    // Breite: format.frameWidth()
    // Framerate: format.framesPerSecond()
    // Pixelart: format.type() (CV_8UC1=Graustufen, CV_8UC3=BGR)
}

Mat ColorKeyer::maskColor(const Mat &input){
    cvtColor(input, input, CV_BGR2HSV);
    medianBlur(input, input, 11);
    //create output picture
    Mat output(input.rows, input.cols, CV_8UC1);
    //run over all pixels in the given frame
    inRange(input, Scalar(minH, minS, minV), Scalar(maxH, maxS, maxV), output);
    medianBlur(input, input, 11);
    return output;
}
Mat ColorKeyer::process(const Mat &input){
    //FILTERING
    //OBJECT LOCATION
    //Maskiertes bild
    Mat output = maskColor(input);
    //Filterung des maskierten Bildes
    erode(output, output, Mat(), Point(-1,-1), 2, 1, 1);
    //dilate(output, output, Mat());
    dilate(output, output, Mat(),  Point(-1, -1), 2, 1, 1);
    //fastNlMeansDenoising(output, output, 3.0f, 7, 21);
    //definieren der contours matrix (2D vector von Points)
    std::vector<std::vector<cv::Point> > contours;
    //vorbereiten des result objektes
    std::vector<std::vector<Point> > results;
    std::vector<Point> centers;
    //duplizieren des output mats
    cv::Mat contourOutput = output.clone();
    //finden der konturen (Simple/none)
    //cv::findContours(contourOutput, contours, CV_RETR_LIST, CV_CHAIN_APPROX_SIMPLE );
    cv::findContours(contourOutput, contours, CV_RETR_LIST, CV_CHAIN_APPROX_NONE);
    contoursret = contourOutput.clone();
    //für jeden eintrag in contours durch findContours
    for(unsigned int x = 0; x<contours.size(); x++)
    {
        //check, ob die area, die durch die konturen umschlossen wird,
        //eine mindestgröße erreicht hat
        if(contourArea(contours[x]) >= amountPixels)
        {
            //wenn ja, zu results hinzufügen
            results.push_back(contours[x]);
        }
    }
    Mat newoutput = output.clone();
    //kopiert output in newoutput und convertiert es zurück in rgb
    cvtColor(output, newoutput, CV_GRAY2RGB);

    //qDebug() << results.size();
    //wenn results die gewünschte anzahl an objekten gefunden hat
    if(results.size() == amountObjects)
    {
        //führe folgende routine für jedes results element aus
        for(unsigned int i = 0; i<results.size(); i++)
        {
            //berechne die moments einer kontur
            Moments mu = moments(contours[i], false);
            //berechne den schwerpunkt
            Point mc(mu.m10/mu.m00, mu.m01/mu.m00);
            centers.push_back(mc);
            //qDebug() << mc.x << mc.y;

            if(mc.x > 10 && mc.x <output.cols-9 && mc.y > 10 && mc.y < output.rows-9)
            {
                if(paintC)
                {
                    //zeichene quadrat in die mitte eines erkannten objektes
                    for(int a = mc.y-9; a<mc.y+10; a++)
                    {
                        for(int b = mc.x-9; b<mc.x+10; b++)
                        {
                            newoutput.at<Vec3b>(a,b)[0] = 0;
                            newoutput.at<Vec3b>(a,b)[1] = 0;
                            newoutput.at<Vec3b>(a,b)[2] = 255;
                        }
                    }
                }
                if(paintExact)
                {
                    int x = mc.x-9;
                    //zeichne kreuz zur klaren erkennung des zentrums
                    for(int a = mc.y-9; a <mc.y+10; a++)
                    {
                        newoutput.at<Vec3b>(a,x)[0] = 0;
                        newoutput.at<Vec3b>(a,x)[1] = 255;
                        newoutput.at<Vec3b>(a,x)[2] = 0;
                        x++;
                    }
                    x = mc.x+10;
                    for(int a = mc.y-9; a <mc.y+10; a++)
                    {
                        newoutput.at<Vec3b>(a,x)[0] = 0;
                        newoutput.at<Vec3b>(a,x)[1] = 255;
                        newoutput.at<Vec3b>(a,x)[2] = 0;
                        x--;
                    }
                }
            }
        }
        centers = sortCenters(centers);
        if(setval)
        {
            yValues.clear();
            for(unsigned int v = 0; v < centers.size(); v++)
            {
                yValues.push_back(centers[v].y);
                qDebug() << centers[v].y;
            }
            setval = !setval;
        }
    }
    else if(setval)
    {
        qDebug() << "error setting the y values, not the correct amount of objectes found";
        setval = !setval;
    }
    //qDebug() << "centers found: " << centers.size();
    //qDebug() << "yValues size: " << yValues.size();
    if(yValues.size() > 0 && paintLines)
    {
        for(unsigned int v= 0; v<yValues.size(); v++)
        {
            for(int a = 0; a < newoutput.cols; a++)
            {
                //qDebug() << yValues[v] - variance;
                //qDebug() << a;
                //top
                if(a == 0)
                {
                    qDebug() << v;
                    qDebug() << yValues[v] - variance;
                    qDebug() << yValues[v] + variance;
                }
                newoutput.at<Vec3b>(yValues[v] - variance, a)[0] = 255;
                newoutput.at<Vec3b>(yValues[v] - variance, a)[1] = 0;
                newoutput.at<Vec3b>(yValues[v] - variance, a)[2] = 0;
                //bot
                newoutput.at<Vec3b>(yValues[v] + variance, a)[0] = 255;
                newoutput.at<Vec3b>(yValues[v] + variance, a)[1] = 0;
                newoutput.at<Vec3b>(yValues[v] + variance, a)[2] = 0;
            }
        }
    }
    if(checkBorders(centers))
    {
        //TODO verarbeitung der werte
    }
    return newoutput;
}
//sortiert einen vector von points aufsteigend nach ihrem y wert
std::vector<Point> ColorKeyer::sortCenters(std::vector<Point> centers)
{
    unsigned int min;
    for(unsigned int c = 0; c < centers.size() - 1; c++)
    {
        min = c;
        for(unsigned int d = c+1; d < centers.size(); d++)
        {
            if(centers[d].y < centers[min].y)
            {
                min = d;
            }
        }
        if(min != c)
        {
            Point temp = centers[c];
            centers[c] = centers[min];
            centers[min] = temp;
        }
    }
    //
    for(unsigned int c = 0; c < centers.size(); c++)
    {
        //qDebug() << centers[c].x << centers[c].y;
    }
    return centers;
}
//returns ccurrent contours image
cv::Mat ColorKeyer::getCurrentContours()
{
    return contoursret;
}
//checks if centers are valid
bool ColorKeyer::checkBorders(std::vector<Point> centers)
{
    //if amount of centers dont match the amount of objects which should be deteccted, return false
    if(centers.size() != yValues.size())
    {
        return false;
    }
    else
    {
        //else check for every single value if it is within its boundaries
        //if >0 are not, return false
        //if 0 are not, return true
        for(unsigned int x = 0; x < centers.size(); x++)
        {
            if(centers[x].y > yValues[x] + variance || centers[x].y < yValues[x] - variance)
            {
                return false;
            }
        }
    }
    return true;
}
void ColorKeyer::setValidValues(std::vector<Point> centers)
{
    //handle
    qDebug() << "valid values";
}

