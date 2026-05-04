# SFloat #
SFloat implementation in C

## How to use ##

```c
uint16_t raw         = 0xD5F0;
double   value       = sfloat2double(raw);
uint16_t sfloatbytes = double2sfloat(value);
```


## Build

To build this project run

```bash
$ mkdir build
$ cd build
$ cmake ..
$ make
```


## Run

To run this project run

```bash
$ ./app
```

## License

[Apache License 2.0](https://choosealicense.com/licenses/apache-2.0/)
