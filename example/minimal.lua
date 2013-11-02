--[[
    Name:        example/minimal.lua
    Purpose:     Minimal Lua example application for LuaGUI
    Author:      Andrea Zanellato
    Modified by: 
    Created:     2013/11/01
    Licence:     ???
--]]
app        = gui.application()
mainwindow = gui.window()

mainwindow:set_title("luagui window")
mainwindow:set_size( 300, 180 )
mainwindow:show_all()

app:run()
os.exit()
