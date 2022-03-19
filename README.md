# Kno

Kno is a smart doors' lock management cloud platform.

* [Download Key Cloud source code here](https://github.com/estrm/kno)

## Feature

* tiny and super quick

## Build and Run

1. Build static libraries

Use the tool `generate_libs.sh` to build mongoose and jsoncpp source code. It will generate libmongoose.a and libjsoncpp.a in directory lib, if they do not exist.

Usage:

```shell
sh generate_libs.sh
```

2. Build the target kno

```c
mkdir build
cd build

cmake ..
make
```

3. Run

Back to root dir and `cd bin`. Run the kno.

```c
./kno
```

Visit the IP: [http://localhost:8888](http://localhost:8888) (or other ports defined by variable **s_http_port** in **server.cc** file)

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
make
```

## Contributors

* [estrm](https://github.com/estrm)

