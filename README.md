
# Simple Web Server using libev

Make simple Web server using C libev library.

## Run Program

Firstly, build program with

```bash
$ make
```

Then, run it

```bash
$ make run
```

## Testing & Comparation with Apache Web-Server

Tested using ApacheBench with command

```bash
$ ab -n 10000 -c 10000 ip-address:port
```

And using `top` to check memory used

```bash
$ top
```

The command above will test web servers with 10000  concurrent requests and two kinds of requested file size (500 bytes and 20 kb). The results are shown below:

| Web Server | File size | Total Time Taken | Time per Request (avg) | Memory used |
:---:|:---:|:---:|:---:|:---:
Simple Web Server | 500 bytes | xxx ms | xxx ms | xxx bytes
Simple Web Server | 20 kb | xxx ms | xxx ms | xxx bytes
Apache Web Server | 500 bytes | 0.605 s | 0.061 ms | xxx bytes
Apache Web Server | 20 kb | 0.754 s | 0.075 ms | xxx bytes

For more details about testing result, please open `result` folder.