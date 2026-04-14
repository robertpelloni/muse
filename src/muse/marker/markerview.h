//=========================================================
//  MusE
//  Linux Music Editor
//    $Id: markerview.h,v 1.4.2.3 2008/08/18 00:15:25 terminator356 Exp $
//  (C) Copyright 2000 Werner Schweer (ws@seh.de)
//
//  This program is free software; you can redistribute it and/or
//  modify it under the terms of the GNU General Public License
//  as published by the Free Software Foundation; version 2 of
//  the License, or (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program; if not, write to the Free Software
//  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
//
//=========================================================

#ifndef __MARKERVIEW_H__
#define __MARKERVIEW_H__

#include <QTreeWidgetItem>
#include <QString>

#include "type_defs.h"
#include "cobject.h"
#include "marker.h"

class QCloseEvent;
class QLineEdit;
class QToolBar;
class QToolButton;
class QTreeWidget;

namespace MusECore {
class Pos;
class Xml;
}

namespace MusEGui {

class PosEdit;

//---------------------------------------------------------
//   MarkerItem
//---------------------------------------------------------

class MarkerItem : public QTreeWidgetItem {
      MusECore::Marker _marker;

   public:
      MarkerItem(QTreeWidget* parent, const MusECore::Marker& m);
      MarkerItem(const MusECore::Marker& m);
      MusECore::Marker marker() const;
      void setMarker(const MusECore::Marker& m);
      unsigned tick() const;
      const QString name() const;
      bool lock() const;
      void setName(const QString& s);
<<<<<<< HEAD:src/muse/marker/markerview.h
      void setPos(const MusECore::Pos& v);
      void setLock(bool lck);
=======
      void setTick(unsigned t);
>>>>>>> origin/audiostreams:muse2/muse/marker/markerview.h
      };

//---------------------------------------------------------
//   MarkerView
//---------------------------------------------------------

class MarkerView : public QWidget {
      Q_OBJECT
    
      QTreeWidget* table;
      QLineEdit* editName;
<<<<<<< HEAD:src/muse/marker/markerview.h
      PosEdit* editSMPTE;
      PosEdit* editTick;
      QToolButton* lock;
=======
      Awl::PosEdit* editSMPTE;
      Awl::PosEdit* editTick;
>>>>>>> origin/audiostreams:muse2/muse/marker/markerview.h
      QToolBar* tools;

      QSize sizeHint() const override;
      bool eventFilter(QObject *, QEvent *event) override;

   private slots:
      void addMarker();
      void addMarker(unsigned);
      void deleteMarker();
      void markerSelectionChanged();
      void nameChanged();
      void tickChanged(const MusECore::Pos&);
      void markerChanged(int);
      void clicked(QTreeWidgetItem*);
      void rebuildList();
      void updateList();
      void songChanged(MusECore::SongChangedStruct_t);
      
   public:
      MarkerView(QWidget* parent);
      ~MarkerView();
      void nextMarker();
      void prevMarker();

      MarkerItem* findId(MusECore::EventID_t id) const;
      };

}

#endif

