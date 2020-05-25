#ifndef SSI_COMMAND_H
#define SSI_COMMAND_H

typedef int (*cmd_handle)(int argc, char **argv);
struct command_handle
{
    const char* cmd;
    const char* help;
    cmd_handle handle;
};

extern const command_handle * get_sensor_command();

#endif