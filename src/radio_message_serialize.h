
#ifndef MSG_SERIALIZE_H
#define MSG_SERIALIZE_H

#include <vector>
//#include <exception>
#include <stdexcept>
#include <stdint.h>
#include <cstring>

typedef unsigned char byte;


// The bytes of the input_val are appended to the end of the provided buffer
//
// WARNING: The bytes are taken as they are in the memory.
// The way a double is stored in memory depends on the platform (endianness, padding, etc.).
//
// Params: byte_buffer - a vector to write the bytes into
//         input_val - the double to be converted
//
// Returns: number of bytes added to the buffer
size_t double_to_bytes(std::vector<byte> &byte_buffer, double input_val);

// Reads bytes from a provided buffer and assembles a double
//
// WARNING: The way a double is stored in memory depends on the platform (endianness, padding, etc.).
// If you use this function, the bytes should come from the same platform, or you'll get a funny behavior.
//
// Params: byte_buffer - the vector to read the bytes from
//         start_index - the first byte of the double in the buffer
//
// Returns: The assembled double
double bytes_to_double(std::vector<byte> &byte_buffer, size_t start_index);


// The bytes of the input_val are appended to the end of the provided buffer
//
// WARNING: The bytes are taken as they are in the memory.
// The way a uint is stored in memory depends on the platform (endianness, padding, etc.).
//
// Params: byte_buffer - a vector to write the bytes into
//         input_val - the uint to be converted
//
// Returns: number of bytes added to the buffer
size_t uint_to_bytes(std::vector<byte> &byte_buffer, uint32_t input_val);

// Reads bytes from a provided buffer and assembles an uint
//
// WARNING: The way a uint is stored in memory depends on the platform (endianness, padding, etc.).
// If you use this function, the bytes should come from the same platform, or you'll get a funny behavior.
//
// Params: byte_buffer - the vector to read the bytes from
//         start_index - the first byte of the double in the buffer
//
// Returns: The assembled uint
uint32_t bytes_to_uint(std::vector<byte> &byte_buffer, size_t start_index);



// This function packs the parameters to the byte buffer, which it cleans first.
void pack_theodolite_message_to_bytes(std::vector<byte> &byte_buffer,
                                      byte theodolite_number,
                                      byte status,
                                      double elevation,
                                      double azimuth,
                                      double distance,
                                      uint32_t secs,
                                      uint32_t nsecs);

// This function checks if the byte buffer contains the correct number of bytes (returns true) and then fills the
// parameters with the values.
bool unpack_theodolite_message_from_bytes(std::vector<byte> &byte_buffer,
                                      byte &theodolite_number,
                                      byte &status,
                                      double &elevation,
                                      double &azimuth,
                                      double &distance,
                                      uint32_t &secs,
                                      uint32_t &nsecs);


// This function packs the parameters to the byte buffer, which it cleans first.
void pack_theodolite_time_to_bytes(std::vector<byte> &byte_buffer,
                                      byte command_code,
                                      uint32_t secs,
                                      uint32_t nsecs);

// This function checks if the byte buffer contains the correct number of bytes (returns true) and then fills the
// parameters with the values.
bool unpack_theodolite_time_from_bytes(std::vector<byte> &byte_buffer,
                                          byte &command_code,
                                          uint32_t &secs,
                                          uint32_t &nsecs);

#endif
