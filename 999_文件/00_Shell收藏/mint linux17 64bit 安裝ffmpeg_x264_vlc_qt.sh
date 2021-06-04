#mint linux17 64bit ¦w¸Ëffmpeg/x264/vlc/qt

sudo apt-get update

sudo apt-get -y install autoconf automake build-essential git libass-dev libgpac-dev libsdl1.2-dev libtheora-dev libtool libva-dev libvdpau-dev libvorbis-dev libx11-dev libxext-dev libxfixes-dev pkg-config texi2html zlib1g-dev

mkdir ~/ffmpeg_sources
wget http://www.tortall.net/projects/yasm/releases/yasm-1.2.0.tar.gz
tar xvzf yasm-1.2.0.tar.gz
cd yasm-1.2.0

sudo ./configure
sudo make && sudo make install

cd ~/ffmpeg_sources
git clone --depth 1 git://git.videolan.org/x264.git
cd x264

./configure --prefix="$HOME/ffmpeg_build" --bindir="$HOME/bin" --enable-static
sudo make && make install
make distclean

cd ~/ffmpeg_sources
git clone --depth 1 git://github.com/mstorsjo/fdk-aac.git
cd fdk-aac

autoreconf -fiv
./configure --prefix="$HOME/ffmpeg_build" --disable-shared
sudo make && make install
make distclean

sudo apt-get -y install libmp3lame-dev

cd ~/ffmpeg_sources
wget http://downloads.xiph.org/releases/opus/opus-1.0.3.tar.gz
tar xzvf opus-1.0.3.tar.gz
cd opus-1.0.3

./configure --prefix="$HOME/ffmpeg_build" --disable-shared
sudo make && make install
make distclean

cd ~/ffmpeg_sources
wget http://webm.googlecode.com/files/libvpx-v1.3.0.tar.bz2
tar xjvf libvpx-v1.3.0.tar.bz2
cd libvpx-v1.3.0

./configure --prefix="$HOME/ffmpeg_build" --disable-examples
sudo make && make install
make clean

cd ~/ffmpeg_sources
git clone --depth 1 git://source.ffmpeg.org/ffmpeg
cd ffmpeg

PKG_CONFIG_PATH="$HOME/ffmpeg_build/lib/pkgconfig"
export PKG_CONFIG_PATH
./configure --prefix="$HOME/ffmpeg_build" --extra-cflags="-I$HOME/ffmpeg_build/include" --extra-ldflags="-L$HOME/ffmpeg_build/lib" --bindir="$HOME/bin" --extra-libs="-ldl" --enable-gpl --enable-libass --enable-libfdk-aac --enable-libmp3lame --enable-libopus --enable-libtheora --enable-libvorbis --enable-libvpx --enable-libx264 --enable-nonfree --enable-x11grab

sudo make && make install
make distclean
hash -r

sudo apt-get -y install libav-tools

sudo apt-get install -y vlc

#create new Terminal
sudo su

cd /media/sf_Linuxmint_x64/
cp -R bin01 /home/jash/
cp -R Multicast_Playlist21_OK /home/jash/
cd /home/jash/
ls -l
chown -R jash:jash bin01 && chown -R jash:jash Multicast_Playlist21_OK/
ls -l

#create new Terminal
cd bin01/
ffmpeg -y -ss 0 -i ./Base.mp4 -f mpegts -vcodec libx264 -crf 25 -maxrate 2000k -bufsize 1500k -profile:v main -level 3.1 -preset medium -qp 0 -s 640x480 -r 30 -g 30 -subq 7 -bf 4 -partitions +parti4x4 -refs 4 -me_method hex -trellis 2 -b:v 1500k -deinterlace -acodec mp3 -strict experimental -b:a 48k -ar 44100 -threads 0 - |cvlc - --logo-file /home/chst01/5TVLOGO.png --logo-x=50 --logo-y=370 --sout '#transcode{sfilter=logo,fps=30,hurry-up,open-gop=normal,udp-caching=0,venc=x264{keyint=30,vqscale=1,vqmin=1,profile=baseline,partition=i4x4,level=2.1,bframes=4,subme=7,ref=4,qpmax=51,qpmin=1,me=hex,trellis=1},vcodec=h264,vb=850,vbv-maxrate=1200,vbv-bufsize=1500,vbv-init=100,width=640,height=480,deblock=0:0,deinterlace{bob},acodec=aac,aenc=ffmpeg{strict=-2},ab=48,samplerate=44100}:standard{mux=ts,access="udp",dst="224.8.8.138:13811"}'

#create new Terminal
sudo apt-get install -y qdevelop

sudo apt-get install -y qt-sdk
sudo apt-get install -y qt4-dev-tools
sudo apt-get install -y qt4-designer
sudo apt-get install -y ctags

#open qdevelop set external path
