#pragma once

#define _USE_MATH_DEFINES
#include <cmath>
#include <string>
#include <unordered_map>
#include <mutex>
#include <atomic>

#if WIN32
#include "win/targetver.h"

#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#define NOSERVICE
#define NOMCX
#define NOIME
#include <windows.h>
#undef TEXT
#endif