#pragma once

#include "port.h"
#include "som.h"
#include <vector>
#include <string>

namespace nhill
{
namespace som
{

class Observer;
class Changed_event_args;

/// <summary>A singleton class to manage the current value for the system of measurement.
/// <para>This class also acts a subject, notifying all attached observers when the system of measurement changes.</para>
/// </summary>
class NHILL_SOM_PORT_CLASS Subject final
{
#pragma region Instance
public:
   static Subject& instance()
   {
      static Subject instance;
      return instance;
   }
#pragma endregion

#pragma region Constructors/Destructor
protected:
    Subject();
public:
    ~Subject();
#pragma endregion

#pragma region Properties
public:
    System_of_measurement current() const;
    /// <summary>All observers will be notified when the system of measurement is set.</summary>
    void current( System_of_measurement value );
    bool is_metric() const;
    bool is_api() const;
#pragma endregion

#pragma region Methods
public:
    void attach( Observer* observer );
    void detach( Observer* observer );
#pragma endregion

#pragma region Private Methods
protected:
    /// <summary>The notification is sent from within the SetCurrent property.</summary>
    void notify_system_of_measurement_changed( const std::string& sender, const Changed_event_args& event_args ) const;
#pragma endregion

#pragma region Fields
private:
   #pragma warning(suppress: 4251)
    std::vector<Observer*> observers_;
    System_of_measurement current_;
#pragma endregion
};

}
}