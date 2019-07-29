#include "log.h"
#include "..\utility\str.h"
#include <algorithm>
#include <cctype>
#include <iomanip>
#include <ctime>
#include <filesystem>
#include <fstream>
#include <map>

//namespace filesys = std::experimental::filesystem::v1;
namespace filesys = std::filesystem;
using namespace std;

nhill::log::Level& nhill::log::level()
{
   // Create an instance that is common throughout the thread;
   // i.e., the exe and all dlls will use this same instance.
   static Level level_;
   return level_;
}

string& nhill::log::path()
{
   // Create an instance that is common throughout the thread;
   // i.e., the exe and all dlls will use this same instance.
   static string path_ = "";
   return path_;
}

namespace nhill
{
namespace log
{

static bool is_on( Level level )
{
   return level <= log::level();
}

static void output( Level level, const string& text, const string& file, int line, const string& time_stamp )
{
   static const map<Level, string> levels{
      { Level::fatal, "FATAL" },
      { Level::error, "ERROR" },
      { Level::warn ,  "WARN" },
      { Level::info ,  "INFO" },
      { Level::debug, "DEBUG" },
   };

   ofstream ofs( path(), ios_base::out | ios_base::app );

   ofs << time_stamp;
   ofs << " " << setw( 5 ) << left << levels.at(level);
   ofs << " " << file;
   ofs << ":" << line;
   ofs << "\t" << text;
   ofs << endl;

   ofs.close();
}

static void output_time_stamp( const string& text )
{
   time_t t = time( 0 );   // get time now
   struct tm  tmstruct;
   localtime_s( &tmstruct, &t );
   char now[256] = {'\0'};
   strftime( now, _countof( now ), "%a %b %d %H:%M:%S %Y", &tmstruct );

   ofstream ofs( path(), ios_base::out | ios_base::app );

   ofs << text << " ";
   ofs << now;
   ofs << endl;

   ofs.close();
}

static void output_header()
{
   if( level() == Level::off )
      return;

   output_time_stamp( "[HEADER]" );
}

static void output_footer()
{
   if( level() == Level::off )
      return;

   output_time_stamp( "[FOOTER]" );
}

}
}

void nhill::log::initialize( Level level, const string& path )
{
   log::level() = level;
   log::path () = path;

   // Delete the existing log file.
   filesys::remove( path );

   // Ouput the header to the log file.
   output_header();
}

void nhill::log::finalize()
{
   output_footer();
}

void nhill::log::fatal( const string& text, const string& file, int line, const string& time_stamp )
{
   if( is_on( Level::fatal ) )
   {
      output( Level::fatal, text, file, line, time_stamp );
   }
}

void nhill::log::error( const string& text, const string& file, int line, const string& time_stamp )
{
   if( is_on( Level::error ) )
   {
      output( Level::error, text, file, line, time_stamp );
   }
}

void nhill::log::warn( const string& text, const string& file, int line, const string& time_stamp )
{
   if( is_on( Level::warn ) )
   {
      output( Level::warn, text, file, line, time_stamp );
   }
}

void nhill::log::info( const string& text, const string& file, int line, const string& time_stamp )
{
   if( is_on( Level::info ) )
   {
      output( Level::info, text, file, line, time_stamp );
   }
}

void nhill::log::debug( const string& text, const string& file, int line, const string& time_stamp )
{
   if( is_on( Level::debug ) )
   {
      output( Level::debug, text, file, line, time_stamp );
   }
}
