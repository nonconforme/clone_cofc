//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#ifndef GeographicDataFormatFactory_h
#define GeographicDataFormatFactory_h
// geographic
#include "GeographicNode.h"
// stream
#include "GeographicDataBaseFormat.h"
class GeographicDataFormatFactory {
   public:
    static GeographicDataBaseFormat* factoryMethod(unsigned char formatType, GeographicNode* node);
};
#endif
