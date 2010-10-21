/* $Id$
 *****************************************************************************
 *
 * File:    pcap_capture.h
 *
 * Author:  Damien Stuart (dstuart@dstuart.org)
 *
 * Purpose: Header file for pcap_capture.c.
 *
 * Copyright (C) 2009 Damien Stuart (dstuart@dstuart.org)
 *
 *  License (GNU Public License):
 *
 *     This program is distributed in the hope that it will be useful,
 *     but WITHOUT ANY WARRANTY; without even the implied warranty of
 *     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *     GNU General Public License for more details.
 *
 *     You should have received a copy of the GNU General Public License
 *     along with this program; if not, write to the Free Software
 *     Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307
 *     USA
 *
 *****************************************************************************
*/
#ifndef PCAP_CAPTURE_H
#define PCAP_CAPTURE_H

/* How many consecutive pcap capture errors will we allow
 * before giving up and bailing out.
*/
#define MAX_PCAP_ERRORS_BEFORE_BAIL 100

/* We normally want pcap in non-blockinbg mode, but this seems to be
 * broken on FreeBSD 7 (at least my test host), so we'll set the default
 * mode to on unless it is a FreeBSD system. --DSS XXX: What we really need
 * to do is figure out what the difference is and address it correctly.
*/
#if defined(__FreeBSD__)
    #define DEF_PCAP_NONBLOCK 0
#else
    #define DEF_PCAP_NONBLOCK 1
#endif

/* Prototypes
*/
int pcap_capture(fko_srv_options_t *opts);

#endif  /* PCAP_CAPTURE_H */
