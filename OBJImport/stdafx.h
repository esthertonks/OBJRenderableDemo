// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
// Windows Header Files:
#include <windows.h>

// C RunTime Header Files
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>

#include <string>
#include <vector>
#include <memory>
#include <tuple>
#include <cassert>
#include <array>
#include <map>
#include <unordered_map>

#ifdef _DEBUG
#define LOG(str)    OutputDebugStringW(str)
#else
#define LOG(str)    (void)(str)
#endif

// TODO: reference additional headers your program requires here
