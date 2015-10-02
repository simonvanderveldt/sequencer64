#ifndef SEQ64_PERFTIME_HPP
#define SEQ64_PERFTIME_HPP

/*
 *  This file is part of seq24/sequencer64.
 *
 *  seq24 is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  seq24 is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with seq24; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

/**
 * \file          perftime.hpp
 *
 *  The time bar shows markers and numbers for the measures of the song,
 *  and also depicts the left and right markers.
 *
 * \library       sequencer64 application
 * \author        Seq24 team; modifications by Chris Ahlstrom
 * \date          2015-07-24
 * \updates       2015-10-02
 * \license       GNU GPLv2 or above
 *
 */

#include "gui_drawingarea_gtk2.hpp"

namespace Gtk
{
    class Adjustment;
}

namespace seq64
{

class perform;

/**
 *  This class implements drawing the piano time at the top of the
 *  "performance window", also known as the "song editor".
 */

class perftime : public gui_drawingarea_gtk2
{

private:

    int m_4bar_offset;
    int m_snap;
    int m_measure_length;

public:

    perftime (perform & perf, Gtk::Adjustment & hadjust);

    void reset ();
    void set_scale (int scale);
    void set_guides (int snap, int measure);
    void increment_size ();

private:

    void update_sizes ();
    void draw_pixmap_on_window ();
    void draw_progress_on_window ();
    void update_pixmap ();
    int idle_progress ();
    void change_horz ();

private:        // callbacks

    void on_realize ();
    bool on_expose_event (GdkEventExpose * ev);
    bool on_button_press_event (GdkEventButton * ev);
    bool on_button_release_event (GdkEventButton * ev);
    void on_size_allocate (Gtk::Allocation & r);
};

}           // namespace seq64

#endif      // SEQ64_PERFTIME_HPP

/*
 * perftime.hpp
 *
 * vim: sw=4 ts=4 wm=4 et ft=cpp
 */
