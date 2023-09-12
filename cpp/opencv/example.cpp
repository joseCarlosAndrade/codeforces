#include<iostream>
#include<chrono>

#include<opencv2/imgproc.hpp>
#include<opencv2/core/core.hpp>
#include<opencv2/highgui.hpp>

int main(int argc, char ** argv) {

    cv::VideoCapture video(0);
    if (!video.isOpened()) return 0;

    cv::namedWindow("my little window", cv::WindowFlags::WINDOW_GUI_NORMAL);

    while(true) {
        cv::Mat frame;
        video >> frame;

        // frame.size[0] 720
        // frame.size[1] 1280
        

        // cv::cvtColor(frame, frame, cv::COLOR_BGR2GRAY);
        cv::circle(frame, cv::Point((int)frame.size[1]/2 , (int)frame.size[0]/2), 50, (255, 0, 0, 255), 10);


        cv::imshow("My little windowww", frame);
        std::cout << frame.size[0] << std::endl;
        if(cv::waitKey(30) >= 0) break;
    }

    // cv::Mat image;
    // image = cv::imread(argv[1]);

    // if (image.data == nullptr) {
    //     std::cerr << "File doesnt exist" << std::endl;
    //     return 0;
    // }

    // cv::resize(image, image, cv::Size(500, 500));
    // cv::arrowedLine(image, cv::Point(70, 70), cv::Point(100,100), (0, 0, 255, 255), 10);
    // cv::line(image, cv::Point(10, 10), cv::Point(50, 50), (255, 0, 0, 255), 10);
    // std::cout << image.cols;
    // cv::imshow("image", image);
    // cv::waitKey(0);

    // cv::destroyAllWindows();
    // return 0;
}

// sudo apt−get install build−essential libgtk2.0−dev libvtk5−dev libjpeg−dev libtiff4−dev libjasper−dev libopenexr−dev libtbb−dev 