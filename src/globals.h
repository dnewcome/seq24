//----------------------------------------------------------------------------
//
//  This file is part of seq24.
//
//  seq24 is free software; you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation; either version 2 of the License, or
//  (at your option) any later version.
//
//  seq24 is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with seq24; if not, write to the Free Software
//  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
//
//-----------------------------------------------------------------------------

#pragma once

#ifdef __WIN32__
#    include "configwin32.h"
#else
#    include "config.h"
#endif

#include <string>
#include <gtkmm/main.h>
#include <gtkmm/drawingarea.h>
//For keys
#include <gtkmm/accelkey.h>



using namespace std;

/* 16 per screen */
const int c_mainwnd_rows = 4;
const int c_mainwnd_cols = 8;
const int c_seqs_in_set = c_mainwnd_rows * c_mainwnd_cols;
const int c_gmute_tracks = c_seqs_in_set * c_seqs_in_set;
const int c_max_sets = 32;
const int c_total_seqs = c_seqs_in_set * c_max_sets;

/* number of sequences */
/* 32 screen sets */
const int c_max_sequence =  c_mainwnd_rows *  c_mainwnd_cols * c_max_sets;


const int c_ppqn         = 192;  /* default - dosnt change */
const int c_bpm          = 120;  /* default */
const int c_maxBuses = 32;

/* trigger width in milliseconds */
const int c_thread_trigger_width_ms = 4;
const int c_thread_trigger_lookahead_ms = 2;

/* for the seqarea class */
const int c_text_x = 6;
const int c_text_y = 12;
const int c_seqarea_x = c_text_x * 15;
const int c_seqarea_y =  c_text_y * 5;

const int c_mainwid_border = 0;
const int c_mainwid_spacing = 2;

const int c_control_height = 0;


const int c_mainwid_x = ((c_seqarea_x + c_mainwid_spacing )
			 * c_mainwnd_cols - c_mainwid_spacing
			 +  c_mainwid_border * 2 );
const int c_mainwid_y = ((c_seqarea_y  + c_mainwid_spacing )
			 * c_mainwnd_rows
			 +  c_mainwid_border * 2
			 +  c_control_height );



/* data entry area (velocity, aftertouch, etc ) */
const int c_dataarea_y = 128;
/* width of 'bar' */
const int c_data_x = 2;

/* keyboard */
const int c_key_x = 16;
const int c_key_y = 8;
const int c_num_keys = 128;
const int c_keyarea_y = c_key_y * c_num_keys + 1;
const int c_keyarea_x = 36;
const int c_keyoffset_x = c_keyarea_x - c_key_x;


/* paino roll */
const int c_rollarea_y = c_keyarea_y;

/* events bar */
const int c_eventarea_y = 16;
const int c_eventevent_y = 10;
const int c_eventevent_x = 5;

/* time scale window on top */
const int c_timearea_y = 18;

/* sequences */
const int c_midi_notes = 256;
const std::string c_dummy( "Untitled" );

/* maximum size of sequence, default size */
const int c_maxbeats     = 0xFFFF;   /* max number of beats in a sequence */


/* midifile tags */
const unsigned long c_midibus =    0x24240001;
const unsigned long c_midich =     0x24240002;
const unsigned long c_midiclocks = 0x24240003;
const unsigned long c_triggers =   0x24240004;
const unsigned long c_notes =      0x24240005;
const unsigned long c_timesig =    0x24240006;
const unsigned long c_bpmtag =     0x24240007;
const unsigned long c_triggers_new =   0x24240008;
const unsigned long c_midictrl =   0x24240010;
const unsigned long c_mutegroups = 0x24240009; // not sure why we went to 10 above, this might need a different value


const char c_font_6_12[] = "-*-fixed-medium-r-*--12-*-*-*-*-*-*";
const char c_font_8_13[] = "-*-fixed-medium-r-*--13-*-*-*-*-*-*";
const char c_font_5_7[]  = "-*-fixed-medium-r-*--7-*-*-*-*-*-*";


/* used in menu to tell setState what to do */
const int c_adding = 0;
const int c_normal = 1;
const int c_paste  = 2;

/* redraw when recording ms */
#ifdef __WIN32__
const int c_redraw_ms = 20;
#else
const int c_redraw_ms = 40;
#endif

/* consts for perform editor */
const int c_names_x = 6 * 24;
const int c_names_y = 22;
const int c_perf_scale_x = 32; /*ticks per pixel */

extern bool global_showmidi;
extern bool global_priority;
extern bool global_stats;
extern bool global_pass_sysex;
extern bool global_with_jack_transport;
extern bool global_with_jack_master;
extern bool global_with_jack_master_cond;
extern bool global_jack_start_mode;
extern bool global_manual_alsa_ports;

extern Glib::ustring global_filename;
extern Glib::ustring global_jack_session_uuid;
extern Glib::ustring last_used_dir;
extern bool is_pattern_playing;

extern bool global_print_keys;

const int c_max_instruments = 64;

struct user_midi_bus_definition
{
    std::string alias;
    int instrument[16];
};

struct user_instrument_definition
{
    std::string instrument;
    bool controllers_active[128];
    std::string controllers[128];
};

extern user_midi_bus_definition   global_user_midi_bus_definitions[c_maxBuses];
extern user_instrument_definition global_user_instrument_definitions[c_max_instruments];

/* scales */
enum c_music_scales {
  c_scale_off,
  c_scale_major,
  c_scale_minor,
  c_scale_size

};


const bool c_scales_policy[c_scale_size][12] =
{
    /* off = chromatic */
    { true,true,true,true,true,true,true,true,true,true,true,true},

    /* major */
    { true,false,true,false,true,true,false,true,false,true,false,true},

    /* minor */
    { true,false,true,true,false,true,false,true,true,false,true,false},

};

const int c_scales_transpose_up[c_scale_size][12] =
{
    /* off = chromatic */
    { 1,1,1,1,1,1,1,1,1,1,1,1},
    /* major */
    { 2,0,2,0,1,2,0,2,0,2,0,1},
    /* minor */
    { 2,0,1,2,0,2,0,1,2,0,2,0},

};




const int c_scales_transpose_dn[c_scale_size][12] =
{
    /* off = chromatic */
    { -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
    /* major */
    { -1,0,-2,0,-2,-1,0,-2,0,-2,0,-2},
    /* minor */
    { -2,0,-2,-1,0,-2,0,-2,-1,0,-2,0},

};

const int c_scales_symbol[c_scale_size][12] =
{
    /* off = chromatic */
    { 32,32,32,32,32,32,32,32,32,32,32,32},

    /* major */
    { 32,32,32,32,32,32,32,32,32,32,32,32},

    /* minor */
    { 32,32,32,32,32,32,32,32,129,128,129,128},

};

// up 128
// down 129


const char c_scales_text[c_scale_size][6] =
{
    "Off",
    "Major",
    "Minor"
};

const char c_key_text[][3] =
{
    "C",
    "C#",
    "D",
    "D#",
    "E",
    "F",
    "F#",
    "G",
    "G#",
    "A",
    "A#",
    "B"
};

const char c_interval_text[][3] =
{
    "P1",
    "m2",
    "M2",
    "m3",
    "M3",
    "P4",
    "TT",
    "P5",
    "m6",
    "M6",
    "m7",
    "M7",
    "P8",
    "m9",
    "M9",
    ""
};
 	  	  	
const char c_chord_text[][5] =
{
    "I",
    "II",
    "III",
    "IV",
    "V",
    "VI",
    "VII",
    "VIII"
};

enum mouse_action_e
{
    e_action_select,
    e_action_draw,
    e_action_grow
};

enum interaction_method_e
{
    e_seq24_interaction,
    e_fruity_interaction,
    e_number_of_interactions // keep this one last...
};

const char* const c_interaction_method_names[] =
{
    "seq24",
    "fruity",
    NULL
};

const char* const c_interaction_method_descs[] =
{
    "original seq24 method",
    "similar to a certain fruity sequencer we like",
    NULL
};

extern interaction_method_e global_interactionmethod;

