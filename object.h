#pragma once

#include <string>

namespace nhill
{

class Object
{
public:
	Object();

	Object( const Object& );
	Object& operator=( const Object& );

	Object( Object&& ) noexcept;
	Object& operator=( Object&& ) noexcept;

	virtual ~Object();

	virtual std::string to_string() const = 0;
};

}

#pragma region Definitions

inline nhill::Object::Object() = default;

inline nhill::Object::Object( const Object& ) = default;
inline auto nhill::Object::operator=( const Object& )->Object & = default;

inline nhill::Object::Object( Object&& ) noexcept = default;
inline auto nhill::Object::operator=( Object&& ) noexcept->Object & = default;

inline nhill::Object::~Object() = default;

inline std::string nhill::Object::to_string() const
{
	return "Object";
}
#pragma endregion

