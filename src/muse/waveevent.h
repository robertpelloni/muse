//=========================================================
//  MusE
//  Linux Music Editor
//  $Id: waveevent.h,v 1.6.2.4 2009/12/20 05:00:35 terminator356 Exp $
//
//  (C) Copyright 1999-2004 Werner Schweer (ws@seh.de)
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

#ifndef __WAVE_EVENT_H__
#define __WAVE_EVENT_H__

#include <sys/types.h>

#include "eventbase.h"
<<<<<<< HEAD:src/muse/waveevent.h
#include "muse_time.h"
=======
#include "audiostream.h"
>>>>>>> origin/audiostreams:muse2/muse/waveevent.h

namespace MusECore {
  
//---------------------------------------------------------
//   WaveEvent
//---------------------------------------------------------

class WaveEventBase : public EventBase {
      // @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
      // @@                                       @@
      // @@  When changing members, don't forget  @@
      // @@  to update the copy-constructor!      @@
      // @@                                       @@
      // @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

      QString _name;
      QString filename;

      AudioStream* audiostream;
      unsigned streamPosition;
      AudioStream::stretch_mode_t stretch_mode;
      
      int _spos;            // start sample position in WaveFile
<<<<<<< HEAD:src/muse/waveevent.h
      Fifo* _prefetchFifo;            // Prefetch Fifo
      MuseCount_t _prefetchWritePos;  // Current fifo write position.
      MuseCount_t _lastSeekPos;       // Remember last seek to optimize seeks.

      // Creates a non-shared clone (copies event base), including the same 'group' id.
      virtual EventBase* clone() const { return new WaveEventBase(*this); }
      // Creates a copy of the event base, excluding the 'group' _id. 
      virtual EventBase* duplicate() const { return new WaveEventBase(*this, true); } 

   public:
      WaveEventBase(EventType t);
      // Creates a non-shared clone with same id, or duplicate with unique id, and 0 ref count and invalid Pos sn. 
      WaveEventBase(const WaveEventBase& ev, bool duplicate_not_clone = false);
      virtual ~WaveEventBase();
      
      virtual void assign(const EventBase& ev); // Assigns to this event, excluding the _id. 
=======
      bool deleted;
      
      virtual EventBase* clone() const;
      
   public:
      WaveEventBase(EventType t);
      WaveEventBase(const WaveEventBase&);
      virtual ~WaveEventBase();
>>>>>>> origin/audiostreams:muse2/muse/waveevent.h
      
      virtual bool isSimilarTo(const EventBase& other) const;

      virtual void read(Xml&);
      virtual void write(int, Xml&, const Pos& offset, bool forcePath = false) const;
      virtual EventBase* mid(unsigned, unsigned) const;
      
      virtual void dump(int n = 0) const;

      virtual const QString name() const       { return _name;  }
      virtual void setName(const QString& s)   { _name = s;     }
      virtual int spos() const                 { return _spos;  }
      virtual void setSpos(int s)              { _spos = s;     }
      
<<<<<<< HEAD:src/muse/waveevent.h
      virtual void readAudio(unsigned frame, float** bpp, int channels, int nn, bool doSeek, bool overwrite);
      virtual void seekAudio(sf_count_t frame);
      virtual Fifo* audioPrefetchFifo()        { return _prefetchFifo; }
      virtual void prefetchAudio(Part* part, sf_count_t frames);
=======
      virtual void reloadAudioFile();
      virtual void setAudioFile(const QString& path);
      virtual QString audioFilePath()               { return filename; }
      virtual AudioStream::stretch_mode_t stretchMode() { return stretch_mode; }
      virtual const AudioStream* getAudioStream()   { return audiostream; }

      virtual void readAudio(WavePart* part, unsigned firstFrame, 
                             float** bpp, int channels, int nFrames, XTick fromXTick, XTick toXTick, bool doSeek, bool overwrite);
      
      virtual bool needCopyOnWrite();
>>>>>>> origin/audiostreams:muse2/muse/waveevent.h
      };
      
} // namespace MusECore

#endif

