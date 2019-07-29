#pragma once

#include "str.h"
#include <filesystem>
#include <regex>

namespace nhill
{
namespace file
{

/// <summary>Append a separator to the directory if it does not already end with one.</summary>
/// <param name="dir">The directory to which the separator is appended.</param>
/// <returns>A reference to the input directory.</returns>
template<typename Char>
std::basic_string<Char>& append_preferred_separator( std::basic_string<Char>& dir )
{
   // Directory is empty
   if( nhill::str::is_empty( dir ) )
      return dir;

   // Truncate the directory string so the back character is non-null
   nhill::str::truncate<Char>( dir );

   // The back character of the string
   Char& back = dir.back();

   // If the back character is a slash
   if( back == nhill::chr::slash<Char>() )
   {
      if( nhill::chr::preferred_file_separator<Char>() != nhill::chr::slash<Char>() )
      {
         back = nhill::chr::preferred_file_separator<Char>();
      }
      return dir;
   }

   // If the back character is a backslash
   if( back == nhill::chr::backslash<Char>() )
   {
      if( nhill::chr::preferred_file_separator<Char>() != nhill::chr::backslash<Char>() )
      {
         back = nhill::chr::preferred_file_separator<Char>();
      }
      return dir;
   }

   // The back character is not a separator
   // Add the preferred separator to the back of the string
   dir.push_back( nhill::chr::preferred_file_separator<Char>() );

   return dir;
}

/// <summary>Append a separator to the directory if it does not already end with one.</summary>
/// <param name="dir">The directory to which the separator is appended.</param>
/// <returns>A copy of the directory with a separator appended.</returns>
template<typename Char>
std::basic_string<Char> append_preferred_separator_copy( std::basic_string<Char> dir )
{
   return nhill::file::append_preferred_separator( dir );
}

template<typename Char>
std::basic_string<Char>& convert_to_preferred_separator( std::basic_string<Char>& path )
{
   for( auto&& c : path )
   {
      if( c == nhill::chr::slash<Char>() || c == nhill::chr::backslash<Char>() )
      {
         c = nhill::chr::preferred_file_separator<Char>();
      }
   }

   return path;
}

template<typename Char>
std::basic_string<Char> convert_to_preferred_separator_copy( std::basic_string<Char> path )
{
   return nhill::file::convert_to_preferred_separator( path );
}

template<typename Char>
std::basic_string<Char> build_name( const std::basic_string<Char>& title, const std::basic_string<Char>& ext )
{
   std::basic_ostringstream<Char> oss;

   oss << title;

   if( ext.front() != nhill::chr::period<Char>() )
   {
      oss << nhill::chr::period<Char>();
   }

   oss << ext;

   return oss.str();
}

template<typename Char, std::size_t N>
std::basic_string<Char> build_name( const Char( &title )[N], const std::basic_string<Char>& ext )
{
   return nhill::file::build_name<Char>( std::basic_string<Char>( title ), ext );
}

template<typename Char, std::size_t M>
std::basic_string<Char> build_name( const std::basic_string<Char>& title, const Char( &ext )[M] )
{
   return nhill::file::build_name<Char>( title, std::basic_string<Char>( ext ) );
}

template<typename Char, size_t N, size_t M>
std::basic_string<Char> build_name( const Char( &title )[N], const Char( &ext )[M] )
{
   return nhill::file::build_name<Char>( std::basic_string<Char>( title ), std::basic_string<Char>( ext ) );
}

template<typename Char>
std::basic_string<Char> build_path( std::basic_string<Char> dir, const std::basic_string<Char>& name )
{
   std::basic_ostringstream<Char> oss;
   oss << nhill::file::append_preferred_separator( nhill::file::convert_to_preferred_separator( dir ) ) << name;
   return oss.str();
}

template<typename Char>
std::basic_string<Char> build_path( const std::basic_string<Char>& dir, const std::basic_string<Char>& title, const std::basic_string<Char>& ext )
{
   return nhill::file::build_path( dir, nhill::file::build_name( title, ext ) );
}

template<typename Char>
std::basic_string<Char> build_dir( std::basic_string<Char> dir_base, std::basic_string<Char> dir_sub )
{
   std::basic_ostringstream<Char> oss;
   oss << nhill::file::append_preferred_separator( nhill::file::convert_to_preferred_separator( dir_base ) ) << nhill::file::append_preferred_separator( nhill::file::convert_to_preferred_separator( dir_sub ) );
   return oss.str();
}

template<typename Char>
std::basic_string<Char> get_dir( const std::basic_string<Char> & path )
{
   namespace fs = std::filesystem;
   fs::path fspath{path};
   std::basic_string<Char> dir{fspath.parent_path().generic_string<Char>()};
   return nhill::file::append_preferred_separator( nhill::file::convert_to_preferred_separator( dir ) );
}

template<typename Char>
std::basic_string<Char> get_title( const std::basic_string<Char>& path )
{
   namespace fs = std::filesystem;
   fs::path fspath{path};
   return fspath.has_stem() ? fspath.stem().generic_string<Char>() : std::basic_string<Char>();
}

template<typename Char>
std::basic_string<Char> get_name( const std::basic_string<Char>& path )
{
   namespace fs = std::filesystem;
   fs::path fspath{path};
   return fspath.has_filename() ? fspath.filename().generic_string<Char>() : std::basic_string<Char>();
}

template<typename Char>
std::basic_string<Char> get_subdir( const std::basic_string<Char>& path )
{
   namespace fs = std::filesystem;

   fs::path fspath{path};
   std::basic_string<Char> sub_dir;
   if( fs::is_directory( fspath ) )
   {
      sub_dir = fspath.generic_string<Char>();
   }
   else
   {
      sub_dir = fspath.parent_path().generic_string<Char>();
   }
   nhill::file::convert_to_preferred_separator( sub_dir );

   if( sub_dir.length() == 0 )
      return sub_dir;

   Char sep = nhill::chr::preferred_file_separator<Char>();
   if( sub_dir.back() == sep )
   {
      sub_dir.erase( sub_dir.end() - 1 );
   }

   if( sub_dir.length() == 0 )
      return sub_dir;

   auto pos = sub_dir.find_last_of( sep );
   if( pos == std::basic_string<Char>::npos )
      return sub_dir;

   sub_dir = sub_dir.substr( pos + 1 );

   return sub_dir;
}

template<typename Char>
bool exists( const std::basic_string<Char>& path )
{
   namespace fs = std::filesystem;
   return fs::exists( path );
}

template<typename Char>
bool remove( const std::basic_string<Char>& path )
{
   namespace fs = std::filesystem;
   return fs::remove( path );
}

/// <summary>Delete a collection of files.</summary>
/// <param name="paths">The collection of full paths of files to be deleted.</param>
/// <returns>The number of files deleted.</returns>
template<typename Char>
int remove( const std::vector<std::basic_string<Char>>& paths, std::vector<std::basic_string<Char>>* paths_removed = nullptr )
{
   if( paths_removed != nullptr )
   {
      paths_removed->clear();
   }

   int count = 0;
   for( const auto& path : paths )
   {
      if( nhill::file::remove( path ) )
      {
         ++count;

         if( paths_removed != nullptr )
         {
            paths_removed->push_back( path );
         }
      }
   }

   return count;
}

/// <summary>Delete all of the files in the directory that follow the given pattern.</summary>
/// <param name="dir">The directory in which the files are located.</param>
/// <param name="name_pattern">The wildcard pattern for the file names to delete; e.g. "MyFile*.txt".</param>
/// <param name="paths_removed">Out. Optional.  The collection of paths that were deleted.</param>
/// <returns>The number of files deleted.</returns>
template<typename Char>
int remove( const std::basic_string<Char>& dir, const std::basic_string<Char>& name_pattern, std::vector<std::basic_string<Char>>* paths_removed = nullptr )
{
   // Find all of the full paths in the directory that match the pattern
   std::vector<std::basic_string<Char>> paths = nhill::file::find_paths( dir, name_pattern );
   return nhill::file::remove( paths, paths_removed );
}

/// <summary>Find all of the file names in the given directory.</summary>
/// <param name="dir">The directory to search.</param>
/// <returns>A collection of all of the file names found in the directory (i.e., file name = file title + extension).</returns>
template<typename Char>
std::vector<std::basic_string<Char>> find_names( const std::basic_string<Char>& dir )
{
   namespace fs = std::filesystem;

   std::vector<std::basic_string<Char>> names;
   for( const auto& entry : fs::directory_iterator( dir ) )
   {
      const fs::path& path = entry.path();
      if( !fs::is_directory( path ) )
      {
         names.push_back( path.filename().generic_string<Char>() );
      }
   }

   return names;
}

template<typename Char>
std::vector<std::basic_string<Char>> find_names_by_extension( const std::basic_string<Char>& dir, std::basic_string<Char> ext )
{
   namespace fs = std::filesystem;

   // Adjust the extension, if necessary, so that it begins with a period.
   // This makes it easier to compare because fs::path::extension() returns the extension with the period.
   if( 0 < ext.size() && ext.front() != nhill::chr::period<Char>() )
   {
      ext.insert( ext.begin(), nhill::chr::period<Char>() );
   }

   std::vector<std::basic_string<Char>> names;
   for( const auto& entry : fs::directory_iterator( dir ) )
   {
      const fs::path& path = entry.path();
      if( path.has_filename() && path.has_extension() )
      {
         // The current extension
         std::basic_string<Char> ext_cur = path.extension().generic_string<Char>();
         // If the current extension matches the given extension,
         // then add the current file name to the collection
         if( ext_cur.compare( ext ) == 0 )
         {
            names.push_back( path.filename().generic_string<Char>() );
         }
      }
   }

   return names;
}

template<typename Char>
std::vector<std::basic_string<Char>> find_names_by_pattern( const std::basic_string<Char>& dir, const std::basic_string<Char>& name_pattern )
{
   namespace fs = std::filesystem;

   std::vector<std::basic_string<Char>> names;
   std::basic_regex<Char> filter{name_pattern};
   std::match_results<typename std::basic_string<Char>::const_iterator> matches;

   for( const auto& entry : fs::directory_iterator( dir ) )
   {
      const fs::path& path = entry.path();
      if( path.has_filename() )
      {
         std::basic_string<Char> name = entry.path().filename().generic_string<Char>();
         if( std::regex_match( name, matches, filter ) )
         {
            names.push_back( name );
         }
      }
   }

   return names;
}

/// <summary>Find all of the files in the given directory.</summary>
/// <param name="dir">The directory to search.</param>
/// <returns>A collection of all of the file paths found in the directory.</returns>
template<typename Char>
std::vector<std::basic_string<Char>> find_paths( const std::basic_string<Char>& dir )
{
   namespace fs = std::filesystem;

   std::vector<std::basic_string<Char>> names;
   for( const auto& entry : fs::directory_iterator( dir ) )
   {
      const fs::path& path = entry.path();
      if( !fs::is_directory(path) )
      {
         names.push_back( nhill::file::convert_to_preferred_separator( entry.path().generic_string<Char>() ));
      }
   }

   return names;
}

template<typename Char>
std::vector<std::basic_string<Char>> find_paths_by_extension( const std::basic_string<Char>& dir, std::basic_string<Char> ext )
{
   namespace fs = std::filesystem;

   // Adjust the extension, if necessary, so that it begins with a period.
   // This makes it easier to compare because fs::path::extension() returns the extension with the period.
   if( 0 < ext.size() && ext.front() != nhill::chr::period<Char>() )
   {
      ext.insert( ext.begin(), nhill::chr::period<Char>() );
   }

   std::vector < std::basic_string<Char>> names;
   for( const auto& entry : fs::directory_iterator( dir ) )
   {
      const fs::path& path = entry.path();
      if( path.has_extension() )
      {
         // The current extension
         std::basic_string<Char> ext_cur = path.extension().generic_string<Char>();
         // If the current extension matches the given extension,
         // then add the current file name to the collection
         if( ext_cur.compare( ext ) == 0 )
         {
            names.push_back( nhill::file::convert_to_preferred_separator( path.generic_string<Char>() ) );
         }
      }
   }

   return names;
}

template<typename Char>
std::vector<std::basic_string<Char>> find_paths_by_pattern( const std::basic_string<Char>& dir, const std::basic_string<Char>& name_pattern )
{
   namespace fs = std::filesystem;

   std::vector<std::basic_string<Char>> names;
   std::basic_regex<Char> filter{name_pattern};
   std::match_results<typename std::basic_string<Char>::const_iterator> matches;

   for( const auto& entry : fs::directory_iterator( dir ) )
   {
      const fs::path& path = entry.path();
      if( path.has_filename() )
      {
         std::basic_string<Char> name = entry.path().filename().generic_string<Char>();
         if( std::regex_match( name, matches, filter ) )
         {
            names.push_back( nhill::file::convert_to_preferred_separator( path.generic_string<Char>() ) );
         }
      }
   }

   return names;
}

template<typename Char>
std::vector<std::basic_string<Char>> find_subdirs( const std::basic_string<Char>& dir )
{
   namespace fs = std::filesystem;

   std::vector<std::basic_string<Char>> sub_dirs;
   for( const auto& entry : fs::directory_iterator( dir ) )
   {
      const fs::path& path = entry.path();
      if( fs::is_directory( path ) )
      {
         std::basic_string<Char> sub_dir = get_subdir( path.generic_string<Char>() );
         if( 0 < sub_dir.length() )
         {
            sub_dirs.push_back( sub_dir );
         }
      }
   }

   return sub_dirs;
}

template<typename Char>
std::basic_string<Char> temp_directory()
{
   namespace fs = std::filesystem;
  
   fs::path fs_path = fs::temp_directory_path();
   return fs_path.generic_string<Char>();
}

template<typename Char>
bool contains_invalid_char( const std::basic_string<Char>& path, Char* invalid_char = nullptr )
{
   static const std::basic_string<Char> invalid_chars{
       0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 
      10, 11, 12, 13, 14, 15, 16, 17, 18, 19,
      20, 21, 22, 23, 24, 25, 26, 27, 28, 29,
      30, 31,
      chr::angle_bra<Char>(),
      chr::angle_ket<Char>(),
      chr::colon<Char>(),
      chr::quote<Char>(),
      chr::slash<Char>(),
      chr::backslash<Char>(),
      chr::pipe<Char>(),
      chr::question_mark<Char>(),
      chr::asterisk<Char>()
   };

   using Pos = typename std::basic_string<Char>::size_type;
   static constexpr auto npos = std::basic_string<Char>::npos;

   for( Char c : invalid_chars )
   {
      Pos pos = path.find( c );
      if( pos != npos )
      {
         if( invalid_char != nullptr )
         {
            *invalid_char = c;
         }
         return false;
      }
   }

   return true;
}

}
}