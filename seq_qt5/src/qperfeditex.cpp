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
 * \file          qperfeditex.cpp
 *
 *  This module declares/defines the base class for the external performance edit
 *  window.
 *
 * \library       sequencer64 application
 * \author        Seq24 team; modifications by Chris Ahlstrom
 * \date          2018-07-21
 * \updates       2018-07-30
 * \license       GNU GPLv2 or above
 *
 */

#include <QGridLayout>

#include "seq64-config.h"
#include "perform.hpp"
#include "qperfeditex.hpp"
#include "qperfeditframe64.hpp"
#include "qsmainwnd.hpp"
#include "sequence.hpp"

/*
 *  Qt's uic application allows a different output file-name, but not sure
 *  if qmake can change the file-name.
 */

#ifdef SEQ64_QMAKE_RULES
#include "forms/ui_qperfeditex.h"
#else
#include "forms/qperfeditex.ui.h"
#endif

/*
 * Don't document the namespace.
 */

namespace seq64
{

/**
 *
 * \param p
 *      Provides the perform object to use for interacting with this sequence.
 *
 * \param ppqn
 *      The optional PPQN value.
 *
 * \param parent
 *      Provides the parent window/widget for this container window.  Defaults
 *      to null.  Note that this parameter does not link this class to the
 *      parent as a QWidget, because that would make this class appear inside
 *      the qsmainwnd user-interface.
 */

qperfeditex::qperfeditex
(
    perform & p,
    int ppqn,
    qsmainwnd * parent
) :
    QWidget             (nullptr),
    ui                  (new Ui::qperfeditex),
    m_perform           (p),
    m_edit_parent       (parent),
    m_edit_frame        (nullptr)
{
    ui->setupUi(this);

    QGridLayout * layout = new QGridLayout(this);
    m_edit_frame = new qperfeditframe64(p, ppqn, this);
    layout->addWidget(m_edit_frame);
    show();
    m_edit_frame->show();
}

/**
 *  Deletes the user interface, then tells the editor parent to remove
 *  this object.
 */

qperfeditex::~qperfeditex()
{
    delete ui;
}

/**
 *
 */

void
qperfeditex::closeEvent (QCloseEvent *)
{
    if (not_nullptr(m_edit_parent))
       m_edit_parent->remove_qperfedit();
}

/**
 *  See usage is qsmainwnd.
 */

void
qperfeditex::update_sizes ()
{
    if (not_nullptr(m_edit_frame))
        m_edit_frame->update_sizes();
}

}               // namespace seq64

/*
 * qperfeditex.cpp
 *
 * vim: sw=4 ts=4 wm=4 et ft=cpp
 */

