//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#ifndef GeographicDataBarrierTagStream_h
#define GeographicDataBarrierTagStream_h

// stream
#include "BinaryStream.h"
#include "GeographicDataBaseTagStream.h"

class GeographicDataBarrierTagStream : public GeographicDataBaseTagStream {
   public:
    GeographicDataBarrierTagStream();
    virtual ~GeographicDataBarrierTagStream();
    GeographicDataBaseFormat* read(BinaryStream* stream, GeographicDataRecordHeader* recordHeader) override;
    bool write(std::ofstream* stream, GeographicDataBaseFormat* format) override;
};

#endif
