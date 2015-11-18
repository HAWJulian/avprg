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
void ColorKeyer::setSizeOfObject(unsigned int amountPixels)
{
    this->amountPixels = amountPixels;
}
void ColorKeyer::setAmountOfObejects(unsigned int amountObjects)
{
    this->amountObjects = amountObjects;
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
    //int y = 0;
    //int x = 0;
    medianBlur(input, input, 11);
    //Vec3b inputPixel = input.at<Vec3b>(y,x);
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

    erode(output, output, Mat(), Point(-1,-1), 2, 1, 1);
    //dilate(output, output, Mat());
    dilate(output, output, Mat(),  Point(-1, -1), 2, 1, 1);

    //fastNlMeansDenoising(output, output, 3.0f, 7, 21);
    //medianBlur(output,output, 5);
    //definieren der contours matrix (2D vector von Points)
    std::vector<std::vector<cv::Point> > contours;
    //vorbereiten des result objektes
    std::vector<std::vector<Point> > results;
    std::vector<Point> centers;
    std::vector<Point> centers_sorted;
    //duplizieren des output mats
    cv::Mat contourOutput = output.clone();
    //finden der konturen (Simple/none)
    //cv::findContours(contourOutput, contours, CV_RETR_LIST, CV_CHAIN_APPROX_SIMPLE );
    cv::findContours(contourOutput, contours, CV_RETR_LIST, CV_CHAIN_APPROX_NONE);
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

    qDebug() << results.size();
    //wenn results die gewünschte anzahl an objekten gefunden hat
    if(results.size() == amountObjects)
    {
        //führe folgende routine für jedes results element aus
        for(unsigned int i = 0; i<results.size(); i++)
        {
            //berechne die moments einer kontur
            Moments mu =  moments(contours[i], false);
            //berechne den schwerpunkt
            Point mc(mu.m10/mu.m00, mu.m01/mu.m00);
            centers.push_back(mc);
            qDebug() << mc.x << mc.y;
            //zeichene rotes quadrat in die mitte eines erkannten objektes
            if(mc.x > 10 && mc.x <output.cols-9 && mc.y > 10 && mc.y < output.rows-9)
            {
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

        }
        //sortieren



        unsigned int min;
        for(unsigned int c = 0; c < centers.size() - 1; c++)
        {
            min = c;
            //qDebug() << min;
            for(unsigned int d = c+1; d < centers.size(); d++)
            {
                if(centers[d].y < centers[min].y)
                {
                    min = d;
                }
                //qDebug() << "inner min";
                //qDebug() << min;
            }
            if(min != c)
            {
                qDebug() << "swap " << min << " and " << c;
                Point temp = centers[c];
                centers[c] = centers[min];
                centers[min] = temp;
            }
        }
        //
        qDebug() << "sorted";
        for(unsigned int c = 0; c < centers.size(); c++)
        {
            qDebug() << centers[c].x << centers[c].y;
        }

    }
    return newoutput;
}


