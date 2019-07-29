#pragma once

#include "port.h"
#include "arcdegree.h"
#include "arcminute.h"
#include "arcsecond.h"
#include "milliarcsecond.h"
#include "degree.h"
#include <string>
#include <string_view>

namespace nhill
{

   class NHILL_GMTRY_PORT_CLASS Latitude
   {
   public:
#pragma region Aliases
      using Sign = nhill::math::Sign;
      using Arcdegree = nhill::Arcdegree<Adjust_arcdegree_c0_90c>;
      template<typename T> using Degree = nhill::geometry::Degree<T>;
#pragma endregion

#pragma region Enumerations
      enum class Direction : int8_t
      {
         S = -1, // South
         N = +1, // North
      };
#pragma endregion

#pragma region Constructors, Assignments, Constructor
      Latitude();
      Latitude(Direction dir, const Arcdegree& arcdeg, const Arcminute& arcmin, const Arcsecond& arcsec, const Milliarcsecond& marcsec = {});

      Latitude(const Latitude&);
      Latitude& operator=(const Latitude&);

      Latitude(Latitude&&) noexcept;
      Latitude& operator=(Latitude &&) noexcept;

      ~Latitude();
#pragma endregion

#pragma region Properties
      const      Direction& direction() const;
      const      Arcdegree& arcdegree() const;
      const      Arcminute& arcminute() const;
      const      Arcsecond& arcsecond() const;
      const Milliarcsecond& milliarcsecond() const;
#pragma endregion

#pragma region Methods
      void set(Direction dir, const Arcdegree& arcdeg, const Arcminute& arcmin, const Arcsecond& arcsec, const Milliarcsecond& marcsec = {});
      void clear();
      template<typename T> Degree<T> to_degree() const;
      std::string to_string() const;
#pragma endregion

   private:
#pragma region Data Members
      Direction dir_;
#pragma warning(suppress:4251)
      Arcdegree arcdeg_;
      Arcminute arcmin_;
      Arcsecond arcsec_;
      Milliarcsecond marcsec_;
#pragma endregion
   };

}

namespace nhill
{

   NHILL_GMTRY_PORT_FUNCTION Latitude operator+(const Latitude& a, const Latitude& b);
   NHILL_GMTRY_PORT_FUNCTION Latitude operator-(const Latitude& a, const Latitude& b);

}

namespace nhill
{

   NHILL_GMTRY_PORT_FUNCTION Latitude to_latitude_s(unsigned arcdeg, unsigned arcmin, unsigned arcsec, unsigned marcsec = 0);
   NHILL_GMTRY_PORT_FUNCTION Latitude to_latitude_n(unsigned arcdeg, unsigned arcmin, unsigned arcsec, unsigned marcsec = 0);
   NHILL_GMTRY_PORT_FUNCTION Latitude to_latitude(std::string_view str);
   template<typename T> Latitude to_latitude(const nhill::geometry::Degree<T>& deg, bool calc_marcsec = true)
   {
      using Direction = Latitude::Direction;
      using Arcdeg_t = Latitude::Arcdegree::value_type;
      using Arcmin_t = Arcminute::value_type;
      using Arcsec_t = Arcsecond::value_type;
      using Marcsec_t = Milliarcsecond::value_type;

      Latitude::Arcdegree::adjust_type adjust;

      Direction dir{ Latitude::Direction::N };
      Arcdeg_t arcdeg{ 0 };
      Arcmin_t arcmin{ 0 };
      Arcsec_t arcsec{ 0 };
      Marcsec_t marcsec{ 0 };

      // Determine the direction
      T value{ static_cast<T>(deg.value()) };
      if (math::less<T, uint8_t>(value, 0))
      {
         dir = Latitude::Direction::S;
      }
      value = std::abs(value);

      // Determine the arcdegree
      // The integer part
      uint64_t valuei{ static_cast<uint64_t>(std::floor(value)) };
      arcdeg = static_cast<Arcdeg_t>(adjust(valuei));

      // Determine the arcminutes
      // The fractional part
      value -= static_cast<T>(valuei);
      // The value as decimal arcminutes
      value *= static_cast<T>(60);
      // The arminutes
      arcmin = static_cast<Arcmin_t>(std::floor(value));

      // Determine the arcseconds
      // The fractional part
      value -= static_cast<T>(arcmin);
      // The value as decimal arcseconds
      value *= static_cast<T>(60);
      // The arcseconds
      if (calc_marcsec)
      {
         arcsec = static_cast<Arcsec_t>(std::floor(value));
      }
      else
      {
         arcsec = static_cast<Arcsec_t>(std::round(value));
      }

      if (calc_marcsec)
      {
         // Determine the milliarcseconds
         // The fractional part
         value -= static_cast<T>(arcsec);
         // The value as decimal milliarcseconds
         value *= static_cast<T>(1000);
         // The milliarcseconds
         marcsec = static_cast<Marcsec_t>(std::round(value));
      }

      // The longitude
      return { dir, arcdeg, arcmin, arcsec, marcsec };
   }
   template<typename T> nhill::geometry::Degree<T> to_degree(const Latitude& lon)
   {
      T arcdeg{ static_cast<T> (lon.arcdegree().value()) };
      T arcmin{ static_cast<T> (lon.arcminute().value()) };
      T arcsec{ static_cast<T> (lon.arcsecond().value()) };
      T arcmsec{ static_cast<T>(lon.milliarcsecond().value()) };

      T div_arcmin{ static_cast<T>(60) };
      T div_arcsec{ div_arcmin*static_cast<T>(60) };
      T div_marcsec{ div_arcsec*static_cast<T>(1000) };

      T deg{ arcdeg + arcmin / div_arcmin + arcsec / div_arcsec + arcmsec / div_marcsec };

      if (lon.direction() == Latitude::Direction::S)
      {
         deg *= static_cast<T>(-1);
      }

      return geometry::Degree<T>{deg};
   }
   NHILL_GMTRY_PORT_FUNCTION char to_char(Latitude::Direction dir);
   NHILL_GMTRY_PORT_FUNCTION std::string to_string(const Latitude& lon);
}

template<typename T> inline
auto nhill::Latitude::to_degree() const->Degree<T>
{
   return nhill::to_degree<T>(*this);
}
