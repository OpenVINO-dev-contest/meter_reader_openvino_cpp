#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/core/core.hpp>
#include <openvino/openvino.hpp>
#include <iostream>
#include <chrono>
#include <cmath>
using namespace std;
using namespace cv;

class Detector
{
public:
    Detector();
    ~Detector();

    bool init(string xml_path, double threshold);

    bool process_frame(Mat &inframe, vector<Rect> &detected_objects);

private:
    // ov::CompiledModel detect_model;
    ov::InferRequest detect_infer_request;
    string _model_path;
    float _threshold;
};