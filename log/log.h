#pragma once

// See http://stackoverflow.com/questions/1008019/c-singleton-design-pattern for details on creating a singleton class.

#include "port.h"
#include "level.h"
#include <string>

namespace nhill
{
#pragma region Macros
// Use these macros instead of direct calls to the methods.
// These macros allow automatic access to the FileName, LineNumber and TimeStamp information for the calling method.
#define LOG_FATAL(msg) log::fatal( msg, __FILE__, __LINE__, __TIMESTAMP__ );
#define LOG_ERROR(msg) log::error( msg, __FILE__, __LINE__, __TIMESTAMP__ );
#define LOG_WARN(msg)  log::warn ( msg, __FILE__, __LINE__, __TIMESTAMP__ );
#define LOG_INFO(msg)  log::info ( msg, __FILE__, __LINE__, __TIMESTAMP__ );
#define LOG_DEBUG(msg) log::debug( msg, __FILE__, __LINE__, __TIMESTAMP__ );
#pragma endregion

/// <summary>
/// Properties and methods for managing the log file.
/// <para>You MUST call Initialize once BEFORE calling any property or method.</para>
/// <para>You MUST call Finalize to write out the footer to the log file.</para>
/// </summary>
namespace log 
{
#pragma region Properties
    /// <summary>Get/Set the level of the log file output.</summary>
    /// <returns>A reference to the level that is valid throughout the thread.</returns>
    NHILL_LOG_PORT_FUNCTION Level& level();

    /// <summary>Get/Set the path for the log file output.</summary>
    /// <returns>A reference to the path that is valid throughout the thread.</returns>
    NHILL_LOG_PORT_FUNCTION std::string& path();
#pragma endregion

#pragma region Methods
    /// <summary>Initialize the path and level of the log file output.
    /// <para>Outputs the log file header.</para>
    /// <para>Usually called just once at the beginning of the thread;</para>
    /// <para>e.g., in the InitInstance method of the user interface.</para>
    /// </summary>
    /// <param name="level">Set the level for the log file output.</param>
    /// <param name="path">Set the path for the log file output.</param>
    NHILL_LOG_PORT_FUNCTION void initialize( Level level, const std::string& path );

    /// <summary>Finalize the log file output.
    /// <para>Outputs the log file footer.</para>
    /// <para>Usually called just once at the end of the thread;</para>
    /// <para>e.g., in the ExitInstance method of the user interface.</para>
    /// </summary>
    NHILL_LOG_PORT_FUNCTION void finalize();

    NHILL_LOG_PORT_FUNCTION void fatal( const std::string& text, const std::string& file, int line, const std::string& timeStamp );
    NHILL_LOG_PORT_FUNCTION void error( const std::string& text, const std::string& file, int line, const std::string& timeStamp );
    NHILL_LOG_PORT_FUNCTION void warn ( const std::string& text, const std::string& file, int line, const std::string& timeStamp );
    NHILL_LOG_PORT_FUNCTION void info ( const std::string& text, const std::string& file, int line, const std::string& timeStamp );
    NHILL_LOG_PORT_FUNCTION void debug( const std::string& text, const std::string& file, int line, const std::string& timeStamp );
#pragma endregion
}
}
