/*
 *    This file is part of MotionPlus.
 *
 *    MotionPlus is free software: you can redistribute it and/or modify
 *    it under the terms of the GNU General Public License as published by
 *    the Free Software Foundation, either version 3 of the License, or
 *    (at your option) any later version.
 *
 *    MotionPlus is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU General Public License for more details.
 *
 *    You should have received a copy of the GNU General Public License
 *    along with MotionPlus.  If not, see <https://www.gnu.org/licenses/>.
 *
 */
#ifndef _INCLUDE_LOGGER_HPP_
#define _INCLUDE_LOGGER_HPP_
    extern cls_log *motlog;

    #define LOGMODE_NONE            0   /* No logging             */
    #define LOGMODE_FILE            1   /* Log messages to file   */
    #define LOGMODE_SYSLOG          2   /* Log messages to syslog */

    #define NO_ERRNO                0   /* Flag to avoid how message associated to errno */
    #define SHOW_ERRNO              1   /* Flag to show message associated to errno */

    #define LOG_ALL                 9
    #define EMG                     1
    #define ALR                     2
    #define CRT                     3
    #define ERR                     4
    #define WRN                     5
    #define NTC                     6
    #define INF                     7
    #define DBG                     8
    #define ALL                     9
    #define LEVEL_DEFAULT           NTC

    /* Log types */
    #define TYPE_CORE               1             /* Core logs         */
    #define TYPE_STREAM             2             /* Stream logs       */
    #define TYPE_ENCODER            3             /* Encoder logs      */
    #define TYPE_NETCAM             4             /* Netcam logs       */
    #define TYPE_DB                 5             /* Database logs     */
    #define TYPE_EVENTS             6             /* Events logs       */
    #define TYPE_TRACK              7             /* Track logs        */
    #define TYPE_VIDEO              8             /* V4L1/2 Bktr logs  */
    #define TYPE_ALL                9             /* All type logs     */
    #define TYPE_DEFAULT            TYPE_ALL      /* Default type      */
    #define TYPE_DEFAULT_STR        "ALL"         /* Default name logs */

    #define MOTPLS_LOG(x, y, z, ...) motlog->write_msg(x, y, z, true, __FUNCTION__, __VA_ARGS__)
    #define MOTPLS_SHT(x, y, z, ...) motlog->write_msg(x, y, z, false, __VA_ARGS__)

    class cls_log {
        public:
            cls_log(ctx_motapp *p_motapp);
            ~cls_log();
            int     log_level;
            int     log_fflevel;
            void set_log_file(std::string pname);
            void write_msg(int loglvl, int msg_type, int flgerr, bool flgfnc, ...);
        private:
            ctx_motapp          *c_motapp;
            pthread_mutex_t     mtx;
            int                 log_mode;
            FILE                *log_file_ptr;
            std::string         log_file_name;
            char                msg_prefix[512];
            char                msg_flood[1024];
            char                msg_full[1024];
            int                 flood_cnt;
            void set_mode(int mode);
            void write_flood(int loglvl);
            void write_norm(int loglvl, int prefixlen);
            void add_errmsg(int flgerr, int err_save);
            void log_stop();

    };


#endif /* _INCLUDE_LOGGER_HPP_ */
