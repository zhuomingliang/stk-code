//  $Id: MainMenu.cxx,v 1.3 2005/05/31 00:49:50 joh Exp $
//
//  TuxKart - a fun racing game with go-kart
//  Copyright (C) 2004 Steve Baker <sjbaker1@airmail.net>
//
//  This program is free software; you can redistribute it and/or
//  modify it under the terms of the GNU General Public License
//  as published by the Free Software Foundation; either version 2
//  of the License, or (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program; if not, write to the Free Software
//  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.

#include "main_menu.hpp"
#include "widget_set.hpp"
#include "race_manager.hpp"
#include "menu_manager.hpp"

enum WidgetTokens {
  WTOK_SINGLE,
  WTOK_MULTI,
  WTOK_OPTIONS,
  WTOK_REPLAY,
  WTOK_QUIT,
  WTOK_HELP,
  WTOK_CREDITS,
};

MainMenu::MainMenu()
{
	menu_id = widgetSet -> varray(0);
	widgetSet -> start(menu_id, "Single Player", GUI_MED, WTOK_SINGLE,  0);
	widgetSet -> state(menu_id, "Multiplayer",   GUI_MED, WTOK_MULTI,   0);
	widgetSet -> state(menu_id, "Options",       GUI_MED, WTOK_OPTIONS, 0);
	widgetSet -> state(menu_id, "Quit",          GUI_MED, WTOK_QUIT,    0);
	widgetSet -> state(menu_id, "Help",          GUI_SML, WTOK_HELP,    0);
	widgetSet -> state(menu_id, "Credits",       GUI_SML, WTOK_CREDITS, 0);
	widgetSet -> space(menu_id);

	widgetSet -> layout(menu_id, 0, 0);
}

MainMenu::~MainMenu()
{
	widgetSet -> delete_widget(menu_id) ;
}
	
void MainMenu::select()
{
	switch ( widgetSet -> token (widgetSet -> click()) )
	{
	case WTOK_SINGLE:	       
                race_manager->setNumPlayers(1);
                menu_manager->pushMenu(MENUID_GAMEMODE);     
                break;
	case WTOK_MULTI:
                menu_manager->pushMenu(MENUID_NUMPLAYERS);
                break;
                
	case WTOK_REPLAY:
                break;

	case WTOK_OPTIONS:     
                menu_manager->pushMenu(MENUID_OPTIONS);	
                break;

	case WTOK_QUIT:
                menu_manager->pushMenu(MENUID_EXITGAME);
                break;
	case WTOK_HELP:
                menu_manager->pushMenu(MENUID_HELP);
                break;
	case WTOK_CREDITS:
                menu_manager->pushMenu(MENUID_CREDITS);
                break;
	}
}

void MainMenu::keybd(int key)
{
	switch ( key )
	{
	case 27:   //ESC
        menu_manager->pushMenu(MENUID_EXITGAME);
		break;

	default:
        BaseGUI::keybd(key);
		break;
	}
}

/* EOF */
