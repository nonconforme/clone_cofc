//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#ifndef GeographicDataBaseTag_h
#define GeographicDataBaseTag_h
// stream
#include "GeographicDataBaseFormat.h"
#include "GeographicDataRecordHeader.h"
class GeographicDataBaseTag : public GeographicDataBaseFormat {
   public:
    GeographicDataRecordHeader* header;
    GeographicDataBaseTag();
    virtual ~GeographicDataBaseTag();
};
#endif
