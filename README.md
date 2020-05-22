# libwarc

A standalone library for enabling WARC functionalities in Web Harvesting applications.

WARC, short for **Web ARChive**, is a data storage format for storing archived web pages. It is an extension of the ARC format, traditionally used by web crawlers to store data from web pages. This project is an effort to create a standalone library for writing WARC files from captured web resources.

## Dependencies:

1. autoconf (>= 2.63)
2. automake (>= 1.11)
3. libtool (>= 2.4.6)
4. Check (>= 0.10.0)


## Build Instructions:

```bash
git clone https://gitlab.com/suhasks123/libwarc.git

cd libwarc

autoreconf -i

mkdir build

cd build

../configure

make

sudo make install
```

## Testing:

Tests can be run using (After running `make`):

```bash
make check
```
