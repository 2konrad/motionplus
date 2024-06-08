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

#include "motionplus.hpp"
#include "conf.hpp"
#include "logger.hpp"
#include "util.hpp"
#include "webu.hpp"
#include "webu_html.hpp"


/* Create the CSS styles used in the navigation bar/side of the page */
static void webu_html_style_navbar(ctx_webui *webui)
{
    webui->resp_page +=
        "    .sidenav {\n"
        "      height: 100%;\n"
        "      width: 10rem;\n"
        "      position: fixed;\n"
        "      z-index: 1;\n"
        "      top: 0;\n"
        "      left: 0;\n"
        "      background-color: lightgrey;\n"
        "      overflow-x: hidden;\n"
        "      overflow: auto;\n"
        "    }\n"
        "    .sidenav a, .dropbtn {\n"
        "      padding: 0.5rem 0rem 0.5em 1rem;\n"
        "      text-decoration: none;\n"
        "      font-size: 1rem;\n"
        "      display: block;\n"
        "      border: none;\n"
        "      background: none;\n"
        "      width:90%;\n"
        "      text-align: left;\n"
        "      cursor: pointer;\n"
        "      outline: none;\n"
        "      color: black;\n"
        "      background-color: lightgray;\n"
        "    }\n"
        "    .sidenav a:hover, .dropbtn:hover {\n"
        "      background-color: #555;\n"
        "      color: white;\n"
        "    }\n"
        "    .sidenav .closebtn {\n"
        "      color: black;\n"
        "      top: 0;\n"
        "      margin-left: 80%;\n"
        "      width: 1rem;\n"
        "      font-size: 1rem;\n"
        "      background-color: lightgray;\n"
        "    }\n"
        "    .sidenav .closebtn:hover {\n"
        "      background-color: lightgray;\n"
        "      color: white;\n"
        "    }\n"
        "    .menubtn {\n"
        "      top: 0;\n"
        "      width: 1rem;\n"
        "      margin-left: 0.5rem;\n"
        "      margin-bottom: 0.25rem;\n"
        "      font-size: 1.5rem;\n"
        "      color:black;\n"
        "      transform: rotate(90deg);\n"
        "      -webkit-transform: rotate(90deg);\n"
        "      background-color: transparent;\n"
        "      border-color: transparent;\n"
        "    }\n"
        "    .menubtn:hover {\n"
        "      color: white;\n"
        "    }\n"

        "    .dropdown-content {\n"
        "      display: none;\n"
        "      background-color:lightgray;\n"
        "      padding-left: 1rem;\n"
        "    }\n"
        "    .actionbtn {\n"
        "      padding: 0.25rem;\n"
        "      text-decoration: none;\n"
        "      font-size: 0.5rem;\n"
        "      display: block;\n"
        "      border: none;\n"
        "      background: none;\n"
        "      width: 3rem;\n"
        "      text-align: center;\n"
        "      cursor: pointer;\n"
        "      outline: none;\n"
        "      color: black;\n"
        "      background-color: lightgray;\n"
        "    }\n";

}

/* Create the css styles used in the config sections */
static void webu_html_style_config(ctx_webui *webui)
{
    webui->resp_page +=
        "    .cls_config {\n"
        "      background-color: #000000;\n"
        "      color: #fff;\n"
        "      text-align: center;\n"
        "      margin-top: 0rem;\n"
        "      margin-bottom: 0rem;\n"
        "      font-weight: normal;\n"
        "      font-size: 0.90rem;\n"
        "    }\n"
        "    .cls_config table {\n"
        "      display: table;\n"
        "      border-spacing: 1rem;\n"
        "      margin: auto;\n"
        "    }\n"
        "    .cls_config label {\n"
        "      padding: 0rem;\n"
        "      text-align: right;\n"
        "      width: 10rem;\n"
        "      height: 2.5rem;\n"
        "    }\n"
        "    .cls_config textarea {\n"
        "      margin: auto;\n"
        "      text-align: center;\n"
        "      width: 15.5rem;\n"
        "      height: 2.5rem;\n"
        "    }\n"
        "    .cls_button {\n"
        "      width: 10rem;\n"
        "      height: 2rem;\n"
        "      padding: 0rem;\n"
        "    }\n"
        "    .cls_drop {\n"
        "      padding: 0rem;\n"
        "      text-align: right;\n"
        "      width: 10rem;\n"
        "      height: 2.25rem;\n"
        "    }\n"
        "    .cls_text {\n"
        "      padding: 0rem;\n"
        "      width: 10em;\n"
        "      text-align: right;\n"
        "    }\n"
        "    .cls_text_nbr {\n"
        "      padding: 0rem;\n"
        "      width: 10rem;\n"
        "      text-align: right;\n"
        "    }\n"
        "    .cls_text_wide {\n"
        "      padding: 0rem;\n"
        "      height: 3rem;\n"
        "      width: 20rem;\n"
        "      text-align: right;\n"
        "    }\n"
        "    .cls_camdrop {\n"
        "      /* Only used to identify all the cam drops on page */\n"
        "    }\n"
        "    .arrow {\n"
        "      border: solid black;\n"
        "      border-width: 0 1rem 1rem 0;\n"
        "      border: double black;\n"
        "      border-width: 0 0.75rem 0.75rem 0;\n"
        "      display: inline-block;\n"
        "      padding: 1rem;\n"
        "      font-size: 0.5rem;\n"
        "    }\n"
        "    .right {\n"
        "      transform: rotate(-45deg);\n"
        "      -webkit-transform: rotate(-45deg);\n"
        "    }\n"
        "    .left {\n"
        "      transform: rotate(135deg);\n"
        "      -webkit-transform: rotate(135deg);\n"
        "    }\n"
        "    .up {\n"
        "      transform: rotate(-135deg);\n"
        "      -webkit-transform: rotate(-135deg);\n"
        "    }\n"
        "    .down {\n"
        "      transform: rotate(45deg);\n"
        "      -webkit-transform: rotate(45deg);\n"
        "    }\n"
        "    .zoombtn {\n"
        "      font-size:1.25rem;\n"
        "      width: 3rem;\n"
        "      height: 1.5rem;\n"
        "      margin: 0;\n"
        "    }\n"
        "    .cls_movies {\n"
        "      background-color: transparent;\n"
        "      color: white;\n"
        "      text-align: center;\n"
        "      margin-top: 0rem;\n"
        "      margin-bottom: 0rem;\n"
        "      font-weight: normal;\n"
        "      font-size: 0.90rem;\n"
        "    }\n"
        "    a:link {\n"
        "      color: white;\n"
        "      background-color: transparent;\n"
        "      text-decoration: none;\n"
        "    }\n"
        "    a:visited {\n"
        "      color: black;\n"
        "      background-color: transparent;\n"
        "      text-decoration: none;\n"
        "    }\n";

}

/* Write out the starting style section of the web page */
static void webu_html_style_base(ctx_webui *webui)
{

    webui->resp_page +=
        "    * {\n"
        "      margin: 0;\n"
        "      padding: 0;\n"
        "    }\n"
        "    body {\n"
        "      padding: 0;\n"
        "      margin: 0;\n"
        "      font-family: Arial, Helvetica, sans-serif;\n"
        "      font-size: 1rem;\n"
        "      line-height: 1;\n"
        "      color: #606c71;\n"
        "      background-color: #159957;\n"
        "      background-image: linear-gradient(120deg, #155799, #159957);\n"
        "      margin-left:0.5% ;\n"
        "      margin-right:0.5% ;\n"
        "      width: device-width ;\n"
        "    }\n"
        "    .page-header {\n"
        "      color: #fff;\n"
        "      text-align: center;\n"
        "      margin-top: 0rem;\n"
        "      margin-bottom: 0rem;\n"
        "      font-weight: normal;\n"
        "    }\n"
        "    .page-header h3 {\n"
        "      height: 2rem;\n"
        "      padding: 0;\n"
        "      margin: 1rem;\n"
        "      border: 0;\n"
        "    }\n"
        "    h3 {\n"
        "      margin-left: 10rem;\n"
        "    }\n"
        "    .header-right{\n"
        "      float: right;\n"
        "      color: white;\n"
        "    }\n"
        "    .header-center {\n"
        "      text-align: center;\n"
        "      color: white;\n"
        "      margin-top: 1rem;\n"
        "      margin-bottom: 1rem;\n"
        "    }\n"
        "    .border {\n"
        "      border-width: 1rem;\n"
        "      border-color: white;\n"
        "      border-style: solid;\n"
        "    }\n";

}

/* Write out the style section of the web page */
static void webu_html_style(ctx_webui *webui)
{
    webui->resp_page += "  <style>\n";

    webu_html_style_base(webui);

    webu_html_style_navbar(webui);

    webu_html_style_config(webui);

    webui->resp_page += "  </style>\n";

}

/* Create the header section of the page */
static void webu_html_head(ctx_webui *webui)
{

    webui->resp_page += "<head> \n"
        "<meta charset='UTF-8'> \n"
        "<title>MotionPlus</title> \n"
        "<meta name='viewport' content='width=device-width, initial-scale=1'> \n";

    webu_html_style(webui);

    webui->resp_page += "</head>\n\n";

}

/* Create the navigation bar section of the page */
static void webu_html_navbar(ctx_webui *webui)
{
    webui->resp_page +=
        "  <div id=\"divnav_main\" class=\"sidenav\">\n"
        "    <a class='closebtn' onclick='nav_close()'>X</a>\n"
        "    <div id=\"divnav_version\">\n"
        "      <a>MotionPlus 0.0.1</a>\n"
        "    </div>\n"
        "    <button onclick='display_cameras()' "
            " id='cam_btn' class='dropbtn'>Cameras</button>\n"
        "    <div id='divnav_cam' class='dropdown-content'>\n"
        "      <!-- Filled in by script -->\n"
        "    </div>\n"
        "    <button onclick='display_actions()' "
            " id='actions_btn' class='dropbtn'>Actions</button>\n"
        "    <div id='divnav_actions' class='dropdown-content'>\n"
        "      <!-- Filled in by script -->\n"
        "    </div>\n"
        "    <button\n"
        "      onclick='display_config()' id='cfg_btn' class='dropbtn'>\n"
        "      Configuration\n"
        "    </button>\n"
        "    <div id='divnav_config' class='dropdown-content'>\n"
        "      <!-- Filled in by script -->\n"
        "    </div>\n"
        "    <button\n"
        "      onclick='display_movies()' id='mov_btn' class='dropbtn'>\n"
        "      Recordings\n"
        "    </button>\n"
        "    <div id='divnav_movies' class='dropdown-content'>\n"
        "      <!-- Filled in by script -->\n"
        "    </div>\n"
        "  </div>\n\n";

}

/* Create the body main section of the page */
static void webu_html_divmain(ctx_webui *webui)
{
    webui->resp_page +=
        "  <div id='divmain' style='margin-left:10rem' >\n"
        "    <button id='menu_btn' \n"
        "      onclick='nav_open();' \n"
        "      style='display:none' \n"
        "      class='menubtn'>|||</button>\n"
        "    <p></p>\n"
        "    <div id='div_cam' >\n"
        "      <!-- Filled in by script -->\n"
        "    </div>\n\n"
        "    <div id='div_config'>\n"
        "      <!-- Filled in by script -->\n"
        "    </div>\n\n"
        "    <div id='div_movies' class='cls_movies'>\n"
        "      <!-- Filled in by script -->\n"
        "    </div>\n\n"
        "  </div>\n\n";

}

/* Create the javascript function send_config */
static void webu_html_script_nav(ctx_webui *webui)
{
    webui->resp_page +=
        "    function nav_open() {\n"
        "      document.getElementById('divnav_main').style.width = '10rem';\n"
        "      document.getElementById('divmain').style.marginLeft = '10rem';\n"
        "      document.getElementById('menu_btn').style.display= 'none';\n"
        "    }\n\n"

        "    function nav_close() {\n"
        "      document.getElementById('divnav_main').style.width = '0rem';\n"
        "      document.getElementById('divmain').style.marginLeft = '0rem';\n"
        "      document.getElementById('menu_btn').style.display= 'inline';\n"
        "    }\n\n";
}

/* Create the javascript function send_config */
static void webu_html_script_send_config(ctx_webui *webui)
{
    webui->resp_page +=
        "    function send_config(category) {\n"
        "      var formData = new FormData();\n"
        "      var request = new XMLHttpRequest();\n"
        "      var xmlhttp = new XMLHttpRequest();\n"
        "      var camid = document.getElementsByName('camdrop')[0].value;\n"
        "      if (camid == 0) {\n"
        "        var pCfg = pData[\"configuration\"][\"default\"];\n"
        "      } else {\n"
        "        var pCfg = pData[\"configuration\"][\"cam\"+camid];\n"
        "      }\n\n"

        "      xmlhttp.onreadystatechange = function() {\n"
        "        if (this.readyState == 4 && this.status == 200) {\n"
        "          pData = JSON.parse(this.responseText);\n"
        "        }\n"
        "      };\n"

        "      request.onreadystatechange = function() {\n"
        "        if (this.readyState == 4 && this.status == 200) {\n"
        "          xmlhttp.open('GET', pHostFull+'/0/config.json');\n"
        "          xmlhttp.send();\n\n"
        "        }\n"
        "      };\n"

        "      formData.append('command', 'config');\n"
        "      formData.append('camid', camid);\n\n"
        "      for (jkey in pCfg) {\n"
        "        if (document.getElementsByName(jkey)[0] != null) {\n"
        "          if (pCfg[jkey].category == category) {\n"
        "            if (document.getElementsByName(jkey)[0].type == 'checkbox') {\n"
        "              formData.append(jkey, document.getElementsByName(jkey)[0].checked);\n"
        "            } else {\n"
        "              formData.append(jkey, document.getElementsByName(jkey)[0].value);\n"
        "            }\n"
        "          }\n"
        "        }\n"
        "      }\n"
        "      request.open('POST', pHostFull);\n"
        "      request.send(formData);\n\n"
        "    }\n\n";
}

/* Create the send_action javascript function */
static void webu_html_script_send_action(ctx_webui *webui)
{
    webui->resp_page +=
        "    function send_action(actval) {\n\n"

        "      var dsp_cam = document.getElementById('div_cam').style.display;\n"
        "      if ((dsp_cam == 'none' || dsp_cam == '') && (actval != 'config_write')) {\n"
        "        return;\n"
        "      }\n\n"

        "      var formData = new FormData();\n"
        "      var camid;\n"
        "      var ans;\n\n"

        "      camid = assign_camid();\n\n"

        "      if (actval == 'action_user') {\n"
        "        ans = prompt('Enter user parameter');\n"
        "      } else {\n"
        "        ans = '';\n"
        "      }\n\n"

        "      formData.append('command', actval);\n"
        "      formData.append('camid', camid);\n"
        "      formData.append('user', ans);\n\n"
        "      var request = new XMLHttpRequest();\n"
        "      request.open('POST', pHostFull);\n"
        "      request.send(formData);\n\n"
        "      return;\n"
        "    }\n\n";
}

/* Create the send_reload javascript function */
static void webu_html_script_send_reload(ctx_webui *webui)
{
    webui->resp_page +=
        "    function send_reload(actval) {\n\n"
        "      var formData = new FormData();\n"
        "      var request = new XMLHttpRequest();\n"
        "      var xmlhttp = new XMLHttpRequest();\n"
        "      var camid;\n"
        "      var ans;\n\n"

        "      camid = assign_camid();\n\n"

        "      if (actval == 'camera_delete') {\n"
        "        ans = confirm('Delete camera ' + camid);\n"
        "        if (ans == false) {\n"
        "          return;\n"
        "        }\n"
        "      }\n\n"

        "      xmlhttp.onreadystatechange = function() {\n"
        "        if (this.readyState == 4 && this.status == 200) {\n"
        "          pData = JSON.parse(this.responseText);\n"
        "          gIndxCam = -1;\n"
        "          assign_config_nav();\n"
        "          assign_vals(0);\n"
        "          assign_cams();\n"
        "        }\n"
        "      };\n"

        "      request.onreadystatechange = function() {\n"
        "        if (this.readyState == 4 && this.status == 200) {\n"
        "          xmlhttp.open('GET', pHostFull+'/0/config.json');\n"
        "          xmlhttp.send();\n\n"
        "        }\n"
        "      };\n"

        "      formData.append('command', actval);\n"
        "      formData.append('camid', camid);\n\n"

        "      request.open('POST', pHostFull);\n"
        "      request.send(formData);\n\n"

        "    }\n\n";
}

/* Create the javascript function dropchange_cam */
static void webu_html_script_dropchange_cam(ctx_webui *webui)
{
    webui->resp_page +=
        "    function dropchange_cam(camobj) {\n"
        "      var indx;\n\n"

        "      assign_vals(camobj.value);\n\n"

        "      var sect = document.getElementsByName('camdrop');\n"
        "      for (indx = 0; indx < sect.length; indx++) {\n"
        "        sect.item(indx).selectedIndex =camobj.selectedIndex;\n"
        "      }\n\n"

        "      gIndxCam = -1;\n"
        "      for (indx = 0; indx < pData['cameras']['count']; indx++) {\n"
        "        if (pData['cameras'][indx]['id'] == camobj.value) {\n"
        "          gIndxCam = indx;\n"
        "        }\n"
        "      }\n\n"

        "    }\n\n";
}

/* Create the javascript function config_hideall */
static void webu_html_script_config_hideall(ctx_webui *webui)
{
    webui->resp_page +=
        "    function config_hideall() {\n"
        "      var sect = document.getElementsByClassName('cls_config');\n"
        "      for (var i = 0; i < sect.length; i++) {\n"
        "        sect.item(i).style.display='none';\n"
        "      }\n"
        "      return;\n"
        "    }\n\n";
}

/* Create the javascript function config_click */
static void webu_html_script_config_click(ctx_webui *webui)
{
    webui->resp_page +=
        "    function config_click(actval) {\n"
        "      config_hideall();\n"
        "      document.getElementById('div_cam').style.display='none';\n"
        "      document.getElementById('div_movies').style.display='none';\n"
        "      document.getElementById('div_config').style.display='inline';\n"
        "      document.getElementById('div_' + actval).style.display='inline';\n"
        "      cams_reset();\n"
        "    }\n\n";
}

/* Create the javascript function assign_camid */
static void webu_html_script_assign_camid(ctx_webui *webui)
{
    webui->resp_page +=
        "    function assign_camid() {\n"
        "      if (gIndxCam == -1 ) {\n"
        "        camid = 0;\n"
        "      } else {\n"
        "        camid = pData['cameras'][gIndxCam]['id'];\n"
        "      }\n\n"
        "      return camid; \n"
        "    }\n\n";

}


/* Create the javascript function assign_version */
static void webu_html_script_assign_version(ctx_webui *webui)
{
    webui->resp_page +=
        "    function assign_version() {\n"
        "      var verstr ='<a>MotionPlus \\n'+pData['version'] +'</a>';\n"
        "      document.getElementById('divnav_version').innerHTML = verstr;\n"
        "    }\n\n";

}

/* Create the javascript function assign_cams */
static void webu_html_script_assign_cams(ctx_webui *webui)
{
    webui->resp_page +=
        "    function assign_cams() {\n"
        "      var camcnt = pData['cameras']['count'];\n"
        "      var indx = 0;\n"
        "      var html_drop = \"\\n\";\n"
        "      var html_nav = \"\\n\";\n"
        "      var html_mov = \"\\n\";\n\n"
        "      html_drop += \" <select class='cls_drop' \";\n"
        "      html_drop += \" onchange='dropchange_cam(this)' \";\n"
        "      html_drop += \" name='camdrop'>\\n\";\n\n"
        "      for (indx=0; indx<camcnt; indx++) {\n"
        "        if (indx == 0) {\n"
        "          html_nav += \"<a onclick='cams_all_click();'>\";\n"
        "          html_nav += \"All Cameras</a>\\n\";\n"
        "          html_nav += \"<a onclick='cams_scan_click();'>\";\n"
        "          html_nav += \"Scan Cameras</a>\\n\";\n\n"
        "          html_drop += \"<option \";\n"
        "          html_drop += \" value='0'>default\";\n"
        "          html_drop += \"</option>\\n\";\n"
        "        }\n\n"
        "        html_nav += \"<a onclick='cams_one_click(\" + indx + \");'>\";\n"
        "        html_nav += pData[\"cameras\"][indx][\"name\"] + \"</a>\\n\";\n"
        "        html_mov += \"<a onclick='movies_click(\" + indx + \");'>\";\n"
        "        html_mov += pData[\"cameras\"][indx][\"name\"] + \"</a>\";\n"
        "        html_drop += \"<option \";\n"
        "        html_drop += \" value='\"+pData[\"cameras\"][indx][\"id\"]+\"'>\";\n"
        "        html_drop += pData[\"cameras\"][indx][\"name\"];\n"
        "        html_drop += \"</option>\\n\";\n"
        "      }\n"
        "      html_drop += \" </select>\\n\";\n\n"
        "      var sect = document.getElementsByClassName(\"cls_camdrop\");\n"
        "      for (indx = 0; indx < sect.length; indx++) {\n"
        "        sect.item(indx).innerHTML = html_drop;\n"
        "      }\n\n"
        "      document.getElementById(\"divnav_cam\").innerHTML = html_nav;\n\n"
        "      document.getElementById(\"divnav_movies\").innerHTML = html_mov;\n\n"
        "      return;\n"
        "    }\n\n";
}

/* Create the javascript function assign_actions */
static void webu_html_script_assign_actions(ctx_webui *webui)
{
    int indx;
    ctx_params *wact;

    webui->resp_page +=
        "    function assign_actions() {\n"
        "      var html_actions = \"\\n\";\n"
        "      html_actions += \"  \";\n";

    wact = webui->motapp->webcontrol_actions;
    for (indx = 0; indx < wact->params_count; indx++) {
        if (mystreq(wact->params_array[indx].param_name,"snapshot") &&
            mystreq(wact->params_array[indx].param_value,"on")) {
            webui->resp_page +=
                "      html_actions += \"<a onclick=\\\"send_action(\";\n"
                "      html_actions += \"'snapshot');\\\">\";\n"
                "      html_actions += \"Snapshot</a>\\n\";\n\n"
                ;
        } else if (mystreq(wact->params_array[indx].param_name,"event") &&
            mystreq(wact->params_array[indx].param_value,"on")) {
            webui->resp_page +=
            "      html_actions += \"<a onclick=\\\"send_action(\";\n"
            "      html_actions += \"'eventstart');\\\">\";\n"
            "      html_actions += \"Start Event</a>\\n\";\n\n"

            "      html_actions += \"<a onclick=\\\"send_action(\";\n"
            "      html_actions += \"'eventend');\\\">\";\n"
            "      html_actions += \"End Event</a>\\n\";\n\n"
            ;
        } else if (mystreq(wact->params_array[indx].param_name,"pause") &&
            mystreq(wact->params_array[indx].param_value,"on")) {
            webui->resp_page +=
                "      html_actions += \"<a onclick=\\\"send_action(\";\n"
                "      html_actions += \"'pause');\\\">\";\n"
                "      html_actions += \"Pause</a>\\n\";\n\n"

                "      html_actions += \"<a onclick=\\\"send_action(\";\n"
                "      html_actions += \"'unpause');\\\">\";\n"
                "      html_actions += \"Unpause</a>\\n\";\n\n"
                ;
        } else if (mystreq(wact->params_array[indx].param_name,"camera_add") &&
            mystreq(wact->params_array[indx].param_value,"on")) {
            webui->resp_page +=
                "      html_actions += \"<a onclick=\\\"send_reload(\";\n"
                "      html_actions += \"'camera_add');\\\">\";\n"
                "      html_actions += \"Add Camera</a>\\n\";\n\n"
                ;
        } else if (mystreq(wact->params_array[indx].param_name,"camera_delete") &&
            mystreq(wact->params_array[indx].param_value,"on")) {
            webui->resp_page +=
                "      html_actions += \"<a onclick=\\\"send_reload(\";\n"
                "      html_actions += \"'camera_delete');\\\">\";\n"
                "      html_actions += \"Delete Camera</a>\\n\";\n\n"
                ;
        } else if (mystreq(wact->params_array[indx].param_name,"config_write") &&
            mystreq(wact->params_array[indx].param_value,"on")) {
            webui->resp_page +=
                "      html_actions += \"<a onclick=\\\"send_action(\";\n"
                "      html_actions += \"'config_write');\\\">\";\n"
                "      html_actions += \"Save Config</a>\\n\";\n\n"
                ;
        } else if (mystreq(wact->params_array[indx].param_name,"stop") &&
            mystreq(wact->params_array[indx].param_value,"on")) {
            webui->resp_page +=
                "      html_actions += \"<a onclick=\\\"send_action(\";\n"
                "      html_actions += \"'stop');\\\">\";\n"
                "      html_actions += \"Stop</a>\\n\";\n\n"
                ;
        } else if (mystreq(wact->params_array[indx].param_name,"restart") &&
            mystreq(wact->params_array[indx].param_value,"on")) {
            webui->resp_page +=
                "      html_actions += \"<a onclick=\\\"send_action(\";\n"
                "      html_actions += \"'restart');\\\">\";\n"
                "      html_actions += \"Start/Restart</a>\\n\";\n\n"
                ;
        } else if (mystreq(wact->params_array[indx].param_name,"action_user") &&
            mystreq(wact->params_array[indx].param_value,"on")) {
            webui->resp_page +=
                "      html_actions += \"<a onclick=\\\"send_action(\";\n"
                "      html_actions += \"'action_user');\\\">\";\n"
                "      html_actions += \"User Action</a>\\n\";\n\n"
                ;
        }
    }

    webui->resp_page +=
        "      document.getElementById(\"divnav_actions\").innerHTML = html_actions;\n\n"
        "      return;\n"

        "    }\n\n";


}


/* Create the javascript function assign_vals */
static void webu_html_script_assign_vals(ctx_webui *webui)
{
    webui->resp_page +=
        "    function assign_vals(camid) {\n"
        "      var pCfg;\n\n"

        "     if (camid == 0) {\n"
        "       pCfg = pData[\"configuration\"][\"default\"];\n"
        "     } else {\n"
        "       pCfg = pData[\"configuration\"][\"cam\"+camid];\n"
        "     }\n\n"

        "      for (jkey in pCfg) {\n"
        "        if (document.getElementsByName(jkey)[0] != null) {\n"
        "          if (pCfg[jkey].enabled) {\n"
        "            document.getElementsByName(jkey)[0].disabled = false;\n"
        "            if (document.getElementsByName(jkey)[0].type == \"checkbox\") {\n"
        "              document.getElementsByName(jkey)[0].checked = pCfg[jkey].value;\n"
        "            } else {\n"
        "              document.getElementsByName(jkey)[0].value = pCfg[jkey].value;\n"
        "            }\n"
        "          } else {\n"
        "            document.getElementsByName(jkey)[0].disabled = true;\n"
        "            document.getElementsByName(jkey)[0].value = '';\n"
        "          }\n"
        "        } else {\n"
        "          console.log('Uncoded ' + jkey + ' : ' + pCfg[jkey].value);\n"
        "        }\n"
        "      }\n"
        "    }\n\n";
}

/* Create the javascript function assign_config_nav */
static void webu_html_script_assign_config_nav(ctx_webui *webui)
{
    webui->resp_page +=
        "    function assign_config_nav() {\n"
        "      var pCfg = pData['configuration']['default'];\n"
        "      var pCat = pData['categories'];\n"
        "      var html_nav = \"\\n\";\n\n"

        "      for (jcat in pCat) {\n"
        "        html_nav += \"<a onclick=\\\"config_click('\";\n"
        "        html_nav += pCat[jcat][\"name\"]+\"');\\\">\";\n"
        "        html_nav += pCat[jcat][\"display\"]+\"</a>\\n\";\n\n"
        "      }\n\n"

        "      document.getElementById(\"divnav_config\").innerHTML = html_nav;\n\n"

        "    }\n\n";
}

/* Create the javascript function assign_config_item */
static void webu_html_script_assign_config_item(ctx_webui *webui)
{
    webui->resp_page +=
        "    function assign_config_item(jkey) {\n"
        "      var pCfg = pData['configuration']['default'];\n"
        "      var html_cfg = \"\";\n"
        "      var indx_lst = 0;\n\n"

        "      html_cfg += \"<tr><td><label for='\";\n"
        "      html_cfg += jkey + \"'>\"+jkey+\"</label></td>\\n\";\n\n"
        "      if (pCfg[jkey][\"type\"] == \"string\") {\n"
        "        html_cfg += \"<td><textarea name='\";\n"
        "        html_cfg += jkey+\"'></textarea></td>\";\n\n"
        "      } else if (pCfg[jkey][\"type\"] == \"bool\") {\n"
        "        html_cfg += \"<td><input class='cfg_check' \";\n"
        "        html_cfg += \" type='checkbox' name='\";\n"
        "        html_cfg += jkey+\"'></td>\";\n\n"
        "      } else if (pCfg[jkey][\"type\"] == \"int\") {\n"
        "        html_cfg += \"<td><input class='cls_text_nbr' \";\n"
        "        html_cfg += \"type='text' name='\";\n"
        "        html_cfg += jkey+\"'></td>\";\n\n"
        "      } else if (pCfg[jkey][\"type\"] == \"list\") {\n"
        "        html_cfg += \"<td><select class='cls_drop' \";\n"
        "        html_cfg += \" name='\"+jkey+\"'  autocomplete='off'>\";\n\n"
        "        for (indx_lst=0; indx_lst < pCfg[jkey][\"list\"].length; indx_lst++) {\n"
        "          html_cfg += \"<option value='\";\n"
        "          html_cfg += pCfg[jkey][\"list\"][indx_lst] + \"'>\";\n"
        "          html_cfg += pCfg[jkey][\"list\"][indx_lst] + \"</option>\\n\";\n"
        "        }\n"
        "        html_cfg += \"</select></td>\";\n"
        "      }\n"
        "      html_cfg += \"</tr>\\n\";\n\n"

        "      return html_cfg;\n\n"

        "    }\n\n";
}

/* Create the javascript function assign_config_cat */
static void webu_html_script_assign_config_cat(ctx_webui *webui)
{
    webui->resp_page +=
        "    function assign_config_cat(jcat) {\n"
        "      var pCfg = pData['configuration']['default'];\n"
        "      var pCat = pData['categories'];\n"
        "      var html_cfg = \"\";\n\n"

        "      html_cfg += \"<div id='div_\";\n"
        "      html_cfg += pCat[jcat][\"name\"];\n"
        "      html_cfg += \"' style='display:none' class='cls_config'>\\n\";\n"
        "      html_cfg += \"<h3>\";\n"
        "      html_cfg += pCat[jcat][\"display\"];\n"
        "      html_cfg += \" Parameters</h3>\\n\";\n"
        "      html_cfg += \"<table><tr> <td><label for 'camdrop'>camera</label></td>\\n\";\n"
        "      html_cfg += \"<td class='cls_camdrop'>\";\n"
        "      html_cfg += \"<select class='cls_drop' \";\n"
        "      html_cfg += \"onchange='dropchange_cam.call(this)' \";\n"
        "      html_cfg += \"name='camdrop'>\\n\";\n"
        "      html_cfg += \"<option value='0000'>default</option>\\n\";\n"
        "      html_cfg += \"</select></td></tr>\\n\";\n\n"
        "      for (jkey in pCfg) {\n"
        "        if (pCfg[jkey][\"category\"] == jcat) {\n"
        "          html_cfg += assign_config_item(jkey); \n"
        "        }\n"
        "      }\n"
        "      html_cfg += \"<tr><td><input type='hidden' name='trailer' value='null'></td>\\n\";\n"
        "      html_cfg += \"<td> <button onclick='send_config(\";\n"
        "      html_cfg += jcat + \")'>Submit</button></td></tr>\\n\";\n"
        "      html_cfg += \"</table></div>\\n\";\n\n"

        "      return html_cfg;\n\n"

        "    }\n\n";
}

/* Create the javascript function assign_config */
static void webu_html_script_assign_config(ctx_webui *webui)
{

    webui->resp_page +=
        "    function assign_config() {\n"
        "      var pCat = pData['categories'];\n"
        "      var html_cfg = \"\";\n\n"

        "      assign_config_nav();\n\n"

        "      for (jcat in pCat) {\n"
        "        html_cfg += assign_config_cat(jcat);\n"
        "      }\n\n"

        "      document.getElementById(\"div_config\").innerHTML = html_cfg;\n\n"

        "    }\n\n";
}

/* Create the javascript function init_form */
static void webu_html_script_initform(ctx_webui *webui)
{
    webui->resp_page +=
        "    function initform() {\n"
        "      var xmlhttp = new XMLHttpRequest();\n\n"

        "      pHostFull = '//' + window.location.hostname;\n"
        "      pHostFull = pHostFull + ':' + window.location.port;\n\n"

        "      xmlhttp.onreadystatechange = function() {\n"
        "        if (this.readyState == 4 && this.status == 200) {\n"
        "          pData = JSON.parse(this.responseText);\n"
        "          gIndxCam  = -1;\n"
        "          gGetImgs  = 1;\n"
        "          gIndxScan = -1;\n\n"

        "          assign_config();\n"
        "          assign_version();\n"
        "          assign_vals(0);\n"
        "          assign_cams();\n"
        "          assign_actions();\n"
        "          cams_all_click();\n"
        "          nav_close();\n"

        "        }\n"
        "      };\n"
        "      xmlhttp.open('GET', pHostFull+'/0/config.json');\n"
        "      xmlhttp.send();\n"
        "    }\n\n";
}

/* Create the javascript function display_cameras */
static void webu_html_script_display_cameras(ctx_webui *webui)
{
    webui->resp_page +=
        "    function display_cameras() {\n"
        "      document.getElementById('divnav_config').style.display = 'none';\n"
        "      document.getElementById('divnav_actions').style.display = 'none';\n"
        "      document.getElementById('divnav_movies').style.display = 'none';\n"
        "      if (document.getElementById('divnav_cam').style.display == 'block'){\n"
        "        document.getElementById('divnav_cam').style.display = 'none';\n"
        "      } else {\n"
        "        document.getElementById('divnav_cam').style.display = 'block';\n"
        "      }\n"
        "    }\n\n";
}

/* Create the javascript function display_config */
static void webu_html_script_display_config(ctx_webui *webui)
{
    webui->resp_page +=
        "    function display_config() {\n"
        "      document.getElementById('divnav_cam').style.display = 'none';\n"
        "      document.getElementById('divnav_actions').style.display = 'none';\n"
        "      document.getElementById('divnav_movies').style.display = 'none';\n"
        "      if (document.getElementById('divnav_config').style.display == 'block') {\n"
        "        document.getElementById('divnav_config').style.display = 'none';\n"
        "      } else {\n"
        "        document.getElementById('divnav_config').style.display = 'block';\n"
        "      }\n"
        "      gIndxScan = -1; \n"
        "      cams_timer_stop();\n"
        "    }\n\n";
}

/* Create the javascript function display_movies */
static void webu_html_script_display_movies(ctx_webui *webui)
{
    webui->resp_page +=
        "    function display_movies() {\n"
        "      document.getElementById('divnav_cam').style.display = 'none';\n"
        "      document.getElementById('divnav_actions').style.display = 'none';\n"
        "      document.getElementById('divnav_config').style.display = 'none';\n"
        "      if (document.getElementById('divnav_movies').style.display == 'block') {\n"
        "        document.getElementById('divnav_movies').style.display = 'none';\n"
        "      } else {\n"
        "        document.getElementById('divnav_movies').style.display = 'block';\n"
        "      }\n"
        "      gIndxScan = -1; \n"
        "      cams_timer_stop();\n"
        "    }\n\n";
}

/* Create the javascript function display_actions */
static void webu_html_script_display_actions(ctx_webui *webui)
{
    webui->resp_page +=
        "    function display_actions() {\n"
        "      document.getElementById('divnav_cam').style.display = 'none';\n"
        "      document.getElementById('divnav_config').style.display = 'none';\n"
         "     if (document.getElementById('divnav_actions').style.display == 'block') {\n"
        "        document.getElementById('divnav_actions').style.display = 'none';\n"
        "      } else {\n"
        "        document.getElementById('divnav_actions').style.display = 'block';\n"
        "      }\n"
        "      gIndxScan = -1; \n"
        "    }\n\n";
}

/* Create the camera_buttons_ptz javascript function */
static void webu_html_script_camera_buttons_ptz(ctx_webui *webui)
{

    webui->resp_page +=
        "    function camera_buttons_ptz() {\n\n"
        "      var html_preview = \"\";\n"

        "      html_preview += \"<table style='float: left' >\";\n"
        "      html_preview += \"<tr><td>&nbsp&nbsp</td><td>&nbsp&nbsp</td></tr>\\n\";\n"

        "      html_preview += \"<tr><td></td><td><button \\n\";\n"
        "      html_preview += \"onclick=\\\"send_action('tilt_up');\\\" \\n\";\n"
        "      html_preview += \"class=\\\"arrow up\\\" \\n\";\n"
        "      html_preview += \"></button></td></tr> \\n\";\n"

        "      html_preview += \"<tr><td><button \\n\";\n"
        "      html_preview += \"onclick=\\\"send_action('pan_left');\\\" \\n\";\n"
        "      html_preview += \"class=\\\"arrow left\\\" \\n\";\n"
        "      html_preview += \"></button></td><td></td> \\n\";\n"

        "      html_preview += \"<td><button \\n\";\n"
        "      html_preview += \"onclick=\\\"send_action('pan_right');\\\" \\n\";\n"
        "      html_preview += \"class=\\\"arrow right\\\" \\n\";\n"
        "      html_preview += \"></button></td><td>&nbsp&nbsp</td> \\n\";\n"

        "      html_preview += \"<td>&nbsp</td><td><button \\n\";\n"
        "      html_preview += \"onclick=\\\"send_action('zoom_in');\\\" \\n\";\n"
        "      html_preview += \"class=\\\"zoombtn\\\" \\n\";\n"
        "      html_preview += \">+</button></td> \\n\";\n"

        "      html_preview += \"<td>&nbsp</td><td><button \\n\";\n"
        "      html_preview += \"onclick=\\\"send_action('zoom_out');\\\" \\n\";\n"
        "      html_preview += \"class=\\\"zoombtn\\\" \\n\";\n"
        "      html_preview += \">-</button></td></tr> \\n\";\n"

        "      html_preview += \"<tr><td></td><td><button \\n\";\n"
        "      html_preview += \"onclick=\\\"send_action('tilt_down');\\\" \\n\";\n"
        "      html_preview += \"class=\\\"arrow down\\\" \\n\";\n"
        "      html_preview += \"></button></td></tr> \\n\";\n"
        "      html_preview += \"<tr><td>&nbsp&nbsp</td><td>&nbsp&nbsp</td></tr>\\n\";\n"
        "      html_preview += \"</table><p></p>\";\n"

        "      return html_preview;\n\n"

        "    }\n\n";

}

/* Create the image_pantilt javascript function */
static void webu_html_script_image_pantilt(ctx_webui *webui)
{
    webui->resp_page +=
        "    function image_pantilt() {\n\n"
        "      if (gIndxCam == -1 ) {\n"
        "        return;\n"
        "      }\n\n"
        "      document.getElementById('pic'+ gIndxCam).addEventListener('click',function(event){\n"
        "        bounds=this.getBoundingClientRect();\n"
        "        var x = Math.floor(event.pageX - bounds.left - window.scrollX);\n"
        "        var y = Math.floor(event.pageY - bounds.top - window.scrollY);\n"
        "        var w = Math.floor(bounds.width);\n"
        "        var h = Math.floor(bounds.height);\n"
        "        var qtr_x = Math.floor(bounds.width/4);\n"
        "        var qtr_y = Math.floor(bounds.height/4);\n"
        "        if ((x > qtr_x) && (x < (w - qtr_x)) && (y < qtr_y)) {\n"
        "          send_action('tilt_up');\n"
        "        } else if ((x > qtr_x) && (x < (w - qtr_x)) && (y >(h - qtr_y))) {\n"
        "          send_action('tilt_down');\n"
        "        } else if ((x < qtr_x) && (y > qtr_y) && (y < (h - qtr_y))) {\n"
        "           send_action('pan_left');\n"
        "        } else if ((x >(w - qtr_x)) && (y > qtr_y) && (y < (h - qtr_y))) {\n"
        "           send_action('pan_right');\n"
        "        }\n"
        "      });\n"
        "    }\n\n";

}

/* Create the cams_reset javascript function */
static void webu_html_script_cams_reset(ctx_webui *webui)
{

    webui->resp_page +=
        "    function cams_timer_stop() {\n"
        "      clearInterval(cams_one_timer);\n"
        "      clearInterval(cams_all_timer);\n"
        "      clearInterval(cams_scan_timer);\n"
        "    }\n\n";

    webui->resp_page +=
        "    function cams_reset() {\n"
        "      var indx, camcnt;\n"
        "      camcnt = pData['cameras']['count'];\n"
        "      for (indx=0; indx<camcnt; indx++) {\n"
        "        if (document.getElementById('pic'+indx) != null) { \n"
        "          document.getElementById('pic'+indx).src = ''; \n"
        "        }\n"
        "      }\n"
        "    } \n\n";

}

/* Create the cams_one_click javascript function */
static void webu_html_script_cams_one_click(ctx_webui *webui)
{

    webui->resp_page +=
        "    function cams_one_click(index_cam) {\n\n"
        "      var html_preview = \"\";\n"
        "      var camid;\n\n"
        "      config_hideall();\n"
        "      cams_timer_stop();\n"
        "      gIndxCam = index_cam;\n\n"
        "      gIndxScan = -1; \n\n"

        "      if (gIndxCam == -1 ) {\n"
        "        return;\n"
        "      }\n\n"

        "      camid = pData['cameras'][index_cam].id;\n"

        "      if ((pData['configuration']['cam'+camid].stream_preview_ptz.value == true)) {\n"
        "        html_preview += camera_buttons_ptz();\n"
        "      }\n\n"
        "      if (pData['configuration']['cam'+camid].stream_preview_method.value == 'static') {\n"
        "        html_preview += \"<a><img id='pic\" + gIndxCam + \"' src=\";\n"
        "        html_preview += pData['cameras'][gIndxCam]['url'];\n"
        "        html_preview += \"static/stream/t\" + new Date().getTime();\n"
        "        html_preview += \" border=0 width=95%></a>\\n\";\n"
        "      } else { \n"
        "        html_preview += \"<a><img id='pic\" + gIndxCam + \"' src=\";\n"
        "        html_preview += pData['cameras'][gIndxCam]['url'];\n"
        "        html_preview += \"mjpg/stream\" ;\n"
        "        html_preview += \" border=0 width=95%></a>\\n\";\n"
        "      }\n"
        "      document.getElementById('div_config').style.display='none';\n"
        "      document.getElementById('div_movies').style.display = 'none';\n"
        "      cams_reset();\n"
        "      document.getElementById('div_cam').style.display='block';\n"
        "      document.getElementById('div_cam').innerHTML = html_preview;\n\n"
        "      image_pantilt();\n\n"
        "      cams_one_timer = setInterval(cams_one_fnc, 1000);\n\n"
        "    }\n\n";

}

/* Create the cams_all_click javascript function */
static void webu_html_script_cams_all_click(ctx_webui *webui)
{

    webui->resp_page +=
        "    function cams_all_click() {\n\n"
        "      var html_preview = \"\";\n"
        "      var indx;\n"
        "      var camid;\n\n"

        "      config_hideall();\n"
        "      cams_timer_stop();\n"
        "      gIndxCam = -1;\n"
        "      gIndxScan = -1; \n\n"
        "      var camcnt = pData['cameras']['count'];\n"
        "      html_preview += \"</table>\";\n"
        "      for (indx=0; indx<camcnt; indx++) {\n"
        "        camid = pData['cameras'][indx].id;\n"
        "        if (pData['configuration']['cam'+camid].stream_preview_method.value == 'static') {\n"
        "          html_preview += \"<a><img id='pic\" + indx + \"' src=\"\n"
        "          html_preview += pData['cameras'][indx]['url'];\n"
        "          html_preview += \"static/stream/t\" + new Date().getTime();\n"
        "          html_preview += \" onclick='cams_one_click(\" + indx + \")' \";\n"
        "          html_preview += \" border=0 width=\";\n"
        "          html_preview += pData['configuration']['cam'+camid].stream_preview_scale.value;\n"
        "          html_preview += \"%></a>\\n\";\n"
        "          if (pData['configuration']['cam'+camid].stream_preview_newline.value == true) {\n"
        "            html_preview += \"<br>\\n\";\n"
        "          }\n"
        "        } else { \n"
        "          html_preview += \"<a><img id='pic\" + indx + \"' src=\"\n"
        "          html_preview += pData['cameras'][indx]['url'];\n"
        "          html_preview += \"mjpg/stream\" ;\n"
        "          html_preview += \" onclick='cams_one_click(\" + indx + \")' \";\n"
        "          html_preview += \" border=0 width=\";\n"
        "          html_preview += pData['configuration']['cam'+camid].stream_preview_scale.value;\n"
        "          html_preview += \"%></a>\\n\";\n"
        "          if (pData['configuration']['cam'+camid].stream_preview_newline.value == true) {\n"
        "            html_preview += \"<br>\\n\";\n"
        "          }\n"
        "        } \n"
        "      }\n"
        "      document.getElementById('div_config').style.display='none';\n"
        "      document.getElementById('div_movies').style.display = 'none';\n"
        "      cams_reset();\n"
        "      document.getElementById('div_cam').style.display='block';\n"
        "      document.getElementById('div_cam').innerHTML = html_preview;\n"
        "      cams_all_timer = setInterval(cams_all_fnc, 1000);\n\n"
        "  }\n\n";
}
/* Create the movies_page javascript function */
static void webu_html_script_movies_page(ctx_webui *webui)
{
    webui->resp_page +=
        "    function movies_page() {\n\n"
        "      var html_tab = \"<div>\";\n"
        "      var indx, movcnt, camid, uri;\n"
        "      var fname,fsize,fdate;\n\n"

        "      if (gIndxCam == -1 ) {\n"
        "        return;\n"
        "      }\n\n"

        "      camid = assign_camid();\n"
        "      uri = pHostFull+'/'+camid+'/movies/';\n\n"

        "      movcnt = pMovies['movies'][gIndxCam].count;\n"
        "      html_tab +=\"<table style='color:white;' >\";\n"
        "      html_tab +=\"  <colgroup width='20%'></colgroup>\";\n"
        "      html_tab +=\"  <colgroup width='2%'></colgroup>\";\n"
        "      html_tab +=\"  <colgroup width='2%'></colgroup>\";\n"
        "      html_tab +=\"  <colgroup width='2%'></colgroup>\";\n"
        "      html_tab +=\"  <colgroup width='2%'></colgroup>\";\n"
        "      html_tab +=\"  <colgroup width='2%'></colgroup>\";\n"
        "      html_tab +=\"  <colgroup width='2%'></colgroup>\";\n"
        "      html_tab +=\"  <colgroup width='2%'></colgroup>\";\n"
        "      html_tab +=\"  <colgroup width='2%'></colgroup>\";\n"

        "      html_tab +=\"  <tr>\";\n"
        "      html_tab +=\"    <td align='left'><b>Name</b></td>\";\n"
        "      html_tab +=\"    <td align='left'><b>Size</b></td>\";\n"
        "      html_tab +=\"    <td align='left'><b>Date</b></td>\";\n"
        "      html_tab +=\"    <td align='left'><b>time</b></td>\";\n"
        "      html_tab +=\"    <td align='left'><b>diff_avg</b></td>\";\n"
        "      html_tab +=\"    <td align='left'><b>sdev_min</b></td>\";\n"
        "      html_tab +=\"    <td align='left'><b>sdev_max</b></td>\";\n"
        "      html_tab +=\"    <td align='left'><b>sdev_avg</b></td>\";\n"
        "      html_tab +=\"    <td align='left'><b></b></td>\";\n"
        "      html_tab +=\"  </tr>\";\n\n"

        "      for (indx = 0; indx < movcnt; indx++) {\n"
        "        fname = pMovies['movies'][gIndxCam][indx]['name'];\n"
        "        fsize = pMovies['movies'][gIndxCam][indx]['size'];\n"
        "        fdate = pMovies['movies'][gIndxCam][indx]['date'];\n\n"
        "        ftime = pMovies['movies'][gIndxCam][indx]['time'];\n\n"
        "        fdavg = pMovies['movies'][gIndxCam][indx]['diff_avg'];\n\n"
        "        fsmin = pMovies['movies'][gIndxCam][indx]['sdev_min'];\n\n"
        "        fsmax = pMovies['movies'][gIndxCam][indx]['sdev_max'];\n\n"
        "        fsavg = pMovies['movies'][gIndxCam][indx]['sdev_avg'];\n\n"

        "        html_tab +=\"<tr>\";\n"
        "        html_tab +=\"  <td align='left'><a href='\"\n"
        "        html_tab += uri + fname + \"'>\" + fname + \"</a></td>\";\n"

        "        html_tab +=\"  <td align='center'>\"+fsize+\"</td>\";\n"
        "        html_tab +=\"  <td align='center'>\"+fdate+\"</td>\";\n"
        "        html_tab +=\"  <td align='center'>\"+ftime+\"</td>\";\n"
        "        html_tab +=\"  <td align='center'>\"+fdavg+\"</td>\";\n"
        "        html_tab +=\"  <td align='center'>\"+fsmin+\"</td>\";\n"
        "        html_tab +=\"  <td align='center'>\"+fsmax+\"</td>\";\n"
        "        html_tab +=\"  <td align='center'>\"+fsavg+\"</td>\";\n"

        "        html_tab +=\"  <td align='center'> </td>\";\n"
        "        html_tab +=\"</tr>\";\n"
        "      }\n"
        "      html_tab +=\"</table>\";\n"
        "      html_tab +=\"</div>\";\n\n"

        "      document.getElementById('div_config').style.display='none';\n"
        "      document.getElementById('div_cam').style.display='none';\n"
        "      cams_reset();\n"
        "      document.getElementById('div_movies').style.display='block';\n"
        "      document.getElementById('div_movies').innerHTML = html_tab;\n\n"
        "    }\n\n";

}

/* Create the movies_page javascript function */
static void webu_html_script_movies_click(ctx_webui *webui)
{

    webui->resp_page +=
        "    function movies_click(index_cam) {\n"
        "      var camid, indx, camcnt, uri;\n\n"

        "      gIndxCam = index_cam;\n"
        "      gIndxScan = -1; \n"
        "      camid = assign_camid();\n"
        "      uri = pHostFull+'/'+camid+'/movies.json';\n\n"
        "      config_hideall();\n"
        "      cams_reset();\n"
        "      var xmlhttp = new XMLHttpRequest();\n"
        "      xmlhttp.onreadystatechange = function() {\n"
        "        if (this.readyState == 4 && this.status == 200) {\n"
        "          pMovies = JSON.parse(this.responseText);\n"
        "          movies_page();\n"
        "        }\n"
        "      };\n"
        "      xmlhttp.open('GET', uri);\n"
        "      xmlhttp.send();\n"
        "    }\n\n";

}
/* Create the cams_scan_click javascript function */
static void webu_html_script_cams_scan_click(ctx_webui *webui)
{
    webui->resp_page +=
        "    function cams_scan_click() {\n\n"
        "      cams_timer_stop();\n\n"
        "      gIndxCam = -1; \n"
        "      gIndxScan = 0; \n\n"
        "      cams_scan_timer = setInterval(cams_scan_fnc, 5);\n"
        "    }\n\n";
}

/* Create the cams_one_fnc javascript function */
static void webu_html_script_cams_one_fnc(ctx_webui *webui)
{
    webui->resp_page +=
        "    function cams_one_fnc () {\n"
        "      var img = new Image();\n"
        "      var camid;\n\n"
        "      if (gIndxCam == -1 ) {\n"
        "        return;\n"
        "      }\n\n"
        "      camid = pData['cameras'][gIndxCam]['id'];\n\n"
        "      if (pData['configuration']['cam'+camid].stream_preview_method.value == 'static') {\n"
        "        pic_url[0] = pData['cameras'][gIndxCam]['url'] + \"static/stream/t\" + new Date().getTime();\n"
        "        img.src = pic_url[0];\n"
        "        document.getElementById('pic'+gIndxCam).src = pic_url[0];\n"
        "      }\n"
        "    }\n\n ";

}

/* Create the cams_all_fnc javascript function */
static void webu_html_script_cams_all_fnc(ctx_webui *webui)
{
    webui->resp_page +=
        "    function cams_all_fnc () {\n"
        "      var previndx = gGetImgs;\n"
        "      gGetImgs++;\n"
        "      if (gGetImgs >= pData['cameras']['count']) {\n"
        "        gGetImgs = 0;\n"
        "      }\n"
        "      camid = pData['cameras'][gGetImgs]['id'];\n"
        "      if (pData['configuration']['cam'+camid].stream_preview_method.value == 'static') {\n"
        "        document.getElementById('pic'+previndx).src =\n"
        "          pData['cameras'][previndx]['url'] + \"static/stream/t\" + new Date().getTime();\n"
        "        document.getElementById('pic'+gGetImgs).src =\n"
        "          pData['cameras'][gGetImgs]['url'] + \"mjpg/stream\";\n"
        "      }\n"
        "    }\n\n";

}

/* Create the scancam_function javascript function */
static void webu_html_script_cams_scan_fnc(ctx_webui *webui)
{
    webui->resp_page +=
        "    function cams_scan_fnc() {\n"
        "      var html_preview = \"\";\n"
        "      var camid;\n"
        "      var camcnt = pData['cameras']['count'];\n\n"
        "      cams_reset();\n"

        "      if(gIndxScan == -1) {\n"
        "        clearInterval(cams_scan_timer);\n"
        "        return;\n"
        "      }\n\n"

        "      if(gIndxScan == (camcnt-1)) {\n"
        "        gIndxScan = 0;\n"
        "      } else { \n"
        "        gIndxScan++;\n"
        "      }\n\n"

        "      camid = pData['cameras'][gIndxScan]['id'];\n"
        "      clearInterval(cams_scan_timer);\n"

        "      cams_scan_timer = setInterval(cams_scan_fnc,\n"
        "        pData['configuration']['cam'+camid].stream_scan_time.value * 1000 \n"
        "      );\n"

        "      html_preview += \"<a><img id='pic0' src=\"\n"
        "      html_preview += pData['cameras'][gIndxScan]['url'];\n"
        "      html_preview += \"mjpg/stream\" ;\n"
        "      html_preview += \" onclick='cams_one_click(\" + gIndxScan + \")' \";\n"
        "      html_preview += \" border=0 width=\";\n"
        "      html_preview += pData['configuration']['cam'+camid].stream_scan_scale.value;\n"
        "      html_preview += \"%></a>\\n\";\n"
        "      document.getElementById('div_config').style.display='none';\n"
        "      document.getElementById('div_movies').style.display='none';\n"
        "      cams_reset();\n"
        "      document.getElementById('div_cam').style.display='block';\n"
        "      document.getElementById('div_cam').innerHTML = html_preview;\n"
        "    };\n\n";

}

/* Call all the functions to create the java scripts of page*/
static void webu_html_script(ctx_webui *webui)
{
    webui->resp_page += "  <script>\n"
        "    var pData, pMovies, pHostFull;\n"
        "    var gIndxScan, gIndxCam, gGetImgs;\n"
        "    var pic_url = Array(4);\n"
        "    var cams_scan_timer, cams_all_timer, cams_one_timer;\n\n";

    webu_html_script_nav(webui);

    webu_html_script_send_config(webui);
    webu_html_script_send_action(webui);
    webu_html_script_send_reload(webui);

    webu_html_script_dropchange_cam(webui);
    webu_html_script_config_hideall(webui);
    webu_html_script_config_click(webui);

    webu_html_script_assign_camid(webui);
    webu_html_script_assign_version(webui);
    webu_html_script_assign_cams(webui);
    webu_html_script_assign_actions(webui);
    webu_html_script_assign_vals(webui);
    webu_html_script_assign_config_nav(webui);
    webu_html_script_assign_config_item(webui);
    webu_html_script_assign_config_cat(webui);
    webu_html_script_assign_config(webui);

    webu_html_script_initform(webui);
    webu_html_script_display_cameras(webui);
    webu_html_script_display_config(webui);
    webu_html_script_display_movies(webui);
    webu_html_script_display_actions(webui);

    webu_html_script_camera_buttons_ptz(webui);
    webu_html_script_image_pantilt(webui);

    webu_html_script_cams_reset(webui);

    webu_html_script_cams_all_click(webui);
    webu_html_script_cams_one_click(webui);
    webu_html_script_cams_scan_click(webui);

    webu_html_script_cams_one_fnc(webui);
    webu_html_script_cams_all_fnc(webui);
    webu_html_script_cams_scan_fnc(webui);

    webu_html_script_movies_page(webui);
    webu_html_script_movies_click(webui);

    webui->resp_page += "  </script>\n\n";

}

/* Create the body section of the web page */
static void webu_html_body(ctx_webui *webui)
{
    webui->resp_page += "<body class='body' onload='initform()'>\n";

    webu_html_navbar(webui);

    webu_html_divmain(webui);

    webu_html_script(webui);

    webui->resp_page += "</body>\n";

}

/* Create the default motionplus page */
void webu_html_page(ctx_webui *webui)
{
    webui->resp_page += "<!DOCTYPE html>\n"
        "<html lang='" + webui->lang + "'>\n";

    webu_html_head(webui);

    webu_html_body(webui);

    webui->resp_page += "</html>\n";
}

/*Create the bad request page*/
void webu_html_badreq(ctx_webui *webui)
{
    webui->resp_page =
        "<!DOCTYPE html>\n"
        "<html>\n"
        "<body>\n"
        "<p>Bad Request</p>\n"
        "<p>The server did not understand your request.</p>\n"
        "</body>\n"
        "</html>\n";

}

/* Load a user provided html page */
void webu_html_user(ctx_webui *webui)
{
    char response[PATH_MAX];
    FILE *fp = NULL;

    fp = myfopen(webui->motapp->conf->webcontrol_html.c_str(), "re");

    if (fp == NULL) {
        MOTPLS_LOG(ERR, TYPE_STREAM, NO_ERRNO
            , _("Invalid user html file: %s")
            , webui->motapp->conf->webcontrol_html.c_str());

        webu_html_badreq(webui);

        return;
    }

    webui->resp_page = "";
    while (fgets(response, PATH_MAX-1, fp)) {
        webui->resp_page += response;
    }

    myfclose(fp);

}


