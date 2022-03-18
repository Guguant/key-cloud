# Key Cloud

**Key Cloud** is a smart doors' lock management cloud platform.

* [Download Key Cloud source code here](https://github.com/estrm/key-cloud)

## Feature

* tiny and super quick

## Build

Build with **CMake**.

```c
mkdir build
cd build

cmake ..
make -j8

cd ../bin/
./kno
```

visit the IP: [http://localhost:8888](http://localhost:8888) (or other ports defined by variable **s_http_port** in **server.cc** file)

## Display

![home-page](doc/home.png)

## Third Party Library

1. [mongoose-6.9](https://github.com/cesanta/mongoose/tree/6.9) GPL-V2 License
2. [jsoncpp-1.8.3](https://github.com/open-source-parsers/jsoncpp/tree/1.8.3) MIT License

### Generate libmongoose.a

```c
git clone -b 6.9 --depth 1 github.com:cesanta/mongoose.git

cd mongoose

gcc -c -o mongoose.o mongoose.c
ar rcs libmongoose.a mongoose.o
```

### Generate libjsoncpp.a

```c
git clone -b 1.8.3 --depth 1 git@github.com:open-source-parsers/jsoncpp.git

cd jsoncpp

mkdir build
cd build

cmake ..
make -j8
```

## Contributors

* [estrm](https://github.com/estrm)
