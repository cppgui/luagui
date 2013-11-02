/*
    Name:        luagui.cpp
    Purpose:     CPPGUI Lua bindings library
    Author:      Andrea Zanellato
    Modified by: 
    Created:     2013/11/01
    Licence:     ???
*/
extern "C"
{
    #include "lua.h"
    #include "lauxlib.h"
    #include "lualib.h"
}

#include <iostream>
#include <luabind/luabind.hpp>

#include <gui/config.hpp>
#include <gui/application.hpp>
//#include <gui/geometry.hpp>
#include <gui/toplevel.hpp>
#include <gui/widget.hpp>
#include <gui/window.hpp>

void greet()
{
    std::cout << "hello world!\n";
}

extern "C" int init(lua_State* L)
{
    using namespace luabind;
    using namespace gui;

    open(L);

    module(L, "gui")
    [
        def("greet", &greet),
        class_< backend_t >("backend_t"),
/*
        def( "default_coord" default_coord ),

        enum_("alignment")
        [
            value("align_none",                     0),
            value("align_left",                     1),
            value("align_right",                    2),
            value("align_top",                      3),
            value("align_bottom",                   4),
            value("align_center_horizontal",        5),
            value("align_center_vertical",          6),
            value("align_center",                   align_center_horizontal |
                                                    align_center_vertical),
            value("align_mask",                     align_center)
        ]
        ,
        enum_("orientation")
        [
            value("orient_none",      0),
            value("horizontal",       1),
            value("vertical",         2),
            value("both",             horizontal|vertical),
            value("orientation_mask", both)
        ]
        ,
*/
        class_< application<backend_t> >("application")
            .def( constructor<>() )
            .def( constructor<int, char**>() )
            .def( "run", &application<backend_t>::run )
        ,
        class_< widget<backend_t> >("widget")
            .def( constructor<>() )
            .def( constructor< widget<backend_t>* >() )
            .def( "destroy",    &widget<backend_t>::destroy )
/*          .def( "expand",     &widget<backend_t>::expand< orientation > ) */
            .def( "is_enabled", &widget<backend_t>::is_enabled )
            .def( "native",     &widget<backend_t>::native )
            .def( "parent",     &widget<backend_t>::parent )
            .def( "set_size",   &widget<backend_t>::set_size )
            .def( "show",       &widget<backend_t>::show )
            .def( "show_all",   &widget<backend_t>::show_all )
        ,
        class_< toplevel<backend_t>, widget<backend_t> >("toplevel")
            .def( "close",     &toplevel<backend_t>::close )
            .def( "title",     &toplevel<backend_t>::title )
            .def( "set_title", &toplevel<backend_t>::set_title )
        ,
        class_< window<backend_t>, toplevel<backend_t>, widget<backend_t> >("window")
            .def( constructor<>() )
    ];

    return 0;
}
