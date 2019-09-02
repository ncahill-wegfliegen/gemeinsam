#pragma once


namespace nhill
{
namespace log
{

/// <summary>The logger heirarchy is ALL DEBUG INFO WARN ERROR FATAL OFF.
/// <para>The extensions for this enumeration are in the GeoScoutLogFile library.</para>
///</summary>
enum class Level
{
    none,
    off = none,
    fatal,
    error,
    warn,
    info,
    debug,
    all,
};

}
}

