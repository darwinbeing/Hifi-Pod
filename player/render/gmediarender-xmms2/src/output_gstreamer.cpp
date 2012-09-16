/* output_gstreamer.c - Output module for GStreamer
 *
 * Copyright (C) 2005-2007   Ivo Clarysse
 *
 * Adapted to gstreamer-0.10 2006 David Siorpaes
 *
 * This file is part of GMediaRender.
 *
 * GMediaRender is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * GMediaRender is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Library General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with GMediaRender; if not, write to the Free Software 
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, 
 * MA 02110-1301, USA.
 *
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include <gst/gst.h>

//#define ENABLE_TRACING

#include "logging.h"
#include "upnp_connmgr.h"
#include "output_gstreamer.h"


#include <xmmsclient/xmmsclient++.h>

class XClient;
XClient *m_xmms2_client = NULL;


class XClient {
	public:
		XClient (const std::string &);

		bool connect (const char *path = NULL, const bool &sync = false);


		bool isConnected () const {
            return m_isconnected;
        };

		void disconnect ();
		void shutdownServer ();

		void play ();
		void pause ();
		void stop ();
		void prev ();
		void next ();
		void addUrl (const std::string &);

//        static QDir esperanza_dir ();
#if (XMMS_IPC_PROTOCOL_VERSION > 13)
		void setDisconnectCallback (const Xmms::DisconnectCallback::value_type &slot) { m_client->setDisconnectCallback (slot); }
#else
		void setDisconnectCallback (const Xmms::DisconnectCallback::slot_type &slot) { m_client->setDisconnectCallback (slot); }
#endif
		const Xmms::Collection* collection () { if (m_client && m_client->isConnected ()) return &m_client->collection; else return NULL; }
		const Xmms::Playlist* playlist () { if (m_client && m_client->isConnected ()) return &m_client->playlist; else return NULL; }
		const Xmms::Playback* playback () { if (m_client && m_client->isConnected ()) return &m_client->playback; else return NULL; }
		const Xmms::Medialib* medialib () { if (m_client && m_client->isConnected ()) return &m_client->medialib; else return NULL; }
		const Xmms::Bindata* bindata () { if (m_client && m_client->isConnected ()) return &m_client->bindata; else return NULL; }
		const Xmms::Config* config () { if (m_client && m_client->isConnected ()) return &m_client->config; else return NULL; }
		const Xmms::Stats* stats () { if (m_client && m_client->isConnected ()) return &m_client->stats; else return NULL; }

		// TODO: remove as soon as it's no longer neede
		Xmms::Client *getClient () {return m_client;}

	protected:
//		Xmms::Client *m_client;

	private:
		std::string m_name;
		Xmms::Client *m_client;
		bool m_isconnected;
		Xmms::Client m_sync;
};


XClient::XClient(const std::string &name): m_sync (name + "-sync")
{
	m_client = NULL;
    m_isconnected = false;
	m_name = name;
}

void XClient::disconnect ()
{
	delete m_client;
	m_client = NULL;
	m_isconnected = false;

}



void XClient::shutdownServer ()
{
	 if (!m_client)
		  return;
	 m_client->quit ();
	 return;
}

bool XClient::connect (const char *ipcpath, const bool &sync)
{
	bool tried_once = false;

	try {
		delete m_client;
		m_client = new Xmms::Client (m_name);
		if (!ipcpath || ipcpath == "")
			m_client->connect (NULL);
		else
			m_client->connect (ipcpath);
	}
	catch (Xmms::connection_error& e) {
		printf("Couldn't connect to XMMS2, please try again.\n");
		return false;
	}


    if (sync) {
	    try {
		    m_sync.connect (ipcpath);
	    }
	    catch (Xmms::connection_error &e) {
		    printf ("Couldn't establish sync connection!\n");
	    }
    }

	m_isconnected = true;
	// useing normal disconnect callback, if that causes problems,
	// an own method schould be created
    setDisconnectCallback (boost::bind (&XClient::disconnect, this));

	return true;
}


void XClient::play ()
{
	if (!isConnected ()) return;

	playback ()->start ();
}

void XClient::pause ()
{
	if (!isConnected ()) return;

	playback ()->pause ();
}


void XClient::stop ()
{
	if (!isConnected ()) return;

	playback ()->stop ();
}

void XClient::prev ()
{
	if (!isConnected ()) return;

	playlist ()->setNextRel (-1);
	playback ()->tickle ();
}

void XClient::next ()
{
	if (!isConnected ()) return;

	playlist ()->setNextRel (1);
	playback ()->tickle ();
}


void XClient::addUrl (const std::string &url)
{
	if (!isConnected ()) return;
	playlist ()->clear();
	playlist ()->addUrl (url) ();
}



static void scan_caps(const GstCaps * caps)
{

}

static void scan_pad_templates_info(GstElement * element,
				    GstElementFactory * factory)
{

}


static void scan_mime_list(void)
{

	ENTER();

	LEAVE();
}



void output_set_uri(const char *uri)
{
	 std::string url = uri;
	ENTER();
	printf("%s: setting uri to '%s'\n", __FUNCTION__, uri);
	if(m_xmms2_client) {
		 m_xmms2_client->addUrl(url);
	}
	LEAVE();
}

int output_play(void)
{
	ENTER();
	m_xmms2_client->play();
	LEAVE();
	return 0;
}

int output_stop(void)
{
	m_xmms2_client->stop();
	 return 0;

}

int output_pause(void)
{
	m_xmms2_client->pause();
	 return 0;
}


int output_loop()
{
	GMainLoop *loop;

	/* Create a main loop that runs the default GLib main context */
	loop = g_main_loop_new(NULL, FALSE);

	g_main_loop_run(loop);

	return 0;
}

static const char *gststate_get_name(GstState state)
{
	switch(state) {
	case GST_STATE_VOID_PENDING:
		return "VOID_PENDING";
	case GST_STATE_NULL:
		return "NULL";
	case GST_STATE_READY:
		return "READY";
	case GST_STATE_PAUSED:
		return "PAUSED";
	case GST_STATE_PLAYING:
		return "PLAYING";
	default:
		return "Unknown";
	}
}

static gboolean my_bus_callback(GstBus * bus, GstMessage * msg,
				gpointer data)
{
	return TRUE;
}

static gchar *audiosink = NULL;
static gchar *videosink = NULL;

/* Options specific to output_gstreamer */
static GOptionEntry option_entries[] = {
        { "gstout-audiosink", 0, 0, G_OPTION_ARG_STRING, &audiosink,
          "GStreamer audio sink to use "
	  "(autoaudiosink, alsasink, osssink, esdsink, ...)",
	  NULL },
        { "gstout-videosink", 0, 0, G_OPTION_ARG_STRING, &videosink,
          "GStreamer video sink to use "
	  "(autovideosink, xvimagesink, ximagesink, ...)",
	  NULL },
        { NULL }
};


int output_gstreamer_add_options(GOptionContext *ctx)
{
	GOptionGroup *option_group;
	ENTER();
	option_group = g_option_group_new("gstout", "GStreamer Output Options",
	                                  "Show GStreamer Output Options",
	                                  NULL, NULL);
	g_option_group_add_entries(option_group, option_entries);

	g_option_context_add_group (ctx, option_group);
	
	g_option_context_add_group (ctx, gst_init_get_option_group ());
	LEAVE();
	return 0;
}

int output_gstreamer_init(void)
{

	ENTER();

	m_xmms2_client = new XClient ("Hifi-Pod");
	m_xmms2_client->connect ();

	LEAVE();

	return 0;
}
