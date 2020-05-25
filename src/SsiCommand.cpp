#include <stdio.h>
#include "SsiCommand.h"
#include "SsiInstrument.h"
#include <string.h>

int sensor_loaddriver_handle(int argc, char **argv)
{
    if(argc == 0)
        return SsiInstrument::GetInstrument().LoadDriver();
    else
        return SsiInstrument::GetInstrument().LoadDriver(argv[0]);
}

int sensor_unloaddriver_handle(int argc, char **argv)
{
    return SsiInstrument::GetInstrument().FreeDriver();
}

int sensor_connect_handle(int argc, char **argv)
{
    if(argc == 0)
        return SsiInstrument::GetInstrument().Connect();
    else if(argc == 1)
        return SsiInstrument::GetInstrument().Connect(argv[0]);
    else
        return SsiInstrument::GetInstrument().Connect(argv[0], argv[1]);
}

int sensor_disconnect_handle(int argc, char **argv)
{
    return SsiInstrument::GetInstrument().DisConnect();
}

int sensor_property_handle(int argc, char **argv)
{
    return SsiInstrument::GetInstrument().GetProperty();
}

int sensor_power_handle(int argc, char **argv)
{
    if(argc == 0)
    {
        return SsiInstrument::GetInstrument().Power(0);
    }
    else if (strcmp(argv[0], "start") == 0)
    {
        return SsiInstrument::GetInstrument().Power(1);
    }
    else if (strcmp(argv[0], "stop") == 0)
    {
        return SsiInstrument::GetInstrument().Power(2);
    }
    else
    {
        return SsiInstrument::GetInstrument().Power(0);
    }
}

int sensor_changeface_handle(int argc, char **argv)
{
    return SsiInstrument::GetInstrument().ChangeFace();
}

int sensor_domeasure_handle(int argc, char **argv)
{
    if(argc == 0)
    {
        return SsiInstrument::GetInstrument().DoMeasure(false);
    }
    else if (strcmp(argv[0], "angle") == 0)
    {
        return SsiInstrument::GetInstrument().DoMeasure(true);
    }
    else
    {
        return SsiInstrument::GetInstrument().DoMeasure(false);
    }
}

int sensor_tracking_handle(int argc, char **argv)
{
    if(argc == 0)
    {
        return SsiInstrument::GetInstrument().Tracking(true);
    }
	else if (strcmp(argv[0], "10hz") == 0)
	{
		return SsiInstrument::GetInstrument().Tracking(true, 1);
	}
	else if (strcmp(argv[0], "20hz") == 0)
	{
		return SsiInstrument::GetInstrument().Tracking(true, 2);
	}
    else if (strcmp(argv[0], "stop") == 0)
    {
        return SsiInstrument::GetInstrument().Tracking(false);
    }
    else
    {
        return SsiInstrument::GetInstrument().Tracking(true);
    }
}

int sensor_idleangle_handle(int argc, char **argv)
{
    if(argc == 0)
    {
        return SsiInstrument::GetInstrument().IdleAngles(0);
    }
    else if (strcmp(argv[0], "start") == 0)
    {
        return SsiInstrument::GetInstrument().IdleAngles(1);
    }
    else if (strcmp(argv[0], "stop") == 0)
    {
        return SsiInstrument::GetInstrument().IdleAngles(2);
    }
    else
    {
        return SsiInstrument::GetInstrument().IdleAngles(0);
    }
}

int sensor_target_handle(int argc, char **argv)
{
    if(argc == 0)
    {
        return SsiInstrument::GetInstrument().Target(SsiInstrument::MODE_PRISM);
    }
    else if (strcmp(argv[0], "dr") == 0)
    {
        return SsiInstrument::GetInstrument().Target(SsiInstrument::MODE_DR);
    }
    else if (strcmp(argv[0], "drl") == 0)
    {
        return SsiInstrument::GetInstrument().Target(SsiInstrument::MODE_DR_LASER);
    }
    else if (strcmp(argv[0], "autolock") == 0)
    {
        return SsiInstrument::GetInstrument().Target(SsiInstrument::MODE_AUTOLOCK);
    }
    else
    {
        return SsiInstrument::GetInstrument().Target(SsiInstrument::MODE_PRISM);
    }
}

int sensor_video_handle(int argc, char **argv)
{
    if(argc == 0)
    {
        return SsiInstrument::GetInstrument().Video(true);
    }
    else if (strcmp(argv[0], "stop") == 0)
    {
        return SsiInstrument::GetInstrument().Video(false);
    }
    else
    {
        return SsiInstrument::GetInstrument().Video(true);
    }
}

int sensor_elevel_handle(int argc, char **argv)
{
    if(argc == 0)
    {
        return SsiInstrument::GetInstrument().Elevel(true);
    }
    else if (strcmp(argv[0], "stop") == 0)
    {
        return SsiInstrument::GetInstrument().Elevel(false);
    }
    else
    {
        return SsiInstrument::GetInstrument().Elevel(true);
    }
}

int sensor_image_handle(int argc, char **argv)
{
    return SsiInstrument::GetInstrument().Image();
}

command_handle sensor_command_list[] = 
{
    {"load", "\tload SsiDriver\n\tload <driver>\n\tdriver: SSeries\n\tDefault SSeries", sensor_loaddriver_handle},
    {"unload", "\tunload SsiDriver", sensor_unloaddriver_handle},
    {"connect", "\tconnect to SsiSensor\n\tconnect [<type>] [<port>]\n\ttype: usb tcp\n\tDefault usb", sensor_connect_handle},
    {"disconnect", "\tdisconnect to SsiSensor", sensor_disconnect_handle},
    {"property", "\tget SsiSensor property", sensor_property_handle},
    {"power", "\tget, start or stop power\n\tpower [start/stop]\n\tif no parameter, it will get power", sensor_power_handle},
    {"changeface", "\tchange the face of SsiSensor", sensor_changeface_handle},
    {"measure", "\tdo measurement\n\tmeasure [angle]\n\tif no parameter, it will measure both distance and angle", sensor_domeasure_handle},
    {"tracking", "\tstart or stop tracking stream\n\ttracking [start/10hz/20hz/stop]\n\tif no parameter, it will start tracking stream", sensor_tracking_handle},
    {"idleangle", "\tget, start or stop idleangle\n\tidleangle [start/stop]\n\tif no parameter, it will get idleangle", sensor_idleangle_handle},
    {"target", "\tset target mode\n\ttarget [dr/drl/autolock]\n\tif no parameter, it will set target to manual mode", sensor_target_handle},
    {"video", "\tstart or stop video stream\n\tvideo [stop]\n\tif no parameter, it will start video stream", sensor_video_handle},
    {"image", "\ttake an image", sensor_image_handle},
    {"elevel", "\tstart or stop TotalStation elevel\n\televel values [stop]\n\tif no parameter, it will start streaming elevel", sensor_elevel_handle},
    {NULL, NULL, NULL}
};

const command_handle *get_sensor_command()
{
    return sensor_command_list;
}
