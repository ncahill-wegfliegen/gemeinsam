#include "event_args.h"

nhill::Event_args::Event_args() = default;

nhill::Event_args::Event_args(const Event_args &) = default;
auto nhill::Event_args::operator=(const Event_args &)->Event_args & = default;

nhill::Event_args::Event_args(Event_args &&) noexcept = default;
auto nhill::Event_args::operator=(Event_args &&) noexcept->Event_args & = default;

nhill::Event_args::~Event_args() = default;

