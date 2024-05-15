#include <iostream>
#include <opencv2/opencv.hpp>
#include <thread> 
#include <chrono> 

using namespace std;
using namespace cv;

// Define the ASCII characters to represent different shades of gray
const string ASCII_CHARS = " .:-=+!#%@";

// Resize the image to fit the desired width and height while maintaining aspect ratio
Mat resize_image(Mat image, int new_width = 180, int new_height = 45) {
    Mat resized_image;
    resize(image, resized_image, Size(new_width, new_height));
    return resized_image;
}

// Convert each pixel to an ASCII character based on its intensity
char pixel_to_ascii(int pixel_value) {
    return ASCII_CHARS[pixel_value / 32];
}

// Convert the image to grayscale and then to ASCII
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

// Process the video frames
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

