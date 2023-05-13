#pragma once
#include <array>
#include <cstdint>
#include <reg/reg.hpp>
#include <string>

// using MyImGuiID

struct MyIDType {
    MyIDType(reg::AnyId idd = {})
        : id{idd}
    {}
    static auto from_int(int x) -> MyIDType
    {
        return reg::AnyId{uuids::uuid{std::array<uuids::uuid::value_type, 16>{

        }}};
    }
    reg::AnyId          id;
    auto operator==(MyIDType const& o) const -> bool { return id ==o.id;}
    mutable std::string as_str{};

    [[nodiscard]] auto AsImguiID() const
    {
        as_str = reg::to_string(id);
        return as_str.c_str();
    }
    [[nodiscard]] auto as_string() const -> std::string { return reg::to_string(id); }

    operator bool() const { return !id.underlying_uuid().is_nil(); }
    bool operator<(MyIDType const& o) const { return id.underlying_uuid() < o.id.underlying_uuid(); }
};