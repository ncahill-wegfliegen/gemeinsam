#include <windows.h>
#include "info.h"
#include "string_table.h"
#include "translation.h"
#include "version.h"
#include "..\utility\file.h"
#include "..\utility\exception\file_not_found.h"
#include "..\enum\core\values.h"
#include <sstream>


namespace
{

std::string last_error()
{
   //Get the error message, if any.
   DWORD error_message_id = ::GetLastError();
   if( error_message_id == 0 )
      return std::string(); //No error message has been recorded

   LPSTR message_buffer = nullptr;
   size_t size = ::FormatMessageA( FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
      NULL, error_message_id, MAKELANGID( LANG_NEUTRAL, SUBLANG_DEFAULT ), (LPSTR)&message_buffer, 0, NULL );

   std::string message( message_buffer, size );

   //Free the buffer.
   ::LocalFree( message_buffer );

   return message;
}

}

nhill::version::Info::Info()
   : file_version_{ std::make_unique<Version>() }
   , product_version_{ std::make_unique<Version>() }
   , file_flag_mask_{ 0UL }
   , file_flags_{ 0UL }
   , file_os_{ 0UL }
   , file_type_{ 0UL }
   , file_subtype_{ 0UL }
{
}

nhill::version::Info::Info( const std::string & path_module )
{
   load( path_module );
}

nhill::version::Info::Info( const Info & other )
   : file_version_{ std::make_unique<Version>( *other.file_version_ ) }
   , product_version_{ std::make_unique<Version>(*other.product_version_) }
   , file_flag_mask_{ other.file_flag_mask_ }
   , file_flags_{ other.file_flags_ }
   , file_os_{ other.file_os_ }
   , file_type_{ other.file_type_ }
   , file_subtype_{ other.file_subtype_ }
{
}

auto nhill::version::Info::operator=( const Info& other )->Info &
{
   file_version_ = std::make_unique<Version>( *other.file_version_ );
   product_version_ = std::make_unique<Version>( *other.product_version_ );
   file_flag_mask_ = other.file_flag_mask_;
   file_flags_ = other.file_flags_;
   file_os_ = other.file_os_;
   file_type_ = other.file_type_;
   file_subtype_ = other.file_subtype_;

   return *this;
}


nhill::version::Info::Info( Info && ) noexcept = default;
auto nhill::version::Info::operator=( Info&& ) noexcept->Info & = default;

nhill::version::Info::~Info() = default;

auto nhill::version::Info::file_version() const->const Version&
{
   return *file_version_;
}

auto nhill::version::Info::product_version() const->const Version&
{
   return *product_version_;
}

unsigned long nhill::version::Info::file_flag_mask() const
{
   return file_flag_mask_;
}

unsigned long nhill::version::Info::file_flags() const
{
   return file_flags_;
}

unsigned long nhill::version::Info::file_os() const
{
   return file_os_;
}

unsigned long nhill::version::Info::file_type() const
{
   return file_type_;
}

unsigned long nhill::version::Info::file_subtype() const
{
   return file_subtype_;
}

void nhill::version::Info::clear()
{
   file_version_->clear();
   product_version_->clear();
   file_flag_mask_ = 0UL;
   file_flags_ = 0UL;
   file_os_ = 0UL;
   file_type_ = 0UL;
   file_subtype_ = 0UL;

   string_tables_.clear();
}

void nhill::version::Info::load( const std::string & path_module )
{
   // http://stackoverflow.com/questions/316626/how-do-i-read-from-a-version-resource-in-visual-c

   using namespace std;

   static const map<Info_item, string> item_labels{
      { Info_item::comments          , "Comments"         },
      { Info_item::company_name      , "CompanyName"      },
      { Info_item::file_description  , "FileDescription"  },
      { Info_item::file_version      , "FileVersion"      },
      { Info_item::internal_name     , "InternalName"     },
      { Info_item::legal_copyright   , "LegalCopyright"   },
      { Info_item::legal_trademarks  , "LegalTrademarks"  },
      { Info_item::original_filename , "OriginalFilename" },
      { Info_item::private_build     , "PrivateBuild"     },
      { Info_item::product_name      , "ProductName"      },
      { Info_item::product_version   , "ProductVersion"   },
      { Info_item::special_build     , "SpecialBuild"     },
   };

   clear();

   // Make sure that the file exists
   if( !file::exists( path_module ) )
   {
      ostringstream msg;
      msg << "Error (" << ::GetLastError() << ") " << last_error() << ": The file " << path_module << " does not exist.";
      //LOG_ERROR( msg.str() );
      throw File_not_found( msg.str() );
   }

   // Get the size of the file's version information
   DWORD version_info_size = ::GetFileVersionInfoSizeA( path_module.c_str(), NULL );
   if( version_info_size == 0 )
   {
      ostringstream msg;
      msg << "Error (" << ::GetLastError() << ") " << last_error() << ": Failed to get the size of the version information for the file " << path_module << ".";
      //LOG_ERROR( msg.str() );
      throw runtime_error( msg.str() );
   }

   // Allocate a buffer to hold the version information
   LPBYTE version_info = new BYTE[version_info_size];

   // Load the raw version info.
   if( !::GetFileVersionInfoA( path_module.c_str(), NULL, version_info_size, version_info ) )
   {
      delete[] version_info;
      std::ostringstream msg;
      msg << "Error (" << ::GetLastError() << ") " << last_error() << ": Failed to get the version information for the file " << path_module << ".";
      //LOG_ERROR( msg.str() );
      throw runtime_error( msg.str() );
   }

   // The fixed file information
   VS_FIXEDFILEINFO*  fixed_info = nullptr;
   UINT fixed_info_size = 0;
   if( !::VerQueryValueA( version_info, "\\", (LPVOID*)&fixed_info, &fixed_info_size ) )
   {
      delete[] version_info;
      std::ostringstream msg;
      msg << "Error (" << ::GetLastError() << ") " << last_error() << ": Failed to get the fixed information for the file " << path_module << ".";
      //LOG_ERROR( msg.str() );
      throw runtime_error( msg.str() );
   }

   WORD major = HIWORD( fixed_info->dwFileVersionMS );
   WORD minor = LOWORD( fixed_info->dwFileVersionMS );
   WORD build = HIWORD( fixed_info->dwFileVersionLS );
   WORD revision = LOWORD( fixed_info->dwFileVersionLS );
   *file_version_ = { major, minor, build, revision };

   major = HIWORD( fixed_info->dwProductVersionMS );
   minor = LOWORD( fixed_info->dwProductVersionMS );
   build = HIWORD( fixed_info->dwProductVersionLS );
   revision = LOWORD( fixed_info->dwProductVersionLS );
   *product_version_ = { major, minor, build, revision };

   file_flag_mask_ = fixed_info->dwFileFlagsMask;
   file_flags_ = fixed_info->dwFileFlags;
   file_os_ = fixed_info->dwFileOS;
   file_type_ = fixed_info->dwFileType;
   file_subtype_ = fixed_info->dwFileSubtype;

   // The variable file information
   Translation* translation = nullptr;
   UINT translation_size = 0;
   if( !::VerQueryValueA( version_info, R"(\VarFileInfo\Translation)", (LPVOID*)&translation, &translation_size ) )
   {
      delete[] version_info;
      std::ostringstream msg;
      msg << "Error (" << ::GetLastError() << ") " << last_error() << ": Failed to get the translation value for the variable file information for the file " << path_module << ".";
      //LOG_ERROR( msg.str() );
      throw runtime_error( msg.str() );
   }
   // The number of translations
   std::size_t translation_count = translation_size / sizeof( Translation );

   // There is a string table for each translation 
   for( std::size_t i = 0 ; i < translation_count ; ++i )
   {
      // The string file information
      ostringstream sub_block_base;
      sub_block_base << "\\StringFileInfo\\" << translation[i] << "\\";

      String_table string_table;
      string_table.translation( translation[i] );

      // Each item in the string table
      for( Info_item item : Values<Info_item>( Info_item::none ) )
      {
         ostringstream sub_block;
         sub_block << sub_block_base.str() << item_labels.at( item );
  
         LPVOID buffer = nullptr;
         UINT buffer_size = 0;

         if( ::VerQueryValueA( version_info, sub_block.str().c_str(), &buffer, &buffer_size ) )
         {
            string_table.set( item, (LPCSTR)buffer );
         }
      }

      add( string_table );
   }

   delete[] version_info;
   version_info = nullptr;
}

void nhill::version::Info::add( const String_table & string_table )
{
   string_tables_.push_back( string_table );
}

auto nhill::version::Info::string_tables() const->const std::vector<String_table>&
{
   return string_tables_;
}

bool nhill::version::Info::is_flag_masked( unsigned long flag ) const
{
   return (file_flag_mask_ & flag) != flag;
}

bool nhill::version::Info::is_flag_unmasked( unsigned long flag ) const
{
   return (file_flag_mask_ & flag) == flag;
}

bool nhill::version::Info::is_flag_set( unsigned long flag ) const
{
   return (file_flags_ & flag) == flag;
}
