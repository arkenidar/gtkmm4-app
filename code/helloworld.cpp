/* gtkmm example Copyright (C) 2002 gtkmm development team
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2
 * as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

#include "helloworld.h"
#include <iostream>
#include <gtkmm/box.h>

HelloWorld::HelloWorld()
        : m_button("Hello World")   // creates a new button with label "Hello World".
{
    // Sets the margin around the button.
    m_button.set_margin(10);

    // When the button receives the "clicked" signal, it will call the
    // on_button_clicked() method defined below.
    m_button.signal_clicked().connect(sigc::mem_fun(*this,
                                                    &HelloWorld::on_button_clicked));

    auto box = Gtk::make_managed<Gtk::Box>(Gtk::Orientation::HORIZONTAL, 5);
    set_child(*box);
    box->append(m_entry);
    box->append(m_button);
}

HelloWorld::~HelloWorld() {
}

void HelloWorld::on_button_clicked() {
    std::cout << "Hello World" << std::endl;
    m_entry.set_text(m_entry.get_text()+" text!!!");
}
