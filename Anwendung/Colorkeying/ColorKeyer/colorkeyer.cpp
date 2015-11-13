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

void ColorKeyer::startProcessing(const VideoFormat& format){
    // Höhe: format.frameHeight()
    // Breite: format.frameWidth()
    // Framerate: format.framesPerSecond()
    // Pixelart: format.type() (CV_8UC1=Graustufen, CV_8UC3=BGR)
}

Mat ColorKeyer::maskColor(const Mat &input){
    cvtColor(input, input, CV_BGR2HSV);
    //create output picture
    Mat output(input.rows, input.cols, CV_8UC1);
    //run over all pixels in the given frame
    inRange(input, Scalar(minH, minS, minV), Scalar(maxH, maxS, maxV), output);
    int y = 0;
    int x = 0;
    Vec3b inputPixel = input.at<Vec3b>(y,x);
    /*
    for(int x = 0; x < input.cols; x++){
        for(int y = 0; y < input.rows; y++){
             //cvInRangeS(input, cvScalar(50,120, 120), cvScalar(70,255,255), output);
            //inRange(input, Scalar(50,120,120),Scalar(70,255,255), output);
            Vec3b inputPixel = input.at<Vec3b>(y,x);
            double distance = norm(inputPixel, REFERENCE_COLOR);


            uchar outputPixel = 0;
            //check if pixel color value is within threshold
            if (distance < THRESHOLD){
                outputPixel = 255;
            }
            output.at<uchar>(y,x) = outputPixel;
        }
    }
    */
    return output;
}
Mat ColorKeyer::process(const Mat &input){
    //FILTERING
    //OBJECT LOCATION
    //Maskiertes bild
    Mat output = maskColor(input);
    //Filterung des maskierten Bildes
    erode(output, output, Mat());
    dilate(output, output, Mat(),  Point(-1, -1), 2, 1, 1);

    //fastNlMeansDenoising(output, output, 3.0f, 7, 21);
    //medianBlur(output,output, 5);
    //definieren der contours matrix (2D vector von Points)
    std::vector<std::vector<cv::Point> > contours;
    //vorbereiten des result objektes
    std::vector<std::vector<Point> > results;
    //duplizieren des output mats
    cv::Mat contourOutput = output.clone();
    //finden der konturen
    cv::findContours(contourOutput, contours, CV_RETR_LIST, CV_CHAIN_APPROX_NONE );

    //für jeden eintrag in contours durch findContours
    for(int x = 0; x<contours.size(); x++)
    {
        //check, ob die area, die durch die konturen umschlossen wird,
        //eine mindestgröße erreicht hat
        if(contourArea(contours[x]) > 10000)
        {
            //wenn ja, zu results hinzufügen
            results.push_back(contours[x]);
        }
    }
    //qDebug() << results.size();
    //wenn results die gewünschte anzahl an objekten gefunden hat
    if(results.size() == 1)
    {
        //führe folgende routine für jedes results element aus
        for(int i = 0; i<results.size(); i++)
        {
            //berechne die moments einer kontur
            Moments mu =  moments(contours[i], false);
            //berechne den schwerpunkt
            Point mc(mu.m10/mu.m00, mu.m01/mu.m00);
            qDebug() << mc.x << mc.y;
            //makiere schwerpunkt durch schwarzes viereck
            /*
            for(int a = mc.y-3; a<mc.y+4; a++)
            {
                for(int b = mc.x-3; b<mc.x+4; b++)
                {
                    output.at<uchar>(a,b) = 0;
                }
            }
            */

        }
    }
    return output;
}

//gibt alle schwerpunkte von zusammenhängenden weißen pixeln zurück,
//die die definierte mindesgröße besitzen, wenn die anzahl der gefunden
//objekte mit der anzahl der erwarteten objekte übereinstimmt
std::vector<cv::Point> ColorKeyer::searchFrame(cv::Mat img)
{
    std::vector<cv::Point> schwerpunkte;
    for(int y = 0; y < img.rows; y++)
    {
        for(int x = 0; x < img.cols; x++)
        {
            if(isWhite(img.at<Vec3b>(y,x)))
            {
                std::list<cv::Point> cluster;
                findNeighbours(cluster, x, y, img);
                //wenn der cluster groß genug ist
                //aus performancegründen zeilen überspringen
                //x reseten auf 0

                //cluster schwerpunkt berechnen und in schwerpunkte hinzufügen
                qDebug() << cluster.size();
                x = 0;
                y+=2;
            }
        }
    }
    return schwerpunkte;
}
void ColorKeyer::findNeighbours(std::list<cv::Point> &neighbours, int x, int y, cv::Mat algoimg)
{
    uchar black = 0;
    uchar grey = 120;
    //wenn x > 0 -> es gibt ein pixel links von x (ohne index out of bounds)
    // -> x-1, sonst 0
    int a = x>0 ? x-1 : 0;
    //wenn x < algoimg.col -> es gibt ein pixel rechts von x (ohne index out of bound)
    // -> x+1, sonst x
    int maxa = x<algoimg.cols-1 ? x+1 : x;
    //gleiches für b
    int b = y>0 ? y-1 : 0;
    int maxb = y<algoimg.rows-1 ? y+1 : y;
    for(a; a < maxa; a++)
    {
        for(b; b<maxb; b++)
        {
            //wenn das pixel weiß ist
            if(isWhite(algoimg.at<Vec3b>(b,a)))
            {
                cv::Point add;
                add.x = a;
                add.y = b;
                //zur list hinzufügen
                neighbours.push_back(add);
                //schwarz färben
                algoimg.at<uchar>(b,a) = black;
                //algoimg.at<uchar>(b,a) = grey;
                //nachbarn diese pixels verarbeiten
                findNeighbours(neighbours, a, b, algoimg);
            }
        }
    }
}
bool ColorKeyer::isWhite(Vec3b pointToCheck)
{
    return pointToCheck[0] == 255;
}

Point ColorKeyer::centerOfMass(Mat& image){
    int sumx = 0;
    int sumy = 0;
    int count = 0;
    for(int x = 0; x < image.cols; x++){
        for (int y = 0; y < image.rows; y++){
            if (image.at<uchar>(y,x) == 255){
                sumx += x;
                sumy += y;
                count++;
            }
        }
    }
    if (count > 0){
        return Point(sumx/count, sumy/count);
    }
    else{
        return Point(0,0);
    }
}
