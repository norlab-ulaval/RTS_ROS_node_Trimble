
#include "VideoStreamingListener.h"

#include "Image/IImageCapture.h"

#include <iostream>
#include <vector>
#include <mutex>


VideoStreamingListener::VideoStreamingListener()
{
    streaming_state = SSI::SS_NotStreaming;
}

VideoStreamingListener::~VideoStreamingListener()
{
}

void VideoStreamingListener::streamingStateChanged(const SSI::StreamingStateChangedEvent& event)
{
    std::lock_guard<std::mutex> state_lock(streaming_state_mutex);
    streaming_state = event.getStreamingState();
    image_count = 0;
}

void VideoStreamingListener::videoStreamigUpdate(const SSI::VideoStreamingUpdateEvent& event)
{
    const SSI::IImageCapture& image_capture = event.getImageCapture();   

    std::lock_guard<std::mutex> state_lock(streaming_state_mutex);
    image_count++;

    std::lock_guard<std::mutex> info_lock(video_info_mutex);
    video_format_type = image_capture.getFormat();
    video_height = image_capture.getHeight();
    video_width = image_capture.getWidth();

    std::lock_guard<std::mutex> image_lock(current_image_mutex);
    int image_size = image_capture.getStreamLength();
    current_image.resize(image_size);

    image_capture.getStream((unsigned char*)current_image.data(), image_size);
}

void VideoStreamingListener::printVideoInfo()
{
    std::lock_guard<std::mutex> state_lock(streaming_state_mutex);
    if(streaming_state == SSI::SS_Streaming && image_count > 0)
    {
        std::cout << "Image number: " << image_count << std::endl;

        std::lock_guard<std::mutex> info_lock(video_info_mutex);
        std::cout << "Format: ";

        switch (video_format_type)
        {
        case 0:
            std::cout << "Jpeg" << std::endl;
            break;
        case 1:
            std::cout << "Bmp" << std::endl;
            break;
        case 2:
            std::cout << "RgbaPixels32NoHeader" << std::endl;
            break;
        case 3:
            std::cout << "RGB_Tiff" << std::endl;
            break;
        case 4:
            std::cout << "Raw" << std::endl;
            break;
        case 5:
            std::cout << "H264" << std::endl;
            break;
        default:
            std::cout << "Unkwown" << std::endl;
            break;
        }

        std::cout << "Width: " << video_width << std::endl;
        std::cout << "Height: " << video_height << std::endl;
        std::cout << "==================" << std::endl;
    }
    else
    {
        std::cout << "Not streaming" << std::endl;
    }
}

unsigned int VideoStreamingListener::getCurrentImageCount()
{
    std::lock_guard<std::mutex> state_lock(streaming_state_mutex);
    return image_count;
}


std::vector<char> VideoStreamingListener::getImage()
{
    std::lock_guard<std::mutex> image_lock(current_image_mutex);
    return current_image;
}
