//=========================================================
//  MusE
//  Linux Music Editor
//    $Id: midieditor.h,v 1.3.2.2 2009/02/02 21:38:00 terminator356 Exp $
//  (C) Copyright 1999 Werner Schweer (ws@seh.de)
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

#ifndef __MIDIEDITOR_H__
#define __MIDIEDITOR_H__

#include "type_defs.h"
#include "cobject.h"
<<<<<<< HEAD:src/muse/midieditor.h
#include "ctrl/ctrledit.h"
#include "event_tag_list.h"
=======
#include "pos.h" // for XTick
>>>>>>> origin/audiostreams:muse2/muse/midieditor.h

#include <set>
#include <QUuid>

class QGridLayout;
class QWidget;
class QPoint;

namespace MusECore {
class Track;
class Part;
class PartList;
class WavePart;
class Xml;
}

namespace MusEGui {
class EventCanvas;
class MTScale;
class ScrollScale;
class TrackInfoWidget;
class RasterizerModel;

using MusECore::XTick;

//---------------------------------------------------------
//   MidiEditor
//---------------------------------------------------------

class MidiEditor : public TopWin  {
      Q_OBJECT

      MusECore::PartList* _pl;
      std::set<QUuid> _parts;
      int _curDrumInstrument;  // currently selected instrument if drum
                               // editor

   protected:
      MusEGui::ScrollScale* hscroll;
      MusEGui::ScrollScale* vscroll;
      MusEGui::MTScale* time;
      EventCanvas* canvas;
      
      TrackInfoWidget* trackInfoWidget;
      MusECore::Track* selected;

<<<<<<< HEAD:src/muse/midieditor.h
      CtrlEditList ctrlEditList;
      int _raster;
      RasterizerModel *_rasterizerModel;
      // The X origin that is applied to any canvases.
      int _canvasXOrigin;
      // The X mag minimum that is applied to any ScrollScale controls.
      // Note that global midi division will also be taken into account.
      int _minXMag;
      // The X mag maximum that is applied to any ScrollScale controls.
      int _maxXMag;
=======
      std::list<CtrlEdit*> ctrlEditList;

      //raster=n raster on n ticks
      //raster=1 means raster on full ticks (for int-ticks, this does nothing)
      //raster=0 means raster on measure
      //raster<0 would mean "don't even touch the subtick" (for XTicks and int-ticks, this does nothing)
      int _raster;
      enum {NO_RASTER=-1};
>>>>>>> origin/audiostreams:muse2/muse/midieditor.h

      QGridLayout* mainGrid;
      QWidget* mainw;
      virtual void readStatus(MusECore::Xml&);
      virtual void writeStatus(int, MusECore::Xml&) const;
      void writePartList(int, MusECore::Xml&) const;
      void genPartlist();
      void movePlayPointerToSelectedEvent();
      
      void genTrackInfo(TrackInfoWidget* trackInfo);
      void switchInfo(int);
      void trackInfoSongChange(MusECore::SongChangedStruct_t flags);
      // Checks if track info track is valid and deletes the strip if the track is not found.
      void checkTrackInfoTrack();

   protected slots:
      void updateTrackInfo();
      
   private slots:
      void addNewParts(const std::map< const MusECore::Part*, std::set<const MusECore::Part*> >&);

   public slots:
      void songChanged(MusECore::SongChangedStruct_t type);
      void setCurDrumInstrument(int instr);

      virtual void updateHScrollRange() { };
   signals:
      void curDrumInstrumentChanged(int);

   public:
      MidiEditor(ToplevelType t, int, MusECore::PartList*,
         QWidget* parent = 0, const char* name = 0);
      virtual ~MidiEditor();

<<<<<<< HEAD:src/muse/midieditor.h
      int rasterStep(unsigned tick) const;
      unsigned rasterVal(unsigned v)  const;
      unsigned rasterVal1(unsigned v) const;
      unsigned rasterVal2(unsigned v) const;
      int raster() const           { return _raster; }
      virtual void setRaster(int val)      { _raster = val; }
=======
      // this is ugly. better use XTick everywhere (flo)
      XTick rasterStep(XTick tick) const { return _raster==NO_RASTER ? tick : XTick(AL::sigmap.rasterStep(tick.to_uint(), _raster)); }
      XTick rasterVal(XTick tick)  const { return _raster==NO_RASTER ? tick : XTick(AL::sigmap.raster(tick.to_uint(), _raster));  }
      XTick rasterVal1(XTick tick) const { return _raster==NO_RASTER ? tick : XTick(AL::sigmap.raster1(tick.to_uint(), _raster)); }
      XTick rasterVal2(XTick tick) const { return _raster==NO_RASTER ? tick : XTick(AL::sigmap.raster2(tick.to_uint(), _raster)); }
      int raster() const           { return _raster; }
      void setRaster(int val)      { _raster = val; }
      void disableRaster()         { _raster = -1; }
>>>>>>> origin/audiostreams:muse2/muse/midieditor.h
      MusECore::PartList* parts()            { return _pl;  }
      const MusECore::PartList* parts() const { return _pl;  }
      int curDrumInstrument() const  { return _curDrumInstrument; }
      MusECore::Part* curCanvasPart();
      void setCurCanvasPart(MusECore::Part*); 
      void addPart(MusECore::Part*);
      bool itemsAreSelected() const;
      // Appends given tag list with item objects according to options. Avoids duplicate events or clone events.
      // Special: We 'abuse' a controller event's length, normally 0, to indicate visual item length.
      void tagItems(MusECore::TagEventList* tag_list, const MusECore::EventTagOptionsStruct& options) const;
      void setHScrollOffset(const int);
};

} // namespace MusEGui

#endif

