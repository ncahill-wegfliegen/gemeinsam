#pragma once

#include "port.h"
#include <vector>
#include <memory>
#include <string>

namespace nhill
{

class Version;

namespace version
{

class String_table;

class NHILL_VERSION_PORT_CLASS Info final
{
public:
   Info();
   Info( const std::string& path_module );
   Info( const Info& );
   Info& operator=( const Info& );
   Info( Info&& ) noexcept;
   Info& operator=( Info&& ) noexcept;
   ~Info();

   const Version& file_version   () const;
   const Version& product_version() const;
   unsigned long  file_flag_mask () const; // versrc.h VS_FF_...
   unsigned long  file_flags     () const; // versrc.h VS_FF_...
   unsigned long  file_os        () const; // versrc.h VSO_...
   unsigned long  file_type      () const; // versrc.h VFT_...
   unsigned long  file_subtype   () const; // versrc.h VFT2_...

   void clear();
   void load( const std::string& path_module );
   void add( const String_table& string_table );
   const std::vector<String_table>& string_tables() const;

   bool is_flag_masked  ( unsigned long flag ) const; // versrc.h VS_FF_...
   bool is_flag_unmasked( unsigned long flag ) const; // versrc.h VS_FF_...
   bool is_flag_set     ( unsigned long flag ) const; // versrc.h VS_FF_...

private:
   #pragma warning(suppress:4251)
   std::unique_ptr<Version> file_version_;

   #pragma warning(suppress:4251)
   std::unique_ptr<Version> product_version_;

   unsigned long file_flag_mask_;
   unsigned long file_flags_;
   unsigned long file_os_;
   unsigned long file_type_;
   unsigned long file_subtype_;

   #pragma warning(suppress:4251)
   std::vector<String_table> string_tables_;
};

}
}

