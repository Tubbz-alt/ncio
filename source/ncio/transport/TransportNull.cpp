/**
 * TransportNull.cpp: class that defines a null transport to help measure
 * overhead of real transports.
 *
 *  Created on: May 15, 2020
 *      Author: William F Godoy godoywf@ornl.gov
 */

#include "TransportNull.h"

namespace ncio::transport
{

TransportNull::TransportNull(const std::string &name, const OpenMode openMode,
                             const Parameters &parameters)
: Transport("Null", name, openMode, parameters)
{
}

// PRIVATE
void TransportNull::DoGetMetadata(
    std::map<std::string, std::set<std::string>> &index)
{
}

#define declare_ncio_types(T)                                                  \
    void TransportNull::DoPut(const std::string &entryName, const T *data,     \
                              const Dimensions &dimensions,                    \
                              const int threadID)                              \
    {                                                                          \
    }                                                                          \
    void TransportNull::DoGet(const std::string &entryName, T *data,           \
                              const Box &box, const int threadID)              \
    {                                                                          \
    }

NCIO_PRIMITIVE_TYPES(declare_ncio_types)
#undef declare_ncio_types

void TransportNull::DoClose() {}

std::any TransportNull::DoGetNativeHandler() noexcept { return std::any(); }

} // end namespace ncio::transport
