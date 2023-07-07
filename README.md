# UVTT Thumbnail Creator

KDE thumbnail-plugin that generates small images (thumbnails) UVTT (.dd2vtt, .df2vtt, and .uvtt) files

## Build and install

### Build

```
mkdir build
cd build
cmake ..
make
```

### Install

```
cd build
sudo make install
```

TODO Install the .desktop into /usr/share/applications instead

```
cp src/uvttthumbnailer.desktop ~/.local/share/applications
```

Go to system settings, Applications, File Associations and add `application/x-universal-vtt`
Find that mime type in known types and add `*.dd2vtt` `*.df2vtt`, and `*.uvtt` to Filename Patterns.
Restart Dolphin

# Credit

Invaluable Universal VTT File reference: https://arkenforge.com/universal-vtt-files/

Copied the source code for this project from https://github.com/StefanHamminga/kde-fcstd-thumbnailer, since it was a VERY simple example of what I wanted to do.
