#pragma once

#include <type_traits>
#include <functional>

// https://stackoverflow.com/questions/8368512/does-c11-have-c-style-properties

// See http://www.cplusplus.com/forum/general/8147/
// for an example of how to pass the classes own get/set methods to the property

namespace gs
{

template<class Value_base, class Host>
class Property
{
private:
   using Getter = Value_base (Host::*)() const;
   using Setter = void (Host::*)( const Value_base& );

public:
   Property(Host& host, Getter get, Setter set)
      : host{host}, get{get}, set{set}
   { }

public:
   operator Value_base() const { return (host.*get)(); }
   void operator=(const Value_base& value) { (host.*set)(value); }

private:
   Host& host;
   Getter get;
   Setter set;
};


template<class Value_base, class Host>
class Property_readonly
{
private:
   using Getter = Value_base(Host::*)() const;

public:
   Property_readonly( const Host& host, Getter get)
      : host{host}, get{get}
   {
   }

public:
   operator Value_base() const { return (host.*get)(); }

private:
   const Host& host;
   Getter get;
};




/// <summary>A template to mimic the functionality of a property.</summary>
/// <example>To define a property:
/// <code>
/// gs::property float > x;
/// </code>
/// </example>
/// <example>To implement a user_control getter/setter just inherit:
/// <code>
/// class : public gs::property&lt;float&gt; {
/// virtual float & operator = (const float &f) { /*user_control code*/ return _value = f; }
/// virtual operator float const & () const { /*user_control code*/ return _value; }
/// } y;
/// </code>
/// </example>
template<typename T>
class Prop
{
public:
public:
   virtual ~Prop() {}
   virtual T & operator = (const T &val) { return value = val; }
   virtual operator T const & () const { return value; }
private:
   T value;
};

template <typename T>
/// <summary>A template to mimic the functionality of a read-only property.</summary>
/// <example>to use it in class 'Owner':
/// <code>
/// class Owner
/// {
/// public:
/// 	class : public gs::property_readonly&lt;float&gt; { friend class Owner; } x;
/// 	Owner() { x = 8.3f; }
/// };
/// </code>
/// </example>
class Prop_readonly
{
public:
   virtual ~Prop_readonly() {}
protected:
   virtual T & operator = (const T &val) { return value = val; }
public:
   virtual operator T const & () const { return value; }
private:
   T value;
};

}
