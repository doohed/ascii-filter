#include <iostream>
#include <opencv2/opencv.hpp>
#include <thread> 
#include <chrono> 

using namespace std;
using namespace cv;

const string ASCII_CHARS = " .:-=+!#%@";

Mat resize_image(Mat image, int new_width = 180, int new_height = 45) {
    Mat resized_image;
    resize(image, resized_image, Size(new_width, new_height));
    return resized_image;
}

char pixel_to_ascii(int pixel_value) {
    return ASCII_CHARS[pixel_value / 32];
}

string image_to_ascii(Mat image) {
    cvtColor(image, image, COLOR_BGR2GRAY);
    string ascii_image;
    for (int i = 0; i < image.rows; ++i) {
        for (int j = 0; j < image.cols; ++j) {
            ascii_image += pixel_to_ascii(image.at<uchar>(i, j));
        }
        ascii_image += '\n';
    }
    return ascii_image;
}

void process_video(string video_path) {
    VideoCapture cap(video_path);
    if (!cap.isOpened()) {
        cerr << "Error opening video file" << endl;
        return;
    }

    while (true) {
        Mat frame;
        cap >> frame;
        if (frame.empty()) break;

        Mat resized_frame = resize_image(frame);
        string ascii_frame = image_to_ascii(resized_frame);
        cout << ascii_frame;

        this_thread::sleep_for(chrono::milliseconds(22));
    }
}

int main() {
    string video_path = "./porter.mp4";
    process_video(video_path);
    return 0;
}

