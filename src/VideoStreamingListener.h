#ifndef SALLY_VIDEOSTREAMINGUPDATELISTENER_H
#define SALLY_VIDEOSTREAMINGUPDATELISTENER_H

#include "Video/IVideoStreamingUpdateListener.h"

#include "IStreamingStateChangedListener.h"

#include <mutex>
#include <vector>

class VideoStreamingListener : 
    public SSI::IVideoStreamingUpdateListener, 
    public SSI::IStreamingStateChangedListener
{
public:
    
    VideoStreamingListener();

    ~VideoStreamingListener();

    virtual void videoStreamigUpdate(const SSI::VideoStreamingUpdateEvent& event);

    virtual void streamingStateChanged(const SSI::StreamingStateChangedEvent& event);
    
    void printVideoInfo();

    unsigned int getCurrentImageCount();

    std::vector<char> getImage();

private:

    SSI::StreamingState streaming_state;
    std::mutex streaming_state_mutex;
    unsigned int image_count;

    SSI::ImageFormatType video_format_type;
    unsigned int video_height;
    unsigned int video_width;
    std::mutex video_info_mutex;

    std::vector<char> current_image;
    std::mutex current_image_mutex;
};

#endif