#!/bin/bash
d=`date +%Y%m%d`
t=`date +%H:%M`

cd /home/pi/web
if [ ! -d $d ]
 then mkdir $d
 cd /home/pi/web/$d
 echo "
<html> 
<head>
 
<meta name='viewport' content='width=640' /> 
<style>
	body  {position: relative;}
	div {min-height: 300px; }
	img {position: absolute;xxxxheight:320px;width:320px;z-index: 10;}
	.hide {display: none;}
</style>
<head>
<body onload='document.body.scrollIntoView(false);'> 
<script type='text/javascript'>
	window.onscroll = scroll;
	function scroll() {
  		var els = document.querySelectorAll('img');
		for (var i=0; i < els.length; i++) {
   			els[i].setAttribute('style', 'display:block');
		}
    }
    function c(id){
    document.getElementById('i'+id).style.display = 'none';
    if (document.getElementById('i'+id).nextSibling === null){
    document.getElementById('i'+id).insertAdjacentHTML('afterend',  \`
    <video width=320  controls autoplay> <source src='\${id}.mp4' type=video/mp4 ></video >\`);
    }
    }
    function t(id){
    document.getElementById('d'+id).classList.toggle('hide');}
</script>
<a href='javascript: document.body.scrollIntoView(false);' 
   style='width:100%;font-size:24pt;margin: 20px auto 20px auto; display:block;'>
   Scroll to bottom
</a><br>
 " > index.htm 
fi

cd /home/pi/web/$d

#echo test

hide=""
if [[ "NNN" == $2 ]]
 then hide="hide"
fi

if [[ "$1" == "lightswitch" ]]
 then echo "<p> $t - &#128161; $3 </p>" >> index.htm
else

#check if jpg is still there or if it was already running

echo $1 >> status.txt
#echo test

if [ ! -e /home/pi/mplus/$1.jpg ]
then echo $1 exit >> status.txt
mv /home/pi/mplus/$1m.mp4 /home/pi/web/$d 
mv /home/pi/mplus/$1.mp4 /home/pi/web/$d 
exit
fi

#ffmpeg -y -i /home/pi/mplus/$1.jpg -compression_level 99 /home/pi/web/$d/$1.jpg

mv /home/pi/mplus/$1.jpg /home/pi/web/$d/$1.jpg


# pgrep -x ffmpeg >/dev/null && sleep 5


echo "
<h2 onclick='t(\"d$1\")'> ${1:5:4} $2</h2> 
<div id='d$1' class='$hide'>
<img id='i$1' src='$1.jpg' onclick='c(\"$1\")' ></div>
" >> index.htm



#ffmpeg -y -threads 1 -f rawvideo -pix_fmt yuv420p -video_size ${4}x${5} -framerate $3 -i /home/pi/mplus/$1.yuv -c:v libx264 -preset veryfast -an  /home/pi/web/$d/$1.mp4 # >> /home/pi/mplus/$1_ffmpeg.txt  2>&1 
mv /home/pi/mplus/$1.mp4 /home/pi/web/$d 
mv /home/pi/mplus/$1m.mp4 /home/pi/web/$d 
rm -f /home/pi/mplus/$1.yuv

#echo "<video width='320' preload='none' controls> <source src='$1.mp4' type='video/mp4'></video >  <br>" >> index.htm
#echo "<video width='320' preload='none' controls> <source src='$1m.mp4' type='video/mp4'></video >  <br>" >> index.htm
fi

find /home/pi/web/ -type d -maxdepth 1 -mindepth 1 -mtime +33 -exec rm -r {} \;


