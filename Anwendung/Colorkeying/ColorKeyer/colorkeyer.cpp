#include "colorkeyer.h"
#include "asdf.h"
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
    //variable which checks if new y-axis values should be taken
    setval = false;
    //holds
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
//sets the minimum size of an object
void ColorKeyer::setSizeOfObject(unsigned int amountPixels)
{
    this->amountPixels = amountPixels;
}
//sets the amount of objects which should be captured
void ColorKeyer::setAmountOfObejects(unsigned int amountObjects)
{
    this->amountObjects = amountObjects;
}
//sets the distance which the center of an object may have to its captured y-axis value
void ColorKeyer::setVariance(unsigned int variance)
{
    this->variance = variance;
}
//sets variable to capture new y-axis values
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
//takes the input image, filters it and checks for colors in a certain range
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
    //Maskiertes bild
    Mat output = maskColor(input);
    //Filterung des maskierten Bildes
    erode(output, output, Mat(), Point(-1,-1), 2, 1, 1);
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
                    for(int a = mc.y-9; a <mc.y+9; a++)
                    {
                        newoutput.at<Vec3b>(a,x)[0] = 0;
                        newoutput.at<Vec3b>(a,x)[1] = 255;
                        newoutput.at<Vec3b>(a,x)[2] = 0;
                        x++;
                    }
                    x = mc.x+9;
                    for(int a = mc.y-9; a <mc.y+9; a++)
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
                //top
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
    //todo fix to check on conditions above
    if(checkBorders(centers))
    {
        setValidValues(centers);
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
        qDebug() << centers[c].x << centers[c].y;
    }
    return centers;
}
//returns ccurrent contours image
cv::Mat ColorKeyer::getCurrentContours()
{
    return contoursret;
}
//checks if centers are valid (correct amount of objects, every center of an object within its defined range)
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
void ColorKeyer::setasdfobject(asdf *asdfobj)
{
    objectasdf = asdfobj;
}

void ColorKeyer::setValidValues(std::vector<Point> centers)
{
    //handle

    //float x = (float)centers[0].x;
    /*
    x /= 480.;
    x *= 10000;
    int y = (int) x;
    */
    //qDebug() << centers.size();
    /*
    if(centers.size() != 0)
    {
        qDebug() << "valid values " << centers[0].x << " " << centers[0].y ;
        float x = (float)centers[0].x;

        x /= 480.;
        x *= 10000;
        int y = (int) x;
        objectasdf->getData(y);
    }
    */
    if(centers.size() != 0)
    {
        std::vector<int> scaledCenters = scaleValues(centers);
        objectasdf->getData(scaledCenters);
        //objectasdf->getData(centers);
    }
}
std::vector<int> ColorKeyer::scaleValues(std::vector<Point> centers)
{
    std::vector<int> scaledCenters;
    float x;
    int y;
    float framewidth = 640.;

    //first slider (0-10000)
    if(centers.size() > 0)
    {
        x = (float) centers[0].x;
        x /= framewidth;
        x *= 10000;
        y = (int) x;
        scaledCenters.push_back(y);
    }
    //second slider (10-1000)

    if(centers.size() > 1)
    {
        x = (float)centers[1].x;
        x /= framewidth;
        x *= 990;
        x += 10;
        y = (int) x;
        scaledCenters.push_back(y);
    }
    //third slider (0-100)
    if(centers.size() > 2)
    {
        x = (float)centers[2].x;
        x /= framewidth;
        x *= 100;
        y = (int)x;
        scaledCenters.push_back(y);
    }
    //fourth slider (0-100)
    if(centers.size() > 3)
    {
        x = (float)centers[3].x;
        x /= framewidth;
        x *= 100;
        y = (int)x;
        scaledCenters.push_back(y);
    }

    //fifth slider (0-100)
    if(centers.size() > 4)
    {
        x = (float)centers[4].x;
        x /= framewidth;
        x *= 100;
        y = (int)x;
        scaledCenters.push_back(y);
    }

    //sixth slider (0-100)
    if(centers.size() > 5)
    {
        x = (float)centers[5].x;
        x /= framewidth;
        x *= 100;
        y = (int)x;
        scaledCenters.push_back(y);
    }

    //seventh slider (1-25)
    if(centers.size() > 6)
    {
        x = (float)centers[5].x;
        x /= framewidth;
        x *= 24;
        x += 1;
        y = (int)x;
        scaledCenters.push_back(y);
    }
    return scaledCenters;
}

